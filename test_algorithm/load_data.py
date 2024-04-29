
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
    
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithm = config["test_algorithm"]
        plot_alg = config["plot_algorithms"]
        grid_size = config["grid_size"]
        robot_radius = config["robot_radius"]
        thread_enable = config["thread_enable"]
        red_cost = config["red_cost"]
        yellow_cost = config["yellow_cost"]
        green_cost = config["green_cost"]
        cost_map = config["cost_map"]
        table_name = config["table_name"]
        image_name = config["resized_location_image"]
        result_image = config["result_image"]
        result_costmap_name = config["result_costmap_name"]
        result_costmap_table = config["result_costmap_table"]
        test_parameters = config["test_parameters"]

    image_path = root / "results" / image_name
    result_image_path = root / "results" / result_image
    result_table_path = root / "results" / table_name
    result_costmap_name = root / "results" / result_costmap_name
    result_costmap_table = root / "results" / result_costmap_table

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

    print(start)

    return binary_path, start, goal, obstacles, coordinates, coast_points, red_zone, yellow_zone, green_zone, grid_size, robot_radius, red_cost, yellow_cost, green_cost, dimensions, test_algorithm, plot_alg, thread_enable, cost_map, image_path, result_image_path, result_table_path, result_costmap_name, result_costmap_table, test_parameters