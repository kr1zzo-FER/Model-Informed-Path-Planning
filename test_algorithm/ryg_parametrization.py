import sys
import pickle
from test_path_planning import test_algorithms
from load_data import load_data
from plot import plot_algorithms, plot_table
from algorithm_class import Algorithms 
import multiprocessing as mp 
import time
import itertools
from test_path_planning import test_dstar_lite_costmap
from load_data import load_data

def main():
    binary_path, start, goal, obstacles, coordinates, coast_points, red_zone, yellow_zone, green_zone, grid_size, robot_radius, red_cost, yellow_cost, green_cost, dimensions, test_algorithm, plot_alg, thread_enable, cost_map, image_path, result_image_path, result_table_path, result_costmap_name, result_costmap_table = load_data()
    results = test_dstar_lite_costmap(start, goal, obstacles, grid_size, robot_radius,dimensions, red_zone, yellow_zone, green_zone)
    with open(binary_path/f"dstarlite_results", "wb") as f:
        pickle.dump(results, f)
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
