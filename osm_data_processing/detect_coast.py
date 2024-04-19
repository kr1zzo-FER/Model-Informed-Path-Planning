
"""

Functions for detecting coast and coastline

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import matplotlib.pyplot as plt
import numpy as np
import cv2
from PIL import Image
from skimage import io
from scipy import ndimage as nd
from math import sqrt, cos, sin, pi
import time

show_mask = False

def detect_coast(image_path,x,y):
    # detect coast or sea at given point (x,y) on image
    try:
        image = io.imread(image_path)

        hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)

        lower_blue = np.array([80, 60,60])
        upper_blue = np.array([120, 255, 255])

        global mask
        mask = cv2.inRange(hsv, lower_blue, upper_blue)
        ox, oy = [], []

        if mask is None:
            raise ValueError("Image mask not set")
        if x < 0 or x >= mask.shape[1] or y < 0 or y >= mask.shape[0]:
            return False
        h,w = mask.shape
        y = h - y
        if mask[y,x] == 0:
            # if coast return True
            return True
        return False
    except:
        return False
    

def detect_coastline(image_path, grid_size):

    print("Detecting coastline points...")

    # load image
    image = io.imread(image_path)
    image1 = Image.open(image_path)

    # convert image to hsv
    hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)

    # define blue color range and create mask
    lower_blue = np.array([80, 60,60])
    upper_blue = np.array([120, 255, 255])
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    # apply morphological operations to mask
    mask = nd.binary_closing(mask, structure=np.ones((10,10)))

    if show_mask:
        plt.imshow(mask)
        plt.show()

    # Detect coastline points - points where the values in the mask changes from 1 to 0
    px = mask

    h,w = mask.shape

    x_width = int(w/grid_size)
    y_width = int(h/grid_size)
    
    directions = [(0,1), (1,0), (0,-1), (-1,0), (1,1), (-1,-1), (1,-1), (-1,1)]

    coast_points = []

    for i in range(0, x_width-1):
        for j in range(0, y_width-1):

            pixel_i = i*grid_size
            pixel_j = j*grid_size

            try:
                for k in directions:
                    k1 = k[0]
                    k2 = k[1]
                    if px[pixel_j, pixel_i] != px[(j+k2)*grid_size, (i+k1)*grid_size]:
                        if [pixel_i, h-pixel_j] not in coast_points:
                            coast_points.append([pixel_i, h-pixel_j])

            except:
                pass     

    return coast_points, (image1.size[0], image1.size[1])

def zones_from_coast(coast_points, image_path, grid_size):
    print("\nGenerating zones from coast, it may take a while...\n")
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
    
    end_time = time.time()
    print(f"Zones generated in {round(end_time-start_time,4)} seconds")

    print(f"Red zone: {len(red_zone)} points\nYellow zone: {len(yellow_zone)} points\nGreen zone: {len(green_zone)} points")

    return red_zone, yellow_zone, green_zone