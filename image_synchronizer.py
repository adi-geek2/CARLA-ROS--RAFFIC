#!/usr/bin/env python


from sensor_msgs.msg import CameraInfo, Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
import os
import time
import rospy
import message_filters

# get the address from OS to store the received image data
os.chdir('/home/rosuser/Pictures/train')

g_image_pipeline_width = 10


def callback(image, info):
    #assert image_rgb.header.stamp == image_gt.header.stamp
    #print ("got an Image and Groundtruth")
    print(info.header.stamp)
    #print(image_gt.header.stamp)
    image_to_be_saved_rgb = CvBridge().imgmsg_to_cv2(image, "bgra8")
    time_string = time.strftime("%Y%m%d-%H%M%S")
    #rospy.loginfo(info_rgb)
    # numpy.save(time_string, carla_image, allow_pickle=True, fix_imports=True)
    cv2.imwrite('' + time_string + '.png', image_to_be_saved_rgb)
    print("info")
    #cv2.imwrite('' + time_string + '.png', image_to_be_saved_gt)


if __name__ == '__main__':
    rospy.init_node('image_synchronizer', anonymous=True)
    print("main")
    image_rgb = message_filters.Subscriber('/carla/ego_vehicle/camera/rgb/front/image_color', Image)
    info_rgb = message_filters.Subscriber('/carla/ego_vehicle/camera/rgb/front/image_color/camera_info', CameraInfo)
    ts_rgb = message_filters.ApproximateTimeSynchronizer([image_rgb, info_rgb], g_image_pipeline_width, 0.1)
    ts_rgb.registerCallback(callback)
    image_gt = message_filters.Subscriber('/carla/ego_vehicle/camera/semantic_segmentation/front/image_segmentation',
                                        Image)
    info_gt = message_filters.Subscriber('/carla/ego_vehicle/camera/semantic_segmentation/front/image_segmentation/camera_info',
                                        CameraInfo)
    ts_gt = message_filters.ApproximateTimeSynchronizer([image_gt, info_gt], g_image_pipeline_width, 0.1)
    ts_gt.registerCallback(callback)
    rospy.spin()

