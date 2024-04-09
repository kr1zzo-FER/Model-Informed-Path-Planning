"""

Process OSM data and data conversion

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import filecmp
import os
import pickle
import math
from pathlib import Path

def pixel_to_meters(root,size_x, size_y):
        image_width_height_m = []
        binary_path = root / "binary_dump"
        isExist = os.path.exists(binary_path)
        if not isExist:
            os.makedirs(binary_path)
        with open(binary_path/"image_width_height_m", "rb") as f:
            image_width_height_m = pickle.load(f)

        factorx = image_width_height_m[0] / size_x
        factory = image_width_height_m[1] / size_y

        return factorx, factory

def gps_to_meters(lat1, lon1, lat2, lon2):
    #print(lat1, lon1, lat2, lon2)
    R = 6378.137 # Radius of earth in KM
    dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
    dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
    a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
    d = R * c
    return d * 1000 # meters

def deg_to_dms(deg):
    #print(deg)
    d = int(deg)
    md = abs(deg - d) * 60
    m = int(md)
    sd = round((md - m) * 60)
    format_string = f"{d}°{m}'{sd}\""
    #print(format_string)
    return format_string

def process_osm_data(binary_path, input_data) -> None:

    print("\nProcessing OSM data...\n")

    with open(input_data/'osm_info.txt', 'r') as file:
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

    with open(binary_path/"coordinates", "wb") as f:
        pickle.dump(latlong, f)

    with open(binary_path/"image_width_height_m", "wb") as f:
        pickle.dump([image_width, image_height], f)
    
    return latlong