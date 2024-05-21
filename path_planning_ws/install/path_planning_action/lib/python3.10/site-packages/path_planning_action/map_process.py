"""

Main program for processing OSM data

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from pathlib import Path
import sys
import pickle 
import os
from .detect_coast import CoastProcessing
from .process_osm_data import OSMProcessing
from .post_processing import PostProcessing
import datetime
from matplotlib import pyplot as plt
import rclpy
from rclpy.node import Node

import yaml


path = Path(__file__).resolve().parent
ws_root = Path(__file__).resolve().parents[6]

def save_to_binary_file(data, file_name):
    with open("processed_maps"/file_name, "wb") as f:
        pickle.dump(data, f)

def load_binary_data(file_name):
    try:
        with open("processed_maps"/file_name, "rb") as f:
            data = pickle.load(f)
    except:
        data = None
    return data

class MapProcess(Node):

    def __init__(self):
        super().__init__('map_process')
        #ros log
        self.get_logger().info("Map processing node started")
        self.declare_parameter('locations', ['location1', 'location2'])
        self.declare_parameter('grid_size', 5)
        self.declare_parameter('save_file', 'test')
        self.locations_folder = self.get_parameter('locations').get_parameter_value().string_array_value
        self.grid_size = self.get_parameter('grid_size').get_parameter_value().integer_value
        self.save_file = self.get_parameter('save_file').get_parameter_value().string_value
        self.process_map()
    
    def process_map(self):

        binary_path = ws_root / "src/path_planning_action/input_data/processed_maps"

        isExist = os.path.exists(binary_path)
        if not isExist:
            os.makedirs(binary_path)

        
        test_dictionary = load_binary_data(f'processed_map_{self.locations_folder}')


        if test_dictionary is None:
            processed_areas = self.locations_folder
            coast_points_gps = []
            red_zone_gps = []
            yellow_zone_gps = []
            green_zone_gps = []
        else:
            processed = test_dictionary["processed_areas"]
            for area in processed:
                if area in self.locations_folder:
                    self.locations_folder.remove(area)
            processed_areas = processed + self.locations_folder
            coast_points_gps = test_dictionary["data"]["coast_points_gps"]
            red_zone_gps = test_dictionary["data"]["red_zone_gps"]
            yellow_zone_gps = test_dictionary["data"]["yellow_zone_gps"]
            green_zone_gps = test_dictionary["data"]["green_zone_gps"]

        self.get_logger().info(f"Locations to process: {self.locations_folder}\nsave file: {self.save_file}")

        for location in self.locations_folder:

            location = Path(location)
            input_data = path / 'input_data' / location

            self.get_logger().info(f"Porcessing {location}!")
            image_name = f"{location}.png"
            image_save = f"{location}_resized.png"


            osm_object = OSMProcessing(input_data/'osm_info.txt', self.grid_size, input_data/image_name)

            # Resize image to 1 m^2 = 1 pixel
            resized_image = osm_object.get_resized_image()
            # save resized image
            resized_image.save(input_data/image_save)

            ## CoastProcessing object

            coast_object = CoastProcessing(input_data/image_save, self.grid_size)
            
            coast_points, red_zone, yellow_zone, green_zone = coast_object.zones_from_coast(12)
            # save coast points to binary file
            osm_object.set_coast_points(coast_points)
            
            for point in coast_points:
                p = osm_object.pixel_to_gps(point[0],point[1])
                if p not in coast_points_gps:
                    coast_points_gps.append(p)
            self.get_logger().info(f"Coast points: {len(coast_points)}")
            for point in red_zone:
                p = osm_object.pixel_to_gps(point[0],point[1])
                if p not in red_zone_gps:
                    red_zone_gps.append(p)
            self.get_logger().info(f"Red zone: {len(red_zone)}")
            for point in yellow_zone:
                p = osm_object.pixel_to_gps(point[0],point[1])
                if p not in yellow_zone_gps:
                    yellow_zone_gps.append(p)
            self.get_logger().info(f"Yellow zone: {len(yellow_zone)}")
            for point in green_zone:
                p = osm_object.pixel_to_gps(point[0],point[1])
                if p not in green_zone_gps:
                    green_zone_gps.append(p)
            self.get_logger().info(f"Green zone: {len(green_zone)}")
            
        
        self.get_logger().info("Post processing")
        post_processing = PostProcessing(coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps,self.grid_size)
        coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps = post_processing.get_coordinates()
        self.get_logger().info("Post processing done!")

        test_dictionary = {}
        test_dictionary["header"] = "Test data"
        test_dictionary["time_stamp"] = f"{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}"
        test_dictionary["processed_areas"] = processed_areas
        test_dictionary["data"] = {}
        test_dictionary["data"]["grid_size"] = self.grid_size
        test_dictionary["data"]["coast_points_gps"] = coast_points_gps
        test_dictionary["data"]["red_zone_gps"] = red_zone_gps
        test_dictionary["data"]["yellow_zone_gps"] = yellow_zone_gps
        test_dictionary["data"]["green_zone_gps"] = green_zone_gps

        save_to_binary_file(test_dictionary, binary_path/f'processed_map_{self.save_file}')
        
        self.get_logger().info("Map processing node finished!")

        sys.exit(0)

def main():
    rclpy.init(args=None)
    node = MapProcess()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
