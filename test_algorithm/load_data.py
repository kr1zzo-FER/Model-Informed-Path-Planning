
import pickle
import yaml
from pathlib import Path

root = Path(__file__).resolve().parents[1]

def load_data():
    
    global root 

    ox, oy = [], []
    redx, redy = [], []
    yellowx, yellowy = [], []
    greenx, greeny = [], []

    global root
    binary_path = root / "binary_dump"
    
    results_dictionary = {}

    results_dictionary["binary_path"] = binary_path

    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithm = config["test_algorithm"]
        results_dictionary["test_algorithm"] = test_algorithm
        plot_alg = config["plot_algorithms"]
        results_dictionary["plot_algorithms"] = plot_alg
        grid_size = config["grid_size"]
        results_dictionary["grid_size"] = grid_size
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
        image_name = config["resized_location_image"]
        results_dictionary["image_name"] = image_name
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

    image_path = root / "results" / image_name
    result_image_path = root / "results" / result_image
    result_table_path = root / "results" / table_name
    result_costmap_name = root / "results" / result_costmap_name
    result_costmap_table = root / "results" / result_costmap_table

    results_dictionary["image_path"] = image_path
    results_dictionary["result_image_path"] = result_image_path
    results_dictionary["result_table_path"] = result_table_path
    results_dictionary["result_costmap_name"] = result_costmap_name
    results_dictionary["result_costmap_table"] = result_costmap_table

    with open(binary_path/"sx", "rb") as f:
        sx = pickle.load(f)
    with open(binary_path/"sy", "rb") as f:
        sy = pickle.load(f)
    with open(binary_path/"gx", "rb") as f:
        gx = pickle.load(f)
    with open(binary_path/"gy", "rb") as f:
        gy = pickle.load(f)
    
    with open(binary_path/"coast_points", "rb") as f:
        coast_points = pickle.load(f)
        for point in coast_points:
            ox.append(point[0])
            oy.append(point[1])
    
    with open(binary_path/"dimensions", "rb") as f:
        dimensions = pickle.load(f)

    with open(binary_path/"coordinates", "rb") as f:
        coordinates = pickle.load(f)
    
    with open(binary_path/"red_zone", "rb") as f:
        red_zone = pickle.load(f)
        for point in red_zone:
            redx.append(point[0])
            redy.append(point[1])
    with open(binary_path/"yellow_zone", "rb") as f:
        yellow_zone = pickle.load(f)
        for point in yellow_zone:
            yellowx.append(point[0])
            yellowy.append(point[1])
    with open(binary_path/"green_zone", "rb") as f:
        green_zone = pickle.load(f)
        for point in green_zone:
            greenx.append(point[0])
            greeny.append(point[1])

    
    start = [sx, sy]
    goal = [gx, gy]
    obstacles = [ox, oy]

    results_dictionary["start"] = start
    results_dictionary["goal"] = goal
    results_dictionary["obstacles"] = obstacles
    results_dictionary["coordinates"] = coordinates
    results_dictionary["coast_points"] = coast_points
    results_dictionary["red_zone"] = red_zone
    results_dictionary["yellow_zone"] = yellow_zone
    results_dictionary["green_zone"] = green_zone
    results_dictionary["dimensions"] = dimensions

    return results_dictionary