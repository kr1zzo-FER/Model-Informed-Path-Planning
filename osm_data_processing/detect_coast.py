
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
        self.grid_size = int(grid_size)
        self.image, self.image1 = self.set_image(image_path)
        self.mask = self.set_mask()
        self.sea_coordinates = self.set_sea_coordinates()
        self.coast_points = []
        self.red_zone = []
        self.yellow_zone = []
        self.green_zone = []
        self.zones_dictionary = {}

    def set_image(self, image_path):
        image = io.imread(image_path)
        image1 = Image.open(image_path)
        return image, image1
    
    def set_mask(self):
        # convert image to hsv
        hsv = cv2.cvtColor(self.image, cv2.COLOR_RGB2HSV)

        # define blue color range and create mask
        lower_blue = np.array([80, 60,60])
        upper_blue = np.array([120, 255, 255])
        mask = cv2.inRange(hsv, lower_blue, upper_blue)

        # apply morphological operations to mask
        mask = nd.binary_closing(mask, structure=np.ones((12,12)))

        if show_mask:
            plt.imshow(mask)
            plt.show()

        return mask
    
    def set_sea_coordinates(self):

        mask = self.mask

        h,w = mask.shape

        x_width = int(w/self.grid_size)
        y_width = int(h/self.grid_size)
        
    

        sea_points = []
        for i in range(0, x_width-1):
            for j in range(0, y_width-1):

                pixel_i = i*self.grid_size
                pixel_j = j*self.grid_size

                try:
                    if mask[pixel_j, pixel_i] == 1:
                        sea_points.append([pixel_i, h-pixel_j])
                except:
                    pass
        
        if show_mask:
            fig, ax = plt.subplots()

            im = ax.imshow(self.image, extent=[0, self.image1.size[0], 0, self.image1.size[1]])
            for point in sea_points:
                ax.plot(point[0], point[1], 'o', color='blue')
            plt.show()
        
        return sea_points

    def get_zones(self):
        return self.coast_points,self.red_zone, self.yellow_zone, self.green_zone

    def get_sea_coordinates(self):  
        return self.sea_coordinates
   

    def detect_coast_points(self,x,y):
        # detect coast or sea at given point (x,y) on image
        try:
            ox, oy = [], []

            if self.mask is None:
                raise ValueError("Image mask not set")
            if x < 0 or x >= self.mask.shape[1] or y < 0 or y >= self.mask.shape[0]:
                return False
            h,w = self.mask.shape
            y = h - y
            if self.mask[y,x] == 0:
                # if coast return True
                return True
            return False
        except:
            return False
        

    def detect_coastline(self):

        mask = self.mask

        h,w = mask.shape

        x_width = int(w/self.grid_size)
        y_width = int(h/self.grid_size)
        
        directions = [(0,1), (1,0), (0,-1), (-1,0), (1,1), (-1,-1), (1,-1), (-1,1)]

        coast_points = []

        for i in range(10, x_width-10):
            for j in range(10, y_width-10):

                pixel_i = i*self.grid_size
                pixel_j = j*self.grid_size

                #print(pixel_i, pixel_j)
                for k in directions:
                    try:
                        k1 = k[0]
                        k2 = k[1]                        
                        if mask[pixel_j, pixel_i] != mask[(j+k2)*self.grid_size, (i+k1)*self.grid_size]:
                            if [pixel_i, h-pixel_j] not in coast_points:
                                coast_points.append([pixel_i, h-pixel_j])

                    except Exception as e:
                        #print(e)
                        pass
                
        self.coast_points = coast_points

        print(f"Detected {len(coast_points)} coastline points\n")

        return coast_points


    def zones_from_coast(self, n):
        print("\nGenerating zones from coast, it may take a while...\n")

        coast_points = self.detect_coastline()
        
        start_time = time.time()
        red_zone = []
        yellow_zone = []
        green_zone = []


        h,w = self.mask.shape

        directions = [(cos(2*pi/n*i),sin(2*pi/n*i)) for i in range(n)]

        print("Detecting red zone points...")
        for point in coast_points:
            for i in range(1, 6):
                red_distance = i*self.grid_size
                red_directions = [(round(direction[0]/self.grid_size*red_distance)*self.grid_size,round(direction[1]/self.grid_size*red_distance)*self.grid_size) for direction in directions]
                red_directions.append((1,0))
                red_directions.append((0,1))
                for direction in red_directions:
                    #print(point[0],point[1])
                    #print(direction[0],direction[1])
                    
                    x = point[0] + direction[0]
                    y = point[1] + direction[1]

                    if x < 0 or x >= self.image1.size[0] or y < 0 or y >= self.image1.size[1] and h-y < 0 or h-y >= h:
                        continue
                    if [x,y] not in red_zone and not self.mask[h-y,x] == 0:
                        red_zone.append([x,y])

        print(f"Detected {len(red_zone)} red zone point\n")

        print("Detecting yellow zone points...")
        for point in coast_points:
            for i in range(6, 16):
                yellow_distance = i*self.grid_size
                yellow_directions = [(round(direction[0]/self.grid_size*yellow_distance)*self.grid_size,round(direction[1]/self.grid_size*yellow_distance)*self.grid_size) for direction in directions]
                yellow_directions.append((1,0))
                yellow_directions.append((-1,0))
                for direction in yellow_directions:
                    
                    x = point[0] + direction[0]
                    y = point[1] + direction[1]

                    if x < 0 or x >= self.image1.size[0] or y < 0 or y >= self.image1.size[1] and h-y < 0 or h-y >= h:
                        continue
                    if [x,y] not in yellow_zone and not self.mask[h-y,x] == 0 and [x,y] not in red_zone:
                        yellow_zone.append([x,y])
        print(f"Detected {len(yellow_zone)} yellow zone points\n")

        print("Detecting green zone points...")
        for point in coast_points:
            for i in range(16, 26):
                green_distance = i*self.grid_size
                green_directions = [(round(direction[0]/self.grid_size*green_distance)*self.grid_size,round(direction[1]/self.grid_size*green_distance)*self.grid_size) for direction in directions]
                green_directions.append((1,0))
                green_directions.append((-1,0))
                for direction in green_directions:
                    try:
                        x = point[0] + direction[0]
                        y = point[1] + direction[1]
                    except:
                        print(point[0],point[1])
                        print(direction[0],direction[1])

                    if x < 0 or x >= self.image1.size[0] or y < 0 or y >= self.image1.size[1] and h-y < 0 or h-y >= h:
                        continue
                    if [x,y] not in green_zone and not self.mask[h-y,x] == 0 and [x,y] not in red_zone and [x,y] not in yellow_zone:
                        green_zone.append([x,y])
        print(f"Detected {len(green_zone)} green zone points\n")
        
        end_time = time.time()
        print(f"Zones generated in {round(end_time-start_time,4)} seconds")

        #make dictionary: cordinates are keys
        zones_dictionary = {}
        for point in red_zone:
            zones_dictionary[tuple(point)] = "r"
        for point in yellow_zone:
            zones_dictionary[tuple(point)] = "y"
        for point in green_zone:
            zones_dictionary[tuple(point)] = "g"
        for point in coast_points:
            zones_dictionary[tuple(point)] = "c"
        
        self.zones_dictionary = zones_dictionary

        return coast_points, red_zone, yellow_zone, green_zone