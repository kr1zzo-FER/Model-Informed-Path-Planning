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

class MapVisualization(Node):

    def __init__(self):
        super().__init__('pcd_coast')
        #ros log
        self.get_logger().info("Map visualization node started")
        self.declare_parameter('save_file', 'test')
        self.save_file = self.get_parameter('save_file').get_parameter_value().string_value

        print(self.save_file)
        self.zones_dictionary, self.coast_points, self.red_points, self.yellow_points, self.green_points, grid_size = self.get_zones_dictionary()

        self.grid_size = grid_size

        self.map_visualization()
    
    def map_visualization(self):   
            coast_points_gps = self.coast_points
            red_zone_gps = self.red_points
            yellow_zone_gps = self.yellow_points
            green_zone_gps = self.green_points 
            fig, ax = plt.subplots()
            ax.plot([x[1] for x in coast_points_gps], [x[0] for x in coast_points_gps], 'bo', markersize=0.1)
            ax.plot([x[1] for x in red_zone_gps], [x[0] for x in red_zone_gps], 'ro', markersize=0.1)
            ax.plot([x[1] for x in yellow_zone_gps], [x[0] for x in yellow_zone_gps], 'yo', markersize=0.1)
            ax.plot([x[1] for x in green_zone_gps], [x[0] for x in green_zone_gps], 'go', markersize=0.1)
            plt.show()


            rclpy.shutdown()

    def get_zones_dictionary(self):
        path = ws_root / f"src/map_maker/map_data/processed_map_{self.save_file}"

        coast_dictionary = load_binary_data(path)

        data = coast_dictionary["data"]

        coast_points_gps = data["coast_points_gps"]
        red_zone_gps = data["red_zone_gps"]
        yellow_zone_gps = data["yellow_zone_gps"]
        green_zone_gps = data["green_zone_gps"]
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
        
        return zones_dictionary, coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, grid_size
    


def main():
    rclpy.init(args=None)
    node = MapVisualization()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)