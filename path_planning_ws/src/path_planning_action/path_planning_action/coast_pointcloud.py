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

def save_to_binary_file(data, file_name):
    with open("processed_maps"/file_name, "wb") as f:
        pickle.dump(data, f)

def load_binary_data(file_name):
    try:
        with open("processed_maps"/file_name, "rb") as f:
            data = pickle.load(f)
    except:
        data = None
    return data

class CoastToPointCloud(Node):

    def __init__(self):
        super().__init__('pcd_coast')
        #ros log
        self.get_logger().info("Publishing coast points node started")
        self.declare_parameter('save_file', 'test')
        self.save_file = self.get_parameter('save_file').get_parameter_value().string_value
        print(self.save_file)

        path = ws_root / f"src/path_planning_action/input_data/processed_maps/processed_map_{self.save_file}"

        coast_dictionary = load_binary_data(path)

        data = coast_dictionary["data"]

        coast_points_gps = data["coast_points_gps"]
        red_zone_gps = data["red_zone_gps"]
        yellow_zone_gps = data["yellow_zone_gps"]
        green_zone_gps = data["green_zone_gps"]
        grid_size = data["grid_size"]

        self.grid_size = grid_size

        zones_dictionary = {}
        for point in red_zone_gps:
            zones_dictionary[tuple(point)] = "r"
        for point in yellow_zone_gps:
            zones_dictionary[tuple(point)] = "y"
        for point in green_zone_gps:
            zones_dictionary[tuple(point)] = "g"
        for point in coast_points_gps:
            zones_dictionary[tuple(point)] = "c"

        lcc = LocalCoordinatesConverter(coast_points_gps, zones_dictionary, grid_size)

        lcc.costmap_visualization()
        
        coast_points = lcc.get_coast_points_m()

        self.pcd_points = self.convert_to_pcd(coast_points)

        self.pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'pcd_points', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

    def process_coast_points(self, coast_dictionary):
        coast_points_gps = coast_dictionary["data"]["coast_points_gps"]
        return coast_points_gps
    
    def convert_to_pcd(self, points, parent_frame_id="map"):

        print(points)

        ros_dtype = sensor_msgs.PointField.FLOAT32
        dtype = np.float32
        itemsize = np.dtype(dtype).itemsize

        fig, ax = plt.subplots()

        cx,cy = [point[1] for point in points], [point[0] for point in points]
        ax.plot(cx, cy, 'co', label='coast points', markersize = 0.1)

        plt.show()

        points = [(point[0], point[1], 0) for point in points]

        print(points)

        points = np.array(points)

        data = points.astype(dtype).tobytes()

        fields = [sensor_msgs.PointField(
        name=n, offset=i*itemsize, datatype=ros_dtype, count=1)
        for i, n in enumerate('xyz')]
    
        header = std_msgs.Header(frame_id=parent_frame_id, stamp=self.get_clock().now().to_msg())

        print(data)

        return sensor_msgs.PointCloud2(
            header=header,
            height=1, 
            width=points.shape[0],
            is_dense=False,
            is_bigendian=False,
            fields=fields,
            point_step=(itemsize * 3), # Every point consists of three float32s.
            row_step=(itemsize * 3 * points.shape[0]),
            data=data
        )

    
    def timer_callback(self):
        self.get_logger().info('Publishing coast points')
        self.pcd_publisher.publish(self.pcd_points)



def main():
    rclpy.init(args=None)
    node = CoastToPointCloud()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)