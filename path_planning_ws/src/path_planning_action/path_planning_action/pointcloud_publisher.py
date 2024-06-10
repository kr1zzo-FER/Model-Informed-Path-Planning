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
from user_action_interfaces.msg import PathMsg

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
        super().__init__('pcd_rviz2_publisher')
        self.get_logger().info("Publishing PointCloud2 Rviz2 local coordinates started")

        self.gps_coordinates_subscriber = self.create_subscription(CoastMsg, 'gps_coordinates_coast', self.gps_coordinates_callback, 10)

        self.start_goal_subscriber = self.create_subscription(StartGoalMsg, 'start_goal_msg', self.start_goal_callback, 10)
        self.path_subscriber = self.create_subscription(PathMsg, 'path', self.path_callback, 10)
        self.partial_path_subscriber = self.create_subscription(PathMsg, 'raw_path', self.raw_path_callback, 10)
        self.searched_area_pcd_subscriber = self.create_subscription(PathMsg, 'searched_area', self.searched_area_callback, 10)

        self.start = [0.0,0.0]
        self.goal = [0.0,0.0]
        self.zones_dictionary = {}
        self.coast_points = []
        self.red_points = []
        self.yellow_points = []
        self.green_points = []
        self.grid_size = 0.0
        self.start_pose = PoseStamped()
        self.goal_pose = PoseStamped()
        self.path_pcd = sensor_msgs.PointCloud2()

        self.first_gps_msg = True

        self.coast_pcd_points = sensor_msgs.PointCloud2()
        self.red_pcd_points = sensor_msgs.PointCloud2()
        self.yellow_pcd_points = sensor_msgs.PointCloud2()
        self.green_pcd_points = sensor_msgs.PointCloud2()
        self.path_pcd = sensor_msgs.PointCloud2()
        self.raw_path_pcd = sensor_msgs.PointCloud2()
        self.searched_area_pcd = sensor_msgs.PointCloud2()
        
        #coast points
        self.coast_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'coast_pcd_points', 10)
        #red points
        self.red_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'red_pcd_points', 10)
        #yellow points
        self.yellow_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'yellow_pcd_points', 10)
        #green points
        self.green_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'green_pcd_points', 10)
        #path points
        self.path_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'path_pcd_points', 10)
        #raw path points
        self.raw_path_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'raw_path_pcd_points', 10)
        # searched area points
        self.searched_area_pcd_publisher = self.create_publisher(sensor_msgs.PointCloud2, 'searched_area_pcd_points', 10)
        #start point
        self.start_publisher = self.create_publisher(PoseStamped, 'start_pose_custom', 10)
        #goal point
        self.goal_publisher = self.create_publisher(PoseStamped, 'goal_pose_custom', 10)
        
        self.timer = self.create_timer(0.1, self.timer_callback)

        self.start_update_subscriber = self.create_subscription(PoseWithCovarianceStamped, 'initialpose', self.start_update_callback, 10)   
        self.goal_update_subscriber = self.create_subscription(PoseStamped, 'goal_pose', self.goal_update_callback, 10)

        self.start_goal_update_publisher = self.create_publisher(StartGoalMsg, 'start_goal_msg_update', 10)

    def gps_coordinates_callback(self, msg):

        if len(msg.coast_points_x.data) == 0:
            self.get_logger().info("No coast points received")
            return
        
        if (len(self.coast_points) != len(msg.coast_points_x.data)):
            self.first_gps_msg = True
            
        if self.first_gps_msg:
            self.get_logger().info("gps_coordinates_coast data received")
            self.first_gps_msg = False
            self.coast_points = [(msg.coast_points_x.data[i], msg.coast_points_y.data[i]) for i in range(len(msg.coast_points_x.data))]
            self.red_points = [(msg.red_points_x.data[i], msg.red_points_y.data[i]) for i in range(len(msg.red_points_x.data))]
            self.yellow_points = [(msg.yellow_points_x.data[i], msg.yellow_points_y.data[i]) for i in range(len(msg.yellow_points_x.data))]
            self.green_points = [(msg.green_points_x.data[i], msg.green_points_y.data[i]) for i in range(len(msg.green_points_x.data))]
            self.grid_size = msg.grid_size
            self.zones_dictionary = {}
            for point in self.red_points:
                self.zones_dictionary[tuple(point)] = "r"
            for point in self.yellow_points:
                self.zones_dictionary[tuple(point)] = "y"
            for point in self.green_points:
                self.zones_dictionary[tuple(point)] = "g"
            for point in self.coast_points:
                self.zones_dictionary[tuple(point)] = "c"
            self.lcc = LocalCoordinatesConverter(self.zones_dictionary, self.grid_size)

            coast_points_m, red_points_m, yellow_points_m, green_points_m = self.lcc.get_points_m()

            self.coast_pcd_points = self.convert_to_pcd(coast_points_m, 2)
            self.red_pcd_points = self.convert_to_pcd(red_points_m, 0)
            self.yellow_pcd_points = self.convert_to_pcd(yellow_points_m, 0)
            self.green_pcd_points = self.convert_to_pcd(green_points_m, 0)
        

    def timer_callback(self):
        self.start_publisher.publish(self.start_pose)
        self.goal_publisher.publish(self.goal_pose)
        self.coast_pcd_publisher.publish(self.coast_pcd_points)
        self.red_pcd_publisher.publish(self.red_pcd_points)
        self.yellow_pcd_publisher.publish(self.yellow_pcd_points)
        self.green_pcd_publisher.publish(self.green_pcd_points)
        self.path_pcd_publisher.publish(self.path_pcd)

        self.raw_path_pcd_publisher.publish(self.raw_path_pcd)
        self.searched_area_pcd_publisher.publish(self.searched_area_pcd)


    def start_update_callback(self, msg):
        if not self.first_gps_msg:
            self.start = [msg.pose.pose.position.x*self.grid_size, msg.pose.pose.position.y*self.grid_size]
            start_gps = self.lcc.pixel_to_gps(self.start[0], self.start[1])
            start_msg = StartGoalMsg()
            start_msg.header.stamp = self.get_clock().now().to_msg()
            start_msg.header.frame_id = 'map'
            start_msg.start = [start_gps[0], start_gps[1]]
            start_msg.goal = self.goal
            self.start_goal_update_publisher.publish(start_msg)
            self.start_goal_update_publisher.publish(start_msg)

    def goal_update_callback(self, msg):
        if not self.first_gps_msg:
            self.goal = [msg.pose.position.x*self.grid_size, msg.pose.position.y*self.grid_size]
            goal_gps = self.lcc.pixel_to_gps(self.goal[0], self.goal[1])
            goal_msg = StartGoalMsg()
            goal_msg.header.stamp = self.get_clock().now().to_msg()
            goal_msg.header.frame_id = 'map'
            goal_msg.start = self.start
            goal_msg.goal = [goal_gps[0], goal_gps[1]]
            self.start_goal_update_publisher.publish(goal_msg)
    
    def start_goal_callback(self, msg):
        if not self.first_gps_msg:
            self.update = True
            self.start = msg.start
            self.goal = msg.goal
            self.lcc.set_start_goal(self.start, self.goal)
            start_m, goal_m = self.lcc.get_start_m(), self.lcc.get_goal_m()

            self.start_pose = self.get_pose(start_m)
            self.goal_pose = self.get_pose(goal_m)

    def path_callback(self, msg):
        if len(msg.path_x) > 0:
            path = []
            for i in range(len(msg.path_x)):
                path.append((msg.path_x[i], msg.path_y[i])) 
            path_m = self.lcc.get_path_m(path)
            self.path_pcd = self.convert_to_pcd(path_m, 0)

    def raw_path_callback(self, msg):
        if len(msg.path_x) > 0:
            path = []
            for i in range(len(msg.path_x)):
                path.append((msg.path_x[i], msg.path_y[i])) 
            path_m = self.lcc.get_path_m(path) 
            self.raw_path_pcd = self.convert_to_pcd(path_m, 0)
    
    def searched_area_callback(self, msg):
        self.get_logger().info("searched_area received")

        path = []
        for i in range(len(msg.path_x)):
            path.append((msg.path_x[i], msg.path_y[i])) 
        path_m = self.lcc.get_path_m(path) 
        self.searched_area_pcd = self.convert_to_pcd(path_m, 0)
    
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
        pose.header.stamp = self.get_clock().now().to_msg()
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