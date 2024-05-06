

import sys
import pickle
from pathlib import Path
import yaml
from matplotlib import pyplot as plt

root = Path(__file__).resolve().parents[1]
binary_path = root / "binary_dump"
sys.path.insert(0, str(root)+"/osm_data_processing")

def load_binary_data(file_name):
    
    with open(binary_path/file_name, "rb") as f:
        data = pickle.load(f)
    return data

def save_to_binary_file(data, file_name):
    with open(binary_path/file_name, "wb") as f:
        pickle.dump(data, f)

def main():

    with open("config.yaml", "r") as f:
        config = yaml.load(f, Loader=yaml.FullLoader)
        locations_folder = config["locations_folder"]
        grid_size = config["grid_size"]
        save_file = config["save_file"]

    test_dictionary = load_binary_data(f'processed_map_{save_file}')

    data = test_dictionary["data"]

    coast_points_gps = data["coast_points_gps"]
    red_zone_gps = data["red_zone_gps"]
    yellow_zone_gps = data["yellow_zone_gps"]
    green_zone_gps = data["green_zone_gps"]

    fig, ax = plt.subplots()

    cx,cy = [point[1] for point in coast_points_gps], [point[0] for point in coast_points_gps]
    ax.plot(cx, cy, 'co', label='coast points', markersize = 0.1)
    rx,ry = [point[1] for point in red_zone_gps], [point[0] for point in red_zone_gps]
    ax.plot(rx, ry, 'ro', label='red zone', markersize = 0.1)
    yx,yy = [point[1] for point in yellow_zone_gps], [point[0] for point in yellow_zone_gps]
    ax.plot(yx, yy, 'yo', label='yellow zone', markersize = 0.1)
    gx,gy = [point[1] for point in green_zone_gps], [point[0] for point in green_zone_gps]
    ax.plot(gx, gy, 'go', label='green zone', markersize = 0.1)

    plt.show()

    zones_dictionary = {}
    for point in red_zone_gps:
        zones_dictionary[tuple(point)] = "r"
    for point in yellow_zone_gps:
        zones_dictionary[tuple(point)] = "y"
    for point in green_zone_gps:
        zones_dictionary[tuple(point)] = "g"
    for point in coast_points_gps:
        zones_dictionary[tuple(point)] = "c"


    publish_dict = {}
    publish_dict["data"] = {}
    publish_dict["data"]["start"] = [(45.211981, 14.633187)]
    publish_dict["data"]["goal"] = [(45.235506, 14.576740)]
    publish_dict["data"]["zones_dictionary"] = zones_dictionary

    save_to_binary_file(publish_dict, f'publish_map_{save_file}')


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
