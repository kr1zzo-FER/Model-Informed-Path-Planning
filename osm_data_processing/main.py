"""

Main program for processing OSM data

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from pathlib import Path
import yaml
import sys
import os
from detect_coast import detect_coastline, zones_from_coast
from process_osm_data import process_osm_data, resize_image 
from set_start_goal import set_start_goal

import pickle 

root = Path(__file__).resolve().parents[1]

def main():

    # start program
    print("\n"+__file__+ " start!!")

    # load configuration file
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        image_name = config["location_image"]
        image_save = config["resized_location_image"]
        grid_size = int(config["grid_size"])
        folder_name = config["location_folder"]
        cost_map = config["cost_map"]
        custom_start_goal = config["custom_start_goal"]
        slatitude = config["start_latitude"]
        slongitude = config["start_longitude"]
        glatitude = config["goal_latitude"]
        glongitude = config["goal_longitude"]
    
    start_goal = [float(slatitude), float(slongitude), float(glatitude), float(glongitude)]
    
    # paths to files, make new directories if they don't exist
    binary_path = root / "binary_dump"
    isExist = os.path.exists(binary_path)
    if not isExist:
        os.makedirs(binary_path)
    results = root / "results"
    isExist = os.path.exists(results)
    if not isExist:
        os.makedirs(results)
    input_data = root / "input_data" / folder_name

    # process OSM data - latitutde and longitude to meters
    latlong, image_wh_meters = process_osm_data(input_data/'osm_info.txt')

    # Save results in binary files
    with open(binary_path/"coordinates", "wb") as f:
        pickle.dump(latlong, f)

    with open(binary_path/"image_width_height_m", "wb") as f:
        pickle.dump(image_wh_meters, f)
    
    # Resize image to 1 m^2 = 1 pixel
    resized_image = resize_image(input_data/image_name,image_wh_meters)

    # save resized image
    resized_image.save(results/image_save)

    # detect edges
    coast_points, image_size = detect_coastline(results/image_save, grid_size)
            
    # save obstacles to binary files
    with open(binary_path/"coast_points", "wb") as f:
        pickle.dump(coast_points, f)
    with open(binary_path/"dimensions", "wb") as f:
        pickle.dump(image_size, f)

    # Cost map zones
    red_zone, yellow_zone, green_zone = [], [], []
    
    if cost_map:
        red_zone, yellow_zone,green_zone = zones_from_coast(coast_points, results/image_save, grid_size) 
        #save zones to binary files
        with open(binary_path/"red_zone", "wb") as f:
            pickle.dump(red_zone, f)
        with open(binary_path/"yellow_zone", "wb") as f:
            pickle.dump(yellow_zone, f)
        with open(binary_path/"green_zone", "wb") as f:
            pickle.dump(green_zone, f)
        
    # set start and goal positions
    sx__pixel, sy__pixel, gx__pixel, gy__pixel = set_start_goal(results/image_save,binary_path,grid_size,image_wh_meters,latlong,custom_start_goal,start_goal,cost_map,coast_points,red_zone,yellow_zone, green_zone)

    #print(f"Start position for calculation: \n{sx__pixel},{sy__pixel}\n")
    #print(f"Goal position for calculation: \n{gx__pixel},{gy__pixel}\n")

    # Save start and goal positions in binary files
    with open(binary_path/"sx", "wb") as f:
        pickle.dump(sx__pixel, f)
    with open(binary_path/"sy", "wb") as f:
        pickle.dump(sy__pixel, f)

    with open(binary_path/"gx", "wb") as f:
        pickle.dump(gx__pixel, f)
    with open(binary_path/"gy", "wb") as f:
        pickle.dump(gy__pixel, f)
    sys.exit(0)
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
