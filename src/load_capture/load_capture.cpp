//代码
/**
 * 该例程将发布turtle1/cmd_vel话题，消息类型geometry_msgs::Twist
 */
 
#include <ros/ros.h>
#include "std_msgs/Float32.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "load_capture_test_publish");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为/joint/gripper1/position_cmd的topic，消息类型为std_msgs::Float32，队列长度10
    ros::Publisher gripper1_pub = n.advertise<std_msgs::Float32>("/joint/gripper1/position_cmd", 10);
    ros::Publisher gripper2_pub = n.advertise<std_msgs::Float32>("/joint/gripper2/position_cmd", 10);
    ros::Publisher delta1_pub = n.advertise<std_msgs::Float32>("/joint/1/position_cmd", 10);
    ros::Publisher delta2_pub = n.advertise<std_msgs::Float32>("/joint/2/position_cmd", 10);
    ros::Publisher delta3_pub = n.advertise<std_msgs::Float32>("/joint/3/position_cmd", 10);

    std_msgs::Float32 delta1_pos, delta2_pos, delta3_pos;
    std_msgs::Float32 gripper1_pos,gripper2_pos;
    ros::Rate loop_rate(0.5);

    while (ros::ok())
    {

        gripper1_pos.data = 2;
        gripper2_pos.data = 2;
        gripper1_pub.publish(gripper1_pos);
        gripper2_pub.publish(gripper2_pos);
        loop_rate.sleep();
        
        delta1_pos.data = 0;
        delta2_pos.data = 0;
        delta3_pos.data = 0;
        delta1_pub.publish(delta1_pos);
        delta2_pub.publish(delta2_pos);
        delta3_pub.publish(delta3_pos);
        loop_rate.sleep();
        
        gripper1_pos.data = 0;
        gripper2_pos.data = 0;
        gripper1_pub.publish(gripper1_pos);
        gripper2_pub.publish(gripper2_pos);
        loop_rate.sleep();

        delta1_pos.data = -1;
        delta2_pos.data = -1;
        delta3_pos.data = -1;
        delta1_pub.publish(delta1_pos);
        delta2_pub.publish(delta2_pos);
        delta3_pub.publish(delta3_pos);
        // 按照循环频率延时
        loop_rate.sleep();
        ROS_INFO("Publsh load capture test ");

    }

    return 0;
}