"""

Program for path planning algorithms testing

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math


class AlgorithmBase():

    def __init__(self,gps_data):
        self.coast_points = gps_data.get_coast_points()
        self.start = gps_data.get_start()
        self.goal = gps_data.get_goal()
        self.grid_size = gps_data.get_grid_size()
        self.coordinates = self.get_coordinates()
        self.size_x = self.get_width()
        self.size_y = self.get_height()
        self.size = (self.size_x, self.size_y)
        self.coast_points_m = self.get_coast_points_m()
        self.start_m = self.get_start_m()
        self.goal_m = self.get_goal_m()
    
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
    
    def get_coordinates(self):
        
        #min of the point[0] and point[1] for x and y
        min_x = min(self.coast_points, key = lambda x: x[0])[0]
        min_y = min(self.coast_points, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(self.coast_points, key = lambda x: x[0])[0]
        max_y = max(self.coast_points, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        print(result)
        return result

    def get_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def get_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))

    def get_start_m(self):
        return self.gps_to_pixel(self.start[0][0], self.start[0][1])

    def get_goal_m(self):
        return self.gps_to_pixel(self.goal[0][0], self.goal[0][1])

    def get_coast_points_m(self):
        return [self.gps_to_pixel(point[0], point[1]) for point in self.coast_points]
    
    def get_coast_points_gps(self):
        return [self.pixel_to_gps(point[0], point[1]) for point in self.coast_points_m]
    
    

