"""

Program for generating costmap

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import matplotlib.pyplot as plt
from PIL import Image
import pickle
from math import sqrt
from skimage import io
import numpy as np
import cv2
from scipy import ndimage as nd

def zones_from_coast(coast_points,results_name, image_path, binary_path,grid_size):
    print("\nGenerating zones from coast")

    red_zone = []
    yellow_zone = []
    green_zone = []
    image = Image.open(image_path)

    image1 = io.imread(image_path)

    hsv = cv2.cvtColor(image1, cv2.COLOR_RGB2HSV)

    lower_blue = np.array([80, 60,60])
    upper_blue = np.array([120, 255, 255])

    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    mask = nd.binary_closing(mask, structure=np.ones((7,7)))

    h,w = mask.shape

    for point in coast_points:
        for i in range(1, 6):
            red_distance = i*grid_size
            red_directions = [(0,red_distance), (red_distance,0), (0,-red_distance), (-red_distance,0), (round(sqrt(2)/2/grid_size*red_distance)*grid_size,round(sqrt(2)/2/grid_size*red_distance)*grid_size), (-round(sqrt(2)/2/grid_size*red_distance)*grid_size,-round(sqrt(2)/2/grid_size*red_distance)*grid_size), (round(sqrt(2)/2/grid_size*red_distance)*grid_size,-round(sqrt(2)/2/grid_size*red_distance)*grid_size), (-round(sqrt(2)/2/grid_size*red_distance)*grid_size,round(sqrt(2)/2/grid_size*red_distance)*grid_size)]
            for direction in red_directions:
                #print(point[0],point[1])
                #print(direction[0],direction[1])
                
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
            green_directions = [(0,green_distance), (green_distance,0), (0,-green_distance), (-green_distance,0), (round(sqrt(2)/2/grid_size*green_distance)*grid_size,round(sqrt(2)/2/grid_size*green_distance)*grid_size), (-round(sqrt(2)/2/grid_size*green_distance)*grid_size,-round(sqrt(2)/2/grid_size*green_distance)*grid_size), (round(sqrt(2)/2/grid_size*green_distance)*grid_size,-round(sqrt(2)/2/grid_size*green_distance)*grid_size), (-round(sqrt(2)/2/grid_size*green_distance)*grid_size,round(sqrt(2)/2/grid_size*green_distance)*grid_size)]
            for direction in green_directions:
                try:
                    x = point[0] + direction[0]
                    y = point[1] + direction[1]
                except:
                    print(point[0],point[1])
                    print(direction[0],direction[1])

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
    #save image
    plt.savefig(results_name)
    plt.show()
    #save zones to binary files
    with open(binary_path/"red_zone", "wb") as f:
        pickle.dump(red_zone, f)
    with open(binary_path/"yellow_zone", "wb") as f:
        pickle.dump(yellow_zone, f)
    with open(binary_path/"green_zone", "wb") as f:
        pickle.dump(green_zone, f)