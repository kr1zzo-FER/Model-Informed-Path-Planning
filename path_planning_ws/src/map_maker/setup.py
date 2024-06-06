from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'map_maker'

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
    data_files=package_files(data_files, ['input_data/', 'launch/']),
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='enio',
    maintainer_email='enio.krizman@fer.hr',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
           'map_process = map_maker.map_process:main',
           'detect_coast = map_maker.detect_coast:CoastProcessing',
           'process_osm_data = map_maker.process_osm_data',
           'post_processing = map_maker.post_processing',
           'map_publisher = map_maker.map_publisher:main',
           'map_visualization = map_maker.map_visualization:main'
        ],
    },
)
