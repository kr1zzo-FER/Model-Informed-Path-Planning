import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import time
from user_action_interfaces.action import StartGoalAction
import sensor_msgs.msg as sensor_msgs
from user_action_interfaces.msg import StartGoalMsg
from user_action_interfaces.msg import CoastMsg
import math
import multiprocessing as mp
import datetime
from curve_generation.path_optimization import PathOptimization
import numpy as np

class Node:
    def __init__(self, coordinate : tuple = (0.0,0.0), cost: float = 0.0):
        self.coordinate = coordinate
        self.x = coordinate[0]
        self.y = coordinate[1]
        self.cost = cost


def add_coordinates(node1: Node, node2: Node):
    new_node = Node()
    new_node.x = node1.x + node2.x
    new_node.y = node1.y + node2.y
    new_node.cost = node1.cost + node2.cost
    return new_node


def compare_coordinates(node1: Node, node2: Node):
    return node1.x == node2.x and node1.y == node2.y

class PathPlanningActionServer(Node):
     
    n = 1
    m = 10

    motions = [
        Node((n, 0),m),
        Node((0, n),m),
        Node((-n, 0),m),
        Node((0, -n),m),
        Node((n, n), m*math.sqrt(2)),
        Node((n, -n),m*math.sqrt(2)),
        Node((-n, n),m*math.sqrt(2)),
        Node((-n, -n),m*math.sqrt(2))
    ]


    def __init__(self):
        super().__init__('path_planning_action_server')
        
        self.first_run = True
        
        # gps_coordinates_coast
        self.coast_points_subscriber = self.create_subscription(CoastMsg, 'gps_coordinates_coast', self.coast_points_callback, 10)

        self.zones_dictionary = {}
        self.coordinates = []
        self.size_x = 0
        self.size_y = 0
        self.zones_m_plot, self.zones_m = {}
        self.grid_size = 10.0

        # action server
        self.start_gps, self.goal_gps = (0.0,0.0), (0.0,0.0)
        self.start, self.goal = Node(), Node()
        self.start_m_plot, self.start_m = {}
        self.goal_m_plot , self.goal_m  = {}
        self.robot_radius = 0.0

        # D* lite
        self.x_min_world, self.y_min_world, self.x_max_world, self.y_max_world = 0.0,0.0,0.0,0.0 
        self.x_min_global, self.y_min_global , self.x_max_global, self.y_max_global = 0.0,0.0,0.0,0.0
        self.U = list()  # Would normally be a priority queue
        self.km = 0.0
        self.rhs = self.create_grid(math.inf)
        self.g = self.create_grid(math.inf)
        self.red_cost = 0.0
        self.yellow_cost = 0.0
        self.green_cost = 0.0

        # results
        self.path = []
        self.path_optimied_gps = []
        
    def coast_points_callback(self, msg):

        if self.first_run:
            self.first_run = False

            self.grid_size = msg.grid_size.data

            coast_points_gps = [(msg.coast_points_x.data[i], msg.coast_points_y.data[i]) for i in range(len(msg.coast_points_x.data))]
            red_zone_gps = [(msg.red_points_x.data[i], msg.red_points_y.data[i]) for i in range(len(msg.red_points_x.data))]
            yellow_zone_gps = [(msg.yellow_points_x.data[i], msg.yellow_points_y.data[i]) for i in range(len(msg.yellow_points_x.data))]
            green_zone_gps = [(msg.green_points_x.data[i], msg.green_points_y.data[i]) for i in range(len(msg.green_points_x.data))]

            self.zones_dictionary_gps = self.make_zones_dictionary(coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps)

            self.coordinates = self.get_coordinates()
            self.size_x = self.set_width()
            self.size_y = self.set_height()
            self.size = (self.size_x, self.size_y)
            self.zones_dictionary = self.set_zones_m()

            self.x_min_world, self.y_min_world, self.x_max_world, self.y_max_world= self.get_minmax_world()
            self.x_min_global, self.y_min_global , self.x_max_global, self.y_max_global = self.get_minmax_global()
            
            self.get_logger().info('Coast points received')

            self._action_server = ActionServer(
            self,
            StartGoalAction,
            'start_goal_action',
            self.execute_callback)
    

    def execute_callback(self, goal_handle):
        
        self.start_gps = goal_handle.request.start
        self.goal_gps = goal_handle.request.goal

        self.start_m_plot, self.start_m = self.set_start_m()
        self.goal_m_plot , self.goal_m  = self.set_goal_m()
        self.robot_radius = self.grid_size/2

        self.start = Node(self.start_m)
        self.goal = Node(self.goal_m)

        self.rhs[self.goal.x][self.goal.y] = 0
        self.U.append((self.goal, self.calculate_key(self.goal)))

        self._logger.info('Executing goal...')
        self._logger.info(f'Start: {self.start_gps}')
        self._logger.info(f'Goal: {self.goal_gps}')

        self.test_dstar_lite()

        self.path_optimied_gps = self.optimize_path()

        path_x = [point[0] for point in self.path_optimized_gps]   
        path_y = [point[1] for point in self.path_optimized_gps]

        result = StartGoalAction.Result()
        result.path_x = path_x  
        result.path_y = path_y

        return result
    
    def optimize_path(self):
        path_optimization = PathOptimization(self.path)
        path_optimization.optimize_path()
        optimized_path = path_optimization.get_path()
        self.internal_optimized_points = optimized_path
        optimized_path_gps = [self.pixel_to_gps(point[0],point[1]) for point in optimized_path]
        return optimized_path_gps

        
    def make_zones_dictionary(self, coast_points, red_zone, yellow_zone, green_zone):
        zones_dictionary = {}
        for point in coast_points:
            zones_dictionary[point] = "c"
        for point in red_zone:
            zones_dictionary[point] = "r"
        for point in yellow_zone:
            zones_dictionary[point] = "y"
        for point in green_zone:
            zones_dictionary[point] = "g"
        return zones_dictionary
    
    def set_zones_m(self):
        gps_dictionary, gps_dictionary_resized = {}, {}
        for key in self.zones_dictionary:
            new_key = self.gps_to_pixel(key[0],key[1])
            gps_dictionary[new_key] = self.zones_dictionary[key]
            new_key = self.adapt_coordinates(key)
            gps_dictionary_resized[new_key] = self.zones_dictionary[key]
        return gps_dictionary_resized
    
    def set_start_m(self):
        start_m = self.gps_to_pixel(self.start.x,self.start.y)
        start_m_resized = self.adapt_coordinates(self.start)
        return start_m_resized
    
    def set_goal_m(self):
        goal_m = self.gps_to_pixel(self.goal[0],self.goal[1])
        goal_m_resized = self.adapt_coordinates(self.goal)
        return goal_m_resized
    
    def get_minmax_world(self):
        obstacle_list = []
        for key, value in self.zones_dictionary.items():
            if value == "c":
                obstacle_list.append(key)

        x_min = min(obstacle_list, key=lambda x: x[0])[0]
        y_min = min(obstacle_list, key=lambda x: x[1])[1]
        x_max = max(obstacle_list, key=lambda x: x[0])[0]
        y_max = max(obstacle_list, key=lambda x: x[1])[1]

        return x_min, y_min, x_max, y_max
    
    def get_minmax_global(self):
        obstacle_list = []
        for key, value in self.zones_dictionary.items():
            obstacle_list.append(key)

        x_min = min(obstacle_list, key=lambda x: x[0])[0]
        y_min = min(obstacle_list, key=lambda x: x[1])[1]
        x_max = max(obstacle_list, key=lambda x: x[0])[0]
        y_max = max(obstacle_list, key=lambda x: x[1])[1]

        return x_min, y_min, x_max, y_max

    def get_coordinates(self):

        coordinates_list = self.zones_dictionary.keys()
        
        #min of the point[0] and point[1] for x and y
        min_x = min(coordinates_list, key = lambda x: x[0])[0]
        min_y = min(coordinates_list, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coordinates_list, key = lambda x: x[0])[0]
        max_y = max(coordinates_list, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        print(f"Coordinates: {result}")
        return result
    
    def gps_to_meters(self,lat1, lon1, lat2, lon2):
        # Convert gps cordinates to meters from (lat1,lon1) to (lat2,lon2)
        R = 6378.137 # Radius of earth in KM
        dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
        dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
        a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
        d = R * c
        return d * 1000 # meters
    
    def gps_to_pixel(self,latitude, longitude):
        # Convert gps coordinates to pixel coordinates
        #print(f"Coordinates gps_to_pixel: {self.coordinates}")
        x_pixel = int(round((longitude - self.coordinates[0]) * self.size_x / (self.coordinates[2] - self.coordinates[0])))
        y_pixel = int(round((latitude - self.coordinates[1]) * self.size_y / (self.coordinates[3] - self.coordinates[1])))
        x_pixel = round(x_pixel/self.grid_size)*self.grid_size
        y_pixel = round(y_pixel/self.grid_size)*self.grid_size
        
        return x_pixel, y_pixel
    
    def pixel_to_gps(self,x_pixel, y_pixel):
        # Convert pixel coordinates to gps coordinates
        latitude = self.coordinates[1] + y_pixel * (self.coordinates[3] - self.coordinates[1]) / self.size_y
        longitude = self.coordinates[0] + x_pixel * (self.coordinates[2] - self.coordinates[0]) / self.size_x
        return latitude, longitude

    def adapt_coordinates(self,coord):
        # Adapt coordinates to the grid size
        new_coord = self.gps_to_pixel(coord.x, coord.y)
        new_coord = (int(new_coord[0]/self.grid_size), int(new_coord[1]/self.grid_size))
        return new_coord
    
    def set_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def set_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))
    
    def create_grid(self, val: float):
        return np.full((self.x_max_world, self.y_max_world), val)
    

    def c(self, node1: Node, node2: Node):
        try:
            factor = self.cost_dictionary[(node2.x, node2.y)]
        except KeyError:
            factor = 1
        #print(self.n)
        new_node = Node((node1.x-node2.x, node1.y-node2.y))
        detected_motion = list(filter(lambda motion:
                                      compare_coordinates(motion, new_node),
                                      self.motions))
        return detected_motion[0].cost * factor

    def h(self, s: Node):
        # Cannot use the 2nd euclidean norm as this might sometimes generate
        # heuristics that overestimate the cost, making them inadmissible,
        # due to rounding errors etc (when combined with calculate_key)
        # To be admissible heuristic should
        # never overestimate the cost of a move
        # hence not using the line below
        # return math.hypot(self.start.x - s.x, self.start.y - s.y)

        # Below is the same as 1; modify if you modify the cost of each move in
        # motion
        # return max(abs(self.start.x - s.x), abs(self.start.y - s.y))
        return 1

    def calculate_key(self, s: Node):
        return (min(self.g[s.x][s.y], self.rhs[s.x][s.y]) + self.h(s)
                + self.km, min(self.g[s.x][s.y], self.rhs[s.x][s.y]))

    def is_valid(self, node: Node):
        if 0 <= node.x < self.x_max_world and 0 <= node.y < self.y_max_world:
            return True
        return False

    def get_neighbours(self, u: Node):
        if u in self.cost_dictionary:
            self.n = 10
        else:
            self.n = 100
        return [add_coordinates(u, motion) for motion in self.motions
                if self.is_valid(add_coordinates(u, motion))]

    def pred(self, u: Node):
        # Grid, so each vertex is connected to the ones around it
        return self.get_neighbours(u)

    def succ(self, u: Node):
        # Grid, so each vertex is connected to the ones around it
        return self.get_neighbours(u)

    
    def update_vertex(self, u: Node):
        if not compare_coordinates(u, self.goal):
            self.rhs[u.x][u.y] = min([self.c(u, sprime) +
                                      self.g[sprime.x][sprime.y]
                                      for sprime in self.succ(u)])
        if any([compare_coordinates(u, node) for node, key in self.U]):
            self.U = [(node, key) for node, key in self.U
                      if not compare_coordinates(node, u)]
            self.U.sort(key=lambda x: x[1])
        if self.g[u.x][u.y] != self.rhs[u.x][u.y]:
            self.U.append((u, self.calculate_key(u)))
            self.U.sort(key=lambda x: x[1])

    def compare_keys(self, key_pair1: tuple[float, float],
                     key_pair2: tuple[float, float]):
        if key_pair1[0] < key_pair2[0]:
            return True
        elif key_pair1[0] == key_pair2[0] and key_pair1[1] < key_pair2[1]:
            return True
        return False
            

    def compute_shortest_path(self):
        self.U.sort(key=lambda x: x[1])
        has_elements = len(self.U) > 0
        start_key_not_updated = self.compare_keys(
            self.U[0][1], self.calculate_key(self.start)
        )
        rhs_not_equal_to_g = self.rhs[self.start.x][self.start.y] != \
            self.g[self.start.x][self.start.y]
        while has_elements and start_key_not_updated or rhs_not_equal_to_g:
            self.kold = self.U[0][1]
            u = self.U[0][0]
            self.U.pop(0)
            if self.compare_keys(self.kold, self.calculate_key(u)):
                self.U.append((u, self.calculate_key(u)))
                self.U.sort(key=lambda x: x[1])
            elif (self.g[u.x, u.y] > self.rhs[u.x, u.y]).any():
                self.g[u.x, u.y] = self.rhs[u.x, u.y]
                for s in self.pred(u):
                    self.update_vertex(s)
            else:
                self.g[u.x, u.y] = math.inf
                for s in self.pred(u) + [u]:
                    self.update_vertex(s)
            self.U.sort(key=lambda x: x[1])
            start_key_not_updated = self.compare_keys(
                self.U[0][1], self.calculate_key(self.start)
            )
            rhs_not_equal_to_g = self.rhs[self.start.x][self.start.y] != \
                self.g[self.start.x][self.start.y]

    def compute_current_path(self):
        path = list()
        current_point = Node(self.start.x, self.start.y)
        while not compare_coordinates(current_point, self.goal):
            path.append(current_point)
            current_point = min(self.succ(current_point),
                                key=lambda sprime:
                                self.c(current_point, sprime) +
                                self.g[sprime.x][sprime.y])
        path.append(self.goal)
        return path

    def compare_paths(self, path1: list, path2: list):
        if len(path1) != len(path2):
            return False
        for node1, node2 in zip(path1, path2):
            if not compare_coordinates(node1, node2):
                return False
        return True
    
    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)
    
    def test_dstar_lite(self):

        pathx = []
        pathy = []
        last = self.start
        self.compute_shortest_path()
        pathx.append(self.start.x + self.x_min_global)
        pathy.append(self.start.y + self.y_min_global)


        while not compare_coordinates(self.goal, self.start):
            if self.g[self.start.x][self.start.y] == math.inf:
                print("No path possible")
                return False, pathx, pathy
            self.start = min(self.succ(self.start),
                             key=lambda sprime:
                             self.c(self.start, sprime) +
                             self.g[sprime.x][sprime.y])
            print(self.start.x + self.x_min_global, self.start.y + self.y_min_global)
            pathx.append(self.start.x + self.x_min_global)
            pathy.append(self.start.y + self.y_min_global)


        rx = pathx
        ry = pathy

        start_time = time.time()    
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.get_logger().info(f"Distance: {distance}") 
        self.get_logger().info(f"Execution time: {function_time}")   

       
        self.path = [(rx[i],ry[i]) for i in range(len(rx))]

    


def main(args=None):
    rclpy.init(args=args)

    pp_action_server = PathPlanningActionServer()

    rclpy.spin(pp_action_server)


if __name__ == '__main__':
    main()