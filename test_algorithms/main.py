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
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        test_algorithms = config["test_algorithms"]
        thread_enable = config["thread_enable"]
        location_folder = config["location_folder"]
    
    input_binary_file = f'test_param_publisher_{location_folder}'
    output_binary_file = f'test_results_{location_folder}'

    # load data
    test_data = load_binary_data(input_binary_file)
    data = test_data["data"]
    start = data["start"]
    goal = data["goal"]
    coast_points = data["coast_points"]
    grid_size = data["grid_size"]

    test_algorithms = TestAlgorithms(start,goal,coast_points,grid_size, test_algorithms, thread_enable)
    test_algorithms.test_algorithms_path()
    publish_data = test_algorithms.get_publish_data()

    test_data["results"] = publish_data

    save_binary_data(test_data, output_binary_file)
    test_algorithms.path_visualization()

    sys.exit(0)

if __name__ == '__main__':
    try:
        main(True)
    except KeyboardInterrupt:
        sys.exit(0)
