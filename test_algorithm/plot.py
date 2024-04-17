
"""

Program for path planning algorithms plotting

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""
import math
import pickle
import matplotlib
import matplotlib.pyplot as plt
from matplotlib import colors
from matplotlib.colors import LinearSegmentedColormap
from matplotlib import cm
from matplotlib import animation
from PIL import Image
from typing import Tuple
from matplotlib.lines import Line2D
from matplotlib.patches import Patch
import matplotlib.ticker as mticker
import math
import matplotlib.colors as mcolors
from pathlib import Path
import yaml
import numpy as np
import sys

root = Path(__file__).resolve().parents[1]
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
    
    if not cost_map:
        print(f"Ploting algorithms : {plot_algorithms}")
        for algorithm in plot_algorithms:
            if algorithm == "a_star":
                rows.append("A*")
                rx_astar = []
                ry_astar = []
                with open(binary_path/"a_star_path_x", "rb") as f:
                    rx_astar = pickle.load(f)
                with open(binary_path/"a_star_path_y", "rb") as f:
                    ry_astar = pickle.load(f)
                plt.plot(rx_astar, ry_astar, "red")
                legend_elements.append(Line2D([0], [0], color='red', lw=4, label='A*'))
        
            if algorithm == "bidirectional_a_star":
                rows.append("Bidirectional A*")
                rx_bidir_astar = []
                ry_bidir_astar = []
                with open(binary_path/"bid_a_star_path_x", "rb") as f:
                    rx_bidir_astar = pickle.load(f)
                with open(binary_path/"bid_a_star_path_y", "rb") as f:
                    ry_bidir_astar = pickle.load(f)
                plt.plot(rx_bidir_astar, ry_bidir_astar, "crimson")
                legend_elements.append(Line2D([0], [0], color='crimson', lw=4, label='Bidirectional A*'))

            if algorithm == "dijkstra":
                try:
                    
                    rx_dijkstra = []
                    ry_dijkstra = []
                    with open(binary_path/"dijkstra_path_x", "rb") as f:
                        rx_dijkstra = pickle.load(f)
                    with open(binary_path/"dijkstra_path_y", "rb") as f:
                        ry_dijkstra = pickle.load(f)
                    plt.plot(rx_dijkstra, ry_dijkstra, "lime")
                    rows.append("Dijkstra")
                    legend_elements.append(Line2D([0], [0], color='lime', lw=4, label='Dijkstra'))
                except:
                    print("Dijkstra failed, no data to plot")
            
            if algorithm == "d_star":
                rows.append("D*")
                rx_dstar = []
                ry_dstar = []
                with open(binary_path/"d_star_path_x", "rb") as f:
                    rx_dstar = pickle.load(f)
                with open(binary_path/"d_star_path_y", "rb") as f:
                    ry_dstar = pickle.load(f)
                plt.plot(rx_dstar, ry_dstar, "cyan")
                legend_elements.append(Line2D([0], [0], color='cyan', lw=4, label='D*'))
            
            if algorithm == "d_star_lite":
                rows.append("D* Lite")
                rx_dstar_lite = []
                ry_dstar_lite = []
                with open(binary_path/"d_star_lite_path_x", "rb") as f:
                    rx_dstar_lite = pickle.load(f)
                with open(binary_path/"d_star_lite_path_y", "rb") as f:
                    ry_dstar_lite = pickle.load(f)
                plt.plot(rx_dstar_lite, ry_dstar_lite, "blue")
                legend_elements.append(Line2D([0], [0], color='blue', lw=4, label='D* Lite'))
            
    
            if algorithm == "breadth_first_search":
                rows.append("BFS")
                rx_bfs = []
                ry_bfs = []
                with open(binary_path/"bfs_path_x", "rb") as f:
                    rx_bfs = pickle.load(f)
                with open(binary_path/"bfs_path_y", "rb") as f:
                    ry_bfs = pickle.load(f)
                plt.plot(rx_bfs, ry_bfs, "gold")
                legend_elements.append(Line2D([0], [0], color='gold', lw=4, label='BFS'))

            if algorithm == "bidirectional_breadth_first_search":
                rows.append("Bidirectional BFS")
                rx_bidir_bfs = []
                ry_bidir_bfs = []
                with open(binary_path/"bid_bfs_path_x", "rb") as f:
                    rx_bidir_bfs = pickle.load(f)
                with open(binary_path/"bid_bfs_path_y", "rb") as f:
                    ry_bidir_bfs = pickle.load(f)
                plt.plot(rx_bidir_bfs, ry_bidir_bfs, "yellow")
                legend_elements.append(Line2D([0], [0], color='yellow', lw=4, label='Bidirectional BFS'))

            if algorithm == "greedy_best_first_search":
                rows.append("Greedy Best First Search")
                rx_gbfs = []
                ry_gbfs = []
                with open(binary_path/"gbfs_path_x", "rb") as f:
                    rx_gbfs = pickle.load(f)
                with open(binary_path/"gbfs_path_y", "rb") as f:
                    ry_gbfs = pickle.load(f)
                plt.plot(rx_gbfs, ry_gbfs, "orange")
                legend_elements.append(Line2D([0], [0], color='orange', lw=4, label='GBFS'))
    else:
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
        plt.show(block = False)
    except:
        pass

    try:
        fig, ax = plt.subplots()
        for row in rows:
            with open(binary_path/f"{row}_results", "rb") as f:
                values = pickle.load(f)
        # hide axes
        fig.patch.set_visible(False)
        ax.axis('off')
        ax.axis('tight')
        ax.table(cellText=values, colLabels=columns, rowLabels=rows, loc='center', cellLoc='center', colLoc='center')
        fig.tight_layout()
        plt.savefig(results/table_name)
    except:
        print("No enough data to plot table!")
    
    plt.show()
    
    
if __name__ == '__main__':
    try:
        plot()
    except KeyboardInterrupt:
        sys.exit(0)
