/**
 * @file box_pose_pub.cpp
 * @brief Get the pose of box from gazebo and publish to ros
 */

#include <gazebo_msgs/GetModelState.h>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

ros::Publisher center_Pub;
// ros::Publisher corner_Pub;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "box_pose_pub_node");
    ros::NodeHandle nh;

    center_Pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/box_pose/box_0_center", 10);
    // corner_Pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/box_pose/box_0_corner", 10);
	gazebo_msgs::GetModelState get_model_state_srv_msg_;
    // get pv car model state client
    ros::ServiceClient get_model_state_client_ = nh.serviceClient<gazebo_msgs::GetModelState>(
		"/gazebo/get_model_state");
    ros::Rate rate(20.0);
    geometry_msgs::PoseStamped box_pose;

    while(ros::ok()){
        //get the 'Big box_0' model state from gazebo
        get_model_state_srv_msg_.request.model_name = "Big box_0";
        get_model_state_srv_msg_.request.relative_entity_name = "link";
        // "link" is the entity name when I add a Big box_0::link in gazebo
        get_model_state_client_.call(get_model_state_srv_msg_);
        box_pose.header.stamp = get_model_state_srv_msg_.response.header.stamp;
        box_pose.pose.position = get_model_state_srv_msg_.response.pose.position;
        box_pose.pose.orientation = get_model_state_srv_msg_.response.pose.orientation;
        center_Pub.publish(box_pose);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
