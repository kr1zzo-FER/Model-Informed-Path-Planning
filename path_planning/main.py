"""

Thread module for running the main functions of the project in parallel.

author: Enio Krizman (@kr1zzo)

"""
import sys
import pickle
from algorithms_test import TestAlgorithms
from pathlib import Path
import yaml

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root)+"/osm_data_processing")

def load_binary_data(file_name):
    binary_path = root / "binary_dump"
    with open(binary_path/file_name, "rb") as f:
        data = pickle.load(f)
    return data

def save_binary_data(data, file_name):
    binary_path = root / "binary_dump"
    with open(binary_path/file_name, "wb") as f:
        pickle.dump(data, f)

def main(test = True):

    print("\n"+__file__+ " start!!")

    # yaml
    with open("config_test.yaml", "r") as f:
        config = yaml.safe_load(f)
        input_binary_file = config["input_binary_file"]
        output_binary_file = config["output_binary_file"]
        test_algorithms = config["test_algorithms"]
        thread_enable = config["thread_enable"]


    # load data
    test_data = load_binary_data(input_binary_file)
    data = test_data["data"]
    start = data["start"]
    goal = data["goal"]
    waypoints = [(45.235309, 14.577240),(45.240601, 14.592553),(45.223621, 14.606432)] #, (45.205115, 14.623724), (45.188642, 14.634578), (45.164687, 14.637477), (45.153386, 14.603332)]
    zones_dictionary = data["zones_dictionary"]
    #zones_dictionary = data["zones_dictionary"]
    grid_size = 10.0

    test_algorithms = TestAlgorithms(waypoints,zones_dictionary,grid_size,test_algorithms, thread_enable)
    #test_algorithms.costmap_visualization()
    test_algorithms.test_algorithms_path()
    optimized_data = test_algorithms.optimize_path()

    save_binary_data(test_data, output_binary_file)
    test_algorithms.path_visualization()

    sys.exit(0)

if __name__ == '__main__':
    try:
        main(True)
    except KeyboardInterrupt:
        sys.exit(0)
