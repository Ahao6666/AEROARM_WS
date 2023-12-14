#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <gazebo_msgs/GetLinkState.h>
#include <eigen3/Eigen/Dense>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include "aerial_toolbox/toolbox.h"
#include "aerial_toolbox/toolbox_array.h"
#include <iostream>
using namespace std;

geometry_msgs::PoseStamped air_toolbox_data;
geometry_msgs::PoseStamped air_manipulator_data;
Eigen::Matrix3f air_toolbox_mat;
Eigen::Matrix3f air_manipulator_mat;

void air_toolbox_Callback(const geometry_msgs::PoseStamped::ConstPtr &msg){
    air_toolbox_data.pose.position.x = msg->pose.position.x;
    air_toolbox_data.pose.position.y = msg->pose.position.y;
    air_toolbox_data.pose.position.z = msg->pose.position.z + 0.2;
    Eigen::Quaternionf q;
    q.x() = msg->pose.orientation.x;
    q.y() = msg->pose.orientation.y;
    q.z() = msg->pose.orientation.z;
    q.w() = msg->pose.orientation.w;
    air_toolbox_mat = q.toRotationMatrix();
}

void air_manipulator_Callback(const geometry_msgs::PoseStamped::ConstPtr &msg){
    air_manipulator_data.pose.position.x = msg->pose.position.x;
    air_manipulator_data.pose.position.y = msg->pose.position.y;
    air_manipulator_data.pose.position.z = msg->pose.position.z + 0.8;
    Eigen::Quaternionf q;
    q.x() = msg->pose.orientation.x;
    q.y() = msg->pose.orientation.y;
    q.z() = msg->pose.orientation.z;
    q.w() = msg->pose.orientation.w;
    air_manipulator_mat = q.toRotationMatrix();
}

int main(int argc, char **argv){
    ros::init(argc, argv, "realsense_sim_node");
    ros::NodeHandle nh;

   //  接收工具箱无人机的位姿信息
    ros::Subscriber air_toolbox_sub =nh.subscribe("/air_toolbox_pose", 10,  &air_toolbox_Callback);
   //  接收作业无人机的位姿信息
    ros::Subscriber air_manipulator_sub =nh.subscribe("/mavros/local_position/pose", 10,  &air_manipulator_Callback);
    // 发送工具箱相对于上方无人机的位置
    ros::Publisher toolbox_pub  = nh.advertise<aerial_toolbox::toolbox_array>("/tool_box_pos", 10);

    ros::ServiceClient getlinkstate_client = nh.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");
    gazebo_msgs::GetLinkState tool_state_srv;
    tool_state_srv.request.reference_frame = "iris::FlyingDelta::base_link";
    //================Set target point=================
    std::vector<Eigen::Vector3d> toolbox_points;
    toolbox_points.resize(4);
    toolbox_points[0] = Eigen::Vector3d(-0.0735,0.0735,0);
    toolbox_points[1] = Eigen::Vector3d(0.0735,0.0735,0);  
    toolbox_points[2] = Eigen::Vector3d(0.0735,-0.0735,0);
    toolbox_points[3] = Eigen::Vector3d(-0.0735,-0.0735,0);
    //=================================================
    
    ros::Rate rate(20.0);
    aerial_toolbox::toolbox_array toolbox_arr;
    while(ros::ok()){
        // ROS_INFO("position of air_toolbox: \t%f, \t%f, \t%f", 
        //     air_toolbox_data.pose.position.x,air_toolbox_data.pose.position.y,air_toolbox_data.pose.position.z);
        // cout<<air_manipulator_mat<<endl;

        Eigen::Matrix3f R_mani_to_toolbox = air_manipulator_mat.inverse() * air_toolbox_mat;
        Eigen::Quaternionf q_mani_to_toolbox(R_mani_to_toolbox);
        Eigen::Vector3d pos_err;
        pos_err[0] = air_toolbox_data.pose.position.x - air_manipulator_data.pose.position.x;
        pos_err[1] = air_toolbox_data.pose.position.y - air_manipulator_data.pose.position.y;
        pos_err[2] = air_toolbox_data.pose.position.z - air_manipulator_data.pose.position.z;
        for (int tool_id = 0; tool_id < 4; tool_id++) {

            Eigen::Vector3d target_tool = R_mani_to_toolbox.cast<double>() * toolbox_points[tool_id] + pos_err;

            toolbox_arr.tools[tool_id].stamp = ros::Time::now();
            toolbox_arr.tools[tool_id].tool_id = tool_id;
            toolbox_arr.tools[tool_id].position[0] = target_tool(0);
            toolbox_arr.tools[tool_id].position[1] = target_tool(1);
            toolbox_arr.tools[tool_id].position[2] = target_tool(2);
            toolbox_arr.tools[tool_id].orientation[0] = q_mani_to_toolbox.w();
            toolbox_arr.tools[tool_id].orientation[1] = q_mani_to_toolbox.x();
            toolbox_arr.tools[tool_id].orientation[2] = q_mani_to_toolbox.y();
            toolbox_arr.tools[tool_id].orientation[3] = q_mani_to_toolbox.z();

            toolbox_arr.tools[tool_id].z_vec[0] = air_toolbox_mat.col(2)(0);
            toolbox_arr.tools[tool_id].z_vec[1] = air_toolbox_mat.col(2)(1);
            toolbox_arr.tools[tool_id].z_vec[2] = air_toolbox_mat.col(2)(2);
            toolbox_arr.tools[tool_id].detected_num = 10;

            tool_state_srv.request.link_name = "tool_" + to_string(tool_id);
            if(getlinkstate_client.call(tool_state_srv)){
                ROS_INFO("%d tool position error:\t%f,\t%f,\t%f", tool_id, toolbox_arr.tools[tool_id].position[0]-tool_state_srv.response.link_state.pose.position.x,
                    toolbox_arr.tools[tool_id].position[1]-tool_state_srv.response.link_state.pose.position.y,
                    toolbox_arr.tools[tool_id].position[2]-tool_state_srv.response.link_state.pose.position.z);
            }
            else
                cout<<"failed to get link state!";
            // ROS_INFO("%d tool oritation:\t%f,\t%f,\t%f,\t%f", tool_id, toolbox_arr.tools[tool_id].orientation[0],
            //     toolbox_arr.tools[tool_id].orientation[1],
            //     toolbox_arr.tools[tool_id].orientation[2],
            //     toolbox_arr.tools[tool_id].orientation[3]);
            // ROS_INFO("%d tool z_vec:\t%f,\t%f,\t%f", tool_id, toolbox_arr.tools[tool_id].z_vec[0],
            //     toolbox_arr.tools[tool_id].z_vec[1],
            //     toolbox_arr.tools[tool_id].z_vec[2]);
        }  //end 4 tools

        toolbox_pub.publish(toolbox_arr);
        ros::spinOnce();
        rate.sleep();

    }
    return 0;
}