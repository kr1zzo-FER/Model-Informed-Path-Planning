import math

import matplotlib.pyplot as plt
import yaml

from sys import maxsize
from skimage import io, measure
from PIL import Image
import pickle
import os 
from pathlib import Path

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

    

def main():
    print(__file__ + " start!!")

    # start and goal position

    ox, oy = [], []
    size_x = 0
    size_y = 0

    root = Path(".")

    binary_path = root / "binary_dump"
    images = root / "images"

    with open(binary_path/"ox", "rb") as f:
        ox = pickle.load(f)
    with open(binary_path/"oy", "rb") as f:
        oy = pickle.load(f)
    
    with open(binary_path/"dim_x", "rb") as f:
        size_x = pickle.load(f)
    with open(binary_path/"dim_y", "rb") as f:
        size_y = pickle.load(f)
    
    sx = size_x * 0.2  # [m]
    sy = size_y * 0.8 # [m]
    gx = size_x * 0.45   # [m]
    gy = size_y * 0.3  # [m]
    
    with open("config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithm = config["test_algorithm"]
        grid_size = config["grid_size"]
        robot_radius = config["robot_radius"]


    for test_algorithm in test_algorithm:
        if test_algorithm == "a_star":
            print("\nA* calculation started..")
            a_star = AStarPlanner(ox, oy, grid_size, robot_radius)
            rx, ry = a_star.planning(sx, sy, gx, gy)
            with open(binary_path/"a_star_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"a_star_path_y", "wb") as f:
                pickle.dump(ry, f)
        
        if test_algorithm == "bidirectional_a_star":
            print("\nBidirectional A* calculation started..")
            bidir_a_star = BidirectionalAStarPlanner(ox, oy, grid_size, robot_radius)
            rx, ry = bidir_a_star.planning(sx, sy, gx, gy)
            with open(binary_path/"bid_a_star_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"bid_a_star_path_y", "wb") as f:
                pickle.dump(ry, f)

        elif test_algorithm == "dijkstra":
            print("\nDijkstra calculation started")
            dijkstra = Dijkstra(ox, oy, grid_size, robot_radius)
            rx, ry = dijkstra.planning(sx, sy, gx, gy)
            with open(binary_path/"dijkstra_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"dijkstra_path_y", "wb") as f:
                pickle.dump(ry, f)
        
        elif test_algorithm == "d_star":
            print("\nD* calculation started")
            m = Map(size_x, size_y)
            m.set_obstacle([(i, j) for i, j in zip(ox, oy)])
            start = [int(sx), int(sy)]
            goal = [int(gx), int(gy)]
            start = m.map[start[0]][start[1]]
            end = m.map[goal[0]][goal[1]]
            dstar = Dstar(m)
            rx, ry = dstar.run(start, end)

            with open(binary_path/"d_star_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"d_star_path_y", "wb") as f:
                pickle.dump(ry, f)

        elif test_algorithm == "d_star_lite":
            print("\nD* lite calculation started")
            spoofed_ox = [[], [], [], []]
            spoofed_oy = [[], [], [], []]
            dstarlite = DStarLite(ox, oy)
            rx, ry = dstarlite.get_path()
            dstarlite.main(Node(x=int(sx), y=int(sy)), Node(x=int(gx), y=int(gy)),
                    spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
            
            for rx_i, ry_i in zip(rx, ry):
                print(rx_i, ry_i)

            with open(binary_path/"d_star_lite_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"d_star_lite_path_y", "wb") as f:
                pickle.dump(ry, f)
        
        elif test_algorithm == "breadth_first_search":
            print("\nBFS calculation started")
            bfs = BreadthFirstSearchPlanner(ox, oy, grid_size, robot_radius)
            rx, ry = bfs.planning(sx, sy, gx, gy)
            with open(binary_path/"bfs_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"bfs_path_y", "wb") as f:
                pickle.dump(ry, f)
        
        elif test_algorithm == "bidirectional_breadth_first_search":
            print("\nbidirectional BFS calculation started")
            bi_bfs = BidirectionalBreadthFirstSearchPlanner(
            ox, oy, grid_size, robot_radius)
            rx, ry = bi_bfs.planning(sx, sy, gx, gy)
            with open(binary_path/"bid_bfs_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"bid_bfs_path_y", "wb") as f:
                pickle.dump(ry, f)

        elif test_algorithm == "depth_first_search":
            dfs = DepthFirstSearchPlanner(ox, oy, grid_size, robot_radius)
            rx, ry = dfs.planning(sx, sy, gx, gy)
            with open(binary_path/"dfs_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"dfs_path_y", "wb") as f:
                pickle.dump(ry, f)
        
        elif test_algorithm == "greedy_best_first_search":
            greedy_best_first_search = BestFirstSearchPlanner(ox, oy, grid_size, robot_radius)
            rx, ry = greedy_best_first_search.planning(sx, sy, gx, gy)
            with open(binary_path/"greedy_best_first_search_path_x", "wb") as f:
                pickle.dump(rx, f)
            with open(binary_path/"greedy_best_first_search_path_y", "wb") as f:
                pickle.dump(ry, f)
    
    print("Path generated")


if __name__ == '__main__':
    main()
