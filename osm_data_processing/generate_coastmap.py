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
from math import cos, sin, pi
import time

def zones_from_coast(coast_points,results_name, image_path, binary_path,grid_size):
    print("\nGenerating zones from coast")
    start_time = time.time()
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

    n = 24


    directions = [(cos(2*pi/n*i),sin(2*pi/n*i)) for i in range(n)]

    for point in coast_points:
        for i in range(1, 6):
            red_distance = i*grid_size


            red_directions = [(round(direction[0]/grid_size*red_distance)*grid_size,round(direction[1]/grid_size*red_distance)*grid_size) for direction in directions]


            for direction in red_directions:
                #print(point[0],point[1])
                #print(direction[0],direction[1])
                
                x = point[0] + direction[0]
                y = point[1] + direction[1]

                if x < 0 or x >= image.size[0] or y < 0 or y >= image.size[1] and h-y < 0 or h-y >= h:
                    continue
                if [x,y] not in red_zone and not mask[h-y,x] == 0:
                    red_zone.append([x,y])
    print("Red zone done")

    for point in coast_points:
        for i in range(6, 16):
            yellow_distance = i*grid_size
            yellow_directions = [(round(direction[0]/grid_size*yellow_distance)*grid_size,round(direction[1]/grid_size*yellow_distance)*grid_size) for direction in directions]
            for direction in yellow_directions:
                
                x = point[0] + direction[0]
                y = point[1] + direction[1]

                if x < 0 or x >= image.size[0] or y < 0 or y >= image.size[1] and h-y < 0 or h-y >= h:
                    continue
                if [x,y] not in yellow_zone and not mask[h-y,x] == 0 and [x,y] not in red_zone:
                    yellow_zone.append([x,y])

    print("Yellow zone done")
    for point in coast_points:
        for i in range(16, 26):
            green_distance = i*grid_size
            green_directions = [(round(direction[0]/grid_size*green_distance)*grid_size,round(direction[1]/grid_size*green_distance)*grid_size) for direction in directions]
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
    print("Green zone done")

    
    #save zones to binary files
    with open(binary_path/"red_zone", "wb") as f:
        pickle.dump(red_zone, f)
    with open(binary_path/"yellow_zone", "wb") as f:
        pickle.dump(yellow_zone, f)
    with open(binary_path/"green_zone", "wb") as f:
        pickle.dump(green_zone, f)
    
    end_time = time.time()
    print(f"Zones generated in {round(end_time-start_time,4)} seconds")

    print(f"Red zone: {len(red_zone)} points\nYellow zone: {len(yellow_zone)} points\nGreen zone: {len(green_zone)} points")

    return red_zone, yellow_zone, green_zone