"""

Thread module for running the main functions of the project in parallel.

author: Enio Krizman (@kr1zzo)

"""
import sys
import pickle
from test_path_planning import test_algorithms
from load_data import load_data
from plot import plot_algorithms, plot_table, plot_costmap

def main():

    binary_path, start, goal, obstacles, coordinates, coast_points, red_zone, yellow_zone, green_zone, grid_size, robot_radius, red_cost, yellow_cost, green_cost, dimensions, test_algorithm, plot_alg, thread_enable, cost_map, image_path, result_image_path, result_table_path, result_costmap_name, result_costmap_table = load_data()
    
    if cost_map:
        pass
    else:
        tested_algorithms = test_algorithms(binary_path,start, goal, obstacles,test_algorithm, grid_size, robot_radius, thread_enable, dimensions)

        for algorithm in tested_algorithms:
            with open(binary_path/f"{algorithm[0]}_results", "wb") as f:
                pickle.dump(algorithm, f)

        plot_algorithms(plot_alg,binary_path, image_path, result_image_path,result_table_path, start, goal, coordinates, coast_points)

    sys.exit(0)

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
