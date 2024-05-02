"""

Main program for processing OSM data

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from pathlib import Path
import sys
import pickle 
from detect_coast import CoastProcessing
from process_osm_data import PathParameters, OSMProcessing
from set_start_goal import set_start_goal
import datetime
from matplotlib import pyplot as plt

root = Path(__file__).resolve().parents[1]

from get_yaml_data import LoadYAMLData

show_results = True

def save_to_binary_file(data, file_name):
    with open(file_name, "wb") as f:
        pickle.dump(data, f)

def main():

    # start program
    print("\n"+__file__+ " start!!")
    
    yaml_object = LoadYAMLData(root/"config.yaml")

    yaml_dict = yaml_object.load_data()

    image_name = yaml_dict["image_name"]
    image_save_path = yaml_dict["image_save"]
    grid_size = yaml_dict["grid_size"]
    cost_map = yaml_dict["cost_map"]
    custom_start_goal = yaml_dict["custom_start_goal"]
    slatitude = yaml_dict["start_latitude"]
    slongitude = yaml_dict["start_longitude"]
    glatitude = yaml_dict["goal_latitude"]
    glongitude = yaml_dict["goal_longitude"]
    binary_path = yaml_dict["binary_path"]
    input_data = yaml_dict["input_data"]
    results = yaml_dict["results"]
    folder_name = yaml_dict["folder_name"]
    
    start_goal = [float(slatitude), float(slongitude), float(glatitude), float(glongitude)]

    
    osm_object = OSMProcessing(input_data/'osm_info.txt', grid_size, input_data/image_name)

    # Resize image to 1 m^2 = 1 pixel
    resized_image = osm_object.get_resized_image()
    # save resized image
    resized_image.save(results/image_save_path)

    ## CoastProcessing object

    coast_object = CoastProcessing(results/image_save_path, grid_size)
    
    if cost_map:
        zones_dictionary = coast_object.zones_from_coast(24)
        osm_object.set_zones_dictionary(zones_dictionary)
        # save zones to binary files
        zones_dictionary_gps = {}
        for key in zones_dictionary:
            k = tuple(osm_object.pixel_to_gps(key[0],key[1]))
            value = zones_dictionary[key]
            zones_dictionary_gps[k] = value
        
    else:
        coast_points, image_size = coast_object.detect_coastline()
        # save coast points to binary file
        osm_object.set_coast_points(coast_points)
        coast_points_gps = []
        for point in coast_points:
            p = osm_object.pixel_to_gps(point[0],point[1])
            coast_points_gps.append(p)

    
    # set start and goal positions
    sx__pixel, sy__pixel, gx__pixel, gy__pixel = set_start_goal(osm_object,coast_object,binary_path,custom_start_goal, start_goal, cost_map)

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

    if cost_map:
        test_dictionary["data"]["zones_dictionary"] = zones_dictionary_gps
        save_to_binary_file(test_dictionary, binary_path/f'costmap_param_publisher_{folder_name}')
    else:
        test_dictionary["data"]["coast_points"] = coast_points_gps
        save_to_binary_file(test_dictionary, binary_path/f'test_param_publisher_{folder_name}')

    # save path parameters to binary file
    save_to_binary_file(osm_object, binary_path/f'osm_object_{folder_name}')

    if show_results:
        fig,ax = plt.subplots()
        ax.plot(start[0],start[1],'cx')
        ax.plot(goal[0],goal[1],'co')
        if cost_map:
            ax = osm_object.prepare_zones_to_plot(ax)
        else:
            ax = osm_object.prepare_coast_to_plot(ax)
        plt.show()
    

    sys.exit(0)
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
