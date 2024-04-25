"""

Thread module for running the main functions of the project in parallel.

author: Enio Krizman (@kr1zzo)

"""
import sys
import pickle
from test_path_planning import test_algorithms, test_dstar_lite_costmap
from load_data import load_data
from plot import plot_algorithms, plot_table, plot_costmap


def main(test = True):

    dict = load_data()

    cost_map = dict["cost_map"]
    test_algorithm = dict["test_algorithm"]
    plot_alg = dict["plot_algorithms"]
    grid_size = dict["grid_size"]
    robot_radius = dict["robot_radius"]
    thread_enable = dict["thread_enable"]
    red_cost = dict["red_cost"]
    yellow_cost = dict["yellow_cost"]
    green_cost = dict["green_cost"]
    result_costmap_name = dict["result_costmap_name"]
    result_costmap_table = dict["result_costmap_table"]
    test_parameters = dict["test_parameters"]
    start = dict["start"]
    goal = dict["goal"]
    obstacles = dict["obstacles"]
    dimensions = dict["dimensions"]
    red_zone = dict["red_zone"]
    yellow_zone = dict["yellow_zone"]
    green_zone = dict["green_zone"]
    coordinates = dict["coordinates"]
    coast_points = dict["coast_points"]
    image_path = dict["image_path"]
    result_image_path = dict["result_image_path"]
    result_table_path = dict["result_table_path"]
    binary_path = dict["binary_path"]
    max_boat_speed = dict["max_boat_speed"]
    red_speed = dict["red_speed"]
    yellow_speed = dict["yellow_speed"]
    green_speed = dict["green_speed"]

    
    if cost_map:

        if test:
            results = test_dstar_lite_costmap(test_parameters,start, goal, obstacles, grid_size, robot_radius,dimensions, red_zone, yellow_zone, green_zone, red_cost, yellow_cost, green_cost, max_boat_speed, red_speed, yellow_speed, green_speed)
            
            for results in results:
                with open(binary_path/f"d_star_lite_advanced_results", "wb") as f:
                    pickle.dump(results, f)

        plot_costmap(binary_path, image_path, start, goal, red_zone, yellow_zone, green_zone, coordinates, coast_points, result_costmap_name, result_costmap_table)
   
    else:
        if test:
            tested_algorithms = test_algorithms(binary_path,start, goal, obstacles,test_algorithm, grid_size, robot_radius, thread_enable, dimensions)

            for algorithm in tested_algorithms:
                with open(binary_path/f"{algorithm[0]}_results", "wb") as f:
                    pickle.dump(algorithm, f)

        plot_algorithms(plot_alg,binary_path, image_path, result_image_path,result_table_path, start, goal, coordinates, coast_points)

    sys.exit(0)

if __name__ == '__main__':
    try:
        main(True)
    except KeyboardInterrupt:
        sys.exit(0)
