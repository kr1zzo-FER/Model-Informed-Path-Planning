
import pickle
import yaml
from pathlib import Path
import os
root = Path(__file__).resolve().parents[1]

class LoadYAMLData:

    def __init__(self, yaml_path):
        self.yaml_path = yaml_path

    def load_data(self):
        global root
        binary_path = root / "binary_dump"
        
        results_dictionary = {}

        binary_path = root / "binary_dump"
        isExist = os.path.exists(binary_path)
        if not isExist:
            os.makedirs(binary_path)
        results = root / "results"
        isExist = os.path.exists(results)
        if not isExist:
            os.makedirs(results)

        results_dictionary["binary_path"] = binary_path

        with open(self.yaml_path, "r") as f:
            config = yaml.safe_load(f)
            image_name = config["location_image"]
            results_dictionary["image_name"] = image_name
            image_save = config["resized_location_image"]
            results_dictionary["image_save"] = image_save
            grid_size = int(config["grid_size"])
            results_dictionary["grid_size"] = grid_size
            folder_name = config["location_folder"]
            results_dictionary["folder_name"] = folder_name
            cost_map = config["cost_map"]
            results_dictionary["cost_map"] = cost_map
            custom_start_goal = config["custom_start_goal"]
            results_dictionary["custom_start_goal"] = custom_start_goal
            slatitude = config["start_latitude"]
            results_dictionary["start_latitude"] = slatitude
            slongitude = config["start_longitude"]
            results_dictionary["start_longitude"] = slongitude
            glatitude = config["goal_latitude"]
            results_dictionary["goal_latitude"] = glatitude
            glongitude = config["goal_longitude"]
            results_dictionary["goal_longitude"] = glongitude
            test_algorithm = config["test_algorithm"]
            results_dictionary["test_algorithm"] = test_algorithm
            plot_alg = config["plot_algorithms"]
            results_dictionary["plot_algorithms"] = plot_alg
            robot_radius = config["robot_radius"]
            results_dictionary["robot_radius"] = robot_radius
            thread_enable = config["thread_enable"]
            results_dictionary["thread_enable"] = thread_enable
            red_cost = config["red_cost"]
            results_dictionary["red_cost"] = red_cost
            yellow_cost = config["yellow_cost"]
            results_dictionary["yellow_cost"] = yellow_cost
            green_cost = config["green_cost"]
            results_dictionary["green_cost"] = green_cost
            cost_map = config["cost_map"]
            results_dictionary["cost_map"] = cost_map
            table_name = config["table_name"]
            results_dictionary["table_name"] = table_name
            result_image = config["result_image"]
            results_dictionary["result_image"] = result_image
            result_costmap_name = config["result_costmap_name"]
            results_dictionary["result_costmap_name"] = result_costmap_name
            result_costmap_table = config["result_costmap_table"]
            results_dictionary["result_costmap_table"] = result_costmap_table
            test_parameters = config["test_parameters"]
            results_dictionary["test_parameters"] = test_parameters
            max_boat_speed = config["max_boat_speed"]
            results_dictionary["max_boat_speed"] = max_boat_speed
            red_speed = config["red_speed"]
            results_dictionary["red_speed"] = red_speed
            yellow_speed = config["yellow_speed"]
            results_dictionary["yellow_speed"] = yellow_speed
            green_speed = config["green_speed"]
            results_dictionary["green_speed"] = green_speed

        results = root / "results"
        input_data = root / "input_data" / folder_name
        image_path = root / "results" / image_name
        image_save_path = root / "results" / image_save
        result_image_path = root / "results" / result_image
        result_table_path = root / "results" / table_name
        result_costmap_name = root / "results" / result_costmap_name
        result_costmap_table = root / "results" / result_costmap_table

        results_dictionary["results"] = results
        results_dictionary["input_data"] = input_data
        results_dictionary["image_path"] = image_path
        results_dictionary["result_image_path"] = result_image_path
        results_dictionary["result_table_path"] = result_table_path
        results_dictionary["result_costmap_name"] = result_costmap_name
        results_dictionary["result_costmap_table"] = result_costmap_table

    

        return results_dictionary