
#!/usr/bin/python3
from re import S
import sys
import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from message_filters import Subscriber, ApproximateTimeSynchronizer
from sensor_msgs.msg import Image, CameraInfo
#from eufs_msgs.msg import BoundingBoxes
from visualization_msgs.msg import MarkerArray, Marker
from geometry_msgs.msg import TransformStamped
import tf2_ros
from eufs_msgs.msg import BoundingBoxes, ConesDepth,ConeDepth 

class DepthViewer(Node):
    def __init__(self):
        super().__init__('depth_viewer')


        self.timer_period = 0.1  # Set the timer period (e.g., 0.1 seconds or 10 Hz)
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        # Subscribe to the left rectified image
        self.left_sub = Subscriber(
            self,
            Image,
            '/zed/zed_node/left/image_rect_color',
        )

        # Subscribe to the depth image
        self.depth_sub = Subscriber(
            self,
            Image,
            '/zed/zed_node/depth/depth_registered',
        )

        # Subscribe to the bounding boxes
        self.bound_box_sub = Subscriber(
            self,
            BoundingBoxes,
            '/bounding_boxess',
        )

        # Create the approximate time synchronizer to sync the subscribers
        self.ats = ApproximateTimeSynchronizer(
            [self.left_sub, self.depth_sub, self.bound_box_sub],
            100,
            0.1  # The slop should almost always be small!
            
            
        )

        # Subscribe to the depth camera info
        self.depth_info_sub = self.create_subscription(
            CameraInfo,
            '/zed/zed_node/depth/camera_info',
            self.depth_info_callback,
            2
        )

        self.depth_info = None  # Variable to store camera info

        self.marker_pub = self.create_publisher(MarkerArray, '/cone_markers', 2)
        
        self.cones_depth_pub = self.create_publisher(ConesDepth, '/cones_center_depth', 2)
        
          # Create a publisher for MarkerArray

        # Create a TF broadcaster
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)

        # Register the callback with the approximate time synchronizer
        self.ats.registerCallback(self.synced_callback)

        self.bridge = CvBridge()

        self.image_pub = self.create_publisher(Image, '/processed_image', 2)  # Create a publisher for the processed image

    def depth_info_callback(self, msg):
        # Store the camera info for further use
        self.depth_info = msg
        self.destroy_subscription(self.depth_info_sub)  # Unsubscribe as we only need the info once

    def synced_callback(self, left_image_msg, depth_image_msg, bounding_boxes_msg):
        # Convert image messages to OpenCV matrices
        left_image_cv = self.bridge.imgmsg_to_cv2(left_image_msg, desired_encoding="bgr8")
        
        
        #left_image_cv =cv2.resize(left_image_cv, (640, 640))
        depth_image_cv = self.bridge.imgmsg_to_cv2(depth_image_msg, desired_encoding="32FC1")
        
        left_image_cv = cv2.resize(left_image_cv, (640, 640))
        depth_image_cv = cv2.resize(depth_image_cv, (640, 640),interpolation=cv2.INTER_LINEAR)
        
        tf_stamped = None
        print("Received synchronized images")  # Add this line for verification

        cones_depth = ConesDepth()
        cones_depth.header.stamp = left_image_msg.header.stamp 
        cones_depth.header.frame_id = left_image_msg.header.frame_id

        if self.depth_info is not None:
            fx = self.depth_info.p[0]  # fx is p[0]
            fy = self.depth_info.p[5]  # fy is p[5]
            cx = self.depth_info.p[2]  # cx is p[2]
            cy = self.depth_info.p[6]  # cy is p[6]
            depth_frame_id = depth_image_msg.header.frame_id
            marker_array = MarkerArray()


            #calculation of 3d coordinates
            projection_matrix= np.array([[fx, 0, cx,0],
                                         [0, fy, cy, 0],
                                         [0, 0, 1, 0]])
            
            pseudo_inv_proj_matrix= np.linalg.pinv(projection_matrix)



            # Access the bounding boxes data from the message
            bounding_boxes = bounding_boxes_msg.bounding_boxes

            # Extract the left image dimensions
            height, width, _ = left_image_cv.shape

# ...    

            
            marker_array = MarkerArray()
            tf_stamped = None
            
            for i, bbox in enumerate(bounding_boxes):
                    # ... (rest of the marker creation code)
                x_min = int(bbox.xmin)
                y_min = int(bbox.ymin)
                x_max = int(bbox.xmax)
                y_max = int(bbox.ymax)
                    
                # Calculate center of the bounding box
                center_x = (x_min + x_max) // 2
                center_y = (y_min + y_max) // 2

                cone_depth = ConeDepth()



                # Get depth value at the center of the bounding box
                depth = depth_image_cv[center_y, center_x]
                if np.isnan(depth):
                    continue

                # Calculate 3D coordinates based on the depth value
                image_coord = np.array([center_x, center_y, 1])
                homogenous_3d_coordinates = np.dot(pseudo_inv_proj_matrix, image_coord)
                x_3d = homogenous_3d_coordinates[0]
                y_3d = homogenous_3d_coordinates[1]
                z_3d = homogenous_3d_coordinates[2]

                X = x_3d
                Y = y_3d
                Z = z_3d

                # Create a single Marker for each cone and add it to the MarkerArray
                marker = Marker()
                marker.header.frame_id = depth_frame_id
                marker.type = Marker.SPHERE
                marker.action = Marker.ADD
                marker.id = i
                
                marker.pose.position.x = X
                marker.pose.position.y = Y
                marker.pose.position.z = float(Z)
                marker.scale.x = 0.1
                marker.scale.y = 0.1
                marker.scale.z = 0.1
                marker.color.a = 1.0
                marker.color.r = 0.0
                marker.color.g = 0.0
                marker.color.b = 1.0
                
                

                # Add the marker to the MarkerArray
                marker_array.markers.append(marker)

                # Create a TransformStamped message for each cone
                tf_stamped = TransformStamped()
                tf_stamped.header.stamp = left_image_msg.header.stamp
                tf_stamped.header.frame_id = "zed2i_left_camera_optical_frame"
                tf_stamped.child_frame_id = f"cone_frame_{i}"
                tf_stamped.transform.translation.x = X
                tf_stamped.transform.translation.y = Y
                tf_stamped.transform.translation.z = float(Z)
                self.tf_broadcaster.sendTransform(tf_stamped)

            # Draw bounding boxes on the left image
                cone_color = (0,0, 255)  # Default to red if color is not specified
                if bbox.color.lower() == 'blue':
                    cone_color = (255,0, 0)  # Blue
                elif bbox.color.lower() == 'yellow':
                    cone_color = (0, 255, 255)  # Blue
                if np.isnan(depth):
            # Skip processing for nan values
                    continue



                cone_depth.color= bbox.color
                cone_depth.depth= float(depth)
                print("depth: ",depth)

                cones_depth.cones_depth.append(cone_depth)

                cv2.rectangle(left_image_cv, (x_min, y_min), (x_max, y_max), cone_color, 2)  # Green rectangles

        # Display depth value on the top-left corner of the rectangle
            # Display depth value in the top-left corner with the same color as the rectangle

                depth_text = f"Depth: {depth:.2f} m"
                cv2.putText(left_image_cv, depth_text, (x_min, y_min), cv2.FONT_HERSHEY_SIMPLEX, 0.5, cone_color, 2)


            

# ...

        



        self.marker_pub.publish(marker_array)

        cones_depth.image_header.stamp = left_image_msg.header.stamp
        cones_depth.image_header.frame_id = left_image_msg.header.frame_id

        self.cones_depth_pub.publish(cones_depth)

        # After processing, publish the image
        processed_image_msg = self.bridge.cv2_to_imgmsg(left_image_cv, encoding="bgr8")
        self.image_pub.publish(processed_image_msg)
        
        # Now you have the synchronized image matrices and bounding boxes
        # Implement your processing logic here
        
        
        
    def timer_callback(self):
        # This callback will be executed at the specified rate
        # Put your synchronized callback logic here
        print("Timer callback")
def main():
    rclpy.init(args=sys.argv)
    dv = DepthViewer()
    rclpy.spin(dv)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

    
