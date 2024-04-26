"""

Program for path planning algorithms testing

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from sys import maxsize
from PIL import Image
from algorithm_class import Algorithms 
import multiprocessing as mp 
import time
import gc
import itertools
import math
from matplotlib import pyplot as plt
from matplotlib.lines import Line2D
import numpy as np

points_viusalization_param = True

class TestAlgorithms(Algorithms):

    def __init__(self, start, goal, coast_points, thread_enable, binary_path,test_algorithms, red_zone = [], yellow_zone = [], green_zone = [], zones_dictionary = {}):
        self.coordinates = self.get_coordinates(coast_points)
        self.size_x = self.get_width()
        self.size_y = self.get_height()
        self.size = (self.size_x, self.size_y)
        print(self.size)
        self.grid_size = self.get_grid_size(coast_points)
        self.robot_radius = self.grid_size/2
        self.start_m = self.get_start_m(start, coast_points)
        self.goal_m = self.get_goal_m(goal, coast_points)
        self.coast_points_m = self.get_coast_points_m(coast_points)
        self.test_algorithms = test_algorithms
        self.thread_enable = thread_enable
        self.binary_path = binary_path
        self.tested_algorithms = []
        self.red_zone_m = self.get_red_zone_m(red_zone) if len(red_zone) > 0 else []
        for red in self.red_zone_m:
            if red[1]<0:
                print(red)
        self.yellow_zone_m = self.get_yellow_zone_m(yellow_zone) if len(yellow_zone) > 0 else []
        self.green_zone_m = self.get_green_zone_m(green_zone) if len(green_zone) > 0 else []
        self.zones_dictionary = self.get_zones_dictionary(zones_dictionary) if len(zones_dictionary) > 0 else {}
        super().__init__(self.start_m, self.goal_m, self.coast_points_m, self.grid_size, self.robot_radius, self.size, self.red_zone_m, self.yellow_zone_m, self.green_zone_m, self.zones_dictionary)
    
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
        if latitude - self.coordinates[1] < 0:
            print(latitude)
        x_pixel = int(round((longitude - self.coordinates[0]) * self.size_x / (self.coordinates[2] - self.coordinates[0])))
        y_pixel = int(round((latitude - self.coordinates[1]) * self.size_y / (self.coordinates[3] - self.coordinates[1])))
        x_pixel = round(x_pixel/self.grid_size)*self.grid_size
        y_pixel = round(y_pixel/self.grid_size)*self.grid_size
        return x_pixel, y_pixel
    
    def get_coordinates(self, coast_points):
        
        #min of the point[0] and point[1] for x and y
        min_x = min(coast_points, key = lambda x: x[0])[0]
        min_y = min(coast_points, key = lambda x: x[1])[1]

        #max of the point[0] and point[1] for x and y
        max_x = max(coast_points, key = lambda x: x[0])[0]
        max_y = max(coast_points, key = lambda x: x[1])[1]

        result = [min_y, min_x, max_y, max_x]
        return result

    def get_width(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[1], self.coordinates[2]))
    
    def get_height(self):
        return round(self.gps_to_meters(self.coordinates[1], self.coordinates[0], self.coordinates[3], self.coordinates[0]))

    def get_start_m(self, start, coast_points):
        return self.gps_to_pixel(start[0][0], start[0][1])

    def get_goal_m(self, goal, coast_points):
        return self.gps_to_pixel(goal[0][0], goal[0][1])

    def get_coast_points_m(self, coast_points):
        return [self.gps_to_pixel(point[0], point[1]) for point in coast_points]
    
    def get_grid_size(self, coast_points):
        # x points without duplicates
        grid_size = 10
        print(f"Grid size: {grid_size}")
        return grid_size
    
    def get_red_zone_m(self, red_zone):
        return [self.gps_to_pixel(point[0], point[1]) for point in red_zone]

    def get_yellow_zone_m(self, yellow_zone):
        return [self.gps_to_pixel(point[0], point[1]) for point in yellow_zone]
    
    def get_green_zone_m(self, green_zone):
        return [self.gps_to_pixel(point[0], point[1]) for point in green_zone]
    
    def get_zones_dictionary(self, zones_dictionary):
        return {self.gps_to_pixel(key[0], key[1]): value for key, value in zones_dictionary.items()}
    
    def test_algorithms_path(self):
        mp.set_start_method('spawn')
        queue = mp.Queue()
    
        threads = []    
        
        tested = []
    
        start_time = time.time()

        for test_algorithm in self.test_algorithms:
            if test_algorithm == "a_star":
                if self.thread_enable:
                    thread1 = mp.Process(target = self.a_star, args=(queue,))
                    threads.append(thread1)
                else:
                    result = self.a_star()

                    tested.append(result)

            if test_algorithm == "bidirectional_a_star":
                if self.thread_enable:
                    thread2 = mp.Process(target = self.bidirectional_a_star, args=(queue,))
                    threads.append(thread2)
                else:
                    result = self.bidirectional_a_star()

                    tested.append(result)
                    

            if test_algorithm == "dijkstra":
                if self.thread_enable:
                    thread3 = mp.Process(target = self.dijkstra, args=(queue,))
                    threads.append(thread3)
                else:
                    result = self.dijkstra()

                    tested.append(result)

            if test_algorithm == "d_star":
                if self.thread_enable:
                    thread4 = mp.Process(target = self.d_star, args=(queue,))
                    threads.append(thread4)
                else:
                    result = self.d_star()

                    tested.append(result)
            
            if test_algorithm == "breadth_first_search":
                if self.thread_enable:
                    thread6 = mp.Process(target = self.breadth_first_search, args=(queue,))
                    threads.append(thread6)
                else:
                    result = self.breadth_first_search()

                    tested.append(result)


            if test_algorithm == "d_star_lite":
                gc.collect()
                if self.thread_enable:
                    thread5 = mp.Process(target = self.d_star_lite, args=(queue,))
                    threads.append(thread5)
                else:
                    result = self.d_star_lite()

                    tested.append(result)
                
        
            if test_algorithm == "bidirectional_breadth_first_search":
                if self.thread_enable:
                    thread7 = mp.Process(target = self.bidirectional_breadth_first_search, args=(queue,))
                    threads.append(thread7)
                else:
                    result = self.bidirectional_breadth_first_search()

                    tested.append(result)

            if test_algorithm == "greedy_best_first_search":
                if self.thread_enable:
                    thread9 = mp.Process(target = self.greedy_best_first_search, args=(queue,))
                    threads.append(thread9)
                else:
                    result = self.greedy_best_first_search()

                    tested.append(result)

        if self.thread_enable:
            for thread in threads:
                thread.start()
        
            for thread in threads:
                tested.append(queue.get())
                thread.join()

        end_time = time.time()

        print(f"Paths generated!\nTotal time: {round(end_time-start_time,4)} seconds\n")

        self.tested_algorithms = tested

        return tested
  
    def path_visualization(self):

        legend_elements = []
        colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']
        fig, ax = plt.subplots()
        ax.plot(self.start_m[0], self.start_m[1], "ok")
        ax.plot(self.goal_m[0], self.goal_m[1], "xk")
        for point in self.coast_points_m:
            plt.plot(point[0],point[1], f"bo",markersize=1)
        for element in self.tested_algorithms:
            random_color = colors[np.random.randint(0, len(colors))]
            plt.plot(element[1], element[2], f"{random_color}", markersize=1)
            legend_elements.append(Line2D([0], [0], color=random_color, lw=4, label=element[0]))
            #remove random color from colors list
            colors.remove(random_color)
        plt.legend(handles=legend_elements, loc='upper right')
        plt.draw()
        plt.grid(True)
        plt.show()

class TestAlgorithmsAdvanced(TestAlgorithms):

    def __init__(self, start, goal, coast_points,thread_enable, binary_path, test_parameters, red_zone, yellow_zone, green_zone, zones_dictionary, max_boat_speed, red_speed, yellow_speed, green_speed):
        super().__init__(start, goal, coast_points, thread_enable, binary_path, [], red_zone, yellow_zone, green_zone, zones_dictionary)
        self.test_parameters = test_parameters
        self.max_boat_speed = max_boat_speed
        self.red_speed = red_speed * 0.514444444 #m/s
        self.yellow_speed = yellow_speed * 0.514444444
        self.green_speed = green_speed * 0.514444444

    
    
    def test_algorithms_path(self, red_cost = 1, yellow_cost = 1, green_cost = 1):
        print(__file__ + " start!!")
        mp.set_start_method('spawn')
        queue = mp.Queue()

        threads = []
        tested = []

        if self.test_parameters:

            parameters_list = [i for i in range(1, 10)]
        
            combinations = list(itertools.combinations(parameters_list, 3))

            for combination in combinations:

                thread = mp.Process(target = self.d_star_lite_advanced, args=(combination[0], combination[1], combination[2], queue,))
                threads.append(thread)

            
            for thread in threads:
                thread.start()

            for thread in threads:
                tested.append(queue.get())
                thread.join()
        
        else:
            result = self.d_star_lite_advanced(red_cost, yellow_cost, green_cost)

            tested.append(result)
        
        self.tested_algorithms = tested
        
        return tested
    
    def path_visualization(self, image : Image.Image):

        legend_elements = []
        colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']
        fig, ax = plt.subplots()
        im = ax.imshow(image, extent=[0, image.size[0], 0, image.size[1]])
        ax.plot(self.start_m[0], self.start_m[1], "ok")
        ax.plot(self.goal_m[0], self.goal_m[1], "xk")
        for point in self.coast_points_m:
            plt.plot(point[0],point[1], f"bo",markersize=1)
        for point in self.red_zone_m:
            plt.plot(point[0],point[1], f"ro",markersize=1)
        for point in self.yellow_zone_m:
            plt.plot(point[0],point[1], f"yo",markersize=1)
        for point in self.green_zone_m:
            plt.plot(point[0],point[1], f"go",markersize=1)
        for element in self.tested_algorithms:
            random_color = colors[np.random.randint(0, len(colors))]
            plt.plot(element[2], element[3], "black", markersize=1)
            legend_elements.append(Line2D([0], [0], color= 'black', lw=4, label=element[0]))
            #remove random color from colors list
            colors.remove(random_color)
        plt.legend(handles=legend_elements, loc='upper right')
        plt.draw()
        plt.grid(True)
        plt.show()
        