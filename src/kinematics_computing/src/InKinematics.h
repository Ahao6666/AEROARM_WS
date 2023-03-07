#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/Point.h"
#include "nav_msgs/Odometry.h"
#include <math.h>
#include "ros/console.h"
#include <sstream>
#include <boost/program_options.hpp>
#include <tf/transform_datatypes.h>
#include <vector>
#include "sensor_msgs/JointState.h"

using namespace std;

#define pi 3.14159265358979323846
#define updateRate 400

#define z_ed -0.14
class Inverse_Kinematics_Talker{
	private:
		ros::NodeHandle nh_;
		double 	R = 0.100;//
		double	r = 0.030;// 
		double	L = 0.120; // 
		double	l = 0.240; // 

		// inverse kinematics results
		double theta1_, theta2_, theta3_;
		double theta1_save_, theta2_save_, theta3_save_;

		// for inverse kinematics computing
		double x_, y_, z_;

		// from trajGenerator
		tf::Vector3 desiredPos;

		double IKinemTh(double x0, double y0, double z0);
		void calculation(double X, double Y, double Z);

	public:
		Inverse_Kinematics_Talker(int, char**);
		void inverse_kinematics();
		bool f1;

		// sub trajGenerator cb
		void endEffe_sub_cb(const geometry_msgs::Point& msg);

		// inverse kinematics initialization
		void setPos();

		// get theta
		tf::Vector3 getJointTheta();

		// get endeff pose		
		tf::Vector3 getDesiredPos();

		// pub to gazebo	
		ros::Publisher joint_gazebo_pub1;
		ros::Publisher joint_gazebo_pub2;
		ros::Publisher joint_gazebo_pub3;

		// pub to rviz node
		ros::Publisher state_pub;

		// sub trajGenerator
		ros::Subscriber endEffe_sub;

};


