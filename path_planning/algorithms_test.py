
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
    
    def __init__(self, start,goal,results_dictionary,grid_size, test_algorithms, thread_enable):
        super().__init__(start,goal,results_dictionary,grid_size)
        self.sx, self.sy = self.start_m[0], self.start_m[1]
        self.gx, self.gy = self.goal_m[0], self.goal_m[1]
        self.robot_radius = self.grid_size/2
        self.test_algorithms = test_algorithms
        self.thread_enable = thread_enable
        self.publish_path_results = []
        self.internal_path_results = []
        self.internal_points = []
        self.internal_optimized_points = []

    def get_obstacles(self):
        return [obstacle[0] for obstacle in self.coast_points_m], [obstacle[1] for obstacle in self.coast_points_m]

    def euclidean_distance(self,x1,y1,x2,y2):
        return math.sqrt((x1-x2)**2 + (y1-y2)**2)
    
    def get_path_results(self):
        return self.publish_path_results
    
    def get_internal_path_results(self):
        return self.internal_points
    
    def get_publish_data(self):
        return self.publish_path_results
    
    def test_algorithms_path(self):
        mp.set_start_method('spawn')
        queue = mp.Queue()
    
        threads = []    
        
        tested = []
        internal_tested = []
        internal_path = []
    
        start_time = time.time()

        for test_algorithm in self.test_algorithms:
                

            if test_algorithm == "d_star":
                if self.thread_enable:
                    thread4 = mp.Process(target = self.d_star, args=(queue,))
                    threads.append(thread4)
                else:
                    result, internal_result = self.d_star()

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
        


        if self.thread_enable:
            for thread in threads:
                thread.start()
        
            for thread in threads:
                queue_res = queue.get()
                tested.append(queue_res[0])
                internal_tested.append(queue_res[1])
                internal_path = queue_res[2]
                thread.join()

        end_time = time.time()

        print(f"Paths generated!\nTotal time: {round(end_time-start_time,4)} seconds\n")

        self.publish_path_results = tested
        self.internal_path_results = internal_tested
        self.internal_points = internal_path

        return tested
    
    def optimize_path(self):
        path_optimization = PathOptimization(self.internal_points)
        path_optimization.optimize_path()
        optimized_path = path_optimization.get_path()
        self.internal_optimized_points = optimized_path
        return optimized_path

        
    def d_star(self,q : mp.Queue = []):
        print("\nD* calculation started")
        m = Map(round(self.size_x/self.grid_size), round(self.size_y/self.grid_size))
        m.set_obstacle(self.zones_m)
        start = m.map[self.start_m[0]][self.start_m[1]]
        end = m.map[self.goal_m[0]][self.goal_m[1]]
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
        
        start_time = time.time()
        dstarlite = DStarLite(self.zones_m, self.start_m, self.goal_m)
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
        result = PathResults("D* Lite",self.start,self.goal,path_points_gps,distance,function_time)
        internal_result = PathResultsInternal("D* Lite",self.start_m,self.goal_m,path_points,distance,0.0,function_time)
        if q:
            q.put([result, internal_result, path_points])
        else:
            return result, internal_result, path_points

    
    
    def path_visualization(self):
        rows, values, columns = [], [], ["Distance", "Time"]
        legend_elements = []
        colors = ['red', 'crimson', 'lime', 'cyan', 'blue', 'gold', 'yellow', 'green', 'purple', 'pink']
        fig, ax = plt.subplots()
        ax.plot(self.start_m_plot[0],self.start_m_plot[1],'cx')
        ax.plot(self.goal_m_plot[0],self.goal_m_plot[1],'co')
        for key, value in self.zones_m_plot.items():
            if value == 'c':
                ax.plot(key[0],key[1],'bo', markersize=0.1)
            elif value == 'r':
                ax.plot(key[0],key[1],'ro', markersize=0.1)
            elif value == 'g':
                ax.plot(key[0],key[1],'go', markersize=0.1)
            elif value == 'y':
                ax.plot(key[0],key[1],'yo', markersize=0.1)
        for result in self.internal_path_results:
            rows.append(result.get_algorithm_name())
            values.append([result.get_distance(), result.get_runtime()])
            path_points = result.get_path()
            rx,ry = [], []
            for point in path_points:
                rx.append(point[0])
                ry.append(point[1])
            random_color = colors[np.random.randint(0, len(colors))]
            ax.plot(rx,ry, f"{random_color}", markersize=1)
            legend_elements.append(Line2D([0], [0], color=random_color, lw=4, label=result.get_algorithm_name()))
             #remove random color from colors list
            colors.remove(random_color)
        rx,ry = [], []
        for point in self.internal_optimized_points:
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
        self.plot_table(rows, values, columns, results)
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
    
    



    
