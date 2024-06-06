import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import time
from user_action_interfaces.action import StartGoalAction
import sensor_msgs.msg as sensor_msgs
from user_action_interfaces.msg import StartGoalMsg
from .algorithms_test import TestAlgorithms
from user_action_interfaces.msg import CoastMsg

class PathPlanningActionServer(Node):

    def __init__(self):
        super().__init__('path_planning_action_server')
        
        self.start = [0,0]
        self.goal = [0,0]

        self.first_run = True

        self.coast_points = []
        self.red_zone = []
        self.green_zone = []
        self.yellow_zone = []
        self.zones_dictionary = {}

        self.thread_enable = True

        self.grid_size = 10.0

        self.coast_points_subscriber = self.create_subscription(CoastMsg, 'gps_coordinates_coast', self.coast_points_callback, 10)

        self._action_server = ActionServer(
            self,
            StartGoalAction,
            'start_goal_action',
            self.execute_callback)
        
    def coast_points_callback(self, msg):

        if self.first_run:
            self.first_run = False
            self.coast_points_x = msg.coast_points_x.data
            self.coast_points_y = msg.coast_points_y.data
            self.red_zone_x = msg.red_points_x.data
            self.red_zone_y = msg.red_points_y.data
            self.green_zone_x = msg.green_points_x.data
            self.green_zone_y = msg.green_points_y.data
            self.yellow_zone_x = msg.yellow_points_x.data
            self.yellow_zone_y = msg.yellow_points_y.data

            self.coast_points = [(self.coast_points_x[i], self.coast_points_y[i]) for i in range(len(self.coast_points_x))]
            self.red_zone = [(self.red_zone_x[i], self.red_zone_y[i]) for i in range(len(self.red_zone_x))]
            self.green_zone = [(self.green_zone_x[i], self.green_zone_y[i]) for i in range(len(self.green_zone_x))]
            self.yellow_zone = [(self.yellow_zone_x[i], self.yellow_zone_y[i]) for i in range(len(self.yellow_zone_x))]

            self.zones_dictionary = self.make_zones_dictionary()

            #self.get_logger().info(f"Coast points: {self.coast_points}")

        
    def make_zones_dictionary(self):
        dictionary = {}
        for point in self.red_zone:
            dictionary[point] = "r"
        for point in self.yellow_zone:
            dictionary[point] = "y"
        for point in self.green_zone:
            dictionary[point] = "g"
        for point in self.coast_points:
            dictionary[point] = "c"
        return dictionary
    

    def execute_callback(self, goal_handle):
        
        self.start = goal_handle.request.start
        self.goal = goal_handle.request.goal

        self._logger.info('Executing goal...')
        print(self.zones_dictionary)
        self._logger.info(f'Start: {self.start}')
        self._logger.info(f'Goal: {self.goal}')


        test_algorithms = TestAlgorithms(self.start, self.goal, self.zones_dictionary, self.grid_size, ["d_star_lite"], self.thread_enable)

        #zones_m, start_m, goal_m = test_algorithms.costmap_visualization()
        
        #self._logger.info(f"Zones: {zones_m}")
        #self._logger.info(f"Start: {start_m}, Goal: {goal_m}")
        

        test_algorithms.test_algorithms_path()

        path = test_algorithms.optimize_path()

        path_x = [point[0] for point in path]   
        path_y = [point[1] for point in path]

        result = StartGoalAction.Result()
        result.path_x = path_x  
        result.path_y = path_y

        return result


def main(args=None):
    rclpy.init(args=args)

    pp_action_server = PathPlanningActionServer()

    rclpy.spin(pp_action_server)


if __name__ == '__main__':
    main()