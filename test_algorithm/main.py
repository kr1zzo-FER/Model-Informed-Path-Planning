"""

Thread module for running the main functions of the project in parallel.

author: Enio Krizman (@kr1zzo)

"""
import sys
import pickle
from algorithms_test import TestAlgorithms
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root)+"/osm_data_processing")
from get_yaml_data import LoadYAMLData



def load_binary_data(file_name):
    with open(file_name, "rb") as f:
        data = pickle.load(f)
    return data

def main(test = True):

    print("\n"+__file__+ " start!!")

    yaml_object = LoadYAMLData(root/"config.yaml")

    yaml_dict = yaml_object.load_data()

    folder_name = yaml_dict["folder_name"]
    binary_path = yaml_dict["binary_path"]
    test_algorithms = yaml_dict["test_algorithms"]
    plot_algorithms = yaml_dict["plot_algorithms"]
    cost_map = yaml_dict["cost_map"]
    thread_enable = yaml_dict["thread_enable"]
    red_cost = yaml_dict["red_cost"]
    yellow_cost = yaml_dict["yellow_cost"]
    green_cost = yaml_dict["green_cost"]
    max_boat_speed = yaml_dict["max_boat_speed"]
    red_speed = yaml_dict["red_speed"]
    yellow_speed = yaml_dict["yellow_speed"]
    green_speed = yaml_dict["green_speed"]
    red_cost = yaml_dict["red_cost"]
    yellow_cost = yaml_dict["yellow_cost"]
    green_cost = yaml_dict["green_cost"]
    test_parameters = yaml_dict["test_parameters"]

    gps_data = load_binary_data(binary_path/f"path_parameters_gps_{folder_name}")
    osm_object = load_binary_data(binary_path/f"osm_object_{folder_name}")
    image = osm_object.get_resized_image()

    start = gps_data.get_start()
    goal = gps_data.get_goal()

    coast_points = gps_data.get_coast_points()
    red_zone, yellow_zone, green_zone, zones_dictionary = gps_data.get_zones()
    coast_points = gps_data.get_coast_points()

    
   
    
    if test:
        if not cost_map:
            test_algorithms = TestAlgorithms(start, goal, coast_points,thread_enable, binary_path, test_algorithms)
            coast_points_tested = test_algorithms.get_coast_points_gps()
            test_algorithms.test_algorithms_path()
            test_algorithms.path_visualization()
            #tested_algorithms = test_algorithms.test_algorithms_path()
            #test_algorithms.path_visualization(image)
        else:
            test_algorithms_adv = TestAlgorithmsAdvanced(start, goal, coast_points, thread_enable, binary_path, test_parameters, red_zone, yellow_zone, green_zone, zones_dictionary, max_boat_speed, red_speed, yellow_speed, green_speed)
            tested_algorithms_adv = test_algorithms_adv.test_algorithms_path(red_cost, yellow_cost, green_cost)
            test_algorithms_adv.path_visualization(image)

        
        


    sys.exit(0)

if __name__ == '__main__':
    try:
        main(True)
    except KeyboardInterrupt:
        sys.exit(0)
