import pickle
from pathlib import Path
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.lines import Line2D
import yaml
import sys

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root)+"/test_algorithms")

def main():

    with open(root/"test_algorithms"/"config_test.yaml", "r") as f:
        config = yaml.safe_load(f)
        input_binary_file = config["input_binary_file"]
        output_binary_file = config["output_binary_file"]
        osm_object = config["osm_object"]

    with open(root/"binary_dump"/osm_object, "rb") as f:
        osm_data = pickle.load(f)
    
    with open(root/"binary_dump"/output_binary_file, "rb") as f:
        results = pickle.load(f)

    # gps coordinates to pixels
    fig, ax = osm_data.prepare_image_to_plot()

    data = results["data"]
    coast_points = data["coast_points"]
    for point in coast_points:
        point = osm_data.gps_to_pixel(point[0], point[1])
        ax.plot(point[0], point[1], 'ro', markersize=1)
    start_ = data["start"]
    goal_ = data["goal"]
    start = osm_data.gps_to_pixel(start_[0][0], start_[0][1])
    goal = osm_data.gps_to_pixel(goal_[0][0], goal_[0][1])
    ax.plot(start[0], start[1], 'go', markersize=5)
    ax.plot(goal[0], goal[1], 'bo', markersize=5)
    legend_elements.append(Line2D([0], [0], marker='o', color='w', label=f'Start : {start_[0][0], start_[0][1]}', markerfacecolor='g', markersize=10))
    legend_elements.append(Line2D([0], [0], marker='o', color='w', label=f'Goal : {goal_[0][0], goal_[0][1]}', markerfacecolor='b', markersize=10))


    

    print(osm_data.get_coordinates())
    legend_elements = []
    colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']

    
    
    algorithm = results[0]
   
   
    
    for algorithm in tested_algorithms:
        random_color = colors[np.random.randint(0, len(colors))]
        path = algorithm.get_path()
        path = [osm_data.gps_to_pixel(point[0], point[1]) for point in path]
        rx, ry = [], []
        for point in path:
            rx.append(point[0])
            ry.append(point[1])
        ax.plot(rx, ry, color=random_color, linewidth=2)
        legend_elements.append(Line2D([0], [0], color=random_color, lw=4, label=algorithm.get_algorithm_name()))
        colors.remove(random_color)

    plt.legend(handles=legend_elements, loc='upper right')
    plt.draw()
    plt.grid(True)
    plt.show()

    sys.exit(0)
    
if __name__ == "__main__":
    main()