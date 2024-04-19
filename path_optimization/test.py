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
import sys
import numpy as np
from matplotlib.lines import Line2D
from algorithms.d_star_lite_advanced import DStarLiteAdvanced

root = Path(__file__).resolve().parents[1]

sys.path.append(str(root))

import osm_data_processing.main as cost_map_main


legend_elements = []
ox, oy = [], []
size_x = 0
size_y = 0

def deg_to_dms(deg):
    #print(deg)
    d = int(deg)
    md = abs(deg - d) * 60
    m = int(md)
    sd = round((md - m) * 60)
    format_string = f"{d}°{m}'{sd}\""
    #print(format_string)
    return format_string

def euclidean_distance(x1,y1,x2,y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)

def plot():

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
        table_name = config["table_name"]
        image_name = config["resized_location_image"]
        result_image = config["result_image"]
        plot_algorithms = config["plot_algorithms"]
        cost_map = config["cost_map"]
        cost_map_show = config["cost_map_show"]
        red_cost = config["red_cost"]
        yellow_cost = config["yellow_cost"]
        green_cost = config["green_cost"]
    

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

    with open(binary_path/"coordinates", "rb") as f:
        coordinates = pickle.load(f)

    image = Image.open(root/"results"/image_name)
    
    fig, ax = plt.subplots()

    im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])

    
    size_x = image.size[0]
    size_y = image.size[1]

    coordinates = [round(float(coordinates[0]),6), round(float(coordinates[1]),6), round(float(coordinates[2]),6), round(float(coordinates[3]),6)]
    #print(coordinates[0])
    coordinates_plot_x = np.arange(coordinates[0], coordinates[2],0.005)
    coordinates_plot_x = np.append(coordinates_plot_x, coordinates[2])
    coordinates_plot_x = [deg_to_dms(i) for i in coordinates_plot_x]
    coordinates_plot_y = np.arange(coordinates[1], coordinates[3],0.005)
    coordinates_plot_y = np.append(coordinates_plot_y, coordinates[3])
    coordinates_plot_y = [deg_to_dms(i) for i in coordinates_plot_y]
    

    image_cordinates_x = np.arange(0, round(size_x), math.ceil(size_x/(len(coordinates_plot_x)-1)))
    image_cordinates_x = np.append(image_cordinates_x, size_x)
    image_cordinates_y = np.arange(0, round(size_y), math.ceil(size_y/(len(coordinates_plot_y)-1)))
    image_cordinates_y = np.append(image_cordinates_y, size_y)

    plt.xticks(image_cordinates_x, coordinates_plot_x, rotation=90)
    plt.yticks(image_cordinates_y, coordinates_plot_y)

    sx_longitude = round(sx * (coordinates[2] - coordinates[0]) / size_x + coordinates[0], 6)
    sx_longitude = deg_to_dms(sx_longitude)
    sy_latitude = round(sy * (coordinates[3] - coordinates[1]) / size_y + coordinates[1], 6)
    sy_latitude = deg_to_dms(sy_latitude)

    gx_longitude = round(gx * (coordinates[2] - coordinates[0]) / size_x + coordinates[0], 6)
    gx_longitude = deg_to_dms(gx_longitude)
    gy_latitude = round(gy * (coordinates[3] - coordinates[1]) / size_y + coordinates[1], 6)
    gy_latitude = deg_to_dms(gy_latitude)
    
    #plt.plot(ox, oy, ".k")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.plot(sx, sy, "ok")
    plt.plot(gx, gy, "xk")

    legend_elements.append(Line2D([0], [0], marker='o', color='k', label=f'Start : ({sx_longitude}, {sy_latitude})'))
    legend_elements.append(Line2D([0], [0], marker='x', color='k', label=f'Goal : ({gx_longitude}, {gy_latitude})'))
    plt.grid(True)

    rows = []
    columns = ['Time [s]', 'Distance [m]']
    values = []
    
    print("Ploting algorithms : D* Lite Advanced")
    rows.append("D* Lite advanced")
    rx_dstar_lite = []
    ry_dstar_lite = []
    with open(binary_path/"d_star_lite_advanced_path_x", "rb") as f:
        rx_dstar_lite = pickle.load(f)
    with open(binary_path/"d_star_lite_advanced_path_y", "rb") as f:
        ry_dstar_lite = pickle.load(f)
    plt.plot(rx_dstar_lite, ry_dstar_lite, "blue")
    legend_elements.append(Line2D([0], [0], color='blue', lw=4, label=f'D* Lite advanced\n(Red cost: {red_cost}\n Yellow cost: {yellow_cost}\nGreen cost: {green_cost})'))

    if cost_map_show:
        for point in red_zone:
            ax.plot(point[0],point[1],".r", markersize=1)
        for point in yellow_zone:
            ax.plot(point[0],point[1],".y", markersize=1)
        for point in green_zone:
            ax.plot(point[0],point[1],".g", markersize=1)
    try: 
        plt.legend(handles=legend_elements, loc='upper right')
        plt.draw()
        plt.savefig(results/result_image)
        plt.show()
    except:
        pass

def test():
    print(__file__ + " start!!")

    # Generate and show cost map
    cost_map_main.main(True,True,"result_costmap.png")
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

   
    print("Cost map enabled : Generating path with D* Lite Advanced algorithm   ")

   

    print("\nD* lite advanced calculation started")
    rows.append("D* Lite advanced")
    spoofed_ox = [[], [], [], []]
    spoofed_oy = [[], [], [], []]
    ox_ = [round(ox/grid_size) for ox in ox]
    oy_ = [round(oy/grid_size) for oy in oy]
    redx = [round(red/grid_size) for red in redx]
    redy = [round(red/grid_size) for red in redy]
    yellowx = [round(yellow/grid_size) for yellow in yellowx]
    yellowy = [round(yellow/grid_size) for yellow in yellowy]
    greenx = [round(green/grid_size) for green in greenx]
    greeny = [round(green/grid_size) for green in greeny]
    sx = round(sx/grid_size)
    sy = round(sy/grid_size)
    gx = round(gx/grid_size)
    gy = round(gy/grid_size)
    
    start_time = time.time()
    dstarlite = DStarLiteAdvanced(ox_,oy_, redx, redy, yellowx, yellowy, greenx, greeny, red_cost, yellow_cost, green_cost)
    print(f"Start: {sx, sy} Goal: {gx, gy}")
    dstarlite.main(Node(x=sx, y=sy), Node(x=gx, y=gy),
            spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
    print("D* Lite calculation finished")
    rx, ry = dstarlite.get_path()
    rx, ry = [rx[i]*grid_size for i in range(len(rx))], [ry[i]*grid_size for i in range(len(ry))]
    end_time = time.time()
    function_time = round(end_time - start_time, 5)
    distance = round(sum([euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
    values.append([function_time, distance])

    with open(binary_path/"d_star_lite_advanced_path_x", "wb") as f:
        pickle.dump(rx, f)
    with open(binary_path/"d_star_lite_advanced_path_y", "wb") as f:
            pickle.dump(ry, f)
    
print("Path generated")

plot()


        
    
        

if __name__ == '__main__':
    try:
        test()
    except KeyboardInterrupt:
        sys.exit(0)
