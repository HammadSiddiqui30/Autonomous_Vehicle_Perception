from setuptools import setup
from glob import glob

package_name = 'depth_viewer'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='J Keane Quigley',
    maintainer_email='keaneq@protonmail.com',
    description='EUFS perception workshop',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'depth_viewer = depth_viewer.depth_viewer:main'
        ],
    },
)
