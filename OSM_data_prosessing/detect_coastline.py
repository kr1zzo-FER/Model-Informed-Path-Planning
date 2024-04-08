
"""

Map generation script

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import matplotlib.pyplot as plt
import numpy as np
import cv2
from pathlib import Path
from PIL import Image
from skimage import io, measure
from scipy import ndimage as nd
import pickle
from matplotlib.backend_bases import MouseButton
import sys
import time

def detect_coast(image_path,x,y):

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
        return True
    return False



def detect_edges(image_path, binary_path, grid_size):

    global image
    global x,y

    image = io.imread(image_path)


    image1 = Image.open(image_path)

    global hsv
    hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)


    lower_blue = np.array([80, 60,60])
    upper_blue = np.array([120, 255, 255])


    global mask
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    mask = nd.binary_closing(mask, structure=np.ones((7,7)))
    h,w = mask.shape
    
    px = mask

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

    
    # save obstacles to binary files
    with open(binary_path/"coast_points", "wb") as f:
        pickle.dump(coast_points, f)
    with open(binary_path/"dimensions", "wb") as f:
        pickle.dump((x_width, y_width), f)

    return coast_points

