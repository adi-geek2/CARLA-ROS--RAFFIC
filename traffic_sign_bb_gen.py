#!/usr/bin/env python
# External includes
from PIL import Image
#from sensor_msgs.msg import CameraInfo, Image
#from cv_bridge import CvBridge, CvBridgeError
import cv2
import os
#import rospy
import numpy as np
import random as rng
import time
import csv
import argparse

# Global variables
bb_param_array_final_list_of_list = []

bb_param_lst_img = [] #Initialize list of bounding boxes for a single image
bb_param_lst_all_images = [] #Initialize list of bounding boxes in all images as a list
#Data type definition for creating a mixed numpy array holding bounding box parameters
mtype = 'object'

# Random number generation used for lines of bounding box rectangles
#rng.seed(12345)


def calculate_bb(ground_truth_image, time_stamp):
    image_to_be_processed = ground_truth_image  # Input image
    #image_to_be_processed = cv2.cvtColor(image_to_be_processed, cv2.COLOR_RGBA2RGB)
    #cv2.imwrite('input' + str(time_stamp) + '.png', image_to_be_processed)
    # Color based segmentation for yellow color
    lower_boundary_yellow_color = (0, 200, 200)
    upper_boundary_yellow_color = (0, 240, 240)
    yellow_filter_mask = cv2.inRange(image_to_be_processed, lower_boundary_yellow_color, upper_boundary_yellow_color)
    # Refining and smoothing the boundaries of yellow color filter mask using morphology operations
    kernel = np.ones((3, 3), dtype=np.float32)
    yellow_filter_mask = cv2.morphologyEx(yellow_filter_mask, cv2.MORPH_OPEN, kernel)
    yellow_filter_mask = cv2.dilate(yellow_filter_mask, kernel, iterations=1)
    # Applying the mask to input image
    masked_image = cv2.bitwise_and(image_to_be_processed, image_to_be_processed, mask=yellow_filter_mask)
    # Module : Extraction of traffic sign bounding boxes for each segmented image
    # Convert to gray
    gray_masked_image = cv2.cvtColor(masked_image, cv2.COLOR_BGR2GRAY)
    # Find edges
    edge_segmented_image = cv2.Canny(gray_masked_image, 150, 170)
    # Find contours : using RETR_EXTERNAL to fetch only external boundary
    contours, _ = cv2.findContours(edge_segmented_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    # Find the convex hull object for each contour
    hull_list = []
    for i in range(len(contours)):
        hull = cv2.convexHull(contours[i])
        hull_list.append(hull)
    contours_poly = [None] * len(contours)
    boundRect = [None] * len(contours)
    #print(type(boundRect))
    # centers = [None] * len(contours)
    # radius = [None] * len(contours)
    for i, c in enumerate(contours):
        contours_poly[i] = cv2.approxPolyDP(c, 3, True)
        boundRect[i] = cv2.boundingRect(contours_poly[i])
        #Add the timestamp to bounding box parameter list
        #print(type(boundRect[i]))
        #list(boundRect[i])
        #boundRect[i].append(timestamp)
        bb_param_lst_img.append(boundRect[i])
    # Add the new bounding box to list of existing bounding boxes for the image
    return bb_param_lst_img


def save_bb_in_csv(bb_param_lst_img):
    #print(type(bb_param_lst_img))
    with open('label.csv', mode='w') as label_file:
        label_writer = csv.writer(label_file)#, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        for row in bb_param_lst_img:
            label_writer.writerow(row)


if __name__ == '__main__':
    # rospy.init_node('traffic_sign_bb_gen', anonymous=True)
    # Subscribe to the topic
    # parse arguments from OS
    parser = argparse.ArgumentParser(description="Convert ground truth semantic segmentation images into csv")
    parser.add_argument('-d', '--directory', type=str, required=True, help='Directory containing the images')
    args = parser.parse_args()	
    for img_key in os.listdir(args.directory):
        # get the address from OS to open the input image data
        #os.chdir('./gt')
        #Initializing array to hold the bb params
        bb_param_array_final = np.ones((1, 5), dtype=mtype)
        bb_param_array_final_list = []
        #print(bb_param_array_final.shape)
        #Iterator for placing timestamps
        time_stamp_iterator = 0
        time_stamp = img_key  # Store the time stamp on the image from the image name
        bb_param_array_final[0][4] = time_stamp
        bb_param_array_final_list.append(bb_param_array_final[0][4])
        #print(bb_param_array_final.shape)
        image_gt = cv2.imread(args.directory + img_key)
        bb_param_tuple = calculate_bb(image_gt, time_stamp)
        bb_param_tuple_array = np.array(bb_param_tuple)
        bb_param_array_final[0][0] = bb_param_tuple_array[0][0]
        bb_param_array_final_list.append(bb_param_array_final[0][0])
        bb_param_array_final[0][1] = bb_param_tuple_array[0][1]
        bb_param_array_final_list.append(bb_param_array_final[0][1])
        bb_param_array_final[0][2] = bb_param_tuple_array[0][2]
        bb_param_array_final_list.append(bb_param_array_final[0][2])
        bb_param_array_final[0][3] = bb_param_tuple_array[0][3]
        bb_param_array_final_list.append(bb_param_array_final[0][0])
        #print(bb_param_array_final_list)
        bb_param_array_final_list_of_list.append(bb_param_array_final_list)
        #bb_param_array_final_list.append()
        # bb_param_array_final_list_of_list =
        #print(bb_param_array_final)
        #bb_param_lst_all_images.append(bb_param_array_final)
    save_bb_in_csv(bb_param_array_final_list_of_list)

