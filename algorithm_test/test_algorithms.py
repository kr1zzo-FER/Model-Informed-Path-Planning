"""

Path planning algorithms test

author: Enio Krizman (@kr1zzo)

"""

import math

import matplotlib.pyplot as plt
import yaml

from sys import maxsize
from skimage import io, measure
from PIL import Image
import pickle
import os 
from pathlib import Path
import time
import threading

from algorithms.a_star import AStarPlanner
from algorithms.dstar import Map, State
from algorithms.dstar import Dstar
from algorithms.d_star_lite import DStarLite
from algorithms.d_star_lite import Node
from algorithms.dijkstra import Dijkstra
from algorithms.bidirectional_a_star import BidirectionalAStarPlanner
from algorithms.breadth_first_search import BreadthFirstSearchPlanner
from algorithms.bidirectional_breadth_first_search import BidirectionalBreadthFirstSearchPlanner
from algorithms.depth_first_search import DepthFirstSearchPlanner
from algorithms.greedy_best_first_search import BestFirstSearchPlanner


show_animation = False



class State:

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.parent = None
        self.state = "."
        self.t = "new"  # tag for state
        self.h = 0
        self.k = 0

    def cost(self, state):
        if self.state == "#" or state.state == "#":
            return maxsize

        return math.sqrt(math.pow((self.x - state.x), 2) +
                         math.pow((self.y - state.y), 2))

    def set_state(self, state):
        """
        .: new
        #: obstacle
        e: oparent of current state
        *: closed state
        s: current state
        """
        if state not in ["s", ".", "#", "e", "*"]:
            return
        self.state = state

class Map:

    def __init__(self, row, col):
        self.row = row
        self.col = col
        self.map = self.init_map()

    def init_map(self):
        map_list = []
        for i in range(self.row):
            tmp = []
            for j in range(self.col):
                tmp.append(State(i, j))
            map_list.append(tmp)
        return map_list

    def get_neighbors(self, state):
        state_list = []
        for i in [-1, 0, 1]:
            for j in [-1, 0, 1]:
                if i == 0 and j == 0:
                    continue
                if state.x + i < 0 or state.x + i >= self.row:
                    continue
                if state.y + j < 0 or state.y + j >= self.col:
                    continue
                state_list.append(self.map[state.x + i][state.y + j])
        return state_list

    def set_obstacle(self, point_list):
        for x, y in point_list:
            if x < 0 or x >= self.row or y < 0 or y >= self.col:
                continue

            self.map[x][y].set_state("#")

class Algorithms:
    def __init__(self, ox, oy):
        self.ox = ox
        self.oy = oy
        self.rows = []
        self.columns = ['Time [s]', 'Distance [m]']
        self.values = []

    def get_path(self):
        return self.rx, self.ry

    def planning(self, sx, sy, gx, gy):
        pass

    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)

    def a_star(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nA* calculation started..")
        self.rows.append("A*")
        start_time = time.time()
        a_star = AStarPlanner(self.ox, self.oy, grid_size, robot_radius)
        rx, ry = a_star.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"a_star_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"a_star_path_y", "wb") as f:
            pickle.dump(ry, f)
        pass

    def bidirectional_a_star(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nBidirectional A* calculation started..")
        self.rows.append("Bidirectional A*")
        start_time = time.time()
        bidir_a_star = BidirectionalAStarPlanner(self.ox, self.oy, grid_size, robot_radius)
        rx, ry = bidir_a_star.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"bid_a_star_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"bid_a_star_path_y", "wb") as f:
            pickle.dump(ry, f)
    
    def dijkstra(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nDijkstra calculation started")
        self.rows.append("Dijkstra")
        start_time = time.time()
        dijkstra = Dijkstra(self.ox, self.oy, grid_size, robot_radius)
        rx, ry = dijkstra.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"dijkstra_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"dijkstra_path_y", "wb") as f:
            pickle.dump(ry, f)
        
    def d_star(self, sx, sy, gx, gy, grid_size, size_x, size_y, robot_radius, binary_path):
        print("\nD* calculation started")
        self.rows.append("D*")
        m = Map(size_x, size_y)
        m.set_obstacle([(i, j) for i, j in zip(self.ox, self.oy)])
        start = [int(sx), int(sy)]
        goal = [int(gx), int(gy)]
        start = m.map[start[0]][start[1]]
        end = m.map[goal[0]][goal[1]]
        start_time = time.time()
        dstar = Dstar(m)
        rx, ry = dstar.run(start, end)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])

        with open(binary_path/"d_star_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"d_star_path_y", "wb") as f:
            pickle.dump(ry, f)

    def d_star_lite(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nD* lite calculation started")
        self.rows.append("D* Lite")
        spoofed_ox = [[], [], [], []]
        spoofed_oy = [[], [], [], []]
        start_time = time.time()
        dstarlite = DStarLite(self.ox, self.oy)
        dstarlite.main(Node(x=int(sx), y=int(sy)), Node(x=int(gx), y=int(gy)),
                spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
        rx, ry = dstarlite.get_path()
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])

        with open(binary_path/"d_star_lite_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"d_star_lite_path_y", "wb") as f:
                pickle.dump(ry, f)
        
    def breadth_first_search(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nBFS calculation started")
        self.rows.append("BFS")
        start_time = time.time()
        bfs = BreadthFirstSearchPlanner(self.ox, self.oy, grid_size, robot_radius)
        rx, ry = bfs.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"bfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"bfs_path_y", "wb") as f:
            pickle.dump(ry, f)
    
    def bidirectional_breadth_first_search(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nbidirectional BFS calculation started")
        self.rows.append("Bidirectional BFS")
        start_time = time.time()
        bi_bfs = BidirectionalBreadthFirstSearchPlanner(
        self.ox, self.oy, grid_size, robot_radius)
        rx, ry = bi_bfs.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"bid_bfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"bid_bfs_path_y", "wb") as f:
            pickle.dump(ry, f)

    def depth_first_search(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nDFS calculation started")
        self.rows.append("DFS")
        start_time = time.time()
        dfs = DepthFirstSearchPlanner(self.ox, self.oy, grid_size, robot_radius)
        rx, ry = dfs.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"dfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"dfs_path_y", "wb") as f:
            pickle.dump(ry, f)
    
    def greedy_best_first_search(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nGreedy Best First Search calculation started")
        self.rows.append("Greedy Best First Search")
        start_time = time.time()
        greedy_best_first_search = BestFirstSearchPlanner(self.ox, self.oy, grid_size, robot_radius)
        rx, ry = greedy_best_first_search.planning(sx, sy, gx, gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])
        with open(binary_path/"gbfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"gbfs_path_y", "wb") as f:
            pickle.dump(ry, f)
    
    
    
    

def main():
    print(__file__ + " start!!")

    # start and goal position

    ox, oy = [], []
    size_x = 0
    size_y = 0

    root = Path(".")

    binary_path = root / "binary_dump"
    images = root / "images"
    results = root / "results"

    with open(binary_path/"ox", "rb") as f:
        ox = pickle.load(f)
    with open(binary_path/"oy", "rb") as f:
        oy = pickle.load(f)
    
    with open(binary_path/"dim_x", "rb") as f:
        size_x = pickle.load(f)
    with open(binary_path/"dim_y", "rb") as f:
        size_y = pickle.load(f)
   
    
    with open("config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithm = config["test_algorithm"]
        grid_size = config["grid_size"]
        robot_radius = config["robot_radius"]
        table_name = config["table_name"]
        thread_enable = config["thread_enable"]
        costume_start_goal = config["costume_start_goal"]

    if costume_start_goal:
        with open(binary_path/"sx", "rb") as f:
            sx = pickle.load(f)
        with open(binary_path/"sy", "rb") as f:
            sy = pickle.load(f)
        with open(binary_path/"gx", "rb") as f:
            gx = pickle.load(f)
        with open(binary_path/"gy", "rb") as f:
            gy = pickle.load(f)
    
    else:
        sx = size_x * 0.2  # [m]
        sy = size_y * 0.8 # [m]
        gx = size_x * 0.45   # [m]
        gy = size_y * 0.3  # [m]

    rows = []
    columns = ['Time [s]', 'Distance [m]']
    values = []
    
    algorithm = Algorithms(ox, oy)

    threads = []    

    for test_algorithm in test_algorithm:
        if test_algorithm == "a_star":
            if thread_enable:
                thread1 = threading.Thread(target = algorithm.a_star, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread1)
            else:
                algorithm.a_star(sx, sy, gx, gy, grid_size, robot_radius, binary_path)

        if test_algorithm == "bidirectional_a_star":
            if thread_enable:
                thread2 = threading.Thread(target = algorithm.bidirectional_a_star, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread2)
            else:
                algorithm.bidirectional_a_star(sx, sy, gx, gy, grid_size, robot_radius, binary_path)
            

        if test_algorithm == "dijkstra":
            if thread_enable:
                thread3 = threading.Thread(target = algorithm.dijkstra, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread3)
            else:
                algorithm.dijkstra(sx, sy, gx, gy, grid_size, robot_radius, binary_path)
        
        if test_algorithm == "d_star":
            if thread_enable:
                thread4 = threading.Thread(target = algorithm.d_star, args=(sx, sy, gx, gy, grid_size, size_x, size_y, robot_radius, binary_path))
                threads.append(thread4)
            else:
                algorithm.d_star(sx, sy, gx, gy, grid_size, size_x, size_y, robot_radius, binary_path)

        if test_algorithm == "d_star_lite":
            if thread_enable:
                thread5 = threading.Thread(target = algorithm.d_star_lite, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread5)
            else:
                algorithm.d_star_lite(sx, sy, gx, gy, grid_size, robot_radius, binary_path)
        
        if test_algorithm == "breadth_first_search":
            if thread_enable:
                thread6 = threading.Thread(target = algorithm.breadth_first_search, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread6)
            else:
                algorithm.breadth_first_search(sx, sy, gx, gy, grid_size, robot_radius, binary_path)

        if test_algorithm == "bidirectional_breadth_first_search":
            if thread_enable:
                thread7 = threading.Thread(target = algorithm.bidirectional_breadth_first_search, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread7)
            else:
                algorithm.bidirectional_breadth_first_search(sx, sy, gx, gy, grid_size, robot_radius, binary_path)

        if test_algorithm == "depth_first_search":
            if thread_enable:
                thread8 = threading.Thread(target = algorithm.depth_first_search, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread8)
            else:
                algorithm.depth_first_search(sx, sy, gx, gy, grid_size, robot_radius, binary_path)
        
        if test_algorithm == "greedy_best_first_search":
            if thread_enable:
                thread9 = threading.Thread(target = algorithm.greedy_best_first_search, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                threads.append(thread9)
            else:
                algorithm.greedy_best_first_search(sx, sy, gx, gy, grid_size, robot_radius, binary_path)
    
    

    print("Path generated")

    if thread_enable:
        for thread in threads:
            thread.setDaemon(True)
            thread.start()
    
        for thread in threads:
            thread.join()
    else:
        fig, ax = plt.subplots()

        # hide axes
        fig.patch.set_visible(False)
        ax.axis('off')
        ax.axis('tight')
        ax.table(cellText=algorithm.values, colLabels=algorithm.columns, rowLabels=algorithm.rows, loc='center', cellLoc='center', colLoc='center')
        fig.tight_layout()
        plt.savefig(results/table_name)
        plt.show()
    
    exit(0)
    
    

if __name__ == '__main__':
    main()
