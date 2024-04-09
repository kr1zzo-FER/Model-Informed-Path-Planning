
"""

Program for setting start and goal positions for the path planning algorithm.

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import yaml
import matplotlib.pyplot as plt
from matplotlib.backend_bases import MouseButton
import sys
from detect_coastline import detect_coast
import pickle
from pathlib import Path
from PIL import Image
import numpy as np
from matplotlib.lines import Line2D
from process_osm_data import deg_to_dms
import os

root = Path(__file__).resolve().parents[1]
binary_path = root / "binary_dump"
counter = 1
ax, fig = 0,0
grid_size = 0
start = []
goal = []
set_start = False
set_goal = False
image_path = ""
coordinates = []
size_x = 0  
size_y = 0
legend_elements = []
start = []

def onclick(event):
    
    global counter
    global ax, fig
    global image_path
    global coordinates
    global size_x
    global size_y
    global legend_elements
    global grid_size
    global binary_path
    global set_start
    global set_goal
    global start

    if event.button == MouseButton.LEFT:
        if counter % 2 != 0:
            counter += 1
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            if detect_coast(image_path,x_data, y_data):
                print("Start position is not set in the sea! Choose another position")
                return
            with open(binary_path/"sx", "wb") as f:
                pickle.dump(x_data, f)
            with open(binary_path/"sy", "wb") as f:
                pickle.dump(y_data, f)
            sx = x_data
            sy = y_data
            sx_longitude = round(sx * (coordinates[2] - coordinates[0]) / size_x + coordinates[0], 6)
            sx_longitude = deg_to_dms(sx_longitude)
            sy_latitude = round(sy * (coordinates[3] - coordinates[1]) / size_y + coordinates[1], 6)
            sy_latitude = deg_to_dms(sy_latitude)
            start
            print(f"Start position for calculation: \nx_longitude : {x_data} [{sx_longitude}]\ny_latitude : {y_data} [{sy_latitude}]\n")
            ax.plot(x_data,y_data, 'go', markersize=5)
            legend_elements.append(Line2D([0], [0], marker='o', color='g', label=f'\nStart and goal positions part {counter/2}:\nStart : ({sx_longitude}, {sy_latitude}))'))
            ax.legend(handles=legend_elements, loc='upper right')
            plt.draw()
            set_start = True
            
        else:
            counter += 1
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            if detect_coast(image_path,x_data, y_data):
                print("Goal position is not set in the sea! Choose another position")
                return
            with open(binary_path/"gx", "wb") as f:
                pickle.dump(x_data, f)
            with open(binary_path/"gy", "wb") as f:
                pickle.dump(y_data, f)
            gx = x_data
            gy = y_data
            gx_longitude = round(gx * (coordinates[2] - coordinates[0]) / size_x + coordinates[0], 6)
            gx_longitude = deg_to_dms(gx_longitude)
            gy_latitude = round(gy * (coordinates[3] - coordinates[1]) / size_y + coordinates[1], 6)
            gy_latitude = deg_to_dms(gy_latitude)
            print(f"Goal position for calculation: \nx_longitude : {x_data} [{gx_longitude}]\ny_latitude : {y_data} [{gy_latitude}]\n")
            ax.plot(x_data,y_data, 'bx', markersize=5)
            legend_elements.append(Line2D([0], [0], marker='x', color='b', label=f'Goal : ({gx_longitude}, {gy_latitude}))'))
            ax.legend(handles=legend_elements, loc='upper right')
            plt.draw()
            set_goal = True
            goal.clear()
            
    

    

    elif event.button == MouseButton.RIGHT:
        if set_start and set_goal:
            print("\nStart and goal positions set!\n")
            plt.close()
            sys.exit(0)
        elif not set_start:
            print("\nSet start position first!\n")
        elif not set_goal:
            print("\nSet goal position first!\n")

def set_start_goal(coast_points, latlong):

    global binary_path
    global root
    global grid_size
    global ax, fig
    global counter
    global fig, ax
    global image_path
    global coordinates
    global size_x
    global size_y
    global legend_elements

    binary_path = root / "binary_dump"
    isExist = os.path.exists(binary_path)
    if not isExist:
        os.makedirs(binary_path)


    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        image_save = config["resized_location_image"]
        grid_size = int(config["grid_size"])
        costume_start_goal = config["costume_start_goal"]
        slatitude = config["start_latitude"]
        slongitude = config["start_longitude"]
        glatitude = config["goal_latitude"]
        glongitude = config["goal_longitude"]

    try:
        image_path = root/"results"/image_save
    except FileNotFoundError:
        print(f"Image {image_save} not found in the results folder!")
        sys.exit(0)

    image = Image.open(root/"results"/image_save)
    

    # plot image and detect start and goal positions
    
    
    fig, ax = plt.subplots()

    im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])

    coordinates = latlong
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
    

    image_cordinates_x = np.arange(0, round(size_x), round(size_x/(len(coordinates_plot_x)-1)))
    image_cordinates_x = np.append(image_cordinates_x, size_x)
    image_cordinates_y = np.arange(0, round(size_y), round(size_y/(len(coordinates_plot_y)-1)))
    image_cordinates_y = np.append(image_cordinates_y, size_y)

    plt.xticks(image_cordinates_x, coordinates_plot_x, rotation=90)
    plt.yticks(image_cordinates_y, coordinates_plot_y)

    
    #plt.plot(ox, oy, ".k")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.grid(True)
    
    
    
    for point in coast_points:
        ax.plot(point[0],point[1], 'bo', markersize=0.1)
    
    print(f"\nCostume start and goal positions: {costume_start_goal}\n")
    
    legend_elements = []

    if costume_start_goal:
        ax.set_title("(<-) Left mouse click - set start and goal positions (->) Right mouse click - end program")
        print("\n(<-) Left mouse click - set start and goal positions (->) Right mouse click - end program\n")
        fig.canvas.mpl_connect('button_press_event', onclick)
   
    else:

        ax.set_title("Start and goal positions are set in the config file (Ctrl+C to exit)")
        print("Start and goal positions are set in the config file (Ctrl+C to exit)\n")
        sx__pixel = int(round((slongitude - coordinates[0]) * size_x / (coordinates[2] - coordinates[0])))
        sy__pixel = int(round((slatitude - coordinates[1]) * size_y / (coordinates[3] - coordinates[1])))
        gx__pixel = int(round((glongitude - coordinates[0]) * size_x / (coordinates[2] - coordinates[0])))
        gy__pixel = int(round((glatitude - coordinates[1]) * size_y / (coordinates[3] - coordinates[1])))
        sx__pixel = round(sx__pixel/grid_size)*grid_size
        sy__pixel = round(sy__pixel/grid_size)*grid_size
        gx__pixel = round(gx__pixel/grid_size)*grid_size
        gy__pixel = round(gy__pixel/grid_size)*grid_size
        ax.plot(sx__pixel, sy__pixel, 'go', markersize=5)
        ax.plot(gx__pixel, gy__pixel, 'bx', markersize=5)  

        print(f"Start position for calculation: \nx_longitude : {sx__pixel} [{deg_to_dms(slongitude)}]\ny_latitude : {sy__pixel} [{deg_to_dms(slatitude)}]\n")
        print(f"Goal position for calculation: \nx_longitude : {gx__pixel} [{deg_to_dms(glongitude)}]\ny_latitude : {gy__pixel} [{deg_to_dms(glatitude)}]\n")

        with open(binary_path/"sx", "wb") as f:
                pickle.dump(sx__pixel, f)
        with open(binary_path/"sy", "wb") as f:
            pickle.dump(sy__pixel, f)

        with open(binary_path/"gx", "wb") as f:
            pickle.dump(gx__pixel, f)
        with open(binary_path/"gy", "wb") as f:
            pickle.dump(gy__pixel, f)
            
        legend_elements.append(Line2D([0], [0], marker='o', color='g', label=f'Start : ({deg_to_dms(slongitude)}, {deg_to_dms(slatitude)})'))
        legend_elements.append(Line2D([0], [0], marker='x', color='b', label=f'Goal : ({deg_to_dms(glongitude)}, {deg_to_dms(glatitude)})'))
    
        ax.legend(handles=legend_elements, loc='upper right')

    plt.show()


if __name__ == '__main__':
    try:
        set_start_goal()
    except KeyboardInterrupt:
        sys.exit(0)
