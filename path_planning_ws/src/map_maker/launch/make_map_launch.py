import launch
import launch_ros.actions
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():

    # Launch configurations for user-defined parameters
    save_file_name = LaunchConfiguration('save_file_name')
    locations = LaunchConfiguration('locations')
    grid_size = LaunchConfiguration('grid_size')
    show_plot = LaunchConfiguration('show_plot')

    # Declare launch arguments
    save_file_name_arg = DeclareLaunchArgument(
        'save_file_name',
        default_value='jadranovo',
        description='Name of the processed map file to save'
    )

    locations_arg = DeclareLaunchArgument(
        'locations',
        default_value='["sv_marko","voz","jadranovo", "kacjak", "rudine"]',
        description='List of input data folder names'
    )

    grid_size_arg = DeclareLaunchArgument(
        'grid_size',
        default_value='10',
        description='Grid size for taking coordinates every N meters'
    )

    show_plot_arg = DeclareLaunchArgument(
        'show_plot',
        default_value='True',
        description='Whether to show the result in a plot'
    )

    # Node definition
    map_process_node = launch_ros.actions.Node(
        package='map_maker',
        executable='map_process',
        output='screen',
        emulate_tty=True,
        name='map_process_jadranovo',
        parameters=[{
            'save_file': save_file_name,
            'locations': locations,
            'grid_size': grid_size,
            'show_plot': show_plot
        }]
    )

    return LaunchDescription([
        save_file_name_arg,
        locations_arg,
        grid_size_arg,
        show_plot_arg,
        map_process_node
    ])