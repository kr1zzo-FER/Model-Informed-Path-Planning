"""
D* Lite grid planning
author: vss2sn (28676655+vss2sn@users.noreply.github.com)
Link to papers:
D* Lite (Link: http://idm-lab.org/bib/abstracts/papers/aaai02b.pd)
Improved Fast Replanning for Robot Navigation in Unknown Terrain
(Link: http://www.cs.cmu.edu/~maxim/files/dlite_icra02.pdf)
Implemented maintaining similarity with the pseudocode for understanding.
Code can be significantly optimized by using a priority queue for U, etc.
Avoiding additional imports based on repository philosophy.
"""
import math
import matplotlib.pyplot as plt
import random
import numpy as np

show_animation = False
pause_time = 0.001
p_create_random_obstacle = 0
path_cordinates_x = []
path_cordinates_y = []


class Node:
    def __init__(self, coordinate : tuple = (0.0,0.0), value : str = "n" , cost: float = 0.0):
        self.coordinate = coordinate
        self.x = coordinate[0]
        self.y = coordinate[1]
        self.value = value
        self.cost = cost


def add_coordinates(node1: Node, node2: Node):
    new_node = Node()
    new_node.x = node1.x + node2.x
    new_node.y = node1.y + node2.y
    new_node.cost = node1.cost + node2.cost
    return new_node


def compare_coordinates(node1: Node, node2: Node):
    return node1.x == node2.x and node1.y == node2.y


class DStarLite:

    # Please adjust the heuristic function (h) if you change the list of
    # possible motions
    n = 1
    m = 10
    motions = [
        Node((n, 0),'m' , m),
        Node((0, n),'m', m),
        Node((-n, 0),'m', m),
        Node((0, -n),'m', m),
        Node((n, n),'m', m*math.sqrt(2)),
        Node((n, -n),'m',m*math.sqrt(2)),
        Node((-n, n),'m',m*math.sqrt(2)),
        Node((-n, -n),'m',m*math.sqrt(2))
    ]

    def __init__(self, zones, start, goal):
        #if value == c, find min value key
        self.zones = zones
        self.x_min_world, self.y_min_world, self.x_max_world, self.y_max_world= self.get_minmax_world()
        self.x_min_global, self.y_min_global , self.x_max_global, self.y_max_global = self.get_minmax_global()
        start = (int(start[0]/self.n)*self.n, int(start[1]/self.n)*self.n)
        goal = (int(goal[0]/self.n)*self.n, int(goal[1]/self.n)*self.n)
        self.start = Node(start, 's')
        self.goal = Node(goal, 'g')
        self.U = list()  # Would normally be a priority queue
        self.km = 0.0
        self.rhs = self.create_grid(math.inf)
        self.g = self.create_grid(math.inf)
        self.rhs[self.goal.x][self.goal.y] = 0
        self.U.append((self.goal, self.calculate_key(self.goal)))
        self.red_cost = 0.0
        self.yellow_cost = 0.0
        self.green_cost = 0.0
        self.cost_dictionary = {}
        self.init_print()
    
    def init_print(self):
        print("Start: ", self.start.x, self.start.y)
        print("Goal: ", self.goal.x, self.goal.y)

    def set_cost(self, red_cost: float, yellow_cost: float, green_cost: float):
        self.red_cost = red_cost
        self.yellow_cost = yellow_cost
        self.green_cost = green_cost
        for key, value in self.zones.items():
            if value == "c":
                self.cost_dictionary[key] = math.inf
            elif value == "r":
                self.cost_dictionary[key] = red_cost
            elif value == "y":
                self.cost_dictionary[key] = yellow_cost
            elif value == "g":
                self.cost_dictionary[key] = green_cost
            else:
                self.cost_dictionary[key] = 1


    def get_minmax_world(self):
        obstacle_list = []
        for key, value in self.zones.items():
            if value == "c":
                obstacle_list.append(key)

        x_min = min(obstacle_list, key=lambda x: x[0])[0]
        y_min = min(obstacle_list, key=lambda x: x[1])[1]
        x_max = max(obstacle_list, key=lambda x: x[0])[0]
        y_max = max(obstacle_list, key=lambda x: x[1])[1]

        return x_min, y_min, x_max, y_max
    
    def get_minmax_global(self):
        obstacle_list = []
        for key, value in self.zones.items():
            obstacle_list.append(key)

        x_min = min(obstacle_list, key=lambda x: x[0])[0]
        y_min = min(obstacle_list, key=lambda x: x[1])[1]
        x_max = max(obstacle_list, key=lambda x: x[0])[0]
        y_max = max(obstacle_list, key=lambda x: x[1])[1]

        return x_min, y_min, x_max, y_max

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
    
    def get_path(self):
        return path_cordinates_x, path_cordinates_y
    
    
    def test(self):

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


        for px in pathx:
            path_cordinates_x.append(px)
        for py in pathy:
            path_cordinates_y.append(py)
        print("Path found")
        return True, pathx, pathy

