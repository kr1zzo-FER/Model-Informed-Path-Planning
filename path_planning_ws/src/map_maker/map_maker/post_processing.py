"""

Post processing module

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""


from matplotlib import pyplot as plt
import numpy as np
import math

class PostProcessing:

    def __init__(self, coast_points, red_zone, yellow_zone, green_zone,safe_zone, grid_size):
        self.coast_points = coast_points
        self.red_zone = red_zone
        self.yellow_zone = yellow_zone
        self.green_zone = green_zone
        self.grid_size = grid_size
        self.safe_zone = safe_zone
        self.coordinates = self.set_coordinates()
        self.size_x = self.set_width()
        self.size_y = self.set_height()
        self.size = (self.size_x, self.size_y)
        self.internal_coast = self.allign_coordinates(coast_points)
        self.internal_red = self.allign_coordinates(red_zone)
        self.internal_yellow = self.allign_coordinates(yellow_zone)
        self.internal_green = self.allign_coordinates(green_zone)
        self.internal_safe = self.allign_coordinates(safe_zone)

    def get_coordinates(self):
        internal_coast = self.internal_coast
        internal_red = []
        internal_yellow = []
        internal_green = []
        internal_safe = []

        for point in self.internal_red:
            if point not in internal_coast:
                internal_red.append(point)
        for point in self.internal_yellow:
            if point not in internal_coast and point not in internal_red:
                internal_yellow.append(point)
        for point in self.internal_green:
            if point not in internal_coast and point not in internal_red and point not in internal_yellow:
                internal_green.append(point)
        for point in self.internal_safe:
            if point not in internal_coast and point not in internal_red and point not in internal_yellow and point not in internal_green:
                internal_safe.append(point)
        
        return internal_coast, internal_red, internal_yellow, internal_green, internal_safe
        
    
    def set_coordinates(self):

        coordinates_list = self.coast_points + self.red_zone + self.yellow_zone + self.green_zone + self.safe_zone
        
        #min of the point[0] and point[1] for x and y
        min_x = min(coordinates_list, key = lambda x: x[0])[0]
        min_y = min(coordinates_list, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coordinates_list, key = lambda x: x[0])[0]
        max_y = max(coordinates_list, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        return result
    
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
    
    def set_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def set_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))
    
    def allign_coordinates(self, list):
        internal_coordinates = []
        for point in list:
            point_ = self.gps_to_pixel(point[0], point[1])
            if point_ not in internal_coordinates:
                internal_coordinates.append(point_)
        
        internal_coordinates_g = []
        for point in internal_coordinates:
            point_ = self.pixel_to_gps(point[0], point[1])
            internal_coordinates_g.append(point_)

        return internal_coordinates_g
    
    def allign_coordinate(self, latitude, longitude):
        x,y = self.gps_to_pixel(latitude, longitude) 
        x = round(x/self.grid_size)*self.grid_size
        y = round(y/self.grid_size)*self.grid_size
        return x,y
    
    def allign_coordnate_gps(self, x, y):   
        x,y = self.allign_coordinate(x,y)
        return self.pixel_to_gps(x,y)
    
    def set_start_goal(self):
        pass