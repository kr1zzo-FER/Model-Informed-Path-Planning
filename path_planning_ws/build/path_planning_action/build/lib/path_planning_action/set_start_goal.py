
"""

Program for setting start and goal positions for the path planning algorithm.

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import matplotlib.pyplot as plt
from matplotlib.backend_bases import MouseButton
import sys
from pathlib import Path
from matplotlib.lines import Line2D

root = Path(__file__).resolve().parents[1]

binary_path = root / "binary_dump"
counter = 1
ax, fig = 0,0
start = []
goal = []
set_start = False
set_goal = False
legend_elements = []
sx, sy, gx, gy = 0,0,0,0

def onclick(event, path_object, coast_object, grid_size, binary_path):
    
    global counter
    global ax, fig
    global legend_elements
    global set_start
    global set_goal
    global start
    global sx, sy, gx, gy

    coordinates, image_wh_meters, size_x, size_y = path_object.get_osm_data()

    if event.button == MouseButton.LEFT:
        if counter % 2 != 0:
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            if coast_object.detect_coast_points(x_data, y_data):
                print("Start position is not set in the sea! Choose another position")
                return
            counter += 1
            sx = x_data
            sy = y_data
            sx_longitude = round(sx * (coordinates[2] - coordinates[0]) / size_x + coordinates[0], 6)
            sx_longitude = path_object.deg_to_dms(sx_longitude)
            sy_latitude = round(sy * (coordinates[3] - coordinates[1]) / size_y + coordinates[1], 6)
            sy_latitude = path_object.deg_to_dms(sy_latitude)
            start.clear()
            print(f"Start position for calculation: \nx_longitude : {x_data} [{sx_longitude}]\ny_latitude : {y_data} [{sy_latitude}]\n")
            ax.plot(x_data,y_data, 'bo', markersize=8)
            legend_elements.append(Line2D([0], [0], marker='o', color='b', label=f'\nStart and goal positions part {counter/2}:\nStart : ({sx_longitude}, {sy_latitude})'))
            ax.legend(handles=legend_elements, loc='upper right')
            plt.draw()
            set_start = True
            
        else:

            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            if coast_object.detect_coast_points(x_data, y_data):
                print("Goal position is not set in the sea! Choose another position")
                return
            counter += 1
            gx = x_data
            gy = y_data
            gx_longitude = round(gx * (coordinates[2] - coordinates[0]) / size_x + coordinates[0], 6)
            gx_longitude = path_object.deg_to_dms(gx_longitude)
            gy_latitude = round(gy * (coordinates[3] - coordinates[1]) / size_y + coordinates[1], 6)
            gy_latitude = path_object.deg_to_dms(gy_latitude)
            print(f"Goal position for calculation: \nx_longitude : {x_data} [{gx_longitude}]\ny_latitude : {y_data} [{gy_latitude}]\n")
            ax.plot(x_data,y_data, 'bx', markersize=8)
            legend_elements.append(Line2D([0], [0], marker='x', color='b', label=f'Goal : ({gx_longitude}, {gy_latitude})'))
            ax.legend(handles=legend_elements, loc='upper right')
            plt.draw()
            set_goal = True
            goal.clear()
            
    elif event.button == MouseButton.RIGHT:
        if set_start and set_goal:
            print("\nStart and goal positions set!\n")
            plt.close()
            return
        elif not set_start:
            print("\nSet start position first!\n")
        elif not set_goal:
            print("\nSet goal position first!\n")
    return

def set_start_goal(path_object,coast_object,binary_path,custom_start_goal, start_goal, cost_map):
    """
    Set start and goal positions for the path planning algorithm
    Option 1 : Set start and goal positions by clicking on the image (costum_start_goal = True)
    Option 2 : Set start and goal positions in the config file (costum_start_goal = False)
    """
    
    global ax, fig
    legend_elements = []

    fig,ax = path_object.prepare_image_to_plot()  
    
    print(f"\ncustom start and goal positions: {custom_start_goal}\n")
    
    grid_size = path_object.get_grid_size()
    
    if cost_map:
        ax = path_object.prepare_zones_to_plot(ax)
    else:
        ax = path_object.prepare_coast_to_plot(ax)

    if custom_start_goal:
        global sx, sy, gx, gy
        ax.set_title("(<-) Left mouse click - set start and goal positions (->) Right mouse click - end program and save start and goal positions")
        print("\n(<-) Left mouse click - set start and goal positions (->) Right mouse click - end program\n")
        fig.canvas.mpl_connect('button_press_event', lambda event: onclick(event, path_object, coast_object, grid_size, binary_path))
        plt.show()
        sx__pixel = sx
        sy__pixel = sy
        gx__pixel = gx
        gy__pixel = gy
    else:
        # load start and goal positions
        slatitude = start_goal[0]
        slongitude = start_goal[1]
        glatitude = start_goal[2]
        glongitude = start_goal[3]

        print(start_goal)

        # Convert start and goal positions to pixels and plot them
        sx__pixel, sy__pixel = path_object.gps_to_pixel(slatitude, slongitude)
        gx__pixel, gy__pixel = path_object.gps_to_pixel(glatitude, glongitude)

        print(f"Start position for calculation: \nx_longitude : {sx__pixel} [{path_object.deg_to_dms(slongitude)}]\ny_latitude : {sy__pixel} [{path_object.deg_to_dms(slatitude)}]\n")

        ax.plot(sx__pixel, sy__pixel, 'bo', markersize=8)
        ax.plot(gx__pixel, gy__pixel, 'bx', markersize=8)  

        # print start and goal positions
        ax.set_title("Start and goal positions are set in the config file. Close the window to exit and save start and goal positions!")
        print("Start and goal positions are set in the config file (Ctrl+C to exit)\n")
        print(f"Start position for calculation: \nx_longitude : {sx__pixel} [{path_object.deg_to_dms(slongitude)}]\ny_latitude : {sy__pixel} [{path_object.deg_to_dms(slatitude)}]\n")
        print(f"Goal position for calculation: \nx_longitude : {gx__pixel} [{path_object.deg_to_dms(glongitude)}]\ny_latitude : {gy__pixel} [{path_object.deg_to_dms(glatitude)}]\n")
            
        legend_elements.append(Line2D([0], [0], marker='o', color='b', label=f'Start : ({path_object.deg_to_dms(slongitude)}, {path_object.deg_to_dms(slatitude)})'))
        legend_elements.append(Line2D([0], [0], marker='x', color='b', label=f'Goal : ({path_object.deg_to_dms(glongitude)}, {path_object.deg_to_dms(glatitude)})'))
    
        ax.legend(handles=legend_elements, loc='upper right')
        plt.show()

    return sx__pixel, sy__pixel, gx__pixel, gy__pixel

def main():
     # set start and goal positions
        sx__pixel, sy__pixel, gx__pixel, gy__pixel = set_start_goal(osm_object,coast_object,binary_path,custom_start_goal, start_goal, cost_map)

        start = sx__pixel, sy__pixel
        goal = gx__pixel, gy__pixel