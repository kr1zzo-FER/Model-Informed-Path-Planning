import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from user_action_interfaces.action import StartGoalAction
from user_action_interfaces.msg import StartGoalMsg
from pathlib import Path
import sys
import pickle 
from matplotlib import pyplot as plt
import numpy as np

path = Path(__file__).resolve().parent
ws_root = Path(__file__).resolve().parents[6]
from matplotlib.lines import Line2D
from matplotlib.backend_bases import MouseButton


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



class PathPlanningPublisher(Node):

    def __init__(self):
        super().__init__('path_planning_action_client')
        self.get_logger().info("Publishing coast points node started")
        self.declare_parameter('start', [0.0,0.0])
        self.declare_parameter('goal', [0.0,0.0])
        self.start = self.get_parameter('start').get_parameter_value().double_array_value
        self.goal = self.get_parameter('goal').get_parameter_value().double_array_value
        self.declare_parameter('save_file', 'test')
        self.save_file = self.get_parameter('save_file').get_parameter_value().string_value

        self.coast_points, self.red_points, self.yellow_points, self.green_points, grid_size = self.get_data()
        
        self.start_goal_publisher = self.create_publisher(StartGoalMsg, 'start_goal_msg', 10)
        self.start_goal_subscriber = self.create_subscription(StartGoalMsg, 'start_goal_msg_update', self.start_goal_callback, 10)

        self.timer = self.create_timer(0.1, self.timer_callback)


    def start_goal_callback(self, msg):
        self.get_logger().info('Received start and goal')
        self.start = msg.start
        self.goal = msg.goal
        
    def timer_callback(self):
        print("Timer callback")
        start_goal_msg = StartGoalMsg()
        start_goal_msg.header.stamp = self.get_clock().now().to_msg()
        start_goal_msg.header.frame_id = 'map'
        start_goal_msg.start = self.start
        start_goal_msg.goal = self.goal

        self.start_goal_publisher.publish(start_goal_msg)

    
    def get_data(self):
        path = ws_root / f"src/path_planning_action/input_data/processed_maps/processed_map_{self.save_file}"
        self.get_logger().info(f"Path: {path}")
        coast_dictionary = load_binary_data(path)

        data = coast_dictionary["data"]

        coast_points_gps = data["coast_points_gps"]
        red_zone_gps = data["red_zone_gps"]
        yellow_zone_gps = data["yellow_zone_gps"]
        green_zone_gps = data["green_zone_gps"]
        grid_size = data["grid_size"]

        self.grid_size = grid_size

        
        return coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, grid_size

    def onclick(event):
        pass
    
def main(args=None):
    rclpy.init(args=args)

    action_client = PathPlanningPublisher()

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()
