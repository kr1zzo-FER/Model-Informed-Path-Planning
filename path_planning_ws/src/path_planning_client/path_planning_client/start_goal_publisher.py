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

        self.start_goal_subscriber = self.create_subscription(StartGoalMsg, 'start_goal_msg_update', self.start_goal_callback, 10)
        self.start_goal_subscriber_manual = self.create_subscription(StartGoalMsg, 'start_goal_msg_update_manual', self.start_goal_callback, 10)

        self.start_goal_publisher = self.create_publisher(StartGoalMsg, 'start_goal_msg', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

        self.rviz2_start = [0.0,0.0]
        self.rviz2_goal = [0.0,0.0]
        self.rviz2_start_time = 0.0
        self.rviz2_goal_time = 0.0
        self.rviz_start_update = False

        self.manual_start = [0.0,0.0]
        self.manual_goal = [0.0,0.0]
        self.manual_start_time = 0.0
        self.manual_goal_time = 0.0

    def start_goal_callback(self, msg):
        if self.rviz2_start != msg.start:
            self.rviz2_start = msg.start
            self.rviz2_start_time = self.get_clock().now().to_msg().sec * 1e9 + self.get_clock().now().to_msg().nanosec
            self.get_logger().info(f"Start updated (RVIZ2): {self.rviz2_start}")
        if self.rviz2_goal != msg.goal and msg.goal != [0.0,0.0]:
            self.rviz2_goal = msg.goal
            self.rviz2_goal_time = self.get_clock().now().to_msg().sec * 1e9 + self.get_clock().now().to_msg().nanosec
            self.get_logger().info(f"Goal updated (RVIZ2): {self.rviz2_goal}")
        
    
    def start_goal_callback_manual(self, msg):
        if self.manual_start != msg.start and msg.start[0] != 0.0 and msg.start[1] != 0.0:
            self.manual_start = msg.start
            self.manual_goal_time = self.get_clock().now().to_msg().sec * 1e9 + self.get_clock().now().to_msg().nanosec
            self.get_logger().info(f"Start updated (Manual): {self.manual_start}")
        elif self.manual_goal != msg.goal and msg.goal[0] != 0.0 and msg.goal[1] != 0.0:
            self.manual_goal = msg.goal
            self.manual_goal_time = self.get_clock().now().to_msg().sec * 1e9 + self.get_clock().now().to_msg().nanosec
            self.get_logger().info(f"Goal updated (Manual): {self.manual_goal}")
        
    def timer_callback(self):

        start_goal_msg = StartGoalMsg()
        start_goal_msg.header.stamp = self.get_clock().now().to_msg()
        start_goal_msg.header.frame_id = 'map'
        #publish newer start_goal_msg
        if self.rviz2_start_time > self.manual_start_time:
            start_goal_msg.start = self.rviz2_start
        if self.manual_start_time > self.rviz2_start_time:
            start_goal_msg.start = self.manual_start
        if self.rviz2_goal_time > self.manual_goal_time:
            start_goal_msg.goal = self.rviz2_goal
        if self.manual_goal_time > self.rviz2_goal_time:
            start_goal_msg.goal = self.manual_goal

        if self.rviz2_start_time == self.manual_start_time:
            start_goal_msg.start = self.rviz2_start
            start_goal_msg.goal = self.rviz2_goal

        self.start_goal_publisher.publish(start_goal_msg)
    
def main(args=None):
    rclpy.init(args=args)

    action_client = PathPlanningPublisher()

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()
