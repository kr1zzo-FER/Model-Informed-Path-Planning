from pathlib import Path
import sys
import pickle 
from matplotlib import pyplot as plt
import rclpy
from rclpy.node import Node
import sys
import os
from .local_coordinates_converter import LocalCoordinatesConverter

import rclpy 
from rclpy.node import Node
import sensor_msgs.msg as sensor_msgs
import std_msgs.msg as std_msgs

import numpy as np


path = Path(__file__).resolve().parent
ws_root = Path(__file__).resolve().parents[6]

rviz_file = 'map_visualization.rviz'


class RunRviz2(Node):

    def __init__(self):
        super().__init__('pcd_coast')

        os.system(f"cd {ws_root}/src/path_planning_client/rviz2 && rviz2 -d {rviz_file} ")


def main():
    rclpy.init(args=None)
    node = RunRviz2()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)