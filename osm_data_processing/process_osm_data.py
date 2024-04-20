"""

Process OSM data and data conversion

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

def gps_to_pixel(latitude, longitude ,coordinates, size_x, size_y, grid_size):
    # Convert gps coordinates to pixel coordinates
    x_pixel = int(round((longitude - coordinates[0]) * size_x / (coordinates[2] - coordinates[0])))
    y_pixel = int(round((latitude - coordinates[1]) * size_y / (coordinates[3] - coordinates[1])))
    x_pixel = round(x_pixel/grid_size)*grid_size
    y_pixel = round(y_pixel/grid_size)*grid_size
    return x_pixel, y_pixel

def gps_to_meters(lat1, lon1, lat2, lon2):
    # Convert gps cordinates to meters from (lat1,lon1) to (lat2,lon2)
    R = 6378.137 # Radius of earth in KM
    dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
    dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
    a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
    d = R * c
    return d * 1000 # meters

def deg_to_dms(deg):
    # convert degrees to dms for plot format
    d = int(deg)
    md = abs(deg - d) * 60
    m = int(md)
    sd = round((md - m) * 60)
    format_string = f"{d}°{m}'{sd}\""
    return format_string

def process_osm_data(text_file):
    # input : path to text file

    print("\nProcessing OSM data...\n")

    with open(text_file, 'r') as file:
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

    image_width = gps_to_meters(float(latlong[1]), float(latlong[0]), float(latlong[1]), float(latlong[2]))

    image_height = gps_to_meters(float(latlong[1]), float(latlong[0]), float(latlong[3]), float(latlong[0]))

    image_wh_meters = [int(image_width), int(image_height)]

    coordinates = [float(latlong[0]), float(latlong[1]), float(latlong[2]), float(latlong[3])]

    return coordinates, image_wh_meters

def resize_image(image_path, image_wh):
    # Resizes imageg to 1 pixel per 1 m^2
    image = Image.open(image_path)
    
    # pixels to meters
    factorx = image_wh[0] / image.size[0]
    factory = image_wh[1] / image.size[1]

    factorx = int(round(image.size[0]*factorx))
    factory = int(round(image.size[1]*factory))

    resized_image = image.resize((factorx, factory))

    return resized_image

def prepare_image_to_plot(image_path, coordinates, coast_points = []):
     
    # Prepare image for plotting
    image = Image.open(image_path)
    
    # plot image and detect start and goal positions

    fig, ax = plt.subplots()

    im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])

    size_x = image.size[0]
    size_y = image.size[1]

    coordinates = [round(float(coordinates[0]),6), round(float(coordinates[1]),6), round(float(coordinates[2]),6), round(float(coordinates[3]),6)]
    #print(coordinates[0])
    coordinates_plot_x = np.arange(coordinates[0], coordinates[2],0.005)
    coordinates_plot_x = np.append(coordinates_plot_x, coordinates[2])
    coordinates_plot_x = [deg_to_dms(i) for i in coordinates_plot_x]

    coordinates_plot_y = np.arange(coordinates[1], coordinates[3],0.005)
    coordinates_plot_y = np.append(coordinates_plot_y, coordinates[3])
    coordinates_plot_y = [deg_to_dms(i) for i in coordinates_plot_y]
    

    image_cordinates_x = np.arange(0, round(size_x), math.ceil(size_x/(len(coordinates_plot_x)-1)))
    image_cordinates_x = np.append(image_cordinates_x, size_x)

    factor_y = size_y/len(coordinates_plot_y)

    image_cordinates_y = np.arange(0, round(size_y), math.ceil(size_y/(len(coordinates_plot_y)-1)))
    image_cordinates_y = np.append(image_cordinates_y, size_y)

    plt.xticks(image_cordinates_x, coordinates_plot_x, rotation=90)
    plt.yticks(image_cordinates_y, coordinates_plot_y)
    
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.grid(True)
    
    for point in coast_points:
        ax.plot(point[0],point[1], 'bo', markersize=0.1)
    

    return fig, ax