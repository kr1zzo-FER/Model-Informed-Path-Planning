"""

Process OSM data and data conversion

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt


class OSMProcessing:

    def __init__(self, text_file, grid_size, image_path):
        self.text_file = text_file
        self.grid_size = grid_size
        self.coordinates, self.image_wh_meters = self.process_osm_data()
        self.size_x = self.image_wh_meters[0]
        self.size_y = self.image_wh_meters[1]
        self.image_path = image_path
        self.original_image = Image.open(self.image_path)
        self.image = self.resize_image()
        self.coast_points = []

    def set_coast_points(self, coast_points):
        self.coast_points = coast_points

    def get_grid_size(self):
        return self.grid_size
    
    def get_osm_data(self):
        return self.coordinates, self.image_wh_meters, self.size_x, self.size_y
    
    def get_resized_image(self):
        return self.image
    
    def get_coordinates(self):  
        return self.coordinates
    
    def process_osm_data(self):
        # input : path to text file

        print("\nProcessing OSM data...\n")

        with open(self.text_file, 'r') as file:
            data = file.read()

        # initializing substrings
        sub1 = "bbox"
        sub2 = "&amp"
        
        # getting index of substrings
        idx1 = data.index(sub1)
        idx2 = data.index(sub2)
        
        res = ''
        # getting elements in between
        for idx in range(idx1 + len(sub1) + 1, idx2):
            res = res + data[idx]

        latlong = res.split("%2C")

        image_width = self.gps_to_meters(float(latlong[1]), float(latlong[0]), float(latlong[1]), float(latlong[2]))

        image_height = self.gps_to_meters(float(latlong[1]), float(latlong[0]), float(latlong[3]), float(latlong[0]))

        image_wh_meters = [int(image_width), int(image_height)]

        coordinates = [float(latlong[0]), float(latlong[1]), float(latlong[2]), float(latlong[3])]

        return coordinates, image_wh_meters

    def gps_to_pixel(self,latitude, longitude):
        # Convert gps coordinates to pixel coordinates
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

    def gps_to_meters(self,lat1, lon1, lat2, lon2):
        # Convert gps cordinates to meters from (lat1,lon1) to (lat2,lon2)
        R = 6378.137 # Radius of earth in KM
        dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
        dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
        a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
        d = R * c
        return d * 1000 # meters
    
    def deg_to_dms(self,deg):
        # convert degrees to dms for plot format
        d = int(deg)
        md = abs(deg - d) * 60
        m = int(md)
        sd = round((md - m) * 60)
        format_string = f"{d}°{m}'{sd}\""
        return format_string

    def resize_image(self):
        # Resizes imageg to 1 pixel per 1 m^2

        # pixels to meters
        factorx = self.size_x / self.original_image.size[0]
        factory = self.size_y / self.original_image.size[1]

        factorx = int(round(self.original_image.size[0]*factorx))
        factory = int(round(self.original_image.size[1]*factory))

        resized_image = self.original_image.resize((factorx, factory))

        return resized_image

    def prepare_image_to_plot(self):
        
        # plot image and detect start and goal positions
        size_x = self.image.size[0]
        size_y = self.image.size[1]

        fig, ax = plt.subplots(figsize=(size_x/2, size_y/2))    

        im = ax.imshow(self.image, extent=[0, self.image.size[0], 0, self.image.size[1]])

        

        coordinates = [round(float(self.coordinates[0]),6), round(float(self.coordinates[1]),6), round(float(self.coordinates[2]),6), round(float(self.coordinates[3]),6)]
        #print(coordinates[0])
        coordinates_plot_x = np.arange(coordinates[0], coordinates[2],0.005)
        coordinates_plot_x = np.append(coordinates_plot_x, coordinates[2])
        coordinates_plot_x = [self.deg_to_dms(i) for i in coordinates_plot_x]

        coordinates_plot_y = np.arange(coordinates[1], coordinates[3],0.005)
        coordinates_plot_y = np.append(coordinates_plot_y, coordinates[3])
        coordinates_plot_y = [self.deg_to_dms(i) for i in coordinates_plot_y]
        

        image_cordinates_x = np.arange(0, round(size_x), math.ceil(size_x/(len(coordinates_plot_x)-1)))
        image_cordinates_x = np.append(image_cordinates_x, size_x)

        image_cordinates_y = np.arange(0, round(size_y), math.ceil(size_y/(len(coordinates_plot_y)-1)))
        image_cordinates_y = np.append(image_cordinates_y, size_y)

        plt.xticks(image_cordinates_x, coordinates_plot_x, rotation=90)
        plt.yticks(image_cordinates_y, coordinates_plot_y)
        
        plt.xlabel("Longitude")
        plt.ylabel("Latitude")
        plt.grid(True)
        

        return fig, ax
    
    def prepare_coast_to_plot(self, ax):
        # plot coast points on image
        for point in self.coast_points:
            ax.plot(point[0],point[1], 'bo', markersize=0.1)
        return ax
