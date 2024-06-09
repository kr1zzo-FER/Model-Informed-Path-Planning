import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from user_action_interfaces.action import StartGoalAction
from user_action_interfaces.msg import StartGoalMsg
from user_action_interfaces.msg import PathMsg
from pathlib import Path
import sys
import pickle 

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

class PathPlanningActionClient(Node):

    def __init__(self):
        super().__init__('path_planning_action_client')

        self. start = [0.0,0.0]
        self.goal = [0.0,0.0]

        self.start_subscriber = self.create_subscription(StartGoalMsg, 'start_goal_msg', self.start_goal_callback, 10)

        self._action_client = ActionClient(self, StartGoalAction, 'start_goal_action')

        self.first_time = True

        self.send_path_publisher = self.create_publisher(PathMsg, 'path', 10)
        self.raw_path_publisher = self.create_publisher(PathMsg, 'raw_path', 10)
        self.searched_area_publisher = self.create_publisher(PathMsg, 'searched_area', 10)

        self.path = PathMsg()
        self.raw_path = PathMsg()
        self.searched_area = PathMsg()

        self.timer = self.create_timer(0.1, self.timer_callback)

        self.path_recived = False
    
    def timer_callback(self):
        if self.path_recived:
            self.send_path_publisher.publish(self.path)
        self.raw_path_publisher.publish(self.raw_path)
        self.searched_area_publisher.publish(self.searched_area)

    def start_goal_callback(self, msg):
        self.start = msg.start
        self.goal = msg.goal
        if self.first_time:
            self.first_time = False
            self.send_goal()

    def send_goal(self):

        self.path_recived = False   
        self.get_logger().info('Sending goal request')
        goal_msg = StartGoalAction.Goal()
        goal_msg.start = self.start
        goal_msg.goal = self.goal

        self._action_client.wait_for_server()

        self._send_goal_future = self._action_client.send_goal_async(goal_msg,  feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result

        self.get_logger().info("Result received!")

        path = PathMsg()
        path.header.stamp = self.get_clock().now().to_msg()
        path.header.frame_id = 'map'
        path.path_x = result.path_x
        path.path_y = result.path_y

        self.path = path

        self.path_recived = True
    
        
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f"Feedback received: {len(feedback.partial_path_x)} points")
        path = PathMsg()
        path.header.stamp = self.get_clock().now().to_msg()
        path.header.frame_id = 'map'
        path.path_x = feedback.partial_path_x
        path.path_y = feedback.partial_path_y
        area = PathMsg()
        area.header.stamp = self.get_clock().now().to_msg()
        area.header.frame_id = 'map'
        area.path_x = feedback.search_area_x
        area.path_y = feedback.search_area_y

        self.raw_path = path
        self.searched_area = area

        
def main(args=None):
    rclpy.init(args=args)

    action_client = PathPlanningActionClient()

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()
