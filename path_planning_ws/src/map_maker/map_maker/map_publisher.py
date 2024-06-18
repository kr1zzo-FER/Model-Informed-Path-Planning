from pathlib import Path
import sys
import pickle 
from matplotlib import pyplot as plt
import rclpy
from rclpy.node import Node
import sys
from user_action_interfaces.msg import CoastMsg


from matplotlib import pyplot as plt
import rclpy 
from rclpy.node import Node


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

class MapPublisher(Node):

    def __init__(self):
        super().__init__('pcd_coast')
        #ros log
        self.get_logger().info("Publishing coast points node started")
        self.declare_parameter('save_file', 'test')
        self.save_file = self.get_parameter('save_file').get_parameter_value().string_value


        self.zones_dictionary, self.coast_points, self.red_points, self.yellow_points, self.green_points, self.safe_points, grid_size = self.get_zones_dictionary()

        self.coast_points_x = [point[0] for point in self.coast_points]
        self.coast_points_y = [point[1] for point in self.coast_points]
        self.red_points_x = [point[0] for point in self.red_points]
        self.red_points_y = [point[1] for point in self.red_points]
        self.yellow_points_x = [point[0] for point in self.yellow_points]
        self.yellow_points_y = [point[1] for point in self.yellow_points]
        self.green_points_x = [point[0] for point in self.green_points]
        self.green_points_y = [point[1] for point in self.green_points]
        self.safe_points_x = [point[0] for point in self.safe_points]
        self.safe_points_y = [point[1] for point in self.safe_points]

        self.grid_size = grid_size

        self.timer = self.create_timer(1, self.timer_callback)

        self.zones_publisher = self.create_publisher(CoastMsg, 'gps_coordinates_coast', 10)

    def timer_callback(self):

        coast_msg = CoastMsg()
        coast_msg.header.stamp = self.get_clock().now().to_msg()
        coast_msg.header.frame_id = 'gps_coordinates'
        coast_msg.coast_points_x.data = self.coast_points_x
        coast_msg.coast_points_y.data = self.coast_points_y
        coast_msg.red_points_x.data = self.red_points_x
        coast_msg.red_points_y.data = self.red_points_y
        coast_msg.yellow_points_x.data = self.yellow_points_x
        coast_msg.yellow_points_y.data = self.yellow_points_y
        coast_msg.green_points_x.data = self.green_points_x
        coast_msg.green_points_y.data = self.green_points_y
        coast_msg.safe_points_x.data = self.safe_points_x
        coast_msg.safe_points_y.data = self.safe_points_y
        coast_msg.grid_size = self.grid_size

        self.zones_publisher.publish(coast_msg)

    def get_zones_dictionary(self):
        path = ws_root / f"src/map_maker/map_data/processed_map_{self.save_file}"

        coast_dictionary = load_binary_data(path)

        data = coast_dictionary["data"]

        coast_points_gps = data["coast_points_gps"]
        red_zone_gps = data["red_zone_gps"]
        yellow_zone_gps = data["yellow_zone_gps"]
        green_zone_gps = data["green_zone_gps"]
        safe_zone_gps = data["safe_zone_gps"]
        grid_size = data["grid_size"]

        grid_size = float(grid_size)

        zones_dictionary = {}
        for point in red_zone_gps:
            zones_dictionary[tuple(point)] = "r"
        for point in yellow_zone_gps:
            zones_dictionary[tuple(point)] = "y"
        for point in green_zone_gps:
            zones_dictionary[tuple(point)] = "g"
        for point in coast_points_gps:
            zones_dictionary[tuple(point)] = "c"
        for point in safe_zone_gps:
            zones_dictionary[tuple(point)] = "s"
        
        return zones_dictionary, coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, safe_zone_gps, grid_size
    


def main():
    rclpy.init(args=None)
    node = MapPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)