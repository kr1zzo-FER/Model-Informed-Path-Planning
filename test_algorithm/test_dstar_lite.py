


"""

Program for path planning algorithms testing

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math

import matplotlib.pyplot as plt
import yaml
import sys
from sys import maxsize
from skimage import io, measure
from PIL import Image
import pickle
import os 
from pathlib import Path
import time
import threading
from plot import deg_to_dms
from algorithm_class import Algorithms 
root = Path(__file__).resolve().parents[1]

def test_dstar():
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
        table_name = config["table_name"]
        thread_enable = config["thread_enable"]


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
    print(f"Test algorithms: {test_algorithm}")

    algorithm = Algorithms(ox, oy, redx, redy, yellowx, yellowy, greenx, greeny)



    algorithm.d_star_lite_advanced(sx, sy, gx, gy, grid_size, robot_radius, binary_path)

if __name__ == '__main__':
    try:
        test_dstar()
    except KeyboardInterrupt:
        sys.exit(0)

    