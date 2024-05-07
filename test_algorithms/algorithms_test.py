
"""

Algorithm class for path planning algorithms

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math
from pathlib import Path
import time
from .algorithms.a_star import AStarPlanner
from .algorithms.dstar import Dstar, Map
from .algorithms.d_star_lite import DStarLite
from .algorithms.d_star_lite import Node
from .algorithms.dijkstra import Dijkstra
from .algorithms.bidirectional_a_star import BidirectionalAStarPlanner
from .algorithms.breadth_first_search import BreadthFirstSearchPlanner
from .algorithms.bidirectional_breadth_first_search import BidirectionalBreadthFirstSearchPlanner
from .algorithms.greedy_best_first_search import BestFirstSearchPlanner
import multiprocessing as mp
import datetime
from .algorithms_base import AlgorithmBase
from .path_results import PathResults,PathResultsInternal
from matplotlib import pyplot as plt
from matplotlib.lines import Line2D
import numpy as np
import os

root = Path(__file__).resolve().parents[1]



class TestAlgorithms(AlgorithmBase):
    
    def __init__(self, start,goal,coast_points,grid_size, test_algorithms, thread_enable):
        super().__init__(start,goal,coast_points,grid_size)
        self.ox, self.oy = self.get_obstacles()
        self.sx, self.sy = self.start_m[0], self.start_m[1]
        self.gx, self.gy = self.goal_m[0], self.goal_m[1]
        self.robot_radius = self.grid_size/2
        self.test_algorithms = test_algorithms
        self.thread_enable = thread_enable
        self.publish_path_results = []
        self.internal_path_results = []
        
    def get_obstacles(self):
        return [obstacle[0] for obstacle in self.coast_points_m], [obstacle[1] for obstacle in self.coast_points_m]

    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)
    
    def get_path_results(self):
        return self.publish_path_results
    
    def get_publish_data(self):
        return self.publish_path_results
    
    def test_algorithms_path(self):

        mp.set_start_method('spawn')
        queue = mp.Queue()
    
        threads = []    
        
        tested = []
        internal_tested = []
    
        start_time = time.time()

        for test_algorithm in self.test_algorithms:
            if test_algorithm == "a_star":
                if self.thread_enable:
                    thread1 = mp.Process(target = self.a_star, args=(queue,))
                    threads.append(thread1)
                else:
                    result, internal_result = self.a_star()

                    tested.append(result)
                    internal_tested.append(internal_result)
                

            if test_algorithm == "bidirectional_a_star":
                if self.thread_enable:
                    thread2 = mp.Process(target = self.bidirectional_a_star, args=(queue,))
                    threads.append(thread2)
                else:
                    result, internal_result = self.bidirectional_a_star()

                    tested.append(result)
                    internal_tested.append(internal_result)
                

            if test_algorithm == "dijkstra":
                if self.thread_enable:
                    thread3 = mp.Process(target = self.dijkstra, args=(queue,))
                    threads.append(thread3)
                else:
                    result, internal_result = self.dijkstra()

                    tested.append(result)
                    internal_tested.append(internal_result)
                

            if test_algorithm == "d_star":
                if self.thread_enable:
                    thread4 = mp.Process(target = self.d_star, args=(queue,))
                    threads.append(thread4)
                else:
                    result, internal_result = self.d_star()

                    tested.append(result)
                    internal_tested.append(internal_result)
                
            
            if test_algorithm == "breadth_first_search":
                if self.thread_enable:
                    thread6 = mp.Process(target = self.breadth_first_search, args=(queue,))
                    threads.append(thread6)
                else:
                    result, internal_result = self.breadth_first_search()

                    tested.append(result)
                    internal_tested.append(internal_result)
                


            if test_algorithm == "d_star_lite":
                if self.thread_enable:
                    thread5 = mp.Process(target = self.d_star_lite, args=(queue,))
                    threads.append(thread5)
                else:
                    result, internal_result = self.d_star_lite()

                    tested.append(result)
                    internal_tested.append(internal_result)
                
        
            if test_algorithm == "bidirectional_breadth_first_search":
                if self.thread_enable:
                    thread7 = mp.Process(target = self.bidirectional_breadth_first_search, args=(queue,))
                    threads.append(thread7)
                else:
                    result, internal_result = self.bidirectional_breadth_first_search()

                    tested.append(result)
                    internal_tested.append(internal_result)
                

            if test_algorithm == "greedy_best_first_search":
                if self.thread_enable:
                    thread9 = mp.Process(target = self.greedy_best_first_search, args=(queue,))
                    threads.append(thread9)
                else:
                    result, internal_result = self.greedy_best_first_search()

                    tested.append(result)
                    internal_tested.append(internal_result)
                

        if self.thread_enable:
            for thread in threads:
                thread.start()
                
            print("Threads started!")
            for thread in threads:
                queue_res = queue.get()
                tested.append(queue_res[0])
                internal_tested.append(queue_res[1])
                thread.join()

            print("Threads finished!")
                

        end_time = time.time()

        print(f"Paths generated!\nTotal time: {round(end_time-start_time,4)} seconds\n")

        self.publish_path_results = tested
        self.internal_path_results = internal_tested

        return tested

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
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("A*",self.start,self.goal,path_points_gps,distance,0.0)
        internal_result = PathResultsInternal("A*",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result

    
    def bidirectional_a_star(self,q : mp.Queue = []):
        print("\nBidirectional A* calculation started..")
        start_time = time.time()
        print(self.sx, self.sy, self.gx, self.gy)
        bidir_a_star = BidirectionalAStarPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bidir_a_star.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("Bidirectional A* calculation finished : ")
        print(f"Function time: {function_time} Distance: {distance}\n")
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("Bidirectional A*",self.start,self.goal,path_points_gps,distance, 0.0)
        internal_result = PathResultsInternal("Bidirectional A*",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result


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
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("Dijkstra",self.start,self.goal,path_points_gps,distance, 0.0)
        internal_result = PathResultsInternal("Dijkstra",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result

        
    def d_star(self,q : mp.Queue = []):
        print("\nD* calculation started")
        m = Map(round(self.size_x/self.grid_size), round(self.size_y/self.grid_size))
        ox_ = [round(ox/self.grid_size) for ox in self.ox]
        oy_ = [round(oy/self.grid_size) for oy in self.oy]
        sx = round(self.sx/self.grid_size)
        sy = round(self.sy/self.grid_size)
        gx = round(self.gx/self.grid_size)
        gy = round(self.gy/self.grid_size)
        print(f"Start: {sx,sy} Goal: {gx,gy}")
        print(f"Coastline points: {len(ox_)}")
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
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("D*",self.start,self.goal,path_points_gps,distance,function_time)
        internal_result = PathResultsInternal("D*",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result


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
        print(f"Start: {sx,sy} Goal: {gx,gy}")
        print(f"Coastline points: {len(ox_)}")
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
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("D* Lite",self.start,self.goal,path_points_gps,distance,function_time)
        internal_result = PathResultsInternal("D* Lite",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result

    def breadth_first_search(self,q : mp.Queue = []):
        print("\nBFS calculation started")
        start_time = time.time()
        bfs = BreadthFirstSearchPlanner(self.ox, self.oy, self.grid_size, self.robot_radius)
        rx, ry = bfs.planning(self.sx, self.sy, self.gx, self.gy)
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("\nBFS calculation finished :")
        print(f"Function time: {function_time} Distance: {distance}")
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("Breadth first search",self.start,self.goal,path_points_gps,distance,function_time)
        internal_result = PathResultsInternal("Breadth first search",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result

    
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
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("Bidirectional Breadth First Search",self.start,self.goal,path_points_gps,distance,function_time)
        internal_result = PathResultsInternal("Bidirectional Breadth First Search",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result

        
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
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        result = PathResults("Greedy Best First Search",self.start,self.goal,path_points_gps,distance,function_time)
        internal_result = PathResultsInternal("Greedy Best First Search",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result])
        else:
            return result, internal_result

    
    
    def path_visualization(self):
        rows, values, columns = [], [], ["Distance", "Time"]
        legend_elements = []
        colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']
        fig, ax = plt.subplots(figsize=(self.size_x, self.size_y))
        for point in self.coast_points_m:
            plt.plot(point[0],point[1], f"bo",markersize=1)
        for result in self.internal_path_results:
            rows.append(result.get_algorithm_name())
            values.append([result.get_distance(), result.get_runtime()])
            start = result.get_start()
            goal = result.get_goal()
            ax.plot(start[0], start[1], "ok")
            ax.plot(goal[0], goal[1], "xk")
            path_points = result.get_path()
            rx,ry = [], []
            for point in path_points:
                rx.append(point[0])
                ry.append(point[1])
            random_color = colors[np.random.randint(0, len(colors))]
            plt.plot(rx,ry, f"{random_color}", markersize=1)
            legend_elements.append(Line2D([0], [0], color=random_color, lw=4, label=result.get_algorithm_name()))
             #remove random color from colors list
            colors.remove(random_color)

        plt.legend(handles=legend_elements, loc='upper right')
        plt.draw()
        plt.grid(True)
        #plt.savefig(root/"results"/f"path_visualization_{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.png")
        plt.show(block = False)
        self.plot_table(rows, values, columns)
        return
    
    def plot_table(self, rows, values, columns):
        fig, ax = plt.subplots()
        try:
            # hide axes
            fig.patch.set_visible(False)
            ax.axis('off')
            ax.axis('tight')
            ax.table(cellText=values, colLabels=columns, rowLabels=rows, loc='center', cellLoc='center', colLoc='center')
            fig.tight_layout()
            #plt.savefig(root/"results"/f"results_table_{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.png", dpi = 100)
            plt.show(block = False)
        except:
            print("No enough data to plot table!")
        return fig, ax, plt
    
    



    
