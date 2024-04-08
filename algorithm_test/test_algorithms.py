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
from algorithms.dstar import Dstar, Map, State
from algorithms.d_star_lite import DStarLite
from algorithms.d_star_lite import Node
from algorithms.dijkstra import Dijkstra
from algorithms.bidirectional_a_star import BidirectionalAStarPlanner
from algorithms.breadth_first_search import BreadthFirstSearchPlanner
from algorithms.bidirectional_breadth_first_search import BidirectionalBreadthFirstSearchPlanner
from algorithms.depth_first_search import DepthFirstSearchPlanner
from algorithms.greedy_best_first_search import BestFirstSearchPlanner
from plot_table import main as plot_table

root = Path(__file__).resolve().parents[1]

show_animation = False

    
class Algorithms:
    def __init__(self, ox, oy, sx, sy, gx, gy, grid_size, robot_radius, binary_path, size_x, size_y):
        self.ox = ox
        self.oy = oy
        self.sx = sx
        self.sy = sy
        self.gx = gx
        self.gy = gy
        self.grid_size = grid_size
        self.robot_radius = robot_radius
        self.binary_path = binary_path
        self.size_x = size_x
        self.size_y = size_y

    def start_print(self, test_algorithm, thread_enable):
        print(f"\nStart position for calculation: {self.sx}, y: {self.sy}\n")
        print(f"Goal position for calculation: {self.gx}, y: {self.gy}\n")
        print(f"Grid size: {self.grid_size}\n")
        print(f"Robot radius: {self.robot_radius}\n")
        print(f"Test algorithms: {test_algorithm}\n")
        print(f"Thread enable: {thread_enable}\n")
        print(f"Coastline points: {len(self.ox)}\n")

    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)

    def a_star(self):
        print("\nA* calculation started..")
        start_time = time.time()
        a_star = AStarPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = a_star.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print(f"Function time: {function_time}, distance: {distance}")
        with open(self.binary_path/"a_star_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"a_star_path_y", "wb") as f:
            pickle.dump(ry, f)
        pass
        with open(self.binary_path/"time_distance_astar", "wb") as f:
            pickle.dump([function_time, distance], f)

    def bidirectional_a_star(self):
        print("\nBidirectional A* calculation started..")
        start_time = time.time()
        bidir_a_star = BidirectionalAStarPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bidir_a_star.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"bid_a_star_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"bid_a_star_path_y", "wb") as f:
            pickle.dump(ry, f)
        
        with open(self.binary_path/"time_distance_bidir_astar", "wb") as f:
            pickle.dump([function_time, distance], f)
    
    def dijkstra(self):
        print("\nDijkstra calculation started")
        start_time = time.time()
        dijkstra = Dijkstra(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = dijkstra.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"dijkstra_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"dijkstra_path_y", "wb") as f:
            pickle.dump(ry, f)
        
        with open(self.binary_path/"time_distance_dijkstra", "wb") as f:
            pickle.dump([function_time, distance], f)
        
        
    def d_star(self):
        print("\nD* calculation started")
        m = Map(round(self.size_x/self.grid_size), round(self.size_y/self.grid_size))
        ox_ = [round(ox/self.grid_size) for ox in self.ox]
        oy_ = [round(oy/self.grid_size) for oy in self.oy]
        self.sx = round(self.sx/self.grid_size)
        self.sy = round(self.sy/self.grid_size)
        self.sx = round(self.sx/self.grid_size)
        self.gy = round(self.gy/self.grid_size)
        print(self.sx, self.sy, self.sx, self.gy)
        m.set_obstacle([(i, j) for i, j in zip(ox_, oy_)])
        start = [int(self.sx), int(self.sy)]
        goal = [int(self.sx), int(self.gy)]
        print(start[1], goal)
        start_ = m.map[start[0]][start[1]]
        end_ = m.map[goal[0]][goal[1]]
        start_time = time.time()
        dstar = Dstar(m)
        rx, ry = dstar.run(start_, end_)
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"d_star_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"d_star_path_y", "wb") as f:
            pickle.dump(ry, f)
        

    def d_star_lite(self):
        print("\nD* lite calculation started")
        spoofed_ox = [[], [], [], []]
        spoofed_oy = [[], [], [], []]
        ox_ = [round(ox/self.grid_size) for ox in self.ox]
        oy_ = [round(oy/self.grid_size) for oy in self.oy]
        start_time = time.time()
        dstarlite = DStarLite(ox_, oy_)
        self.sx = round(self.sx/self.grid_size)
        self.sy = round(self.sy/self.grid_size)
        self.sx = round(self.sx/self.grid_size)
        self.gy = round(self.gy/self.grid_size)
        dstarlite.main(Node(x=int(self.sx), y=int(self.sy)), Node(x=int(self.sx), y=int(self.gy)),
                spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)

        with open(self.binary_path/"d_star_lite_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"d_star_lite_path_y", "wb") as f:
                pickle.dump(ry, f)
        
        with open(self.binary_path/"time_distance_dstar_lite", "wb") as f:
            pickle.dump([function_time, distance], f)
        
        
    def breadth_first_search(self):
        print("\nBFS calculation started")
        start_time = time.time()
        bfs = BreadthFirstSearchPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bfs.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"bfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"bfs_path_y", "wb") as f:
            pickle.dump(ry, f)

        with open(self.binary_path/"time_distance_bfs", "wb") as f:
            pickle.dump([function_time, distance], f)
    
    def bidirectional_breadth_first_search(self):
        print("\nbidirectional BFS calculation started")
        start_time = time.time()
        bi_bfs = BidirectionalBreadthFirstSearchPlanner(
        self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bi_bfs.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"bid_bfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"bid_bfs_path_y", "wb") as f:
            pickle.dump(ry, f)
        
        with open(self.binary_path/"time_distance_bidir_bfs", "wb") as f:
            pickle.dump([function_time, distance], f)

    def depth_first_search(self):
        print("\nDFS calculation started")
        start_time = time.time()
        dfs = DepthFirstSearchPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = dfs.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"dfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"dfs_path_y", "wb") as f:
            pickle.dump(ry, f)
        
        with open(self.binary_path/"time_distance_dfs", "wb") as f:
            pickle.dump([function_time, distance], f)
    
    def greedy_best_first_search(self):
        print("\nGreedy Best First Search calculation started")
        start_time = time.time()
        greedy_best_first_search = BestFirstSearchPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = greedy_best_first_search.planning(self.sx, self.sy, self.sx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        with open(self.binary_path/"gbfs_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(self.binary_path/"gbfs_path_y", "wb") as f:
            pickle.dump(ry, f)
        with open(self.binary_path/"time_distance_gbfs", "wb") as f:
            pickle.dump([function_time, distance], f)
    
    
    
    

def main():
    print(__file__ + " start!!")

    # start and goal position

    ox, oy = [], []
    size_x = 0
    size_y = 0

    global root
    binary_path = root / "binary_dump"
    results = root / "results"

    with open(binary_path/"coast_points", "rb") as f:
        coast_points = pickle.load(f)
        for point in coast_points:
            ox.append(point[0])
            oy.append(point[1])
    
    with open(binary_path/"dimensions", "rb") as f:
        dimensions = pickle.load(f)
        size_x = dimensions[0]
        size_y = dimensions[1]
        print(size_x, size_y)

    
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithm = config["test_algorithm"]
        grid_size = config["grid_size"]
        robot_radius = config["robot_radius"]
        thread_enable = config["thread_enable"]
        image = config["resized_location_image"]
    
    image = Image.open(results/image)

    with open(binary_path/"sx", "rb") as f:
        sx = pickle.load(f)
    with open(binary_path/"sy", "rb") as f:
        sy = pickle.load(f)
    with open(binary_path/"gx", "rb") as f:        
        gx = pickle.load(f)
    with open(binary_path/"gy", "rb") as f:
        gy = pickle.load(f)
    
    algorithm = Algorithms(ox, oy, sx, sy, gx, gy, grid_size, robot_radius, binary_path, size_x, size_y)
    algorithm.start_print(test_algorithm, thread_enable)

    threads = []    

    for test_algorithm in test_algorithm:
        if test_algorithm == "a_star":
            if thread_enable:
                thread1 = threading.Thread(target = algorithm.a_star)
                threads.append(thread1)
            else:
                algorithm.a_star()

        if test_algorithm == "bidirectional_a_star":
            if thread_enable:
                thread2 = threading.Thread(target = algorithm.bidirectional_a_star)
            else:
                algorithm.bidirectional_a_star()
            

        if test_algorithm == "dijkstra":
            if thread_enable:
                thread3 = threading.Thread(target = algorithm.dijkstra)
                threads.append(thread3)
            else:
                algorithm.dijkstra()
        
        if test_algorithm == "d_star":
            if thread_enable:
                print
                thread4 = threading.Thread(target = algorithm.d_star)
                threads.append(thread4)
            else:
                algorithm.d_star()

        if test_algorithm == "d_star_lite":
            if thread_enable:
                thread5 = threading.Thread(target = algorithm.d_star_lite)
                threads.append(thread5)
            else:
                algorithm.d_star_lite()
        
        if test_algorithm == "breadth_first_search":
            if thread_enable:
                thread6 = threading.Thread(target = algorithm.breadth_first_search)
                threads.append(thread6)
            else:
                algorithm.breadth_first_search()

        if test_algorithm == "bidirectional_breadth_first_search":
            if thread_enable:
                thread7 = threading.Thread(target = algorithm.bidirectional_breadth_first_search)
                threads.append(thread7)
            else:
                algorithm.bidirectional_breadth_first_search()

        if test_algorithm == "depth_first_search":
            if thread_enable:
                thread8 = threading.Thread(target = algorithm.depth_first_search)
                threads.append(thread8)
            else:
                algorithm.depth_first_search()
        
        if test_algorithm == "greedy_best_first_search":
            if thread_enable:
                thread9 = threading.Thread(target = algorithm.greedy_best_first_search)
                threads.append(thread9)
            else:
                algorithm.greedy_best_first_search()
    
    

    print("Path generated")

    if thread_enable:
        for thread in threads:
            thread.setDaemon(True)
            thread.start()
    
        for thread in threads:
            thread.join()
    

    
    

if __name__ == '__main__':
    main()
