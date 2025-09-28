#!/bin/bash
# add_ros2_jazzy_source.sh

CUR_DIR=$(pwd)

WS_SETUP="$CUR_DIR/install/setup.bash"

# Add ROS 2 Jazzy source if not already in ~/.bashrc
if ! grep -Fxq "source $ROS_SETUP" ~/.bashrc; then
    echo "source $ROS_SETUP" >> ~/.bashrc
    echo "Added: source $ROS_SETUP to ~/.bashrc"
else
    echo "ROS 2 Jazzy source already in ~/.bashrc"
fi

# Add workspace source if not already in ~/.bashrc
if ! grep -Fxq "source $WS_SETUP" ~/.bashrc; then
    echo "source $WS_SETUP" >> ~/.bashrc
    echo "Added: source $WS_SETUP to ~/.bashrc"
else
    echo "Workspace source already in ~/.bashrc"
fi

