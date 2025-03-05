import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node as rclpy_Node
import numpy as np
import heapq
import math
import matplotlib.pyplot as plt
from user_action_interfaces.action import StartGoalAction
from user_action_interfaces.msg import CoastMsg
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors

import numpy as np
import heapq


class PathPlanningServer(rclpy_Node):
    def __init__(self):
        super().__init__('path_planning_server')

        self.get_logger().info('Path planning server started')

        # Load parameters
        self.cost_values = np.array(self.get_parameter_or('cost_values', [20.0, 1.5, 1.2, 1.1]), dtype=np.float32)
        self.grid_size = 0.0
        self.first_run = True
        self.coordinates = np.empty((0, 2), dtype=np.float32)

        # min and max values
        self.min_x, self.min_y = 0, 0
        self.max_x, self.max_y = 0, 0

        # Zone coordinates
        self.coast_points = np.empty((0, 2), dtype=np.float32)
        self.red_zone = np.empty((0, 2), dtype=np.float32)
        self.yellow_zone = np.empty((0, 2), dtype=np.float32)
        self.green_zone = np.empty((0, 2), dtype=np.float32)
        self.safe_zone = np.empty((0, 2), dtype=np.float32)

        # start and goal
        self.start = None
        self.goal = None

        # Grid initialization
        self.grid = None
        self.size_x, self.size_y = 0, 0

        self.path = np.empty((0, 2), dtype=np.int32)  # NumPy array for path

        # ROS2 Subscriptions and Action Server
        self.create_subscription(CoastMsg, 'gps_coordinates_coast', self.coast_points_callback, 10)
        self._action_server = ActionServer(self, StartGoalAction, 'start_goal_client', self.execute_callback)

        self.rhs = None
        self.g = None
        self.U_keys = None
        self.U_mask = None
        self.grid_cost = None

    def coast_points_callback(self, msg):
        """ Processes map data and initializes a unified NumPy grid. """
        if not self.first_run:
            return
        
        self.first_run = False
        self.grid_size = np.int32(msg.grid_size)

        def extract_points(data_x, data_y):
            return np.column_stack((np.array(data_x.data), np.array(data_y.data)))

        # Load zone coordinates in GPS
        coast_points_gps = extract_points(msg.coast_points_x, msg.coast_points_y)
        red_zone_gps = extract_points(msg.red_points_x, msg.red_points_y)
        yellow_zone_gps = extract_points(msg.yellow_points_x, msg.yellow_points_y)
        green_zone_gps = extract_points(msg.green_points_x, msg.green_points_y)
        safe_zone_gps = extract_points(msg.safe_points_x, msg.safe_points_y)

        
        # Stack all GPS points together
        gps_points_stack = np.vstack((coast_points_gps, red_zone_gps, yellow_zone_gps, green_zone_gps, safe_zone_gps))

        if gps_points_stack.size == 0:
            self.get_logger().error("No valid points received. Aborting initialization.")
            return

        # print gps_points_stack
        self.get_logger().info(f"gps_points_stack: {gps_points_stack}")

        # Compute min/max GPS coordinates
        self.min_x, self.min_y = np.min(gps_points_stack, axis=0)
        self.max_x, self.max_y = np.max(gps_points_stack, axis=0)
        self.coordinates = np.array([self.min_x, self.min_y, self.max_x, self.max_y], dtype=np.float32)

        self.get_logger().info(f"Min: ({self.min_x}, {self.min_y}), Max: ({self.max_x}, {self.max_y})")

        # Convert GPS coordinates to local pixel coordinates
        self.coast_points = self.convert_gps_to_local(coast_points_gps)
        self.red_zone = self.convert_gps_to_local(red_zone_gps)
        self.yellow_zone = self.convert_gps_to_local(yellow_zone_gps)
        self.green_zone = self.convert_gps_to_local(green_zone_gps)
        self.safe_zone = self.convert_gps_to_local(safe_zone_gps)

        local_points_stack = np.vstack((self.coast_points, self.red_zone, self.yellow_zone, self.green_zone, self.safe_zone))

        self.min_local_x, self.min_local_y = np.min(local_points_stack, axis=0)
        self.max_local_x, self.max_local_y = np.max(local_points_stack, axis=0)

        self.size_x_local = int(np.ceil(self.max_local_x - self.min_local_x))
        self.size_y_local = int(np.ceil(self.max_local_y - self.min_local_y))

        self.size_x = self.size_x_local
        self.size_y = self.size_y_local

        self.get_logger().info(f"size_x: {self.size_x}, size_y: {self.size_y}")

        # Unified grid: [zone_type, movement_cost]
        self.grid = np.full((self.size_x, self.size_y, 2), fill_value=[6, 1], dtype=np.float32)

        # Assign zones with corresponding costs
        self.assign_zone(self.coast_points, 1, np.inf)  # Coast (impassable)
        self.assign_zone(self.red_zone, 2, self.cost_values[0])
        self.assign_zone(self.yellow_zone, 3, self.cost_values[1])
        self.assign_zone(self.green_zone, 4, self.cost_values[2])
        self.assign_zone(self.safe_zone, 5, self.cost_values[3])

        # Initialize D* Lite grid
        self.rhs = np.full((self.size_x, self.size_y), np.inf)
        self.g = np.full((self.size_x, self.size_y), np.inf)

        # Display the grid
        self.get_logger().info(f"Grid shape: {self.grid.shape}, Unique zone types: {np.unique(self.grid[:, :, 0])}")
        self.get_logger().info(f"Unique movement costs: {np.unique(self.grid[:, :, 1])}")

        
        # Run ROS2 path planning server
        self._action_server = ActionServer(
            self,
            StartGoalAction,
            'start_goal_client',
            self.execute_callback)
    

    def convert_gps_to_local(self, gps_points):
        #gps points is np.column_stack((np.array(data_x.data), np.array(data_y.data)))
        """ Converts GPS coordinates to local meters. """
        return np.array([
            [np.round(self.gps_to_meters(self.min_x, self.min_y, self.min_x, point[1])/self.grid_size),
             np.round(self.gps_to_meters(self.min_x, self.min_y, point[0], self.min_y)/self.grid_size)]
            for point in gps_points
        ], dtype=np.int32)

    def convert_local_to_gps(self, local_points):
        """ Converts local meters to GPS coordinates. """
        return np.array([
            self.meters_to_gps(point[0], point[1])
            for point in local_points
        ], dtype=np.float32)


    def gps_to_meters(self, lat1, lon1, lat2, lon2):
        """ Converts GPS coordinates (lat/lon) to meters using Haversine formula. """
        R = 6378137  # Radius of Earth in meters

        lat1, lon1, lat2, lon2 = map(np.radians, [lat1, lon1, lat2, lon2])  # Convert to radians

        dLat = lat2 - lat1
        dLon = lon2 - lon1

        a = np.sin(dLat / 2) ** 2 + np.cos(lat1) * np.cos(lat2) * np.sin(dLon / 2) ** 2
        c = 2 * np.arctan2(np.sqrt(a), np.sqrt(1 - a))

        return R * c  # Distance in meters


    def meters_to_gps(self, x, y):
        """ Converts meters to GPS coordinates (lat/lon) using Haversine formula. """
        latitude = self.coordinates[1] + y * (self.coordinates[3] - self.coordinates[1]) / self.size_y
        longitude = self.coordinates[0] + x * (self.coordinates[2] - self.coordinates[0]) / self.size_x

        return np.array([latitude, longitude], dtype=np.float32)



    def assign_zone(self, points, zone_type, cost):
        """ Assigns the zone type and cost in the unified NumPy grid using local coordinates. """
        if points.shape[0] == 0:
            return

        indices = np.floor(points).astype(int)

        # Ensure indices are within valid grid boundaries
        valid_mask = (indices[:, 0] >= 0) & (indices[:, 0] < self.size_x) & \
                    (indices[:, 1] >= 0) & (indices[:, 1] < self.size_y)
        valid_indices = indices[valid_mask]

        # Log assignments
        self.get_logger().info(f"Assigning zone {zone_type} to {valid_indices.shape[0]} points.")

        self.grid[valid_indices[:, 0], valid_indices[:, 1], 0] = zone_type
        self.grid[valid_indices[:, 0], valid_indices[:, 1], 1] = cost

    def execute_callback(self, goal_handle):
        """ Executes the path planning algorithm. """
        self.get_logger().info('Executing path planning')

        start_gps = np.array(goal_handle.request.start)
        goal_gps = np.array(goal_handle.request.goal)


        if np.all(start_gps == 0.0) or np.all(goal_gps == 0.0):
            self.get_logger().info("Invalid start or goal coordinates. Aborting.")
            return StartGoalAction.Result()

        # Convert GPS to grid indices
        start_idx = np.array([np.round(self.gps_to_meters(self.min_x, self.min_y, self.min_x, start_gps[1])/self.grid_size),
                              np.round(self.gps_to_meters(self.min_x, self.min_y, start_gps[0], self.min_y)/self.grid_size)], dtype=np.int32)
        
        goal_idx = np.array([np.round(self.gps_to_meters(self.min_x, self.min_y, self.min_x, goal_gps[1])/self.grid_size),
                                np.round(self.gps_to_meters(self.min_x, self.min_y, goal_gps[0], self.min_y)/self.grid_size)], dtype=np.int32)
        
        self.start = start_idx
        self.goal = goal_idx

        # grid values at start and goal
        self.get_logger().info(f"Grid value at start {self.start} : {self.grid[start_idx[0], start_idx[1]]}")
        self.get_logger().info(f"Grid value at goal {self.goal} : {self.grid[goal_idx[0], goal_idx[1]]}")

        self.print_map()

        # Check if start and goal are within grid boundaries
        if not (0 <= start_idx[0] < self.size_x and 0 <= start_idx[1] < self.size_y):
            self.get_logger().info("Start index out of bounds. Aborting.")
            return StartGoalAction.Result()

        self.get_logger().info(f"Start: {start_idx}, Goal: {goal_idx}")

        # print grid 0n position 100, 100
        self.get_logger().info(f"Grid value at start: {self.grid[start_idx[0], start_idx[1]]}")
        self.get_logger().info(f"Grid value at goal: {self.grid[goal_idx[0], goal_idx[1]]}")



        # Plan the path
        self.path = self.plan_path()

        self.get_logger().info(f"Path length: {self.path.shape[0]}")
        self.get_logger().info(f"Path: {self.path}")


    def print_map(self):
        """ Displays the map with different zones and costs in a visually appealing way. """

        plt.figure(figsize=(8, 6), dpi=300)  # High-resolution figure
        ax = plt.gca()

        # Set only the inside of the plot to light blue
        ax.set_facecolor("#ADD8E6")  # Light blue background inside the plot area

        # Define colors for better contrast
        colors = {
            "Coast": "black",
            "Red Zone": "#E74C3C",
            "Yellow Zone": "#F1C40F",
            "Green Zone": "#90EE90",  # Light Green
            "Safe Zone": "#3498DB",
            "Start": "magenta",
            "Goal": "blue"
        }

        # Plot different zones with scatter for better visibility
        if self.coast_points.size > 0:
            plt.scatter(self.coast_points[:, 0], self.coast_points[:, 1], c=colors["Coast"], s=1, label="Coast")
        if self.red_zone.size > 0:
            plt.scatter(self.red_zone[:, 0], self.red_zone[:, 1], c=colors["Red Zone"], s=1, label="Red Zone")
        if self.yellow_zone.size > 0:
            plt.scatter(self.yellow_zone[:, 0], self.yellow_zone[:, 1], c=colors["Yellow Zone"], s=1, label="Yellow Zone")
        if self.green_zone.size > 0:
            plt.scatter(self.green_zone[:, 0], self.green_zone[:, 1], c=colors["Green Zone"], s=1, label="Green Zone")
        if self.safe_zone.size > 0:
            plt.scatter(self.safe_zone[:, 0], self.safe_zone[:, 1], c=colors["Safe Zone"], s=1, label="Safe Zone")
        if self.start is not None:
            plt.scatter(self.start[0], self.start[1], c=colors["Start"], marker='o', s=10, edgecolors='black', label="Start")
        if self.goal is not None:
            plt.scatter(self.goal[0], self.goal[1], c=colors["Goal"], marker='o', s=10, edgecolors='black', label="Goal")
        if self.path.size > 0:
            plt.plot(self.path[:, 0], self.path[:, 1], color="orange", linewidth=1, label="Path")

        # Improve legend
        plt.legend(loc="upper right", fontsize=10, frameon=True, facecolor="white", edgecolor="black")

        # Set limits and aspect ratio
        plt.xlim(self.min_local_x, self.max_local_x)
        plt.ylim(self.min_local_y, self.max_local_y)
        plt.gca().set_aspect('equal', adjustable='box')

        # Add grid **in front** of the background
        plt.grid(True, linestyle='--', alpha=0.7, color='black', zorder=3)  # Grid is now on top

        # Add labels and title
        plt.xlabel("X Coordinate", fontsize=12)
        plt.ylabel("Y Coordinate", fontsize=12)
        plt.title("Map with Different Zones", fontsize=14)

        # Save high-quality image for paper
        plt.savefig("map_visualization.png", dpi=300, bbox_inches="tight")

        # Show the figure
        plt.show()

    def heuristic(self, a, b):
        """Manhattan distance heuristic."""
        return np.sum(np.abs(a - b))

    def calculate_key(self, s):
        """Computes priority queue key with movement cost."""
        min_cost = np.minimum(self.g[s[0], s[1]], self.rhs[s[0], s[1]])
        key = np.array([min_cost + self.heuristic(self.start, s), min_cost], dtype=np.float32)
        return key

    def insert(self, s):
        """Inserts a node into the priority queue."""
        self.U_keys[s[0], s[1]] = self.calculate_key(s)
        self.U_mask[s[0], s[1]] = True

    def remove(self, s):
        """Removes a node from the priority queue."""
        self.U_mask[s[0], s[1]] = False
        self.U_keys[s[0], s[1]] = np.inf

    def pop_min(self):
        """Pops the node with the smallest key from the priority queue."""
        masked_keys = np.ma.masked_array(self.U_keys[:, :, 0], mask=~self.U_mask)
        if np.all(masked_keys.mask):
            return None  # No valid nodes left

        min_idx = np.unravel_index(masked_keys.argmin(), self.U_keys.shape[:2])

        # ✅ Add debug log to confirm selection is correct
        self.get_logger().info(f"Popped node: {min_idx} with key: {self.U_keys[min_idx]}")

        self.U_mask[min_idx] = False  # Remove from queue
        return np.array(min_idx, dtype=np.int32)


    def get_neighbors(self, node):
        """Returns valid 4-connected neighbors that are within bounds and not obstacles."""
        x, y = node
        potential_neighbors = np.array([
            [x + 1, y], [x - 1, y],
            [x, y + 1], [x, y - 1]
        ], dtype=np.int32)

        valid_mask = (potential_neighbors[:, 0] >= 0) & (potential_neighbors[:, 0] < self.size_x) & \
                     (potential_neighbors[:, 1] >= 0) & (potential_neighbors[:, 1] < self.size_y)

        neighbors = potential_neighbors[valid_mask]

        # Exclude impassable cells (cost == np.inf)
        traversable_mask = self.grid_cost[neighbors[:, 0], neighbors[:, 1]] < np.inf
        return neighbors[traversable_mask]

    def update_vertex(self, u):

        if not np.array_equal(u, self.goal):
            neighbors = self.get_neighbors(u)
            if len(neighbors) > 0:
                movement_costs = self.grid_cost[neighbors[:, 0], neighbors[:, 1]]
                neighbor_costs = self.g[neighbors[:, 0], neighbors[:, 1]] + movement_costs
                self.rhs[u[0], u[1]] = np.min(neighbor_costs)

        self.remove(u)

        if not np.isclose(self.g[u[0], u[1]], self.rhs[u[0], u[1]]):
            self.insert(u)


    def compute_shortest_path(self):
        """Computes the shortest path using the priority queue."""
        while np.any(self.U_mask):  # Keep processing while queue is not empty
            u = self.pop_min()
            if u is None:
                return  # No path found


            g_old = self.g[u[0], u[1]]
            if g_old > self.rhs[u[0], u[1]]:  # Overconsistent
                self.g[u[0], u[1]] = self.rhs[u[0], u[1]]
            else:  # Underconsistent
                self.g[u[0], u[1]] = np.inf
                self.update_vertex(u)

            # ✅ Process all neighbors to ensure path expansion
            neighbors = self.get_neighbors(u)


            for n in neighbors:
                self.update_vertex(n)





    def extract_path(self):
        """Extracts the path from start to goal using movement costs."""
        path = [self.start.copy()]
        current = self.start.copy()

        while not np.array_equal(current, self.goal):
            neighbors = self.get_neighbors(current)

            if len(neighbors) == 0:
                return np.array([])  # No valid path found

            movement_costs = self.grid_cost[neighbors[:, 0], neighbors[:, 1]]
            neighbor_costs = self.g[neighbors[:, 0], neighbors[:, 1]] + movement_costs
            best_neighbor_idx = np.argmin(neighbor_costs)
            current = neighbors[best_neighbor_idx]

            if self.g[current[0], current[1]] == np.inf:
                return np.array([])  # No path exists

            path.append(current.copy())

        return np.array(path, dtype=np.int32)

    def plan_path(self):
        #make grid just a cost
        self.grid_cost = self.grid[:, :, 1]

        # Cost matrices
        self.rhs = np.full((self.size_x, self.size_y), np.inf, dtype=np.float32)
        self.g = np.full((self.size_x, self.size_y), np.inf, dtype=np.float32)

        # NumPy-based priority queue
        self.U_keys = np.full((self.size_x, self.size_y, 2), np.inf, dtype=np.float32)
        self.U_mask = np.zeros((self.size_x, self.size_y), dtype=bool)

        # Ensure goal is initialized
        self.rhs[self.goal[0], self.goal[1]] = 0.0
        self.get_logger().info(f"rhs goal: {self.rhs[self.goal[0], self.goal[1]]}")
        
        #grid cost at goal
        self.get_logger().info(f"Grid cost at goal: {self.grid_cost[self.goal[0], self.goal[1]]}")

        self.insert(self.goal)

        self.get_logger().info(f"Inserted goal {self.goal} into priority queue: {self.U_mask[self.goal[0], self.goal[1]]}")

        self.compute_shortest_path()
        return self.extract_path()


def main(args=None):
    rclpy.init(args=args)
    pp_action_server = PathPlanningServer()
    rclpy.spin(pp_action_server)

if __name__ == '__main__':
    main()
