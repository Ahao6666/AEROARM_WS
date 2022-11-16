#include <ros/ros.h>
#include "std_msgs/String.h"



#include "navigator.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "navigator_node");

    ros::NodeHandle navigator_node;

    ros::Rate loop_rate(50);
 //ROS_INFO_THROTTLE(5, "understand main function");
    Navigator navigator_obj;

    while (ros::ok())
    {
        ros::spinOnce();

        navigator_obj.mainLoop();

        loop_rate.sleep();
    }


    return 0;

}
