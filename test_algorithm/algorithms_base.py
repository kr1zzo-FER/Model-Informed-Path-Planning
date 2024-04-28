"""

Program for path planning algorithms testing

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from sys import maxsize
from PIL import Image
import multiprocessing as mp 
import time
import gc
import itertools
import math
from matplotlib import pyplot as plt
from matplotlib.lines import Line2D
import numpy as np

points_viusalization_param = True


class AlgorithmBase():

    def __init__(self, start, goal, coast_points, thread_enable, binary_path,test_algorithms):
        self.coordinates = self.get_coordinates(coast_points)
        self.size_x = self.get_width()
        self.size_y = self.get_height()
        self.size = (self.size_x, self.size_y)
        self.grid_size = self.get_grid_size(coast_points)
        self.robot_radius = self.grid_size/2
        self.start = start
        self.goal = goal
        self.coast_points = coast_points
        self.start_m = self.get_start_m(start)
        self.goal_m = self.get_goal_m(goal)
        self.coast_points_m = self.get_coast_points_m(coast_points)
        self.test_algorithms = test_algorithms
        self.thread_enable = thread_enable
        self.binary_path = binary_path
    
    def gps_to_meters(self,lat1, lon1, lat2, lon2):
        # Convert gps cordinates to meters from (lat1,lon1) to (lat2,lon2)
        R = 6378.137 # Radius of earth in KM
        dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
        dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
        a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
        d = R * c
        return d * 1000 # meters
    
    def gps_to_pixel(self,latitude, longitude):
        # Convert gps coordinates to pixel coordinates
        #print(f"Coordinates gps_to_pixel: {self.coordinates}")
        x_pixel = int(round((longitude - self.coordinates[0]) * self.size_x / (self.coordinates[2] - self.coordinates[0])))
        y_pixel = int(round((latitude - self.coordinates[1]) * self.size_y / (self.coordinates[3] - self.coordinates[1])))
        x_pixel = round(x_pixel/self.grid_size)*self.grid_size
        y_pixel = round(y_pixel/self.grid_size)*self.grid_size
        return x_pixel, y_pixel
    
    def pixel_to_gps(self,x_pixel, y_pixel):
        # Convert pixel coordinates to gps coordinates
        latitude = self.coordinates[1] + y_pixel * (self.coordinates[3] - self.coordinates[1]) / self.size_y
        longitude = self.coordinates[0] + x_pixel * (self.coordinates[2] - self.coordinates[0]) / self.size_x
        return latitude, longitude
    
    def get_coordinates(self, coast_points):
        
        #min of the point[0] and point[1] for x and y
        min_x = min(coast_points, key = lambda x: x[0])[0]
        min_y = min(coast_points, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coast_points, key = lambda x: x[0])[0]
        max_y = max(coast_points, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        print(result)
        return result

    def get_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def get_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))

    def get_start_m(self, start):
        return self.gps_to_pixel(start[0][0], start[0][1])

    def get_goal_m(self, goal):
        return self.gps_to_pixel(goal[0][0], goal[0][1])

    def get_coast_points_m(self, coast_points):
        return [self.gps_to_pixel(point[0], point[1]) for point in coast_points]
    
    def get_grid_size(self, coast_points):
        # x points without duplicates
        grid_size = 10
        return grid_size
    
    def get_coast_points_gps(self):
        return [self.pixel_to_gps(point[0], point[1]) for point in self.coast_points_m]
    
    

