class AlgorithmsAdvancedBase():


    def __init__(self, start, goal, coast_points, thread_enable, binary_path, red_zone, yellow_zone, green_zone, zones_dictionary, test_parameters):
        self.coordinates = self.get_coordinates(coast_points)
        self.size_x = self.get_width()
        self.size_y = self.get_height()
        self.size = (self.size_x, self.size_y)
        self.grid_size = self.get_grid_size(coast_points)
        self.robot_radius = self.grid_size/2
        self.start_m = self.get_start_m(start, coast_points)
        self.goal_m = self.get_goal_m(goal, coast_points)
        self.coast_points_m = self.get_coast_points_m(coast_points)
        self.thread_enable = thread_enable
        self.binary_path = binary_path
        self.tested_algorithms = []
    
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

    def get_start_m(self, start, coast_points):
        return self.gps_to_pixel(start[0][0], start[0][1])

    def get_goal_m(self, goal, coast_points):
        return self.gps_to_pixel(goal[0][0], goal[0][1])

    def get_coast_points_m(self, coast_points):
        return [self.gps_to_pixel(point[0], point[1]) for point in coast_points]
    
    def get_grid_size(self, coast_points):
        # x points without duplicates
        grid_size = 10
        return grid_size
    
    
    def get_coordinates(self, coast_points, red_zone, yellow_zone, green_zone):

        min_x_coast = min(coast_points, key = lambda x: x[0])[0]
        min_y_coast = min(coast_points, key = lambda x: x[1])[1]

        min_x_red = min(red_zone, key = lambda x: x[0])[0]
        min_y_red = min(red_zone, key = lambda x: x[1])[1]

        min_x_yellow = min(yellow_zone, key = lambda x: x[0])[0]
        min_y_yellow = min(yellow_zone, key = lambda x: x[1])[1]

        min_x_green = min(green_zone, key = lambda x: x[0])[0]
        min_y_green = min(green_zone, key = lambda x: x[1])[1]

        print(f"Coordinates min x get_coordinates_ryg: {min_x_red, min_x_yellow, min_x_green}")
        
        min_x = min(min_x_red, min_x_yellow, min_x_green)
        min_y = min(min_y_red, min_y_yellow, min_y_green)

        max_x_red = max(red_zone, key = lambda x: x[0])[0]
        max_y_red = max(red_zone, key = lambda x: x[1])[1]

        max_x_yellow = max(yellow_zone, key = lambda x: x[0])[0]
        max_y_yellow = max(yellow_zone, key = lambda x: x[1])[1]

        max_x_green = max(green_zone, key = lambda x: x[0])[0]
        max_y_green = max(green_zone, key = lambda x: x[1])[1]

        max_x = max(max_x_red, max_x_yellow, max_x_green)
        max_y = max(max_y_red, max_y_yellow, max_y_green)

        result = [min_y, min_x, max_y, max_x]

        print(f"Coordinates get_coordinates_ryg: {result}")
        return result

    def gps_to_pixel_ryg(self,latitude, longitude):
        # Convert gps coordinates to pixel coordinates
        #print(f"Coordinates gps_to_pixel: {self.coordinates}")
        x_pixel = int(round((longitude - self.coordinates_ryg[0]) * self.size_x / (self.coordinates_ryg[2] - self.coordinates_ryg[0])))
        y_pixel = int(round((latitude - self.coordinates_ryg[1]) * self.size_y / (self.coordinates_ryg[3] - self.coordinates_ryg[1])))
        x_pixel = round(x_pixel/self.grid_size)*self.grid_size
        y_pixel = round(y_pixel/self.grid_size)*self.grid_size
        return x_pixel, y_pixel

    def get_red_zone_m(self, red_zone):
        return [self.gps_to_pixel_ryg(point[0], point[1]) for point in red_zone]

    def get_yellow_zone_m(self, yellow_zone):
        return [self.gps_to_pixel_ryg(point[0], point[1]) for point in yellow_zone]
    
    def get_green_zone_m(self, green_zone):
        return [self.gps_to_pixel_ryg(point[0], point[1]) for point in green_zone]
    
    def get_zones_dictionary(self, zones_dictionary):
        return zones_dictionary

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
    

class TestAlgorithmsAdvanced(AlgorithmsAdvancedBase):

    def __init__(self, start, goal, coast_points, thread_enable, binary_path, test_parameters, red_zone, yellow_zone, green_zone, zones_dictionary, max_boat_speed, red_speed, yellow_speed, green_speed):
        super().__init__(start, goal, coast_points,thread_enable, binary_path, test_parameters, red_zone, yellow_zone, green_zone, zones_dictionary, max_boat_speed, red_speed, yellow_speed, green_speed)
        self.ox, self.oy = self.get_resized_obstacles()
        self.sx, self.sy = round(self.start_m[0]/self.grid_size), round(self.start_m[1]/self.grid_size)
        self.gx, self.gy = round(self.goal_m[0]/self.grid_size), round(self.goal_m[1]/self.grid_size)
        self.spoofed_ox = [[], [], [], []]
        self.spoofed_oy = [[], [], [], []]
        self.red_x = []
        self.red_y = []
        self.yellow_x = []
        self.yellow_y = []
        self.green_x = []
        self.green_y = []
        self.zones = self.get_resized_zone_dictionary()
        print(f"Zones: {self.zones}")
    

    def get_redx(self):
        return [round(red[0]/self.grid_size) for red in self.red_zone_m]
    
    def get_redy(self):
        return [round(red[1]/self.grid_size) for red in self.red_zone_m]
    
    def get_yellowx(self):
        return [round(yellow[0]/self.grid_size) for yellow in self.yellow_zone_m]

    def get_yellowy(self):
        return [round(yellow[1]/self.grid_size) for yellow in self.yellow_zone_m]
    
    def get_greenx(self):
        return [round(green[0]/self.grid_size) for green in self.green_zone_m]
    
    def get_greeny(self):
        return [round(green[1]/self.grid_size) for green in self.green_zone_m]
    

    def get_resized_obstacles(self):
        return [round(obstacle[0]/self.grid_size) for obstacle in self.coast_points_m], [round(obstacle[1]/self.grid_size) for obstacle in self.coast_points_m]

    def get_resized_zone_dictionary(self):
        #resize keys, values intact
        #print(f"Zones dictionary: {self.zones_dictionary}")
        #return {round(key/self.grid_size): value for key, value in self.zones_dictionary.items()}
        return {}
    
    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)
    
    def d_star_lite_advanced(self,red_cost, yellow_cost, green_cost, q : mp.Queue = []):
        print(f"\nD* lite advanced calculation started[r:{red_cost},y:{yellow_cost},g:{green_cost}]")
        
        start_time = time.time()
        dstarlite = DStarLiteAdvanced(self.ox, self.oy, self.red_x, self.red_y, self.yellow_x, self.yellow_y, self.green_x, self.green_y, red_cost, yellow_cost, green_cost)
        print(f"Start: {self.sx, self.sy} Goal: {self.gx, self.gy}")
        dstarlite.main(Node(x=self.sx, y=self.sy), Node(x=self.gx, y=self.gy),
                spoofed_ox=self.spoofed_ox, spoofed_oy=self.spoofed_oy)
        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        #arrival_time, arrival_datetime = self.calculate_arrival_time(rx,ry)
        print(f"D* Lite advanced calculation finished")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["d_star_lite", [red_cost,yellow_cost,green_cost] ,rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result