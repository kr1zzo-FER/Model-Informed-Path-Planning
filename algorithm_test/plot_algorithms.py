
"""

Path planning algorithms plotter

author: Enio Krizman (@kr1zzo)

"""
import math
import pickle
import matplotlib.pyplot as plt
from PIL import Image
from matplotlib.lines import Line2D
from matplotlib.patches import Patch
import matplotlib.ticker as mticker

import matplotlib.colors as mcolors
from pathlib import Path
import yaml
import numpy as np

show_animation = True
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

def main():

    root = Path(".")

    binary_path = root / "binary_dump"
    images = root / "images"
    results = root / "results"

    with open("config.yaml", "r") as f:
        config = yaml.safe_load(f)
        plot_algorithm = config["plot_algorithms"]
        image_name = config["image_save"]
        result_image_name = config["result_image_name"]
        costume_start_goal = config["costume_start_goal"]
    

    with open(binary_path/"ox", "rb") as f:
        ox = pickle.load(f)
    with open(binary_path/"oy", "rb") as f:
        oy = pickle.load(f)
    with open(binary_path/"coordinates", "rb") as f:
        coordinates = pickle.load(f)
    with open(binary_path/"dim_x", "rb") as f:
        size_x = pickle.load(f)
    with open(binary_path/"dim_y", "rb") as f:
        size_y = pickle.load(f)
    

    
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

    im = plt.imread(images/image_name)
    fig, ax = plt.subplots()
    # new axis with the same size as the image
    im = ax.imshow(im, extent=[0, size_x, 0, size_y])

    coordinates = [round(float(coordinates[0]),6), round(float(coordinates[1]),6), round(float(coordinates[2]),6), round(float(coordinates[3]),6)]
    #print(coordinates[0])
    coordinates_plot_x = np.arange(coordinates[0], coordinates[2],0.005)
    coordinates_plot_x = np.append(coordinates_plot_x, coordinates[2])
    coordinates_plot_x = [deg_to_dms(i) for i in coordinates_plot_x]
    coordinates_plot_y = np.arange(coordinates[1], coordinates[3],0.005)
    coordinates_plot_y = np.append(coordinates_plot_y, coordinates[3])
    coordinates_plot_y = [deg_to_dms(i) for i in coordinates_plot_y]
    

    image_cordinates_x = np.arange(0, round(size_x), round(size_x/(len(coordinates_plot_x)-1)))
    image_cordinates_x = np.append(image_cordinates_x, size_x)
    image_cordinates_y = np.arange(0, round(size_y), round(size_y/(len(coordinates_plot_y)-1)))
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
    plt.plot(sx, sy, "og")
    plt.plot(gx, gy, "xb")

    legend_elements.append(Line2D([0], [0], marker='o', color='g', label=f'Start : ({sx_longitude}, {sy_latitude})'))
    legend_elements.append(Line2D([0], [0], marker='x', color='b', label=f'Goal : ({gx_longitude}, {gy_latitude})'))
    plt.grid(True)


    
    for algorithm in plot_algorithm:
        if algorithm == "a_star":
            rx_astar = []
            ry_astar = []
            with open(binary_path/"a_star_path_x", "rb") as f:
                rx_astar = pickle.load(f)
            with open(binary_path/"a_star_path_y", "rb") as f:
                ry_astar = pickle.load(f)
            plt.plot(rx_astar, ry_astar, "red")
            legend_elements.append(Line2D([0], [0], color='red', lw=4, label='A*'))
    
        if algorithm == "bidirectional_a_star":
            rx_bidir_astar = []
            ry_bidir_astar = []
            with open(binary_path/"bid_a_star_path_x", "rb") as f:
                rx_bidir_astar = pickle.load(f)
            with open(binary_path/"bid_a_star_path_y", "rb") as f:
                ry_bidir_astar = pickle.load(f)
            plt.plot(rx_bidir_astar, ry_bidir_astar, "crimson")
            legend_elements.append(Line2D([0], [0], color='crimson', lw=4, label='Bidirectional A*'))
        
        if algorithm == "dijkstra":
            rx_dijkstra = []
            ry_dijkstra = []
            with open(binary_path/"dijkstra_path_x", "rb") as f:
                rx_dijkstra = pickle.load(f)
            with open(binary_path/"dijkstra_path_y", "rb") as f:
                ry_dijkstra = pickle.load(f)
            plt.plot(rx_dijkstra, ry_dijkstra, "lime")
            legend_elements.append(Line2D([0], [0], color='lime', lw=4, label='Dijkstra'))
        
        if algorithm == "d_star":
            rx_dstar = []
            ry_dstar = []
            with open(binary_path/"d_star_path_x", "rb") as f:
                rx_dstar = pickle.load(f)
            with open(binary_path/"d_star_path_y", "rb") as f:
                ry_dstar = pickle.load(f)
            plt.plot(rx_dstar, ry_dstar, "cyan")
            legend_elements.append(Line2D([0], [0], color='cyan', lw=4, label='D*'))
        
        if algorithm == "d_star_lite":
            rx_dstar_lite = []
            ry_dstar_lite = []
            with open(binary_path/"d_star_lite_path_x", "rb") as f:
                rx_dstar_lite = pickle.load(f)
            with open(binary_path/"d_star_lite_path_y", "rb") as f:
                ry_dstar_lite = pickle.load(f)
            plt.plot(rx_dstar_lite, ry_dstar_lite, "blue")
            legend_elements.append(Line2D([0], [0], color='blue', lw=4, label='D* Lite'))
        
 
        if algorithm == "breadth_first_search":
            rx_bfs = []
            ry_bfs = []
            with open(binary_path/"bfs_path_x", "rb") as f:
                rx_bfs = pickle.load(f)
            with open(binary_path/"bfs_path_y", "rb") as f:
                ry_bfs = pickle.load(f)
            plt.plot(rx_bfs, ry_bfs, "gold")
            legend_elements.append(Line2D([0], [0], color='gold', lw=4, label='BFS'))

        if algorithm == "bidirectional_breadth_first_search":
            rx_bidir_bfs = []
            ry_bidir_bfs = []
            with open(binary_path/"bid_bfs_path_x", "rb") as f:
                rx_bidir_bfs = pickle.load(f)
            with open(binary_path/"bid_bfs_path_y", "rb") as f:
                ry_bidir_bfs = pickle.load(f)
            plt.plot(rx_bidir_bfs, ry_bidir_bfs, "yellow")
            legend_elements.append(Line2D([0], [0], color='yellow', lw=4, label='Bidirectional BFS'))
        
        
        
        if algorithm == "depth_first_search":
            rx_dfs = []
            ry_dfs = []
            with open(binary_path/"dfs_path_x", "rb") as f:
                rx_dfs = pickle.load(f)
            with open(binary_path/"dfs_path_y", "rb") as f:
                ry_dfs = pickle.load(f)
            plt.plot(rx_dfs, ry_dfs, "purple")
            legend_elements.append(Line2D([0], [0], color='purple', lw=4, label='DFS'))

        if algorithm == "greedy_best_first_search":
            rx_gbfs = []
            ry_gbfs = []
            with open(binary_path/"gbfs_path_x", "rb") as f:
                rx_gbfs = pickle.load(f)
            with open(binary_path/"gbfs_path_y", "rb") as f:
                ry_gbfs = pickle.load(f)
            plt.plot(rx_gbfs, ry_gbfs, "orange")
            legend_elements.append(Line2D([0], [0], color='orange', lw=4, label='GBFS'))

    
    ax.legend(handles=legend_elements, loc='upper right')
    plt.savefig(results/result_image_name)
    plt.show()
    
if __name__ == '__main__':
    main()