/**
 * @file box_pose_pub.cpp
 * @brief Get the pose of box from gazebo and publish to ros
 */

#include <gazebo_msgs/GetModelState.h>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include "task_plan/corner.h"

ros::Publisher center_Pub;
ros::Publisher corner_Pub;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "box_pose_pub_node");
    ros::NodeHandle nh;
    float length = 2.68129; //1;   //3.01935;
    float width = 1;    //2.86748;  //1.14714;
    float hight = 1;
    center_Pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/box_pose/box_0_center", 10);
    corner_Pub = nh.advertise<task_plan::corner>("mavros/box_pose/box_0_corner", 10);
	gazebo_msgs::GetModelState get_model_state_srv_msg_;
    // get pv car model state client
    ros::ServiceClient get_model_state_client_ = nh.serviceClient<gazebo_msgs::GetModelState>(
		"/gazebo/get_model_state");
    ros::Rate rate(20.0);
    geometry_msgs::PoseStamped box_pose;
    task_plan::corner box_corner;

    while(ros::ok()){
        //get the 'Big box_0' model state from gazebo
        get_model_state_srv_msg_.request.model_name = "payload box";
        get_model_state_srv_msg_.request.relative_entity_name = "link";
        // "link" is the entity name when I add a Big box_0::link in gazebo
        get_model_state_client_.call(get_model_state_srv_msg_);
        box_pose.header.stamp = get_model_state_srv_msg_.response.header.stamp;
        box_pose.pose.position = get_model_state_srv_msg_.response.pose.position;
        box_pose.pose.orientation = get_model_state_srv_msg_.response.pose.orientation;
        center_Pub.publish(box_pose);

        box_corner.header.stamp = get_model_state_srv_msg_.response.header.stamp;
        box_corner.header.frame_id = "box corner";
        box_corner.corner_1 = {box_pose.pose.position.x + length/2,
                               box_pose.pose.position.y + width/2, 
                               box_pose.pose.position.z + hight/2};
        box_corner.corner_2 = box_corner.corner_1;
        box_corner.corner_2[1] = box_corner.corner_1[1] - width;
        box_corner.corner_3 = box_corner.corner_2;
        box_corner.corner_3[0] = box_corner.corner_2[0] - length;
        box_corner.corner_4 = box_corner.corner_3;
        box_corner.corner_4[1] = box_corner.corner_3[1] + width;
        box_corner.corner_5 = box_corner.corner_1;
        box_corner.corner_5[2] = box_corner.corner_1[2] - hight;
        box_corner.corner_6 = box_corner.corner_2;
        box_corner.corner_6[2] = box_corner.corner_2[2] - hight;
        box_corner.corner_7 = box_corner.corner_3;
        box_corner.corner_7[2] = box_corner.corner_3[2] - hight;
        box_corner.corner_8 = box_corner.corner_4;
        box_corner.corner_8[2] = box_corner.corner_4[2] - hight;

        corner_Pub.publish(box_corner);
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
