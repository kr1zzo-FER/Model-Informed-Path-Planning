import pickle
from pathlib import Path
import matplotlib.pyplot as plt

root = Path(__file__).resolve().parents[1]

def main():
    with open(root/"binary_dump"/"path_parameters_gps_voz2", "rb") as f:
        parameters = pickle.load(f)
    with open(root/"binary_dump"/"osm_object_voz2", "rb") as f:
        osm_data = pickle.load(f)

    coast_points = parameters.get_coast_points()
    red_zone, yellow_zone, green_zone, zones_dictionary = parameters.get_zones()
    start = parameters.get_start()
    goal = parameters.get_goal()
    print("Start: ", start)

    start = osm_data.gps_to_pixel(start[0][0], start[0][1])
    goal = osm_data.gps_to_pixel(goal[0][0], goal[0][1])

    print("Start: ", start)

    image = osm_data.get_resized_image()

    # gps coordinates to pixels
    fig, ax = plt.subplots()
    

    im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])
   
    ax.plot(start[0], start[1], 'bo')
    ax.plot(goal[0], goal[1], 'bx')

    for point in coast_points:
        point = osm_data.gps_to_pixel(point[0], point[1])

        ax.plot(point[0], point[1], 'ro', markersize=0.1)
    
    for point in red_zone:
        point = osm_data.gps_to_pixel(point[0], point[1])

        ax.plot(point[0], point[1], 'ro', markersize=0.1)
    
    for point in yellow_zone:
        point = osm_data.gps_to_pixel(point[0], point[1])

        ax.plot(point[0], point[1], 'yo', markersize=0.1)
    
    for point in green_zone:
        point = osm_data.gps_to_pixel(point[0], point[1])

        ax.plot(point[0], point[1], 'go', markersize=0.1)

    plt.show()
    
if __name__ == "__main__":
    main()