#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{

	ros::init(argc, argv, "talker_test");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter_tool", 1000);

	ros::Rate loop_rate(0.5);

	int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;

		std::stringstream ss;

		switch (count)
		{
		case 1:
			ss << "A100";
			break;
		case 2:
			ss << "A200";
			break;
		case 3:
			ss << "A111";
			break;
		case 4:
			ss << "A211";
			count = 0;
			break;
		default:
			break;
		}
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		count++;
	}

	return 0;
}