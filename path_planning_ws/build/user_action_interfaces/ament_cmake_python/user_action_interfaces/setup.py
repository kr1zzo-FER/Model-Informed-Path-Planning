from setuptools import find_packages
from setuptools import setup

setup(
    name='user_action_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('user_action_interfaces', 'user_action_interfaces.*')),
)
