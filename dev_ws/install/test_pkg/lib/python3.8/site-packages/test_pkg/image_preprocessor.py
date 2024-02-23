# Import necessary libraries
import cv2
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO
from eufs_msgs.msg import BoundingBoxes, BoundingBox 



class ImagePreprocessor(Node):
    def __init__(self):
        super().__init__('image_preprocessor')

        # Load the YOLOv8 model
        self.model = YOLO('/home/hammad/Desktop/test_pkg_ros-master/src/test_pkg/test_pkg/last.pt')

        # Create subscribers and publishers
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            10)
        self.publisher = self.create_publisher(Image, '/preprocessed_images', 10)
        self.bounding_box_publisher = self.create_publisher(BoundingBoxes, '/bounding_boxess', 10)
        self.bridge = CvBridge()

    def image_callback(self, msg):
        try:
        	
            # Convert ROS Image message to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

            # Perform your image preprocessing here (e.g., resize)
            
            desired_width = 640
            desired_height = 640
            preprocessed_image = cv2.resize(cv_image, (desired_width, desired_height))
            #preprocessed_image = cv_image

            # Run YOLOv8 inference on the frame
            results = self.model(preprocessed_image)
            
            bounding_boxes = BoundingBoxes()
            	
            	# Set the header with the current time in seconds and nanoseconds
            bounding_boxes.header.stamp = msg.header.stamp 
            bounding_boxes.header.frame_id = msg.header.frame_id

            for result in results:
            	boxes =result.boxes.cpu().numpy()
            	

            	for i in range(len(boxes.conf)):
            		
            		bounding_box = BoundingBox()
            		bounding_box.xmin = float(boxes.xyxy[i][0])
            		bounding_box.ymin = float(boxes.xyxy[i][1])
            		bounding_box.xmax = float(boxes.xyxy[i][2])
            		bounding_box.ymax = float(boxes.xyxy[i][3])
            		
            		
            		if boxes.cls[i]== 1:
            			bounding_box.color = "yellow"  # Set the color as needed
            		elif boxes.cls[i] == 2:
            			bounding_box.color = "blue"  # Set the color as needed
            		elif boxes.cls[i] == 4:
            			bounding_box.color = "redb"  # Set the color as needed
            		elif boxes.cls[i] == 3:
            			bounding_box.color = "reds"  # Set the color as needed
            		else:
            			bounding_box.color = "redp"  # Set the color as needed
            			
            		
            		
            		bounding_box.probability= float(boxes.conf[i])
            		bounding_box.type =  BoundingBox.PIXEL
            		
            		
            		bounding_boxes.bounding_boxes.append(bounding_box)
            
             # Set image_header based on the input msg		
            bounding_boxes.image_header.stamp = msg.header.stamp
            bounding_boxes.image_header.frame_id = msg.header.frame_id
            
            
            self.bounding_box_publisher.publish(bounding_boxes)
            		



            	
            	
            

            # Do something with the bounding box information

            # Annotate the frame with bounding boxes (this is just an example)
            annotated_frame = results[0].plot()

            # Display the annotated frame (optional)
            cv2.imshow("YOLOv8 Inference", annotated_frame)
            cv2.waitKey(1)  # Adjust the delay as needed

            # Convert the annotated frame back to ROS Image message
            preprocessed_msg = self.bridge.cv2_to_imgmsg(annotated_frame, encoding='bgr8')
            self.publisher.publish(preprocessed_msg)

        except Exception as e:
            self.get_logger().error(str(e))

def main(args=None):
    rclpy.init(args=args)
    image_preprocessor = ImagePreprocessor()
    rclpy.spin(image_preprocessor)
    image_preprocessor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

