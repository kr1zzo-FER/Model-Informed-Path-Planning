
"""

Algorithm class for path planning algorithms

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math
from pathlib import Path
import time
from algorithms.a_star import AStarPlanner
from algorithms.dstar import Dstar, Map
from algorithms.d_star_lite import DStarLite
from algorithms.d_star_lite import Node
from algorithms.d_star_lite_advanced import DStarLiteAdvanced
from algorithms.dijkstra import Dijkstra
from algorithms.bidirectional_a_star import BidirectionalAStarPlanner
from algorithms.breadth_first_search import BreadthFirstSearchPlanner
from algorithms.bidirectional_breadth_first_search import BidirectionalBreadthFirstSearchPlanner
from algorithms.greedy_best_first_search import BestFirstSearchPlanner
import multiprocessing as mp
import datetime

root = Path(__file__).resolve().parents[1]

class Algorithms:
    def __init__(self, start, goal, obstacles, grid_size, robot_radius, size):
        self.sx = start[0]
        self.sy = start[1]
        self.gx = goal[0]
        self.gy = goal[1]
        self.ox = obstacles[0]
        self.oy = obstacles[1]
        self.grid_size = grid_size
        self.robot_radius = robot_radius
        self.size_x = size[0]
        self.size_y = size[1]
        

    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)

    def a_star(self,q : mp.Queue = []):
        print("\nA* calculation started..")
        start_time = time.time()
        a_star = AStarPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = a_star.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("A* calculation finished : ")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["a_star",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result

    def bidirectional_a_star(self,q : mp.Queue = []):
        print("\nBidirectional A* calculation started..")
        start_time = time.time()
        bidir_a_star = BidirectionalAStarPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bidir_a_star.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print(f"Function time: {function_time} Distance: {distance}")
        result = ["bid_a_star",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result
    
    def dijkstra(self,q : mp.Queue = []):
        print("\nDijkstra calculation started")
        start_time = time.time()
        dijkstra = Dijkstra(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = dijkstra.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("Dijkstra calculation finished :")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["dijkstra",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result
        
    def d_star(self,q : mp.Queue = []):
        print("\nD* calculation started")
        m = Map(round(self.size_x/self.grid_size), round(self.size_y/self.grid_size))
        ox_ = [round(ox/self.grid_size) for ox in self.ox]
        oy_ = [round(oy/self.grid_size) for oy in self.oy]
        sx = round(self.sx/self.grid_size)
        sy = round(self.sy/self.grid_size)
        gx = round(self.gx/self.grid_size)
        gy = round(self.gy/self.grid_size)
        m.set_obstacle([(i, j) for i, j in zip(ox_, oy_)])
        start = [int(sx), int(sy)]
        goal = [int(gx), int(gy)]
        start = m.map[start[0]][start[1]]
        end = m.map[goal[0]][goal[1]]
        start_time = time.time()
        dstar = Dstar(m)
        rx, ry = dstar.run(start, end)
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("D* calculation finished : ")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["d_star",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result
        

    def d_star_lite(self,q : mp.Queue = []):
        print("\nD* lite calculation started")
        spoofed_ox = [[], [], [], []]
        spoofed_oy = [[], [], [], []]
        ox_ = [round(ox/self.grid_size) for ox in self.ox]
        oy_ = [round(oy/self.grid_size) for oy in self.oy]
        sx = round(self.sx/self.grid_size)
        sy = round(self.sy/self.grid_size)
        gx = round(self.gx/self.grid_size)
        gy = round(self.gy/self.grid_size)
        start_time = time.time()
        dstarlite = DStarLite(ox_,oy_)
        dstarlite.main(Node(x=sx, y=sy), Node(x=gx, y=gy),
                spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("D* Lite calculation finished : ")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["d_star_lite",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result
        
    def breadth_first_search(self,q : mp.Queue = []):
        print("\nBFS calculation started")
        start_time = time.time()
        bfs = BreadthFirstSearchPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bfs.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print(f"Function time: {function_time} Distance: {distance}")
        result = ["bfs",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result
    
    def bidirectional_breadth_first_search(self,q : mp.Queue = []):
        print("\nbidirectional BFS calculation started")
        start_time = time.time()
        bi_bfs = BidirectionalBreadthFirstSearchPlanner(
        self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bi_bfs.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("Bidirectional BFS calculation finished :")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["bid_bfs",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result
       
    
    def greedy_best_first_search(self,q : mp.Queue = []):
        print("\nGreedy Best First Search calculation started")
        start_time = time.time()
        greedy_best_first_search = BestFirstSearchPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = greedy_best_first_search.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("Greedy Best First Search calculation finished :")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["gbfs",rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result

class AdvancedAlgorithms(Algorithms):
    
    def __init__(self, start, goal, obstacles, grid_size, robot_radius,dimensions, red_zone:list, yellow_zone:list, green_zone:list, max_boat_speed, red_speed, yellow_speed, green_speed):
        super().__init__(start, goal, obstacles, grid_size, robot_radius, dimensions)
        self.redx = self.get_redx(red_zone)
        self.redy = self.get_redy(red_zone)
        self.yellowx = self.get_yellowx(yellow_zone)
        self.yellowy = self.get_yellowy(yellow_zone)
        self.greenx = self.get_greenx(green_zone)
        self.greeny = self.get_greeny(green_zone)
        self.red_zone = red_zone
        self.yellow_zone = yellow_zone
        self.green_zone = green_zone
        self.max_boat_speed = max_boat_speed
        self.red_speed = red_speed * 0.514444444 #m/s
        self.yellow_speed = yellow_speed * 0.514444444
        self.green_speed = green_speed * 0.514444444
        
        
    def get_redx(self,red_zone):
        return [red[0] for red in red_zone]
    def get_redy(self,red_zone):
        return [red[1] for red in red_zone]
    def get_yellowx(self,yellow_zone):
        return [yellow[0] for yellow in yellow_zone]
    def get_yellowy(self,yellow_zone):
        return [yellow[1] for yellow in yellow_zone]
    def get_greenx(self,green_zone):
        return [green[0] for green in green_zone]
    def get_greeny(self,green_zone):
        return [green[1] for green in green_zone]

    def calculate_arrival_time(self,rx,ry):
        arrival_time = 0
        current_time = datetime.datetime.now()
        print(f"\nCurrent time: {current_time}")
        counter = 0
        
        for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:]):
            print(x1,y1)
            if [y1,x1] in self.red_zone:
                print(x1,y1)
                counter += 1
                time_factor = self.red_speed
            if [y1,x1] in self.yellow_zone:
                print(x1,y1)
                counter += 1
                speed_factor = self.yellow_speed
            if [y1,x1] in self.green_zone:
                print(x1,y1)
                counter += 1
                speed_factor = self.green_speed
            else:
                speed_factor = self.max_boat_speed 

            arrival_time += (self.euclidean_distance(x1, y1, x2, y2)/speed_factor)
        
        arrival_datetime = current_time + datetime.timedelta(seconds=arrival_time)

        print(f"Arrival time: {arrival_datetime} Counter: {counter}")
        print(f"Red,yellow,green points in path : {counter}\n")
        return arrival_time,arrival_datetime
    
    def d_star_lite_advanced(self,red_cost, yellow_cost, green_cost, q : mp.Queue = []):
        print(f"\nD* lite advanced calculation started[r:{red_cost},y:{yellow_cost},g:{green_cost}]")
        spoofed_ox = [[], [], [], []]
        spoofed_oy = [[], [], [], []]
        ox_ = [round(ox/self.grid_size) for ox in self.ox]
        oy_ = [round(oy/self.grid_size) for oy in self.oy]
        redx = [round(red/self.grid_size) for red in self.redx]
        redy = [round(red/self.grid_size) for red in self.redy]
        yellowx = [round(yellow/self.grid_size) for yellow in self.yellowx]
        yellowy = [round(yellow/self.grid_size) for yellow in self.yellowy]
        greenx = [round(green/self.grid_size) for green in self.greenx]
        greeny = [round(green/self.grid_size) for green in self.greeny]
        sx = round(self.sx/self.grid_size)
        sy = round(self.sy/self.grid_size)
        gx = round(self.gx/self.grid_size)
        gy = round(self.gy/self.grid_size)
        
        start_time = time.time()
        dstarlite = DStarLiteAdvanced(ox_,oy_, redx, redy, yellowx, yellowy, greenx, greeny, red_cost, yellow_cost, green_cost)
        print(f"Start: {sx, sy} Goal: {gx, gy}")
        dstarlite.main(Node(x=sx, y=sy), Node(x=gx, y=gy),
                spoofed_ox=spoofed_ox, spoofed_oy=spoofed_oy)
        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        arrival_time, arrival_datetime = self.calculate_arrival_time(rx,ry)
        print(f"D* Lite advanced calculation finished")
        print(f"Function time: {function_time} Distance: {distance}\n")
        result = ["d_star_lite", [red_cost,yellow_cost,green_cost] ,rx,ry,function_time,distance]
        if q:
            q.put(result)
        else:
            return result

    
