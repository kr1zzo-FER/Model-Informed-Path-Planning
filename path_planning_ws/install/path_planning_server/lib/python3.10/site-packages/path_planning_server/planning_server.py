import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import time
from user_action_interfaces.action import PathPlanning


class PathPlanningActionServer(Node):

    def __init__(self):
        super().__init__('path_planning_action_server')
        self._action_server = ActionServer(
            self,
            PathPlanning,
            'path_planning',
            self.execute_callback)

    def execute_callback(self, goal_handle):

        self.get_logger().info('Start and goal set, waiting for the result...')
        
        feedback_msg = PathPlanning.Feedback()

        sequence = [0,1,2,3,4,5,6,7,8,9]

        for i in range(10):
            feedback_msg.partial_path = sequence[:i]
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.partial_path))
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)

        sequence = [0,1,2,3,4,5,6,7,8,9]

        goal_handle.succeed()


        result = PathPlanning.Result()
        result.path = sequence

        return result


def main(args=None):
    rclpy.init(args=args)

    pp_action_server = PathPlanningActionServer()

    rclpy.spin(pp_action_server)


if __name__ == '__main__':
    main()