import pickle
from pathlib import Path
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.lines import Line2D

root = Path(__file__).resolve().parents[1]

def main():
    with open(root/"binary_dump"/"osm_object_voz2", "rb") as f:
        osm_data = pickle.load(f)
    with open(root/"binary_dump"/f"coast_points_tested_voz2", "rb") as f:
        coast_points_tested = pickle.load(f)
    with open(root/"binary_dump"/f"paths_points_tested_voz2", "rb") as f:
        tested_algorithms = pickle.load(f)
        
    #coast_points = parameters.get_coast_points()
    #red_zone, yellow_zone, green_zone, zones_dictionary = parameters.get_zones()
    #start = parameters.get_start()
    #goal = parameters.get_goal()
    #start = osm_data.gps_to_pixel(start[0][0], start[0][1])
    #goal = osm_data.gps_to_pixel(goal[0][0], goal[0][1])

    #print("Start: ", start)

    image = osm_data.get_resized_image()

    # gps coordinates to pixels
    fig, ax = osm_data.prepare_image_to_plot()

    print(osm_data.get_coordinates())
    legend_elements = []
    colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']
    #ax.plot(start[0], start[1], 'bo')
    #ax.plot(goal[0], goal[1], 'bx')

    for point in coast_points_tested:
        point = osm_data.gps_to_pixel(point[0], point[1])

        ax.plot(point[0], point[1], 'ro', markersize=1)
    
    test = True
    if test:
        for element in tested_algorithms:
                random_color = colors[np.random.randint(0, len(colors))]
                rx,ry = [], []
                for point in element[2]:
                    print(point)
                    rx_gps, ry_gps = osm_data.gps_to_pixel(point[0], point[1])
                    rx.append(rx_gps)
                    ry.append(ry_gps)
                ax.plot(rx, ry, color=random_color, linewidth=2)
                legend_elements.append(Line2D([0], [0], color=random_color, lw=4, label=element[0]))
                #remove random color from colors list
                colors.remove(random_color)

    plt.show()
    
if __name__ == "__main__":
    main()