from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # ros2 run image_transport republish compressed raw --ros-args \
    #   --remap in/compressed:=/camera/left/image_rect_color/compressed \
    #   --remap out:=/camera/left/image_rect_color
    left_image_uncompresser_node = Node(
        package='image_transport',
        executable='republish',
        name='left_image_uncompresser',
        arguments=[
            'compressed',
            'raw',
        ],
        remappings=[
            ('in/compressed', '/camera/left/image_rect_color/compressed'),
            ('out', '/camera/left/image_rect_color'),
        ],
    )

    # ros2 run image_transport republish compressed raw --ros-args \
    #   --remap in/compressed:=/camera/right/image_rect_color/compressed \
    #   --remap out:=/camera/right/image_rect_color
    right_image_uncompresser_node = Node(
        package='image_transport',
        executable='republish',
        name='right_image_uncompresser',
        arguments=[
            'compressed',
            'raw',
        ],
        remappings=[
            ('in/compressed', '/camera/right/image_rect_color/compressed'),
            ('out', '/camera/right/image_rect_color'),
        ],
    )

    # ros2 run image_transport republish compressed raw --ros-args \
    #   --remap in/angusDepth:=/camera/depth/depth_registered/angusDepth \
    #   --remap out:=/camera/depth/depth_registered
    depth_image_uncompresser_node = Node(
        package='image_transport',
        executable='republish',
        name='depth_image_uncompresser',
        arguments=[
            'angusDepth',
            'raw',
        ],
        remappings=[
            ('in/angusDepth', '/camera/depth/depth_registered/angusDepth'),
            ('out', '/camera/depth/depth_registered'),
        ],
    )

    ld = LaunchDescription()
    ld.add_action(left_image_uncompresser_node)
    ld.add_action(right_image_uncompresser_node)
    ld.add_action(depth_image_uncompresser_node)

    return ld
