"""

Program for path planning algorithms testing

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

from sys import maxsize
from PIL import Image
from algorithm_class import Algorithms 
from algorithm_class import AdvancedAlgorithms
import multiprocessing as mp 
import time
import gc
import itertools

def test_algorithms(binary_path,start, goal, obstacles,test_algorithm, grid_size, robot_radius, thread_enable, size):

    print(__file__ + " start!!")
    mp.set_start_method('spawn')
    queue = mp.Queue()
    
    algorithm = Algorithms(start, goal, obstacles, grid_size, robot_radius,size)

    threads = []    
    
    tested = []
   
    start_time = time.time()
    for test_algorithm in test_algorithm:
        if test_algorithm == "a_star":
            if thread_enable:
                thread1 = mp.Process(target = algorithm.a_star, args=(queue,))
                threads.append(thread1)
            else:
                result = algorithm.a_star()

                tested.append(result)

        if test_algorithm == "bidirectional_a_star":
            if thread_enable:
                thread2 = mp.Process(target = algorithm.bidirectional_a_star, args=(queue,))
                threads.append(thread2)
            else:
                result = algorithm.bidirectional_a_star()

                tested.append(result)
                

        if test_algorithm == "dijkstra":
            if thread_enable:
                thread3 = mp.Process(target = algorithm.dijkstra, args=(queue,))
                threads.append(thread3)
            else:
                result = algorithm.dijkstra()

                tested.append(result)

        if test_algorithm == "d_star":
            if thread_enable:
                thread4 = mp.Process(target = algorithm.d_star, args=(queue,))
                threads.append(thread4)
            else:
                result = algorithm.d_star()

                tested.append(result)
        
        if test_algorithm == "breadth_first_search":
            if thread_enable:
                thread6 = mp.Process(target = algorithm.breadth_first_search, args=(queue,))
                threads.append(thread6)
            else:
                result = algorithm.breadth_first_search()

                tested.append(result)


        if test_algorithm == "d_star_lite":
            gc.collect()
            if thread_enable:
                thread5 = mp.Process(target = algorithm.d_star_lite, args=(queue,))
                threads.append(thread5)
            else:
                result = algorithm.d_star_lite()

                tested.append(result)
            
    
        if test_algorithm == "bidirectional_breadth_first_search":
            if thread_enable:
                thread7 = mp.Process(target = algorithm.bidirectional_breadth_first_search, args=(queue,))
                threads.append(thread7)
            else:
                result = algorithm.bidirectional_breadth_first_search()

                tested.append(result)

        if test_algorithm == "greedy_best_first_search":
            if thread_enable:
                thread9 = mp.Process(target = algorithm.greedy_best_first_search, args=(queue,))
                threads.append(thread9)
            else:
                result = algorithm.greedy_best_first_search()

                tested.append(result)

    if thread_enable:
        for thread in threads:
            thread.start()
    
        for thread in threads:
            tested.append(queue.get())
            thread.join()

    end_time = time.time()

    print(f"Paths generated!\nTotal time: {round(end_time-start_time,4)} seconds\n")

    return tested
    
        

def test_dstar_lite_costmap(start, goal, obstacles, grid_size, robot_radius,dimensions, red_zone, yellow_zone, green_zone):

   
    
    print(__file__ + " start!!")
    mp.set_start_method('spawn')
    queue = mp.Queue()

    print(red_zone)
    
    algorithm = AdvancedAlgorithms(start, goal, obstacles, grid_size, robot_radius,dimensions, red_zone, yellow_zone, green_zone)

    threads = []    
    
    tested = []

    parameters_list = [i for i in range(1, 10)]
    
    combinations = list(itertools.combinations(parameters_list, 3))

    for combination in combinations:

        thread = mp.Process(target = algorithm.d_star_lite_advanced, args=(combination[0], combination[1], combination[2], queue,))
        threads.append(thread)

    
    for thread in threads:
        thread.start()

    for thread in threads:
        tested.append(queue.get())
        thread.join()