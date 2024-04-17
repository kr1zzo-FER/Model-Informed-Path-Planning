"""

Program for path planning algorithms testing

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
from algorithms.d_star_lite_advanced import DStarLiteAdvanced
from algorithms.d_star_lite import Node
from algorithms.dijkstra import Dijkstra
from algorithms.bidirectional_a_star import BidirectionalAStarPlanner
from algorithms.breadth_first_search import BreadthFirstSearchPlanner
from algorithms.bidirectional_breadth_first_search import BidirectionalBreadthFirstSearchPlanner
from algorithms.depth_first_search import DepthFirstSearchPlanner
from algorithms.greedy_best_first_search import BestFirstSearchPlanner
import sys
from algorithm_class import Algorithms 

root = Path(__file__).resolve().parents[1]

show_animation = False
    

def test():
    print(__file__ + " start!!")

    # start and goal position

    ox, oy = [], []
    redx, redy = [], []
    yellowx, yellowy = [], []
    greenx, greeny = [], []
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
    
    
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithm = config["test_algorithm"]
        grid_size = config["grid_size"]
        robot_radius = config["robot_radius"]
        thread_enable = config["thread_enable"]
        red_cost = config["red_cost"]
        yellow_cost = config["yellow_cost"]
        green_cost = config["green_cost"]
        cost_map = config["cost_map"]


    with open(binary_path/"sx", "rb") as f:
        sx = pickle.load(f)
    with open(binary_path/"sy", "rb") as f:
        sy = pickle.load(f)
    with open(binary_path/"gx", "rb") as f:
        gx = pickle.load(f)
    with open(binary_path/"gy", "rb") as f:
        gy = pickle.load(f)
    with open(binary_path/"red_zone", "rb") as f:
        red_zone = pickle.load(f)
        for point in red_zone:
            redx.append(point[0])
            redy.append(point[1])
    with open(binary_path/"yellow_zone", "rb") as f:
        yellow_zone = pickle.load(f)
        for point in yellow_zone:
            yellowx.append(point[0])
            yellowy.append(point[1])
    with open(binary_path/"green_zone", "rb") as f:
        green_zone = pickle.load(f)
        for point in green_zone:
            greenx.append(point[0])
            greeny.append(point[1])
    
    print(f"Start position: {sx}, {sy}")
    print(f"Goal position: {gx}, {gy}")
    print(f"Grid size: {grid_size}")
    print(f"Robot radius: {robot_radius}")
   

    rows = []
    columns = ['Time [s]', 'Distance [m]']
    values = []
    
    algorithm = Algorithms(ox, oy, redx, redy, yellowx, yellowy, greenx, greeny)     

    threads = []    

    if not cost_map:
        print(f"Test algorithms: {test_algorithm}")
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
            
            if test_algorithm == "greedy_best_first_search":
                if thread_enable:
                    thread9 = threading.Thread(target = algorithm.greedy_best_first_search, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path))
                    threads.append(thread9)
                else:
                    algorithm.greedy_best_first_search(sx, sy, gx, gy, grid_size, robot_radius, binary_path)
    
    else:
        print("Cost map enabled : Generating path with D* Lite Advanced algorithm   ")
        if thread_enable:
                    thread5 = threading.Thread(target = algorithm.d_star_lite_advanced, args=(sx, sy, gx, gy, grid_size, robot_radius, binary_path, red_cost, yellow_cost, green_cost))
                    threads.append(thread5)
        else:
            algorithm.d_star_lite_advanced(sx, sy, gx, gy, grid_size, robot_radius, binary_path, red_cost, yellow_cost, green_cost)

    print("Path generated")

    values = algorithm.values
    rows = algorithm.rows

    if thread_enable:
        for thread in threads:
            thread.setDaemon(True)
            thread.start()
    
        for thread in threads:
            thread.join()
        
    for row, value in zip(algorithm.rows, values):
        with open(binary_path/f"{row}_results", "wb") as f:
            pickle.dump(values, f)
    
        

if __name__ == '__main__':
    try:
        test()
    except KeyboardInterrupt:
        sys.exit(0)
