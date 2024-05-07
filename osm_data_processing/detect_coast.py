
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

class CoastProcessing:

    def __init__(self, image_path, grid_size):
        self.image_path = image_path
        self.grid_size = grid_size
        self.image, self.image1 = self.get_image(image_path)
        self.coast_points = []

    def get_image(self, image_path):
        image = io.imread(image_path)
        image1 = Image.open(image_path)
        return image, image1

    def detect_coast_points(self,x,y):
        # detect coast or sea at given point (x,y) on image
        try:
            hsv = cv2.cvtColor(self.image, cv2.COLOR_RGB2HSV)

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
        

    def detect_coastline(self):

        print("Detecting coastline points...")
        

        # convert image to hsv
        hsv = cv2.cvtColor(self.image, cv2.COLOR_RGB2HSV)

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

        x_width = int(w/self.grid_size)
        y_width = int(h/self.grid_size)
        
        directions = [(0,1), (1,0), (0,-1), (-1,0), (1,1), (-1,-1), (1,-1), (-1,1)]

        coast_points = []

        for i in range(0, x_width-1):
            for j in range(0, y_width-1):

                pixel_i = i*self.grid_size
                pixel_j = j*self.grid_size

                try:
                    for k in directions:
                        k1 = k[0]
                        k2 = k[1]
                        if px[pixel_j, pixel_i] != px[(j+k2)*self.grid_size, (i+k1)*self.grid_size]:
                            if [pixel_i, h-pixel_j] not in coast_points:
                                coast_points.append([pixel_i, h-pixel_j])

                except:
                    pass     
        
        self.coast_points = coast_points

        print(f"Detected {len(coast_points)} coastline points\n")

        return coast_points, (self.image1.size[0], self.image1.size[1])

    