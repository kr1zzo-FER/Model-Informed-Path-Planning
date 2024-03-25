import filecmp
import os
import pickle
import math
from pathlib import Path

def gps_to_meters(lat1, lon1, lat2, lon2):
    #print(lat1, lon1, lat2, lon2)
    R = 6378.137 # Radius of earth in KM
    dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
    dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
    a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
    d = R * c
    return d * 1000 # meters

def main():

    with open('osm_info.txt', 'r') as file:
        data = file.read()

    #bbox=14.555339813232424%2C45.22261674445821%2C14.624004364013674%2C45.24912016648356&amp;

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

    #print(latlong)

    root = Path(".")

    binary_path = root / "binary_dump"

    with open(binary_path/"coordinates", "wb") as f:
        pickle.dump(latlong, f)
    
    image_width = gps_to_meters(float(latlong[1]), float(latlong[0]), float(latlong[1]), float(latlong[2]))

    image_height = gps_to_meters(float(latlong[1]), float(latlong[0]), float(latlong[3]), float(latlong[0]))

    #print(image_width, image_height)

    with open(binary_path/"image_width_height_m", "wb") as f:
        pickle.dump([image_width, image_height], f)

    




if __name__ == '__main__':
    main()