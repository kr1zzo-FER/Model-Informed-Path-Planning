
from pathlib import Path
import pickle
import yaml
from algorithm_class import Algorithms
import math
import sys

root = Path(__file__).resolve().parents[1]

def euclidean_distance(x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)

def calculate_arrival_time():
    
    redx , redy = [], []
    yellowx, yellowy = [], []
    greenx, greeny = [], []
    rx_dstar_lite, ry_dstar_lite = [], []

    global root
    binary_path = root / "binary_dump"
    results = root / "results"
    
    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        max_boat_speed = config["max_boat_speed"]
        red_speed = config["red_speed"]
        yellow_speed = config["yellow_speed"]
        green_speed = config["green_speed"]
        grid_size = config["grid_size"]

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
    with open(binary_path/"d_star_lite_advanced_path_x", "rb") as f:
        rx = pickle.load(f)
    with open(binary_path/"d_star_lite_advanced_path_y", "rb") as f:
        ry = pickle.load(f)
    
    # Convert speed from knots to m/s
    red_speed_ms = red_speed * 1.852 * 0.27777777777778 
    yellow_speed_ms= yellow_speed * 1.852 * 0.27777777777778
    green_speed_ms = green_speed * 1.852 * 0.27777777777778 

    #global_distance = round(sum([euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)

    global_path = []

    for rx_, ry_ in zip(rx, ry):
        global_path.append((round(rx_), round(ry_)))
    
    red_path = []
    yellow_path = []
    green_path = []
    
    for element in global_path:
        print(element)

    for element in red_zone:
        red_path.append((round(element[0]), round(element[1])))
    for element in yellow_zone:
        yellow_path.append((round(element[0]), round(element[1])))
    for element in green_zone:
        green_path.append((round(element[0]), round(element[1])))
    
    arrival_time = 0

    print(f"len(global_path): {len(global_path)}")
    print(f"len(red_path): {len(red_path)}")
    print(f"len(yellow_path): {len(yellow_path)}")
    print(f"len(green_path): {len(green_path)}")
    


    for i, path in enumerate(global_path):
        try:
            next_path = global_path[i+1]
            distance = euclidean_distance(path[0], path[1], next_path[0], next_path[1])
            for element in green_path:
                if path == element:
                    print(f"Green path: {path}")
            for element in yellow_path:
                if path[1] == element[1]:
                    print(f"Yellow path: {path}")
            if path in red_path:
                print(path, next_path, distance)
                time = distance / red_speed_ms
                arrival_time += time
            elif path in yellow_path:
                print(path, next_path, distance)
                time = distance / yellow_speed_ms
                arrival_time += time
            elif path in green_path:
                time = distance / green_speed_ms
                arrival_time += time
            else:
                time = distance / max_boat_speed
                arrival_time += time
        except IndexError:
            continue
  
    print(f"Arrival time: {arrival_time}")

if __name__ == '__main__':
    try:
        calculate_arrival_time()
    except KeyboardInterrupt:
        sys.exit(0)
