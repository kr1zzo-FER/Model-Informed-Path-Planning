import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node as rclpy_Node
from .Node import Node
from .Node import add_coordinates
from .Node import compare_coordinates
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
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

show_debug = False
show_results = False

class PathPlanningServer(rclpy_Node):

    def __init__(self):
        super().__init__('path_planning_server')
        
        # enable fetching subscription once
        self.first_run = True

        
        # gps_coordinates_coast
        self.coast_points_subscriber = self.create_subscription(CoastMsg, 'gps_coordinates_coast', self.coast_points_callback, 10)
        
        # gps data
        self.zones_dictionary_gps = {}
        self.coordinates = []

        # Local coordinate system = 1:grid_size scale (1 pixel = grid_size meters)
        self.grid_size = 0.0
        self.zones_dictionary = {}
        self.size_x = 0
        self.size_y = 0
        self.x_min_world, self.y_min_world, self.x_max_world, self.y_max_world = 0.0,0.0,0.0,0.0 
        self.x_min_global, self.y_min_global , self.x_max_global, self.y_max_global = 0.0,0.0,0.0,0.0
        
        # action server
        self.goal_handle = None
        self.start_gps, self.goal_gps = (0.0,0.0), (0.0,0.0)
        self.start_m, self.goal_m = (0,0), (0,0)
        self.start, self.goal = Node(), Node()

        # D* lite
        self.red_cost = 10.0
        self.yellow_cost = 2.0
        self.green_cost = 1.5

        self.cost_dictionary = {}   
        self.U = list()  # Would normally be a priority queue
        self.km = 0.0
        self.rhs = np.array([])
        self.g = np.array([])

        # results
        self.path = []
        self.path_gps = []
        self.path_optimized = []
        self.path_optimied_gps = []
        
    def coast_points_callback(self, msg):

        if self.first_run:

            self.get_logger().info('Coast points callback started')

            self.first_run = False
            
            # coordinates sampling rate
            self.grid_size = msg.grid_size

            # Fetch ROS2 CoastMsg message data
            coast_points_gps = [(msg.coast_points_x.data[i], msg.coast_points_y.data[i]) for i in range(len(msg.coast_points_x.data))]
            red_zone_gps = [(msg.red_points_x.data[i], msg.red_points_y.data[i]) for i in range(len(msg.red_points_x.data))]
            yellow_zone_gps = [(msg.yellow_points_x.data[i], msg.yellow_points_y.data[i]) for i in range(len(msg.yellow_points_x.data))]
            green_zone_gps = [(msg.green_points_x.data[i], msg.green_points_y.data[i]) for i in range(len(msg.green_points_x.data))]

            # 1.1. Create a dictionary : key = gps coordinates, value = zone
            self.make_zones_dictionary(coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps)

            # 1.4. min and max coordinates - all gps coordinates (zones+coast)
            minmax_global = self.get_minmax_global(self.zones_dictionary)
            self.x_min_global, self.y_min_global , self.x_max_global, self.y_max_global = minmax_global[0], minmax_global[1], minmax_global[2], minmax_global[3]

            minmax_world = self.get_minmax_world(self.zones_dictionary)
            self.x_min_world, self.y_min_world , self.x_max_world, self.y_max_world = minmax_world[0], minmax_world[1], minmax_world[2], minmax_world[3]
            # 1.5. Create a grid
            self.rhs = self.create_grid(math.inf)
            self.g = self.create_grid(math.inf)

            if self.zones_dictionary_gps == {}:
                self.get_logger().info("gps_coordinates_coast is empty. Aborting process.")
                return StartGoalAction.Result()
            
            # Run ROS2 path planning server
            self._action_server = ActionServer(
                self,
                StartGoalAction,
                'start_goal_action',
                self.execute_callback)
    

    def execute_callback(self, goal_handle):

        self.goal_handle = goal_handle

        self.get_logger().info('Executing path planning server started')
        
        self.start_gps = goal_handle.request.start
        self.goal_gps = goal_handle.request.goal
        
        if [self.start_gps[0],self.start_gps[1]] == [0.0,0.0] or [self.goal_gps[0],self.goal_gps[1]] == [0.0,0.0]:
            self.get_logger().info("Start or goal coordinates are not set. Aborting process with empty path.")
            return StartGoalAction.Result()

        self.start_m = self.set_start_m(self.start_gps)
        self.goal_m  = self.set_goal_m(self.goal_gps)
        
        self.start = Node(self.start_m)
        self.goal = Node(self.goal_m)
        self.partial_start = Node(self.start_m)
        self.partial_goal = Node(self.goal_m)

        if show_debug:
            self.visualization(True,self.zones_dictionary_gps,self.start_gps,self.goal_gps)
            self.visualization(False,self.zones_dictionary,self.start_m,self.goal_m)

        self._logger.info(f'Start: {self.start_gps}[{(self.start.x,self.start.y)}]')
        self._logger.info(f'Goal: {self.goal_gps}[{(self.goal.x,self.goal.y)}]')


        self.rhs[self.goal.x][self.goal.y] = 0
        self.U.append((self.goal, self.calculate_key(self.goal)))

        
        self.test_dstar_lite()

        self.path_gps = [self.adapt_coordinates_reverse(point) for point in self.path]

        self.path_optimized = self.optimize_path()

        self.optimized_path_gps = [self.adapt_coordinates_reverse(point) for point in self.path_optimized]

        path_x = [point[0] for point in self.optimized_path_gps]   
        path_y = [point[1] for point in self.optimized_path_gps]

        result = StartGoalAction.Result()
        result.path_x = path_x  
        result.path_y = path_y

        if show_results:
            self.visualization(False,self.zones_dictionary,self.start_m,self.goal_m,self.path,self.path_optimized)
            self.visualization(True,self.zones_dictionary_gps,self.start_gps,self.goal_gps,self.path_gps,self.optimized_path_gps)

        return result
    
    def optimize_path(self):
        path_optimization = PathOptimization(self.path)
        path_optimization.optimize_path()
        optimized_path = path_optimization.get_path()
        return optimized_path

        
    def make_zones_dictionary(self, coast_points, red_zone, yellow_zone, green_zone):
        # 1.1. Create a dictionary : key = gps coordinates, value = zone
        zones_dictionary_gps, zones_dictionary, cost_dictionary = {}, {}, {}

        for point in red_zone:
            zones_dictionary_gps[point] = "r"
        for point in yellow_zone:
            zones_dictionary_gps[point] = "y"
        for point in green_zone:
            zones_dictionary_gps[point] = "g"
        for point in coast_points:
            zones_dictionary_gps[point] = "c"
        
        # 1.2. min and max coordinates - all gps coordinates (zones+coast)
        self.coordinates = self.get_coordinates(zones_dictionary_gps)
        # 1.2.1. Set the width and height of the grid in meters
        self.size_x = self.set_width()
        self.size_y = self.set_height()

        # 1.3. gps coordinates to local coordinates (meters)
        for key in zones_dictionary_gps.keys():
            new_key = self.adapt_coordinates(key)
            zones_dictionary[new_key] = zones_dictionary_gps[key]

        for key, value in zones_dictionary.items():
                
            if value == "r":
                cost_dictionary[key] = self.red_cost
            elif value == "y":
                cost_dictionary[key] = self.yellow_cost
            elif value == "g":
                cost_dictionary[key] = self.green_cost
            elif value == "c":
                cost_dictionary[key] = math.inf
            else:
                cost_dictionary[key] = 1

        self.zones_dictionary = zones_dictionary  
        self.zones_dictionary_gps = zones_dictionary_gps  
        self.cost_dictionary = cost_dictionary
    
    def get_coordinates(self, zones_dictionary_gps):

        coordinates_list = zones_dictionary_gps.keys()
        
        #min of the point[0] and point[1] for x and y
        min_x = min(coordinates_list, key = lambda x: x[0])[0]
        min_y = min(coordinates_list, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coordinates_list, key = lambda x: x[0])[0]
        max_y = max(coordinates_list, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        print(f"Coordinates: {result}")
        return result

    
    def get_minmax_global(self, zones_dictionary):
        # 1.2./1.4. Get the min and max coordinates of the all gps coordinates
        coordinates_list = zones_dictionary.keys()
        
        min_x = min(coordinates_list, key = lambda x: x[0])[0]
        min_y = min(coordinates_list, key = lambda x: x[1])[1]
        max_x = max(coordinates_list, key = lambda x: x[0])[0]
        max_y = max(coordinates_list, key = lambda x: x[1])[1]

        result = [min_x, min_y, max_x, max_y]
        self.get_logger().info(f"Minmax_global:")
        self.get_logger().info(f"min_x: {min_x}, min_y: {min_y}, max_x: {max_x}, max_y: {max_y}")
        return result

    def get_minmax_world(self, zones_dictionary):
        # 1.4. min and max coordinates - only coast gps coordinates
        coordinates_list = []
        for key, value in zones_dictionary.items():
            if value == "c":
                coordinates_list.append(key)

        #min of the point[0] and point[1] for x and y
        min_x = min(coordinates_list, key = lambda x: x[0])[0]
        min_y = min(coordinates_list, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coordinates_list, key = lambda x: x[0])[0]
        max_y = max(coordinates_list, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        self.get_logger().info(f"Minmax_world:")
        self.get_logger().info(f"min_x: {min_x}, min_y: {min_y}, max_x: {max_x}, max_y: {max_y}")
        return result
            
    def set_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def set_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))

    
    def set_start_m(self, start = [0.0,0.0]):   
        start_m = self.gps_to_pixel(start[0],start[1])
        start_m_resized = self.adapt_coordinates(start)
        return start_m_resized
    
    def set_goal_m(self, goal = [0.0,0.0]):
        goal_m = self.gps_to_pixel(goal[0],goal[1])
        goal_m_resized = self.adapt_coordinates(goal)
        return goal_m_resized
    

    ### Data conversion functions ###

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
        new_coord = self.gps_to_pixel(coord[0], coord[1])
        new_coord = (round(new_coord[0]/self.grid_size), round(new_coord[1]/self.grid_size))
        return new_coord
    
    def adapt_coordinates_reverse(self,coord):
        # Adapt coordinates to the grid size
        new_coord = (coord[0]*self.grid_size, coord[1]*self.grid_size)
        new_coord = self.pixel_to_gps(new_coord[0], new_coord[1])
        return new_coord

    
    ### D* Lite algorithm functions ###

    motions = [
    Node((1, 0),1),
    Node((0, 1),1),
    Node((-1, 0),1),
    Node((0, -1),1),
    Node((1, 1),math.sqrt(2)),
    Node((-1, 1),math.sqrt(2)),
    Node((1, -1),math.sqrt(2)),
    Node((-1, -1),math.sqrt(2))
    ]

    def create_grid(self, val: float):
        # 1.5. Create a grid
        return np.full((self.x_max_world, self.y_max_world), val)

    def c(self, node1: Node, node2: Node):
        try:
            factor = self.cost_dictionary[(node2.x, node2.y)]
            if factor == math.inf:
                #self.get_logger().info(f"Obastacle detected at {node2.x, node2.y}")
                return math.inf
        except KeyError:
            factor = 1

        #self.get_logger().info(f"Factor: {factor}")
        new_node = Node((node1.x-node2.x, node1.y-node2.y))
        detected_motion = list(filter(lambda motion:
                                      compare_coordinates(motion, new_node),
                                      self.motions))
        motion = detected_motion[0].cost * factor
        return motion

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
        self.get_logger().info('Computing shortest path')
        self.U.sort(key=lambda x: x[1])
        has_elements = len(self.U) > 0
        start_key_not_updated = self.compare_keys(
            self.U[0][1], self.calculate_key(self.start)
        )
        rhs_not_equal_to_g = self.rhs[self.start.x][self.start.y] != \
            self.g[self.start.x][self.start.y]
        
        area_x, area_y = [], []
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
            
            area_x.append(u.x)
            area_y.append(u.y)

            area_gps = [self.adapt_coordinates_reverse(u) for u in zip(area_x,area_y)]

            area_x_gps = [point[0] for point in area_gps]
            area_y_gps = [point[1] for point in area_gps]

            feedback = StartGoalAction.Feedback()
            feedback.search_area_x = area_x_gps
            feedback.search_area_y = area_y_gps
            feedback.partial_path_x = []
            feedback.partial_path_y = []

            self.goal_handle.publish_feedback(feedback)



    
   
        

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
        self.get_logger().info('D* Lite algorithm started')
        self.get_logger().info('Start: ' + str(self.start.x) + ' ' + str(self.start.y))
        self.get_logger().info('Goal: ' + str(self.goal.x) + ' ' + str(self.goal.y))
        self.get_logger().info('min_world: ' + str(self.x_min_world) + ' ' + str(self.y_min_world))
        self.get_logger().info('max_world: ' + str(self.x_max_world) + ' ' + str(self.y_max_world))
        self.get_logger().info('cost_dictionary: ' + str(self.cost_dictionary)) 
        
        start_time = time.time() 
        pathx, pathy = [], []
        rx, ry = [], []
        self.compute_shortest_path()
        self.start = self.partial_start
        self.goal = self.partial_goal
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
            pathx.append(self.start.x + self.x_min_global)
            pathy.append(self.start.y + self.y_min_global)

        rx = pathx
        ry = pathy

        rx, ry = [rx[i] for i in range(len(rx))], [ry[i] for i in range(len(ry))]
        
        self.path = [(rx[i],ry[i]) for i in range(len(rx))]
        
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.get_logger().info(f"Distance: {distance}") 
        self.get_logger().info(f"Execution time: {function_time}")   

       
        

    ### Visualization functions ###

    def visualization(self, gps = True, zones_dictionary = dict, start = [0.0,0.0], goal = [0.0,0.0], path = [], path_optimized = []):
        fig, ax = plt.subplots()
        ax.grid(True)
        if gps:
            i,j = 1,0
            legend_elements = []
            legend_elements.append(Line2D([0], [0], color='black', lw=4, label=f"min_global = {self.coordinates[0]}, {self.coordinates[1]}"))
            legend_elements.append(Line2D([0], [0], color='black', lw=4, label=f"max_global = {self.coordinates[2]}, {self.coordinates[3]}"))
            legend_elements.append(Line2D([0], [0], color='blue', lw=4, label=f"start = {self.start_gps[0]}, {self.start_gps[1]}"))
            legend_elements.append(Line2D([0], [0], color='blue', lw=4, label=f"goal = {self.goal_gps[0]}, {self.goal_gps[1]}"))
            ax.legend(handles=legend_elements, loc='upper right')

        else:
            i,j = 0,1
            legend_elements = []
            legend_elements.append(Line2D([0], [0], color='black', lw=4, label=f"min_global = {self.x_min_global}, {self.y_min_global}"))
            legend_elements.append(Line2D([0], [0], color='black', lw=4, label=f"max_global = {self.x_max_global}, {self.y_max_global}"))
            legend_elements.append(Line2D([0], [0], color='black', lw=4, label=f"min_world = {self.x_min_world}, {self.y_min_world}"))
            legend_elements.append(Line2D([0], [0], color='black', lw=4, label=f"max_world = {self.x_max_world}, {self.y_max_world}"))
            legend_elements.append(Line2D([0], [0], color='blue', lw=4, label=f"start = {self.start.x}, {self.start.y}"))
            legend_elements.append(Line2D([0], [0], color='blue', lw=4, label=f"goal = {self.goal.x}, {self.goal.y}"))
            ax.legend(handles=legend_elements, loc='upper right')

        for key, value in zones_dictionary.items():
            if value == 'c':
                ax.plot(key[i],key[j],'bo', markersize=0.1)
            elif value == 'r':
                ax.plot(key[i],key[j],'ro', markersize=0.1)
            elif value == 'g':
                ax.plot(key[i],key[j],'go', markersize=0.1)
            elif value == 'y':
                ax.plot(key[i],key[j],'yo', markersize=0.1)
        
        ax.plot(start[i],start[j],'bx', markersize=10)
        ax.plot(goal[i],goal[j],'bo', markersize=10)

        for point in path:
                ax.plot(point[i],point[j],'co', markersize=2)
        for point in path_optimized:
                ax.plot(point[i],point[j],'mo', markersize=2)

        plt.show()


def main(args=None):

    rclpy.init(args=args)

    pp_action_server = PathPlanningServer()

    rclpy.spin(pp_action_server)


if __name__ == '__main__':
    main()