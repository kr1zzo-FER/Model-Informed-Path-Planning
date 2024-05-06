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
from post_processing import PostProcessing
from set_start_goal import set_start_goal
import datetime
from matplotlib import pyplot as plt

root = Path(__file__).resolve().parents[1]
binary_path = root / "binary_dump"

import yaml

show_results = True

def save_to_binary_file(data, file_name):
    with open(binary_path/file_name, "wb") as f:
        pickle.dump(data, f)

def load_binary_data(file_name):
    try:
        with open(binary_path/file_name, "rb") as f:
            data = pickle.load(f)
    except:
        data = None
    return data

def main():

    # start program
    print("\n"+__file__+ " start!!")
    
    
    with open("config.yaml", "r") as f:
        config = yaml.load(f, Loader=yaml.FullLoader)
        locations_folder = config["locations_folder"]
        grid_size = config["grid_size"]
        slatitude = config["start_latitude"]
        slongitude = config["start_longitude"]
        glatitude = config["goal_latitude"]
        glongitude = config["goal_longitude"]
        save_file = config["save_file"]
    
    test_dictionary = load_binary_data(f'processed_map_{save_file}')

    print(test_dictionary)

    if test_dictionary is None:
        processed_areas = locations_folder
        coast_points_gps = []
        red_zone_gps = []
        yellow_zone_gps = []
        green_zone_gps = []
    else:
        processed = test_dictionary["processed_areas"]
        for area in processed:
            if area in locations_folder:
                locations_folder.remove(area)
        processed_areas = processed + locations_folder
        coast_points_gps = test_dictionary["data"]["coast_points_gps"][0]
        red_zone_gps = test_dictionary["data"]["red_zone_gps"][0]
        yellow_zone_gps = test_dictionary["data"]["yellow_zone_gps"][0]
        green_zone_gps = test_dictionary["data"]["green_zone_gps"][0]

    print(red_zone_gps)
    

    print(f"\nLocations to process: {locations_folder}")

    for location in locations_folder:

        print(f"\nPorcessing {location}!")
        input_data = root / "input_data" / location
        binary_path = root / "binary_dump"
        image_name = f"{location}.png"
        image_save = f"{location}_resized.png"


        osm_object = OSMProcessing(input_data/'osm_info.txt', grid_size, input_data/image_name)

        # Resize image to 1 m^2 = 1 pixel
        resized_image = osm_object.get_resized_image()
        # save resized image
        resized_image.save(input_data/image_save)

        ## CoastProcessing object

        coast_object = CoastProcessing(input_data/image_save, grid_size)
        
        
        coast_points, red_zone, yellow_zone, green_zone = coast_object.zones_from_coast(12)
        # save coast points to binary file
        osm_object.set_coast_points(coast_points)
        
        for point in coast_points:
            p = osm_object.pixel_to_gps(point[0],point[1])
            if p not in coast_points_gps:
                coast_points_gps.append(p)
        for point in red_zone:
            p = osm_object.pixel_to_gps(point[0],point[1])
            if p not in red_zone_gps:
                red_zone_gps.append(p)
        for point in yellow_zone:
            p = osm_object.pixel_to_gps(point[0],point[1])
            if p not in yellow_zone_gps:
                yellow_zone_gps.append(p)
        for point in green_zone:
            p = osm_object.pixel_to_gps(point[0],point[1])
            if p not in green_zone_gps:
                green_zone_gps.append(p)

    
    post_processing = PostProcessing(coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, grid_size)
    coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps = post_processing.get_coordinates()

    test_dictionary = {}
    test_dictionary["header"] = "Test data"
    test_dictionary["time_stamp"] = f"{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}"
    test_dictionary["processed_areas"] = processed_areas
    test_dictionary["data"] = {}
    test_dictionary["data"]["grid_size"] = grid_size
    test_dictionary["data"]["coast_points"] = coast_points
    test_dictionary["data"]["red_zone"] = red_zone
    test_dictionary["data"]["yellow_zone"] = yellow_zone
    test_dictionary["data"]["green_zone"] = green_zone
    test_dictionary["data"]["coast_points_gps"] = coast_points_gps
    test_dictionary["data"]["red_zone_gps"] = red_zone_gps
    test_dictionary["data"]["yellow_zone_gps"] = yellow_zone_gps
    test_dictionary["data"]["green_zone_gps"] = green_zone_gps

    save_to_binary_file(test_dictionary, binary_path/f'processed_map_{save_file}')
    
    sys.exit(0)
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
