#!/bin/bash

ros2 launch map_maker publish_map_launch.py save_file:="jadranovo"

ros2 launch path_planning_action rviz2_pointcloud_launch.py 



