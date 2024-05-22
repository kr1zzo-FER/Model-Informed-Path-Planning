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
import geometry_msgs.msg as geometry_msgs
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Quaternion
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
        self.declare_parameter('start', [0.0,0.0])
        self.declare_parameter('goal', [0.0,0.0])
        self.save_file = self.get_parameter('save_file').get_parameter_value().string_value
        self.start = self.get_parameter('start').get_parameter_value().double_array_value
        self.goal = self.get_parameter('goal').get_parameter_value().double_array_value

        zones_dictionary, grid_size = self.get_zones_dictionary()
        lcc = LocalCoordinatesConverter(zones_dictionary, grid_size, self.start, self.goal)

        #lcc.costmap_visualization()

        start = lcc.get_start_m()
        goal = lcc.get_goal_m()

        print(f"Start: {start}")
        print(f"Goal: {goal}")  

        self.start_pose = self.get_pose(start)
        self.goal_pose = self.get_pose(goal)

        print(f"Start pose: {self.start_pose}")

        self.start_publisher = self.create_publisher(geometry_msgs.PoseStamped, 'start_pose', 10)
        self.goal_publisher = self.create_publisher(geometry_msgs.PoseStamped, 'goal_pose', 10)


        coast_points, red_points, yellow_points, green_points = lcc.get_points_m()

        self.coast_pcd_points = self.convert_to_pcd(coast_points, 2)
        self.red_pcd_points = self.convert_to_pcd(red_points, 0)
        self.yellow_pcd_points = self.convert_to_pcd(yellow_points, 0)
        self.green_pcd_points = self.convert_to_pcd(green_points, 0)
        


        #coast points
        self.coast_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'coast_pcd_points', 10)
        #red points
        self.red_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'red_pcd_points', 10)
        #yellow points
        self.yellow_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'yellow_pcd_points', 10)
        #green points
        self.green_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'green_pcd_points', 10)
        
        self.timer = self.create_timer(0.1, self.timer_callback)

        #os.system(f"cd {ws_root}/src/path_planning_action/rviz2 && rviz2 -d {self.save_file}.rviz ")

    def timer_callback(self):
        self.get_logger().info('Publishing coast points')
        self.start_publisher.publish(self.start_pose)
        self.goal_publisher.publish(self.goal_pose)
        self.coast_pcd_publisher.publish(self.coast_pcd_points)
        self.red_pcd_publisher.publish(self.red_pcd_points)
        self.yellow_pcd_publisher.publish(self.yellow_pcd_points)
        self.green_pcd_publisher.publish(self.green_pcd_points)

    def get_zones_dictionary(self):
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
        
        return zones_dictionary, grid_size

    
    def convert_to_pcd(self, points, height, parent_frame_id="map"):


        ros_dtype = sensor_msgs.PointField.FLOAT32
        dtype = np.float32
        itemsize = np.dtype(dtype).itemsize

        points = [(point[0], point[1], height) for point in points]

        points = np.array(points)

        data = points.astype(dtype).tobytes()

        fields = [sensor_msgs.PointField(
        name=n, offset=i*itemsize, datatype=ros_dtype, count=1)
        for i, n in enumerate('xyz')]
    
        header = std_msgs.Header(frame_id=parent_frame_id, stamp=self.get_clock().now().to_msg())

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
    
    def get_pose(self,point):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.pose.position.x = float(point[0])
        pose.pose.position.y = float(point[1])
        pose.pose.position.z = 0.0
        return pose


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