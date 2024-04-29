
"""

Program for path planning algorithms plotting

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import pickle
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
from pathlib import Path
import sys
from load_data import load_data


root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root)+"/osm_data_processing")

from process_osm_data import deg_to_dms, gps_to_pixel, prepare_image_to_plot



def plot_table(rows, values, columns):
        fig, ax = plt.subplots()
        try:
            # hide axes
            fig.patch.set_visible(False)
            ax.axis('off')
            ax.axis('tight')
            ax.table(cellText=values, colLabels=columns, rowLabels=rows, loc='center', cellLoc='center', colLoc='center')
            fig.tight_layout()
            plt.show(block = False)
        except:
            print("No enough data to plot table!")
        return fig, ax, plt

def plot_algorithms(plot_alg, binary_path, image_path, result_image_path, result_table_path,start, goal, coordinates, coast_points):
    global root, plt

    fig,ax = prepare_image_to_plot(image_path, coordinates, coast_points)

    sx = start[0]
    sy = start[1]
    gx = goal[0]
    gy = goal[1]

    plt.plot(sx, sy, "ok")
    plt.plot(gx, gy, "xk")
    plt.grid(True)

    legend_elements = []
    rows,values = [],[]

    legend_elements.append(Line2D([0], [0], marker='o', color='k', label='Start', markersize=8))
    legend_elements.append(Line2D([0], [0], marker='x', color='k', label='Goal', markersize=8))

    for algorithm in plot_alg:
        if algorithm == "a_star":
            with open(binary_path/"a_star_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "red")
            legend_elements.append(Line2D([0], [0], color='red', lw=4, label='A*'))

        if algorithm == "bidirectional_a_star":
            with open(binary_path/"bid_a_star_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "crimson")
            legend_elements.append(Line2D([0], [0], color='crimson', lw=4, label='Bidirectional A*'))

        if algorithm == "dijkstra":
            with open(binary_path/"dijkstra_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "lime")
            legend_elements.append(Line2D([0], [0], color='lime', lw=4, label='Dijkstra'))

        
        if algorithm == "d_star":
            with open(binary_path/"d_star_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "cyan")
            legend_elements.append(Line2D([0], [0], color='cyan', lw=4, label='D*'))
        
        if algorithm == "d_star_lite":
            with open(binary_path/"d_star_lite_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "blue")
            legend_elements.append(Line2D([0], [0], color='blue', lw=4, label='D* Lite'))
        

        if algorithm == "breadth_first_search":
            with open(binary_path/"bfs_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "gold")
            legend_elements.append(Line2D([0], [0], color='gold', lw=4, label='BFS'))

        if algorithm == "bidirectional_breadth_first_search":
            with open(binary_path/"bid_bfs_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "yellow")
            legend_elements.append(Line2D([0], [0], color='yellow', lw=4, label='Bidirectional BFS'))

        if algorithm == "greedy_best_first_search":
            with open(binary_path/"gbfs_results", "rb") as f:
                results = pickle.load(f)
            rows.append(results[0])
            values.append(results[3:])
            plt.plot(results[1], results[2], "orange")
            legend_elements.append(Line2D([0], [0], color='orange', lw=4, label='GBFS'))


    try: 
        plt.legend(handles=legend_elements, loc='upper right')
        plt.draw()
        plt.savefig(result_image_path)
        plt.show(block = False)
    except:
        print("Plotting failed")
        pass
    
    columns = ['Runtime [s]', 'Distance [m]']
    print(rows, values, columns)

    fig, ax, plt = plot_table(rows, values, columns)

    plt.savefig(result_table_path)
    plt.show()

    return

def plot_costmap(binary_path, image_path, start, goal, red_zone, yellow_zone, green_zone, coordinates, coast_points, result_costmap_name, result_costmap_table):
    
    global root, plt

    legend_elements = []

    fig,ax = prepare_image_to_plot(image_path, coordinates, coast_points)

    sx = start[0]
    sy = start[1]
    gx = goal[0]
    gy = goal[1]

    plt.plot(sx, sy, "ok")
    plt.plot(gx, gy, "xk")
    plt.grid(True)

    for point in red_zone:
        ax.plot(point[0],point[1],".r", markersize=1)
    for point in yellow_zone:
        ax.plot(point[0],point[1],".y", markersize=1)
    for point in green_zone:
        ax.plot(point[0],point[1],".g", markersize=1)

    rows,values = [],[]
    with open(binary_path/"d_star_lite_advanced_results", "rb") as f:
        results = pickle.load(f)
    name = [results[0]]
    values = [[f"r:{results[1][0]} y:{results[1][1]} g:{results[1][2]}", results[4], results[5]]]
    red_cost = results[1][0]
    yellow_cost = results[1][1]
    green_cost = results[1][2]
    plt.plot(results[2], results[3], "blue")
    
    legend_elements.append(Line2D([0], [0], color='blue', lw=4, label=f'D* Lite advanced\n(Red cost: {red_cost}\n Yellow cost: {yellow_cost}\nGreen cost: {green_cost})'))
    
    plt.savefig(result_costmap_name)
    plt.show(block=False)
    
    columns = ['Cost values','Runtime [s]', 'Distance [m]']

    fig,ax,plt = plot_table(name, values, columns)
    plt.savefig(result_costmap_table)  
    plt.show()

    return
    
