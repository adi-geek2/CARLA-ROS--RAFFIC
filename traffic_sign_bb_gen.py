#!/usr/bin/env python
# External includes

from sensor_msgs.msg import CameraInfo, Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
import os
import rospy
import numpy as np
import random as rng
import time
import csv
import argparse

# Global variables
# get the address from OS to store the received image data
#os.chdir('./gt')
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
    # Refining and smoothening the boundaries of yellow color filter mask using morphology operations
    kernel = np.ones((3, 3), dtype=np.float32)
    yellow_filter_mask = cv2.morphologyEx(yellow_filter_mask, cv2.MORPH_OPEN, kernel)
    yellow_filter_mask = cv2.dilate(yellow_filter_mask, kernel, iterations=1)
    #cv2.imwrite('mask' + str(time_stamp) + '.png', yellow_filter_mask)
    # Applying the mask to input image
    masked_image = cv2.bitwise_and(image_to_be_processed, image_to_be_processed, mask=yellow_filter_mask)
    cv2.imwrite('masked_image' + str(time_stamp) + '.png', masked_image)
    # Extraction of traffic sign bounding boxes for each segmented image
    # Convert to gray
    gray_masked_image = cv2.cvtColor(masked_image, cv2.COLOR_BGR2GRAY)
    # Find edges
    edge_segmented_image = cv2.Canny(gray_masked_image, 150, 170)
    # Find contours : using RETR_EXTERNAL to fetch only external boundary
    _, contours, _ = cv2.findContours(edge_segmented_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    # Find the convex hull object for each contour
    hull_list = []
    for i in range(len(contours)):
	hull = cv2.convexHull(contours[i])
	hull_list.append(hull)
    # Draw contours + hull results
    # drawing = np.zeros((edge_segmented_image.shape[0], edge_segmented_image.shape[1], 3), dtype=np.uint8)
    # for i in range(len(contours)):
	# color = (rng.randint(0, 256), rng.randint(0, 256), rng.randint(0, 256))
	# cv2.drawContours(drawing, contours, i, color)
	# cv2.drawContours(drawing, hull_list, i, color)
    # Calculate the outer boundary of traffic sign by applying convex hull
    contours_poly = [None] * len(contours)
    boundRect = [None] * len(contours)
    centers = [None] * len(contours)
    radius = [None] * len(contours)
    for i, c in enumerate(contours):
	contours_poly[i] = cv2.approxPolyDP(c, 3, True)
	boundRect[i] = cv2.boundingRect(contours_poly[i])
	# Add the timestamp to bounding box parameter list		
	boundRect[i].append(timestamp)
	# Add the new bounding box to list of existing bounding boxes for the image
	bb_param_lst.append(boundRect[i])
	return bb_param_lst
	# centers[i], radius[i] = cv2.minEnclosingCircle(contours_poly[i])
    # Assign the calculated bounding rectangles and timestamp to bounding box list


    # drawing = np.zeros((edge_segmented_image.shape[0], edge_segmented_image.shape[1], 3), dtype=np.uint8)

    #for i in range(len(contours)):
	#color = (rng.randint(0, 256), rng.randint(0, 256), rng.randint(0, 256))
	#cv2.drawContours(drawing, contours_poly, i, color)
	#cv2.rectangle(drawing, (int(boundRect[i][0]), int(boundRect[i][1])), \
	              #(int(boundRect[i][0] + boundRect[i][2]), int(boundRect[i][1] + boundRect[i][3])), color, 2)
	#cv2.circle(drawing, (int(centers[i][0]), int(centers[i][1])), int(radius[i]), color, 2)
    	#cv2.imwrite('drawing' + str(time_stamp) + '.png', drawing)


def save_bb_in_csv(bb_param_lst, img_key):
    with open('label.csv', mode='w') as label_file:
	label_file.write(img_key)
        label_writer = csv.writer(label_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
	for i in range(bb_param_lst):
	    label_writer = writerow(bb_param_lst[i])


if __name__ == '__main__':
    # rospy.init_node('traffic_sign_bb_gen', anonymous=True)
    # Subscribe to the topic
    # parse arguments from OS
    parser = argparse.ArgumentParser(description="Convert ground truth semantic segmentation images into csv")
    parser.add_argument('-d', '--directory', type=str, required=True, help='Directory containing the images')
    args = parser.parse_args()	
    for img_key in os.listdir(args.directory):
	time_stamp = img_key  # Store the time stamp on the image from the image name	
    	image_gt = Image.open(args.directory+img)
    	bb_param_lst = [] #Initialize list of bounding boxes in all images	
    	bb_param_lst = calculate_bb(image_gt, time_stamp)
    	save_bb_in_csv(bb_param_lst, img_key)	

