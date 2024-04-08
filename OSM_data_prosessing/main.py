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
from detect_coastline import detect_edges, detect_coast
from process_osm_data import gps_to_meters, process_osm_data, pixel_to_meters
import pickle
from set_start_goal import set_start_goal
import time

root = Path(__file__).resolve().parents[1]


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
        image_name = config["location_image"]
        image_save = config["resized_location_image"]
        grid_size = int(config["grid_size"])
        folder_name = config["location_folder"]
    
    # paths to files
    binary_path = root / "binary_dump"
    results = root / "results"
    input_data = root / "input_data" / folder_name

    # process OSM data - latitutde and longitude to meters
    latlong = process_osm_data(binary_path, input_data)

    
    print(f"Input image: {image_name}\n")
    
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
    print("Detecting coastline points...\n")
    tic = time.time()
    coast_points= detect_edges(results/image_save, binary_path, grid_size)
    toc = time.time()
    print(f"Runtime {round(toc-tic,4)} seconds : {len(coast_points)} coast points\nMin x: {min(coast_points, key=lambda x: x[0])[0]}, Max x: {max(coast_points, key=lambda x: x[0])[0]}\nMin y: {min(coast_points, key=lambda x: x[1])[1]}, Max y: {max(coast_points, key=lambda x: x[1])[1]}")


    # set start and goal positions
    set_start_goal(coast_points, latlong)
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
