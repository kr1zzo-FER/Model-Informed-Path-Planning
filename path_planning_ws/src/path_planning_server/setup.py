from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'path_planning_server'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
    ('share/ament_index/resource_index/packages',
        ['resource/' + package_name]),
    ('lib/' + package_name, ['package.xml']),
    ('lib/ament_index/resource_index/packages',
        ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']),
    (os.path.join('share', package_name, 'launch'), glob('launch/*launch.py')),
    (os.path.join('lib', package_name, 'launch'), glob('launch/*launch.py')),
],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='enio',
    maintainer_email='enio.krizman@fer.hr',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
           'planning_server = path_planning_server.planning_server:main'
        ],
    },
)
