
import math


def gps_to_meters(lat1, lon1, lat2, lon2):
    # Convert gps cordinates to meters from (lat1,lon1) to (lat2,lon2)
    R = 6378.137 # Radius of earth in KM
    dLat = lat2 * 3.141592653589793 / 180 - lat1 * 3.141592653589793 / 180
    dLon = lon2 * 3.141592653589793 / 180 - lon1 * 3.141592653589793 / 180
    a = (dLat/2) * (dLat/2) + math.cos(lat1 * 3.141592653589793 / 180) * math.cos(lat2 * 3.141592653589793 / 180) * (dLon/2) * (dLon/2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
    d = R * c * 1000
    print(d)
    return d 

def deg_to_dms(self,deg):
    # convert degrees to dms for plot format
    d = int(deg)
    md = abs(deg - d) * 60
    m = int(md)
    sd = round((md - m) * 60)
    format_string = f"{d}°{m}'{sd}\""
    return format_string

def main():
    d = gps_to_meters(50,0,150,0)
    print(d)

if __name__ == "__main__":
    main()