
"""

Algorithm class for path planning algorithms

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

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
from plot import deg_to_dms

from algorithms.a_star import AStarPlanner
from algorithms.dstar import Map, State
from algorithms.dstar import Dstar, Map, State
from algorithms.d_star_lite import DStarLite
from algorithms.d_star_lite import Node
from algorithms.d_star_lite_advanced import DStarLiteAdvanced
from algorithms.dijkstra import Dijkstra
from algorithms.bidirectional_a_star import BidirectionalAStarPlanner
from algorithms.breadth_first_search import BreadthFirstSearchPlanner
from algorithms.bidirectional_breadth_first_search import BidirectionalBreadthFirstSearchPlanner
from algorithms.depth_first_search import DepthFirstSearchPlanner
from algorithms.greedy_best_first_search import BestFirstSearchPlanner
root = Path(__file__).resolve().parents[1]

class Algorithms:
    def __init__(self, ox, oy, redx=[], redy=[], yellowx=[], yellowy=[],greenx=[], greeny=[]):
        self.ox = ox
        self.oy = oy
        self.rows = []
        self.columns = ['Time [s]', 'Distance [m]']
        self.values = []
        self.redx = redx
        self.redy = redy
        self.yellowx = yellowx
        self.yellowy = yellowy
        self.greenx = greenx
        self.greeny = greeny

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
        m = Map(round(size_x/grid_size), round(size_y/grid_size))
        ox_ = [round(ox/grid_size) for ox in self.ox]
        oy_ = [round(oy/grid_size) for oy in self.oy]
        sx = round(sx/grid_size)
        sy = round(sy/grid_size)
        gx = round(gx/grid_size)
        gy = round(gy/grid_size)
        m.set_obstacle([(i, j) for i, j in zip(ox_, oy_)])
        start = [int(sx), int(sy)]
        goal = [int(gx), int(gy)]
        start = m.map[start[0]][start[1]]
        end = m.map[goal[0]][goal[1]]
        start_time = time.time()
        dstar = Dstar(m)
        rx, ry = dstar.run(start, end)
        rx, ry = [rx[i]*grid_size for i in range(len(rx))], [ry[i]*grid_size for i in range(len(ry))]
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
        ox_ = [round(ox/grid_size) for ox in self.ox]
        oy_ = [round(oy/grid_size) for oy in self.oy]
        sx = round(sx/grid_size)
        sy = round(sy/grid_size)
        gx = round(gx/grid_size)
        gy = round(gy/grid_size)
        start_time = time.time()
        dstarlite = DStarLite(ox_,oy_)
        print(f"Start: {sx, sy} Goal: {gx, gy}")
        dstarlite.main(Node(x=sx, y=sy), Node(x=gx, y=gy),
                spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
        print("D* Lite calculation finished")
        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*grid_size for i in range(len(rx))], [ry[i]*grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])

        with open(binary_path/"d_star_lite_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"d_star_lite_path_y", "wb") as f:
                pickle.dump(ry, f)
    
    def d_star_lite_advanced(self, sx, sy, gx, gy, grid_size, robot_radius, binary_path):
        print("\nD* lite calculation started")
        self.rows.append("D* Lite advanced")
        spoofed_ox = [[], [], [], []]
        spoofed_oy = [[], [], [], []]
        ox_ = [round(ox/grid_size) for ox in self.ox]
        oy_ = [round(oy/grid_size) for oy in self.oy]
        redx = [round(red/grid_size) for red in self.redx]
        redy = [round(red/grid_size) for red in self.redy]
        yellowx = [round(yellow/grid_size) for yellow in self.yellowx]
        yellowy = [round(yellow/grid_size) for yellow in self.yellowy]
        greenx = [round(green/grid_size) for green in self.greenx]
        greeny = [round(green/grid_size) for green in self.greeny]
        sx = round(sx/grid_size)
        sy = round(sy/grid_size)
        gx = round(gx/grid_size)
        gy = round(gy/grid_size)
        print(f"len redx: {len(redx)}")
        print(f"len redy: {len(redy)}")
        
        start_time = time.time()
        dstarlite = DStarLiteAdvanced(ox_,oy_, redx, redy, yellowx, yellowy, greenx, greeny)
        print(f"Start: {sx, sy} Goal: {gx, gy}")
        dstarlite.main(Node(x=sx, y=sy), Node(x=gx, y=gy),
                spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
        print("D* Lite calculation finished")
        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*grid_size for i in range(len(rx))], [ry[i]*grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        self.values.append([function_time, distance])

        with open(binary_path/"d_star_lite_avdanced_path_x", "wb") as f:
            pickle.dump(rx, f)
        with open(binary_path/"d_star_lite_advanced_path_y", "wb") as f:
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
    