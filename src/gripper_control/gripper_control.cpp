//代码
/**
 * 该例程将发布turtle1/cmd_vel话题，消息类型geometry_msgs::Twist
 */
 
#include <ros/ros.h>
#include "std_msgs/Float32.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "gripper_control_publish");

    // 创建节点句柄
    ros::NodeHandle g1,g2;;

    // 创建一个Publisher，发布名为/joint/gripper1/position_cmd的topic，消息类型为std_msgs::Float32，队列长度10
    ros::Publisher gripper1_pub = g1.advertise<std_msgs::Float32>("/joint/gripper1/position_cmd", 10);
    ros::Publisher gripper2_pub = g2.advertise<std_msgs::Float32>("/joint/gripper2/position_cmd", 10);

    // 设置循环的频率
    ros::Rate loop_rate(10);
    bool flag=0;
    int count = 0;
    while (ros::ok())
    {
        // 初始化std_msgs::Float32类型的消息
        std_msgs::Float32 gripper1_pos,gripper2_pos;
        if(flag == 0)
            count++;
        else if(flag == 1)
            count--;

        if(count <= 0)
            flag = 0;
        else if(count >= 10)
            flag = 1;

        gripper1_pos.data = count * 0.2;
        gripper1_pub.publish(gripper1_pos);

        // 发布消息
        gripper2_pos.data = count * (-0.2);
        gripper2_pub.publish(gripper2_pos);
        ROS_INFO("Publsh gripper1 position command[%0.2f ]", gripper1_pos.data);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}