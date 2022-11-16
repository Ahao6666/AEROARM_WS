#include <ros/ros.h>
#include "std_msgs/String.h"

#include "off_mission_node.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "off_mission_node");
    ros::NodeHandle off_mission_node;
    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(50.0);
    TaskManager off_mission_obj;

    // wait for FCU connection
    while(ros::ok() && !off_mission_obj.current_state.connected)
    {

        ros::spinOnce();

        rate.sleep();
    }


    while(ros::ok())
    {
        off_mission_obj.mainLoop();
        ros::spinOnce();
        rate.sleep();
    }


    return 0;

}
