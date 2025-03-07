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



class StartGoalUpdate(Node):

    def __init__(self):
        super().__init__('path_planning_action_client')
        self.get_logger().info("Publishing coast points node started")
        self.declare_parameter('start', [0.0,0.0])
        self.declare_parameter('goal', [0.0,0.0])
        self.start = self.get_parameter('start').get_parameter_value().double_array_value
        self.goal = self.get_parameter('goal').get_parameter_value().double_array_value

        self.start_goal_publisher = self.create_publisher(StartGoalMsg, 'start_goal_msg_update_manual', 10)

        self.timer = self.create_timer(0.1, self.timer_callback)

        self.i = 0
        
    def timer_callback(self):
        self.i += 1
        start_goal_msg = StartGoalMsg()
        start_goal_msg.header.stamp = self.get_clock().now().to_msg()
        start_goal_msg.header.frame_id = 'map'
        start_goal_msg.start = self.start
        start_goal_msg.goal = self.goal
        self.start_goal_publisher.publish(start_goal_msg)
        if self.i == 10:
            self.get_logger().info(f"Messaging start: {start_goal_msg.start} goal: {start_goal_msg.goal}")
            self.destroy_node()
            sys.exit(0)
    
def main(args=None):
    rclpy.init(args=args)

    action_client = StartGoalUpdate()

    try:
        rclpy.spin(action_client)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    action_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()