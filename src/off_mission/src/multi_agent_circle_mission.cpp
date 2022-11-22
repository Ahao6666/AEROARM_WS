/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

mavros_msgs::State uav1_current_state;
geometry_msgs::PoseStamped uav1_local_pose,uav0_local_pose;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    uav1_current_state = *msg;}
void uav1_local_pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
    uav1_local_pose = *msg;}
void uav0_local_pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
    uav0_local_pose = *msg;}


int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber uav0_local_pose_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("uav0/mavros/local_position/pose", 10, uav0_local_pose_cb);
    ros::Subscriber uav1_state_sub = nh.subscribe<mavros_msgs::State>
            ("uav1/mavros/state", 10, state_cb);
    ros::Subscriber uav1_local_pose_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("uav1/mavros/local_position/pose", 10, uav1_local_pose_cb);
    ros::Publisher uav1_local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("uav1/mavros/setpoint_position/local", 10);
    ros::ServiceClient uav1_arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("uav1/mavros/cmd/arming");
    ros::ServiceClient uav1_set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("uav1/mavros/set_mode");
    double uav1_position_offset_x=0;
    double uav1_position_offset_y=0;
    double uav1_position_offset_z=0;
    ros::param::get("/uav1/uav1_position_offset_x", uav1_position_offset_x);
    ros::param::get("/uav1/uav1_position_offset_y", uav1_position_offset_y);
    ros::param::get("/uav1/uav1_position_offset_z", uav1_position_offset_z);
    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && !uav1_current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped uav1_set_pose;
    uav1_set_pose.pose.position.x = uav0_local_pose.pose.position.x - uav1_position_offset_x;
    uav1_set_pose.pose.position.y = uav0_local_pose.pose.position.y - uav1_position_offset_y;
    uav1_set_pose.pose.position.z = uav0_local_pose.pose.position.z - uav1_position_offset_z + 3;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        uav1_local_pos_pub.publish(uav1_set_pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode uav1_offb_set_mode;
    uav1_offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool uav1_arm_cmd;
    uav1_arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        if( uav1_current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( uav1_set_mode_client.call(uav1_offb_set_mode) &&
                uav1_offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
        } else {
            if( !uav1_current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( uav1_arming_client.call(uav1_arm_cmd) &&
                    uav1_arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }
        double run_time = ros::Time::now().toSec();
        // ROS_INFO("UAV0 position is:X= %f\t, Y=%f\t, Z=%f\t\n",uav0_local_pose.pose.position.x, 
        //     uav0_local_pose.pose.position.y, uav0_local_pose.pose.position.z);
        // ROS_INFO("UAV1 position is:X= %f\t, Y=%f\t, Z=%f\t\n",uav1_local_pose.pose.position.x, 
        //     uav1_local_pose.pose.position.y, uav1_local_pose.pose.position.z);

        uav1_set_pose.pose.position.x = uav0_local_pose.pose.position.x - uav1_position_offset_x + 3 * sin(0.5 * run_time);
        uav1_set_pose.pose.position.y = uav0_local_pose.pose.position.y - uav1_position_offset_y + 3 * cos(0.5 * run_time);
        uav1_set_pose.pose.position.z = uav0_local_pose.pose.position.z - uav1_position_offset_z + 3;
        
        uav1_local_pos_pub.publish(uav1_set_pose);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

