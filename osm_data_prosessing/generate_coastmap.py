

import matplotlib.pyplot as plt
from PIL import Image
import pickle
from math import sqrt

def zones_from_coast(coast_points, image_path, mask, grid_size):
    red_zone = []
    red_border = []
    yellow_zone = []
    green_zone = []
    image = Image.open(image_path)
    h,w = mask.shape

    for point in coast_points:
        for i in range(1, 6):
            red_distance = i*grid_size
            red_directions = [(0,red_distance), (red_distance,0), (0,-red_distance), (-red_distance,0), (round(sqrt(2)/2/grid_size*red_distance)*grid_size,round(sqrt(2)/2/grid_size*red_distance)*grid_size), (-round(sqrt(2)/2/grid_size*red_distance)*grid_size,-round(sqrt(2)/2/grid_size*red_distance)*grid_size), (round(sqrt(2)/2/grid_size*red_distance)*grid_size,-round(sqrt(2)/2/grid_size*red_distance)*grid_size), (-round(sqrt(2)/2/grid_size*red_distance)*grid_size,round(sqrt(2)/2/grid_size*red_distance)*grid_size)]
            for direction in red_directions:
                
                x = point[0] + direction[0]
                y = point[1] + direction[1]

                if x < 0 or x >= image.size[0] or y < 0 or y >= image.size[1] and h-y < 0 or h-y >= h:
                    continue
                if [x,y] not in red_zone and not mask[h-y,x] == 0:
                    red_zone.append([x,y])
    for point in coast_points:
        for i in range(6, 16):
            yellow_distance = i*grid_size
            yellow_directions = [(0,yellow_distance), (yellow_distance,0), (0,-yellow_distance), (-yellow_distance,0), (round(sqrt(2)/2/grid_size*yellow_distance)*grid_size,round(sqrt(2)/2/grid_size*yellow_distance)*grid_size), (-round(sqrt(2)/2/grid_size*yellow_distance)*grid_size,-round(sqrt(2)/2/grid_size*yellow_distance)*grid_size), (round(sqrt(2)/2/grid_size*yellow_distance)*grid_size,-round(sqrt(2)/2/grid_size*yellow_distance)*grid_size), (-round(sqrt(2)/2/grid_size*yellow_distance)*grid_size,round(sqrt(2)/2/grid_size*yellow_distance)*grid_size)]
            for direction in yellow_directions:
                
                x = point[0] + direction[0]
                y = point[1] + direction[1]

                if x < 0 or x >= image.size[0] or y < 0 or y >= image.size[1] and h-y < 0 or h-y >= h:
                    continue
                if [x,y] not in yellow_zone and not mask[h-y,x] == 0 and [x,y] not in red_zone:
                    yellow_zone.append([x,y])

    for point in coast_points:
        for i in range(16, 26):
            green_distance = i*grid_size
            green_directions = [(0,green_distance), (green_distance,0), (0,-green_distance), (-green_distance,0), 
                                (round(sqrt(2)/2/grid_size*green_distance)*grid_size,round(sqrt(2)/2/grid_size*green_distance)*grid_size), (-round(sqrt(2)/2/grid_size*green_distance)*grid_size,-round(sqrt(2)/2/grid_size*green_distance)*grid_size), (round(sqrt(2)/2/grid_size*green_distance)*grid_size,-round(sqrt(2)/2/grid_size*green_distance)*grid_size), 
                                (-round(sqrt(2)/2/grid_size*green_distance)*grid_size,round(sqrt(2)/2/grid_size*green_distance)*grid_size), (round)]
            for direction in green_directions:
                
                x = point[0] + direction[0]
                y = point[1] + direction[1]

                if x < 0 or x >= image.size[0] or y < 0 or y >= image.size[1] and h-y < 0 or h-y >= h:
                    continue
                if [x,y] not in green_zone and not mask[h-y,x] == 0 and [x,y] not in red_zone and [x,y] not in yellow_zone:
                    green_zone.append([x,y])
    
    
    fig, ax = plt.subplots()

    im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])

    for point in red_zone:
        ax.plot(point[0],point[1],".r", markersize=1)
    for point in coast_points:
        ax.plot(point[0],point[1],".b", markersize=1)
    for point in yellow_zone:
        ax.plot(point[0],point[1],".y", markersize=1)
    for point in green_zone:
        ax.plot(point[0],point[1],".g", markersize=1)
    plt.show()