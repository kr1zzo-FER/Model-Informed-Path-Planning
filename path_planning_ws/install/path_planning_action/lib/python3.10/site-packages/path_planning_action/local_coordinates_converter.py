"""

Program for path planning algorithms testing

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math
import numpy as np
from numpy import uint8
import matplotlib.pyplot as plt

class LocalCoordinatesConverter():

    def __init__(self, zones_dictionary = {}, grid_size = 0.0):

        if not zones_dictionary:
            print("Zones dictionary is empty")
            return
        
        self.zones = zones_dictionary
        self.start = [0.0,0.0]
        self.goal = [0.0,0.0]
        self.goal_m = (0,0)
        self.start_m = (0,0)
        self.grid_size = grid_size
        self.coordinates = self.get_coordinates()
        self.size_x = self.set_width()
        self.size_y = self.set_height()
        self.size = (self.size_x, self.size_y)
        self.zones_m_plot, self.zones_m = self.set_zones_m()


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

    def gps_to_pixel_m(self,latitude, longitude):
        # Convert gps coordinates to pixel coordinates
        x_pixel = int(round((longitude - self.coordinates[0]) * self.size_x / (self.coordinates[2] - self.coordinates[0])))
        y_pixel = int(round((latitude - self.coordinates[1]) * self.size_y / (self.coordinates[3] - self.coordinates[1])))
        return x_pixel, y_pixel
    
    def pixel_to_gps(self,x_pixel, y_pixel):
        # Convert pixel coordinates to gps coordinates
        x_pixel = round(x_pixel/self.grid_size)*self.grid_size
        y_pixel = round(y_pixel/self.grid_size)*self.grid_size
        latitude = self.coordinates[1] + y_pixel * (self.coordinates[3] - self.coordinates[1]) / self.size_y
        longitude = self.coordinates[0] + x_pixel * (self.coordinates[2] - self.coordinates[0]) / self.size_x
        return latitude, longitude
    
    def get_coordinates(self):

        coordinates_list = self.zones.keys()
        
        #min of the point[0] and point[1] for x and y
        min_x = min(coordinates_list, key = lambda x: x[0])[0]
        min_y = min(coordinates_list, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coordinates_list, key = lambda x: x[0])[0]
        max_y = max(coordinates_list, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        print(f"Coordinates: {result}")
        return result

    def adapt_coordinates(self,coord):
        # Adapt coordinates to the grid size
        new_coord = self.gps_to_pixel(coord[0], coord[1])
        new_coord = (int(new_coord[0]/self.grid_size), int(new_coord[1]/self.grid_size))
        return new_coord
    
    def set_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def set_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))
    
    def get_points_m(self):
        coast_points_m = []
        red_points_m = []
        yellow_points_m = []
        green_points_m = []
        for key, value in self.zones_m.items():
            if value == 'c':
                coast_points_m.append(key)
            if value == 'r':
                red_points_m.append(key)
            if value == 'y':
                yellow_points_m.append(key)
            if value == 'g':
                green_points_m.append(key)
        return coast_points_m, red_points_m, yellow_points_m, green_points_m
    
    def set_start_goal(self,start,goal):   
        self.start = start
        self.goal = goal
        self.start_m, self.start_m_resized = self.set_start_m()
        self.goal_m, self.goal_m_resized = self.set_goal_m()
    
    
    def get_start_m(self):
        return self.start_m_resized
    
    def get_goal_m(self):
        return self.goal_m_resized
    
    def get_path_m(self,path): 
        print(f"Path: {path}") 
        path_m = []
        for point in path:
            path_cord = self.gps_to_pixel_m(point[0],point[1])
            path_m.append(path_cord)
        path_m = [(x/self.grid_size,y/self.grid_size) for x,y in path_m]
        return path_m

    def set_zones_m(self):
        gps_dictionary, gps_dictionary_resized = {}, {}
        for key in self.zones:
            new_key = self.gps_to_pixel(key[0],key[1])
            gps_dictionary[new_key] = self.zones[key]
            new_key = self.adapt_coordinates(key)
            gps_dictionary_resized[new_key] = self.zones[key]
        return gps_dictionary, gps_dictionary_resized
    
    def set_start_m(self):
        start_m = self.gps_to_pixel(self.start[0],self.start[1])
        start_m_resized = self.adapt_coordinates(self.start)
        return start_m, start_m_resized
    
    def set_goal_m(self):
        goal_m = self.gps_to_pixel(self.goal[0],self.goal[1])
        goal_m_resized = self.adapt_coordinates(self.goal)
        return goal_m,goal_m_resized

    
    
    def costmap_visualization(self):
        fig,ax = plt.subplots()
        for key, value in self.zones_m.items():
            if value == 'c':
                ax.plot(key[0],key[1],'bo', markersize=0.1)
            elif value == 'r':
                ax.plot(key[0],key[1],'ro', markersize=0.1)
            elif value == 'g':
                ax.plot(key[0],key[1],'go', markersize=0.1)
            elif value == 'y':
                ax.plot(key[0],key[1],'yo', markersize=0.1)
        plt.show()
        return
    
            

