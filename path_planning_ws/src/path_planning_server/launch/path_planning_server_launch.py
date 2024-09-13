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
    speed_limits =  LaunchConfiguration('speed_limits')
    show_feedback =  LaunchConfiguration('show_feedback')
    show_results =  LaunchConfiguration('show_results')
    show_debug =  LaunchConfiguration('show_debug')
    optimization_method =  LaunchConfiguration('optimization_method')
    sampling_rate =  LaunchConfiguration('sampling_rate')   
    show_downsampling =  LaunchConfiguration('show_downsampling')
    show_interpolation =  LaunchConfiguration('show_interpolation')

    cost_values_arg = DeclareLaunchArgument(
        'cost_values',
        default_value= '[10.0,2.0,1.5,1.2]',
    )

    step_sizes_arg = DeclareLaunchArgument(
        'step_sizes',
        default_value= '[50.0,50.0,100.0,100.0]',
    )

    speed_limits_arg = DeclareLaunchArgument(
        'speed_limits',
        default_value= '[2.0,5.0,8.0,25.0]',
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

    optimization_method_arg = DeclareLaunchArgument(
        'optimization_method',
        default_value='polynomial',
        description='The optimization method to use',
    )

    sampling_rate_arg = DeclareLaunchArgument(
        'sampling_rate',
        default_value='5.0',
        description='The sampling rate to use',
    )

    show_downsampling_arg = DeclareLaunchArgument(
        'show_downsampling',
        default_value='False',
        description='Whether to show the downsampling of the path planning server',
    )

    show_interpolation_arg = DeclareLaunchArgument(
        'show_interpolation',
        default_value='False',
        description='Whether to show the interpolation of the path planning server',
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
                     'show_debug': show_debug,
                     'optimization_method': optimization_method,
                     'speed_limits': speed_limits,
                     'sampling_rate': sampling_rate,
                     'show_downsampling': show_downsampling,
                     'show_interpolation': show_interpolation,}]
    )


    
    return LaunchDescription([
        cost_values_arg,
        step_sizes_arg,
        speed_limits_arg,
        show_feedback_arg,
        show_results_arg,
        show_debug_arg,
        show_downsampling_arg,
        show_interpolation_arg,
        optimization_method_arg,
        sampling_rate_arg,
        map_maker_node
    ])