#include <ros/ros.h>

#include "clik_main.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "clik");
    ros::NodeHandle clik_node;
    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);
    clikRos clikRos_obj;

    
    // wait for FCU connection
    // while(ros::ok() && !clikRos_obj.current_state.connected)
    // {
    //     printf("1\n");
    //     ros::spinOnce();

    //     rate.sleep();
    // }
    /*clikRos_obj.Delta_mode.request.mode = 1;
    clikRos_obj.manipulator_client.call(clikRos_obj.Delta_mode);*/

    while(ros::ok())
    {
        //printf("2\n");
        
        clikRos_obj.mainLoop();

        ros::spinOnce();
        rate.sleep();
    }


    return 0;

}