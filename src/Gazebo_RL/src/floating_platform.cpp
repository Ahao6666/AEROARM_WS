/******************************************************************************
 * Copyright (c) 2022-2024 The IUSL_UAV Shen Jiahao. All rights reserved.
 * See the AUTHORS file for names of contributors.
 *****************************************************************************/

/******************************************************************************
 * @file floating_platform.cpp
 * @author Shen Jiahao <shenjiahao@westlake.edu.cn>
 *****************************************************************************/
#include <ros/ros.h>
#include <math.h>
#include <string>
#include <gazebo_msgs/SetLinkState.h>
#include <geometry_msgs/Point.h>

int main(int argc, char** argv) {
	// Initialize the ROS node
	ros::init(argc, argv, "floating_platform_node");
	ros::NodeHandle node_handle;

	// Create a service client for the Gazebo SetLinkState service
	ros::ServiceClient client = node_handle.serviceClient<gazebo_msgs::SetLinkState>("/gazebo/set_link_state");

	// Create a SetLinkState message object
    gazebo_msgs::SetLinkState objstate;

    // Set the link name and reference frame for the SetLinkState message
    objstate.request.link_state.link_name = "toolbox::platform";
	objstate.request.link_state.reference_frame = "world";

	// Set the sample time for the loop
	ros::Rate rate_timer(1 / 0.01);

	// Loop while ROS is still running
	while(ros::ok()) {
		// Set the position and orientation of the platform using a sine and cosine function
		objstate.request.link_state.pose.position.x = 0.5* cos(0.25 * ros::Time::now().toSec());
		objstate.request.link_state.pose.position.y = 0.5* sin(0.25 * ros::Time::now().toSec());
		objstate.request.link_state.pose.position.z = 0.2;
		objstate.request.link_state.pose.orientation.w = 1;
		objstate.request.link_state.pose.orientation.x = 0;
		objstate.request.link_state.pose.orientation.y = 0;
		objstate.request.link_state.pose.orientation.z = 0;

		// Call the SetLinkState service and check for errors
		if (!client.call(objstate)) {
			ROS_ERROR("Failed to call SetLinkState service");
		}

		// Spin once to process any callbacks
		ros::spinOnce();

		// Sleep for the sample time
		rate_timer.sleep();
	}

	// Exit the program
	return 0;
}

