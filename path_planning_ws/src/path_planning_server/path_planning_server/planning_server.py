import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import time
from user_action_interfaces.action import StartGoalAction


class PathPlanningActionServer(Node):

    def __init__(self):
        super().__init__('path_planning_action_server')
        self._action_server = ActionServer(
            self,
            StartGoalAction,
            'start_goal_action',
            self.execute_callback)
        self.start = [0,0]
        self.goal = [0,0]

    def execute_callback(self, goal_handle):
        
        self.start = goal_handle.request.start
        self.goal = goal_handle.request.goal

        self.get_logger().info(f'Start: {self.start}, Goal: {self.goal}')
       
        feedback_msg = StartGoalAction.Feedback()

        sequence = [0,1,2,3,4,5,6,7,8,9]

        for i in range(10):
            feedback_msg.partial_path = sequence[:i]
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.partial_path))
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)

        sequence = [0,1,2,3,4,5,6,7,8,9]

        goal_handle.succeed()


        result = StartGoalAction.Result()
        result.path = sequence

        return result


def main(args=None):
    rclpy.init(args=args)

    pp_action_server = PathPlanningActionServer()

    rclpy.spin(pp_action_server)


if __name__ == '__main__':
    main()