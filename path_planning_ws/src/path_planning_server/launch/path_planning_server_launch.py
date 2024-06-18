import launch
import launch_ros.actions
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression


def generate_launch_description():

    cost_values =  LaunchConfiguration('cost_values')
    step_sizes =  LaunchConfiguration('step_sizes')
    show_feedback =  LaunchConfiguration('show_feedback')
    show_results =  LaunchConfiguration('show_results')
    show_debug =  LaunchConfiguration('show_debug')

    cost_values_arg = DeclareLaunchArgument(
        'cost_values',
        default_value= '[10.0,2.0,1.5,1.2]',
    )

    step_sizes_arg = DeclareLaunchArgument(
        'step_sizes',
        default_value= '[50.0,50.0,100.0,100.0]',
    )

    show_feedback_arg = DeclareLaunchArgument(
        'show_feedback',
        default_value='False',
        description='Whether to show the feedback of the path planning server',
    )

    show_debug_arg = DeclareLaunchArgument(
        'show_debug',
        default_value='False',
        description='Whether to show the debug of the path planning server',
    )

    show_results_arg = DeclareLaunchArgument(
        'show_results',
        default_value='False',
        description='Whether to show the results of the path planning server',
    )

    map_maker_node = Node(
        package='path_planning_server',
        executable='path_planning_server',
        output='screen',
        name='path_planning_server',
        parameters=[{'cost_values': cost_values,
                     'step_sizes': step_sizes,
                     'show_feedback': show_feedback,
                     'show_results': show_results,
                     'show_debug': show_debug}]
    )
    
    return LaunchDescription([
        cost_values_arg,
        step_sizes_arg,
        show_feedback_arg,
        show_results_arg,
        show_debug_arg,
        map_maker_node
    ])