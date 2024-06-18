
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

show_results = False
show_mask = False
show_image = False
shoe_image_gps = False

class CoastProcessing:

    def __init__(self, image_path, grid_size, osm_object):
        self.image_path = image_path
        self.grid_size = int(grid_size)
        self.image, self.image1 = self.set_image(image_path)
        self.mask = self.set_mask()
        self.osm_object = osm_object    
        self.coast_points = []
        self.red_zone = []
        self.yellow_zone = []
        self.green_zone = []
        self.safe_zone = []
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
        mask0 = nd.binary_closing(mask, structure=np.ones((12,12)))

        return mask0


    def get_zones(self):
        return self.coast_points,self.red_zone, self.yellow_zone, self.green_zone

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

        x_width = round(w/self.grid_size)
        y_width = round(h/self.grid_size)
        
        directions = [(0,1), (1,0), (0,-1), (-1,0), (1,1), (-1,-1), (1,-1), (-1,1)]

        coast_points = []

        for i in range(5, x_width-5):
            for j in range(5, y_width-5):

                pixel_i = i*self.grid_size
                pixel_j = j*self.grid_size
                for k in directions:
                    try:
                        k1 = k[0]
                        k2 = k[1]                        
                        if mask[pixel_j, pixel_i] != mask[(j+k2)*self.grid_size, (i+k1)*self.grid_size]:
                            if [pixel_i, h-pixel_j] not in coast_points:
                                coast_points.append([pixel_i, h-pixel_j])

                    except Exception as e:
                        pass
                
        self.coast_points = coast_points

        print(f"Detected {len(coast_points)} coastline points")

        return coast_points


    def zones_from_coast(self, n):
        print("Generating zones from coast, it may take a while")

        coast_points = self.detect_coastline()
        
        start_time = time.time()
        red_zone = []
        yellow_zone = []
        green_zone = []


        h,w = self.mask.shape

        directions = [(cos(2*pi/n*i),sin(2*pi/n*i)) for i in range(n)]

        print("Detecting red zone points")
        for point in coast_points:
            for i in range(1, 6):
                red_distance = i*self.grid_size
                red_directions = [(round(direction[0]/self.grid_size*red_distance)*self.grid_size,round(direction[1]/self.grid_size*red_distance)*self.grid_size) for direction in directions]
                red_directions.append((1,0))
                red_directions.append((0,1))
                for direction in red_directions:
                    
                    x = point[0] + direction[0]
                    y = point[1] + direction[1]

                    if x < 0 or x >= self.image1.size[0] or y < 0 or y >= self.image1.size[1] and h-y < 0 or h-y >= h:
                        continue
                    if [x,y] not in red_zone and not self.mask[h-y,x] == 0:
                        red_zone.append([x,y])

        print(f"Detected {len(red_zone)} red zone points")

        print("Detecting yellow zone points")
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
        print(f"Detected {len(yellow_zone)} yellow zone points")

        print("Detecting green zone points")
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
        print(f"Detected {len(green_zone)} green zone points")
    
        #detect safe zone
        print("Detecting safe zone points")
        for point in coast_points:
            for i in range(26,31):
                safe_distance = i*self.grid_size
                safe_directions = [(round(direction[0]/self.grid_size*safe_distance)*self.grid_size,round(direction[1]/self.grid_size*safe_distance)*self.grid_size) for direction in directions]
                safe_directions.append((1,0))
                safe_directions.append((-1,0))
                for direction in safe_directions:
                    try:
                        x = point[0] + direction[0]
                        y = point[1] + direction[1]
                    except:
                        print(point[0],point[1])
                        print(direction[0],direction[1])

                    if x < 0 or x >= self.image1.size[0] or y < 0 or y >= self.image1.size[1] and h-y < 0 or h-y >= h:
                        continue
                    if [x,y] not in self.safe_zone and not self.mask[h-y,x] == 0 and [x,y] not in red_zone and [x,y] not in yellow_zone and [x,y] not in green_zone:
                        self.safe_zone.append([x,y])
        print(f"Detected {len(self.safe_zone)} safe zone points")

        
        end_time = time.time()
        print(f"Zones generated in {round(end_time-start_time,4)} seconds")

        self.osm_object.set_coast_points(coast_points)

        # remove duplicates and points greather od lower than min max values
        n = 50
        coast_points = [point for point in coast_points if point[0] > n and point[0] < self.image1.size[0]-n and point[1] > n and point[1] < self.image1.size[1]-n]
        red_zone = [point for point in red_zone if point[0] > n and point[0] < self.image1.size[0]-n and point[1] > n and point[1] < self.image1.size[1]-n]
        yellow_zone = [point for point in yellow_zone if point[0] > n and point[0] < self.image1.size[0]-n and point[1] > n and point[1] < self.image1.size[1]-n]
        green_zone = [point for point in green_zone if point[0] > n and point[0] < self.image1.size[0]-n and point[1] > n and point[1] < self.image1.size[1]-n]
        safe_zone = [point for point in self.safe_zone if point[0] > n and point[0] < self.image1.size[0]-n and point[1] > n and point[1] < self.image1.size[1]-n]

        coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, safe_zone_gps = [], [], [], [], []

        for point in coast_points:
            p = self.osm_object.pixel_to_gps(point[0],point[1])
            if p not in coast_points_gps:
                coast_points_gps.append(p)
        for point in red_zone:
            p = self.osm_object.pixel_to_gps(point[0],point[1])
            if p not in red_zone_gps:
                red_zone_gps.append(p)
        for point in yellow_zone:
            p = self.osm_object.pixel_to_gps(point[0],point[1])
            if p not in yellow_zone_gps:
                yellow_zone_gps.append(p)
        for point in green_zone:
            p = self.osm_object.pixel_to_gps(point[0],point[1])
            if p not in green_zone_gps:
                green_zone_gps.append(p)
        for point in safe_zone:
            p = self.osm_object.pixel_to_gps(point[0],point[1])
            if p not in safe_zone_gps:
                safe_zone_gps.append(p)
        

        if show_results:
            
            if show_mask:
                plt.imshow(self.mask)
                plt.show()
            
            if show_image:
                fig,ax = plt.subplots()
                for point in coast_points:
                    ax.plot(point[0], point[1], 'o', color='blue', markersize=1)
                for point in red_zone:
                    ax.plot(point[0], point[1], 'o', color='red', markersize=0.1)
                for point in yellow_zone:
                    ax.plot(point[0], point[1], 'o', color='yellow', markersize=0.1)
                for point in green_zone:
                    ax.plot(point[0], point[1], 'o', color='green', markersize=0.1)
                for point in self.safe_zone:
                    ax.plot(point[0], point[1], 'o', color='black', markersize=0.1)
                ax.grid(True)
                plt.show()

            if shoe_image_gps:
                fig,ax = plt.subplots()
                for point in coast_points_gps:
                    ax.plot(point[1], point[0], 'o', color='blue', markersize=1)
                for point in red_zone_gps:
                    ax.plot(point[1], point[0], 'o', color='red', markersize=0.1)
                for point in yellow_zone_gps:
                    ax.plot(point[1], point[0], 'o', color='yellow', markersize=0.1)
                for point in green_zone_gps:
                    ax.plot(point[1], point[0], 'o', color='green', markersize=0.1)
                for point in safe_zone_gps:
                    ax.plot(point[1], point[0], 'o', color='black', markersize=0.1)
                ax.grid(True)
                ax.set_xlabel("Longitude")
                ax.set_ylabel("Latitude")
                plt.show()

        return coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, safe_zone_gps