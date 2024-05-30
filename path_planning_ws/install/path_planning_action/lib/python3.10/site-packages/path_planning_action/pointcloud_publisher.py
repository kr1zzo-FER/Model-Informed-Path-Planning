from pathlib import Path
import sys
import pickle 
from matplotlib import pyplot as plt
import rclpy
from rclpy.node import Node
import sys
import os
from .local_coordinates_converter import LocalCoordinatesConverter
from user_action_interfaces.msg import CoastMsg
from user_action_interfaces.msg import StartGoalMsg

from matplotlib import pyplot as plt
import rclpy 
from rclpy.node import Node
import sensor_msgs.msg as sensor_msgs
import std_msgs.msg as std_msgs
from std_msgs.msg import Float32MultiArray
import geometry_msgs.msg as geometry_msgs
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
import numpy as np


show_plot = True

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

        self.start_goal_subscriber = self.create_subscription(StartGoalMsg, 'start_goal_msg', self.start_goal_callback, 10)

        self.start = [0.0,0.0]
        self.goal = [0.0,0.0]
        self.start_pose = PoseStamped()
        self.goal_pose = PoseStamped()

        self.zones_dictionary, self.coast_points, self.red_points, self.yellow_points, self.green_points, grid_size = self.get_zones_dictionary()

        print(self.coast_points)
        self.coast_points_x = [point[0] for point in self.coast_points]
        self.coast_points_y = [point[1] for point in self.coast_points]
        self.red_points_x = [point[0] for point in self.red_points]
        self.red_points_y = [point[1] for point in self.red_points]
        self.yellow_points_x = [point[0] for point in self.yellow_points]
        self.yellow_points_y = [point[1] for point in self.yellow_points]
        self.green_points_x = [point[0] for point in self.green_points]
        self.green_points_y = [point[1] for point in self.green_points]

        self.lcc = LocalCoordinatesConverter(self.zones_dictionary, grid_size)

        coast_points_m, red_points_m, yellow_points_m, green_points_m = self.lcc.get_points_m()

        self.coast_pcd_points = self.convert_to_pcd(coast_points_m, 2)
        self.red_pcd_points = self.convert_to_pcd(red_points_m, 0)
        self.yellow_pcd_points = self.convert_to_pcd(yellow_points_m, 0)
        self.green_pcd_points = self.convert_to_pcd(green_points_m, 0)
        
        self.coast_publisher_rviz = self.create_publisher(CoastMsg, 'coast_pcd_rviz2', 10)


        #coast points
        self.coast_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'coast_pcd_points', 10)
        #red points
        self.red_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'red_pcd_points', 10)
        #yellow points
        self.yellow_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'yellow_pcd_points', 10)
        #green points
        self.green_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'green_pcd_points', 10)
        #start point
        self.start_publisher = self.create_publisher(PoseStamped, 'start_pose_costume', 10)
        #goal point
        self.goal_publisher = self.create_publisher(PoseStamped, 'goal_pose_costume', 10)
        
        self.timer = self.create_timer(0.1, self.timer_callback)

        self.start_update_subscriber = self.create_subscription(PoseWithCovarianceStamped, 'initialpose', self.start_update_callback, 10)   
        self.goal_update_subscriber = self.create_subscription(PoseStamped, 'goal_pose', self.goal_update_callback, 10)

        self.start_goal_update_publisher = self.create_publisher(StartGoalMsg, 'start_goal_msg_update', 10)

        self.zones_publisher = self.create_publisher(CoastMsg, 'coast_points_gps', 10)

    def timer_callback(self):
        self.get_logger().info('Publishing coast points')
        self.start_publisher.publish(self.start_pose)
        self.goal_publisher.publish(self.goal_pose)
        self.coast_pcd_publisher.publish(self.coast_pcd_points)
        self.red_pcd_publisher.publish(self.red_pcd_points)
        self.yellow_pcd_publisher.publish(self.yellow_pcd_points)
        self.green_pcd_publisher.publish(self.green_pcd_points)


        coast_msg = CoastMsg()
        coast_msg.header.stamp = self.get_clock().now().to_msg()
        coast_msg.coast_points_x.data = self.coast_points_x
        coast_msg.coast_points_y.data = self.coast_points_y
        coast_msg.red_points_x.data = self.red_points_x
        coast_msg.red_points_y.data = self.red_points_y
        coast_msg.yellow_points_x.data = self.yellow_points_x
        coast_msg.yellow_points_y.data = self.yellow_points_y
        coast_msg.green_points_x.data = self.green_points_x
        coast_msg.green_points_y.data = self.green_points_y

        self.zones_publisher.publish(coast_msg)

    def start_update_callback(self, msg):
        print("Start update")
        self.start = [msg.pose.pose.position.x*self.grid_size, msg.pose.pose.position.y*self.grid_size]
        start_gps = self.lcc.pixel_to_gps(self.start[0], self.start[1])
        self.start_goal_update_publisher.publish(StartGoalMsg(start=[start_gps[0], start_gps[1]], goal=self.goal))

    def goal_update_callback(self, msg):
        print("Goal update")
        self.goal = [msg.pose.position.x*self.grid_size, msg.pose.position.y*self.grid_size]
        goal_gps = self.lcc.pixel_to_gps(self.goal[0], self.goal[1])
        self.start_goal_update_publisher.publish(StartGoalMsg(start=self.start, goal=[goal_gps[0], goal_gps[1]]))
    
    def start_goal_callback(self, msg):
        self.update = True
        self.get_logger().info('Received start and goal')
        self.start = msg.start
        self.goal = msg.goal
        self.lcc.set_start_goal(self.start, self.goal)
        start_m, goal_m = self.lcc.get_start_m(), self.lcc.get_goal_m()
        self.start_pose = self.get_pose(start_m)
        self.goal_pose = self.get_pose(goal_m)

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
        
        return zones_dictionary, coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, grid_size

    
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

        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = 10.0
        pose.pose.orientation.w = 10.0

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