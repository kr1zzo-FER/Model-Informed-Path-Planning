import rclpy
from rclpy.node import Node
import matplotlib.pyplot as plt
from user_action_interfaces.msg import ZonesDictionaryEntry

class ZonesPlotter(Node):
    def __init__(self):
        super().__init__('zones_plotter')
        self.subscription = self.create_subscription(
            ZonesDictionaryEntry,
            'zones_dictionary_cpp',
            self.listener_callback,
            10)
        self.zones = {'r': [], 'y': [], 'g': [], 's': [], 'c': []}
        self.new_data = False
        self.get_logger().info("Zones plotter node started")

    def listener_callback(self, msg):
        self.get_logger().info(f"Received {len(msg.key_x)} points")
        
        # Clear previous data
        self.zones = {'r': [], 'y': [], 'g': [], 's': [], 'c': []}
        
        # Store the received coordinates
        for x, y, zone in zip(msg.key_x, msg.key_y, msg.value):
            if zone in self.zones:
                self.zones[zone].append((y, x))

        self.new_data = True
        self.plot_zones()

    def plot_zones(self):
        if not self.new_data:
            return

        colors = {'r': 'red', 'y': 'yellow', 'g': 'green', 's': 'blue', 'c': 'cyan'}
        plt.figure(figsize=(10, 8))

        for zone, points in self.zones.items():
            if points:
                x_vals, y_vals = zip(*points)
                plt.scatter(x_vals, y_vals, color=colors[zone], label=f'{zone} zone', alpha=0.03)

        plt.xlabel('Longitude')
        plt.ylabel('Latitude')
        plt.title('Zones Visualization')
        plt.legend()
        plt.grid(True)
        plt.show()

        self.new_data = False  # Reset flag after plotting

def main(args=None):
    rclpy.init(args=args)
    node = ZonesPlotter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
