"""

Main program for processing OSM data

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from pathlib import Path
import sys
import pickle 
from detect_coast import CoastProcessing
from process_osm_data import OSMProcessing
from set_start_goal import set_start_goal
import datetime
from matplotlib import pyplot as plt
import yaml
import os

root = Path(__file__).resolve().parents[1]


show_results = False

def save_to_binary_file(data, file_name):
    with open(file_name, "wb") as f:
        pickle.dump(data, f)

def main():

    # start program
    print("\n"+__file__+ " start!!")
    

    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        slatitude = config["start_latitude"]
        slongitude = config["start_longitude"]
        glatitude = config["goal_latitude"]
        glongitude = config["goal_longitude"]
        location_folder = config["location_folder"]
        grid_size = int(config["grid_size"])
        custom_start_goal = config["custom_start_goal"]
    
    start_goal = [float(slatitude), float(slongitude), float(glatitude), float(glongitude)]

    input_data = root / "input_data" / location_folder

    binary_path = root / "binary_dump"
    isExist = os.path.exists(binary_path)
    if not isExist:
        os.makedirs(binary_path)

    image_name = f"{location_folder}.png"
    image_save = f"{location_folder}_resized.png"

    osm_object = OSMProcessing(input_data/'osm_info.txt', grid_size, input_data/image_name)

    # Resize image to 1 m^2 = 1 pixel
    resized_image = osm_object.get_resized_image()
    # save resized image
    resized_image.save(input_data/image_save)

    ## CoastProcessing object

    coast_object = CoastProcessing(input_data/image_save, grid_size)
 
    coast_points, image_size = coast_object.detect_coastline()
    # save coast points to binary file
    osm_object.set_coast_points(coast_points)
    coast_points_gps = []
    for point in coast_points:
        p = osm_object.pixel_to_gps(point[0],point[1])
        coast_points_gps.append(p)

    
    # set start and goal positions
    sx__pixel, sy__pixel, gx__pixel, gy__pixel = set_start_goal(osm_object,coast_object,binary_path,custom_start_goal, start_goal)

    start = sx__pixel, sy__pixel
    goal = gx__pixel, gy__pixel

    start_gps = [osm_object.pixel_to_gps(start[0],start[1])]
    goal_gps = [osm_object.pixel_to_gps(goal[0],goal[1])]

    test_dictionary = {}
    test_dictionary["header"] = "Test data"
    test_dictionary["time_stamp"] = f"{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}"
    test_dictionary["data"] = {}
    test_dictionary["data"]["start"] = start_gps
    test_dictionary["data"]["goal"] = goal_gps
    test_dictionary["data"]["grid_size"] = grid_size
    test_dictionary["data"]["coast_points"] = coast_points_gps
        
    save_to_binary_file(test_dictionary, binary_path/f'test_param_publisher_{location_folder}')

    # save path parameters to binary file
    save_to_binary_file(osm_object, binary_path/f'osm_object_{location_folder}')

    if show_results:
        fig,ax = plt.subplots()
        ax.plot(start[0],start[1],'cx')
        ax.plot(goal[0],goal[1],'co')
        ax = osm_object.prepare_coast_to_plot(ax)
        plt.show()
    

    sys.exit(0)
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
