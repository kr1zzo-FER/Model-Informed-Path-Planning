
"""

Algorithm class for path planning algorithms

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import math
from pathlib import Path
import time
from algorithms.hybrid_dstar import Dstar, Map, Dstar 
from algorithms.hybrid_d_star_lite import DStarLite, Node
import multiprocessing as mp
import datetime
from algorithms_base import AlgorithmBase
from path_results import PathResults,PathResultsInternal
from matplotlib import pyplot as plt
from matplotlib.lines import Line2D
import numpy as np
import os
from curve_generation.path_optimization import PathOptimization

root = Path(__file__).resolve().parents[1]



class TestAlgorithms(AlgorithmBase):
    
    def __init__(self, waypoints ,results_dictionary,grid_size, test_algorithms, thread_enable):
        super().__init__(waypoints,results_dictionary,grid_size)
        self.robot_radius = self.grid_size/2
        self.test_algorithms = test_algorithms
        self.thread_enable = thread_enable
        self.internal_points = []
        self.path_points = []
        self.smoothed_points = []

    def get_obstacles(self):
        return [obstacle[0] for obstacle in self.coast_points_m], [obstacle[1] for obstacle in self.coast_points_m]

    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)
    
    def get_path_results(self):
        return self.path_points
    
    def get_internal_path_results(self):
        return self.internal_points
    
    
    def test_algorithms_path(self):
    
        queue = mp.Queue()
    
        threads = []    
        
        tested = []
        internal_tested = []

        start_time = time.time()

        for i in range(len(self.waypoints)-1):
                
            if self.thread_enable:
                thread5 = mp.Process(target = self.d_star_lite, args=(queue,self.waypoints_m[i], self.waypoints_m[i+1]))
                threads.append(thread5)
            else:
                result, internal_result = self.d_star_lite(self.waypoints_m[i], self.waypoints_m[i+1])

                tested = tested + result
                internal_tested = internal_tested + internal_result
        


        if self.thread_enable:
            for thread in threads:
                thread.start()
        
            for thread in threads:
                queue_res = queue.get()
                tested = tested + queue_res[0]
                internal_tested = internal_tested + queue_res[1]
                thread.join()

        end_time = time.time()

        print(f"Paths generated!\nTotal time: {round(end_time-start_time,4)} seconds\n")

        self.internal_points = internal_tested
        self.path_points = tested

        self.path_visualization()

        return
    
    def optimize_path(self):
        path_optimization = PathOptimization(self.internal_points)
        path_optimization.optimize_path()
        optimized_path = path_optimization.get_path()
        self.smoothed_points = optimized_path
        return optimized_path

    def d_star_lite(self,q : mp.Queue = [], start = (0,0), goal = (0,0)):
        print("\nD* lite calculation started")
        print(start)
        start_time = time.time()
        dstarlite = DStarLite(self.zones_m, start, goal)
        dstarlite.set_cost(10.0,2.0,1.5)
        dstarlite.test()

        rx, ry = dstarlite.get_path()
        rx, ry = [rx[i]*self.grid_size for i in range(len(rx))], [ry[i]*self.grid_size for i in range(len(ry))]
        end_time = time.time()
        function_time = round(end_time - start_time, 5)
        distance = round(sum([self.euclidean_distance(x1, y1, x2, y2) for x1, y1, x2, y2 in zip(rx, ry, rx[1:], ry[1:])]),5)
        print("D* Lite calculation finished : ")
        print(f"Function time: {function_time} Distance: {distance}\n")
        path_points = [(rx[i],ry[i]) for i in range(len(rx))]
        path_points_gps = [self.pixel_to_gps(point[0],point[1]) for point in path_points]
        if q:
            q.put([path_points_gps, path_points])
        else:
            return path_points_gps, path_points

    
    
    def path_visualization(self):
        rows, values, columns = [], [], ["Distance", "Time"]
        legend_elements = []
        colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']
        fig, ax = plt.subplots()

        for wp in self.waypoints_m:
            ax.plot(wp[0],wp[1],'bx', markersize=5)

        for key, value in self.zones_m_plot.items():
            if value == 'c':
                ax.plot(key[0],key[1],'bo', markersize=0.1)
            elif value == 'r':
                ax.plot(key[0],key[1],'ro', markersize=0.1)
            elif value == 'g':
                ax.plot(key[0],key[1],'go', markersize=0.1)
            elif value == 'y':
                ax.plot(key[0],key[1],'yo', markersize=0.1)
        
        rx,ry = [], []
        for point in self.internal_points:
            rx.append(point[0])
            ry.append(point[1])

        ax.plot(rx,ry, 'red', markersize=1)

        for point in self.smoothed_points:
            rx.append(point[0])
            ry.append(point[1])
        
        ax.plot(rx,ry, 'black', markersize=1)

        results = "results_test"
        
        isExist = os.path.exists(results)
        if not isExist:
            os.makedirs(results)
        else:
            #delete content
            os.system(f"rm -r {results}/*")

        plt.legend(handles=legend_elements, loc='upper right')
        plt.draw()
        plt.grid(True)
        plt.savefig(f"{results}/path_visualization_{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.png")
        plt.show(block = False)
        plt.show()
        return
    
    def plot_table(self, rows, values, columns, results):
        fig, ax = plt.subplots()
        try:
            # hide axes
            fig.patch.set_visible(False)
            ax.axis('off')
            ax.axis('tight')
            ax.table(cellText=values, colLabels=columns, rowLabels=rows, loc='center', cellLoc='center', colLoc='center')
            fig.tight_layout()
            plt.savefig(f"{results}/table_{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.png")
            plt.show(block = False)
        except:
            print("No enough data to plot table!")
        return fig, ax, plt
    
    



    
