"""

Map generation script

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from skimage import io, measure
from PIL import Image
from pathlib import Path
import yaml
import matplotlib.pyplot as plt
from matplotlib.backend_bases import MouseButton
import sys
from detect_coastline import detect_edges
from process_osm_data import gps_to_meters, process_osm_data, pixel_to_meters
import pickle

root = Path(__file__).resolve().parents[1]
counter = 0
x_width = 0
y_width = 0
ax, fig = 0,0
grid_size = 0
start = []
goal = []
set_start = False
set_goal = False


def onclick(event):
    
    global root

    binary_path = root / "binary_dump"
    images = root / "images"
    global counter
    global grid_size
    global start
    global x_width
    global y_width
    global ax, fig
    global set_start
    global set_goal
    global goal, start
    if event.button == MouseButton.LEFT:
        if counter == 0:
            print(f"Start position set: {event.xdata}, {event.ydata}")
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            start = [x_data, y_data]
            ax.plot(start[0],start[1], 'go', markersize=5)
            plt.show()
            with open(binary_path/"sx", "wb") as f:
                pickle.dump(x_data, f)
            with open(binary_path/"sy", "wb") as f:
                pickle.dump(y_data, f)
            print(f"Start position for calculation: {x_data}, y: {y_data}\n")
            set_start = True
            counter += 1
        elif counter == 1:
            print(f"Goal position set: {event.xdata}, {event.ydata}")
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            goal = [x_data, y_data]
            ax.plot(goal[0],goal[1], 'bx', markersize=5)
            plt.show()
            with open(binary_path/"gx", "wb") as f:
                pickle.dump(x_data, f)
            with open(binary_path/"gy", "wb") as f:
                pickle.dump(y_data, f)
            print(f"Goal position for calculation: {x_data}, y: {y_data}\n")
            set_goal = True
            goal.clear()
            counter -= 1

    elif event.button == MouseButton.RIGHT:
        if set_start and set_goal:
            print("\nStart and goal positions set!\n")
            plt.close()
            sys.exit(0)
        elif not set_start:
            print("\nSet start position first!\n")
        elif not set_goal:
            print("\nSet goal position first!\n")


def main():

    # start program
    print("\n"+__file__+ " start!!\n")

    # global variables
    global root
    global grid_size
    global x_width

    # load configuration file
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        image_name = config["start_image_name"]
        image_save = config["image_save"]
        grid_size = int(config["grid_size"])
        canny_detection = config["canny_detection"]
        folder_name = config["folder_name"]
    
    # paths to files
    binary_path = root / "binary_dump"
    results = root / "results"

    input_data = Path(".")

    print(input_data)

    # process OSM data - latitutde and longitude to meters
    process_osm_data(binary_path, input_data)

    
    print(f"Input image: {image_name}")
    
    # load images
    image = Image.open(input_data/image_name)

    # resize images to fit the grid size : 1 pixel = 1 meter
    factorx, factory = pixel_to_meters(root,image.size[0], image.size[1])

    factorx = int(round(image.size[0]*factorx))
    factory = int(round(image.size[1]*factory))

    image = image.resize((factorx, factory))

    # save resized images
    image.save(results/image_save)

    # detect edges
    ox, oy = detect_edges(results/image_save, binary_path, grid_size, canny_detection)

    # plot image and detect start and goal positions
    print("\nSet start and goal positions with left mouse click. Right click to end\n")
    global fig, ax
    fig, ax = plt.subplots()

    im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])
    
    ax.set_title("Left mouse click - set start and goal positions, end with right mouse click")
    
    for ox, oy in zip(ox, oy):
        ax.plot(ox, oy, 'bo', markersize = 0.5)

    fig.canvas.mpl_connect('button_press_event', onclick)

    plt.show()

    
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
