
import math
import pickle
import matplotlib.pyplot as plt
from PIL import Image
from matplotlib.lines import Line2D
from matplotlib.patches import Patch

show_animation = True

def main():

    ox, oy = [], []
    size_x = 0
    size_y = 0
    rx_astar = []
    ry_astar = []

    rx_bidir_astar = []
    ry_bidir_astar = []

    rx_dijkstra = []
    ry_dijkstra = []

    rx_dstar = []
    ry_dstar = []

    rx_dstar_lite = []
    ry_dstar_lite = []


    with open("ox", "rb") as f:
        ox = pickle.load(f)
    with open("oy", "rb") as f:
        oy = pickle.load(f)
    
    with open("dim_x", "rb") as f:
        size_x = pickle.load(f)
    with open("dim_y", "rb") as f:
        size_y = pickle.load(f)
    
    with open("a_star_path_x", "rb") as f:
        rx_astar = pickle.load(f)
    with open("a_star_path_y", "rb") as f:
        ry_astar = pickle.load(f)
    with open("dijkstra_path_x", "rb") as f:
        rx_dijkstra = pickle.load(f)
    with open("dijkstra_path_y", "rb") as f:
        ry_dijkstra = pickle.load(f)
    with open("bid_a_star_path_x", "rb") as f:
        rx_bidir_astar = pickle.load(f)
    with open("bid_a_star_path_y", "rb") as f:
        ry_bidir_astar = pickle.load(f)
    with open("d_star_path_x", "rb") as f:
        rx_dstar = pickle.load(f)
    with open("d_star_path_y", "rb") as f:
        ry_dstar = pickle.load(f)
    with open("d_star_lite_path_x", "rb") as f:
        rx_dstar_lite = pickle.load(f)
    with open("d_star_lite_path_y", "rb") as f:
        ry_dstar_lite = pickle.load(f)
    
    
    sx = size_x * 0.2  # [m]
    sy = size_y * 0.8 # [m]
    gx = size_x * 0.45   # [m]
    gy = size_y * 0.3  # [m]
    


    if show_animation:  # pragma: no cover
        
        im = plt.imread("jadranovo_resized.png")
        fig, ax = plt.subplots()
        im = ax.imshow(im, extent=[0, size_x, 0, size_y])
        plt.plot(ox, oy, ".k")
        plt.plot(sx, sy, "og")
        plt.plot(gx, gy, "xb")
        plt.grid(True)
        #plt.axis("equal")
        plt.plot(rx_astar, ry_astar, "-r")
        plt.plot(rx_bidir_astar, ry_bidir_astar, "-g")
        plt.plot(rx_dijkstra, ry_dijkstra, "-b")
        plt.plot(rx_dstar, ry_dstar, "-m")
        plt.plot(rx_dstar_lite, ry_dstar_lite, "-c")
        legend_elements = [Line2D([0], [0], color='r', lw=4, label='A*'),
                           Line2D([0], [0], color='g', lw=4, label='Bidirectional A*'),
                           Line2D([0], [0], color='b', lw=4, label='Dijkstra')
                           ,Line2D([0], [0], color='m', lw=4, label='D*')
                           ,Line2D([0], [0], color='c', lw=4, label='D* Lite')]
        ax.legend(handles=legend_elements, loc='upper right')
        plt.show()

if __name__ == '__main__':
    main()