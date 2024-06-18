from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'path_planning_client'

data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ]


def package_files(data_files, directory_list):

    paths_dict = {}
    
    folders = ['share', 'lib', 'lib/python3.10/site-packages']
    
    for folder in folders:
        for directory in directory_list:

            for (path, directories, filenames) in os.walk(directory):

                for filename in filenames:

                    file_path = os.path.join(path, filename)
                    install_path = os.path.join(folder, package_name, path)

                    if install_path in paths_dict.keys():
                        paths_dict[install_path].append(file_path)

                    else:
                        paths_dict[install_path] = [file_path]

        for key in paths_dict.keys():
            data_files.append((key, paths_dict[key]))

    return data_files

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=package_files(data_files, ['launch/', 'rviz2/']),
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='enio',
    maintainer_email='enio.krizman@fer.hr',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
           'start_goal_client = path_planning_client.start_goal_client:main',
           'start_goal_publisher = path_planning_client.start_goal_publisher:main',
           'pointcloud_publisher = path_planning_client.pointcloud_publisher:main',
           'rviz2_launch = path_planning_client.rviz2_launch:main',
           'start_goal_update = path_planning_client.start_goal_update:main',
           
        ],
    },
)
