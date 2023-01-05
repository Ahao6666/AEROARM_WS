
#include "InKinematics.h"



double Inverse_Kinematics_Talker::IKinemTh(double x0, double y0, double z0)
{
	double y1 = -R;
	double a, b, theta;
	double yj, zj;
	y0 = y0 - r; // shift center to edge
	a = (x0*x0 + y0*y0 + z0*z0 + L*L - l*l - y1*y1) / (2 * z0);
	b = (y1 - y0) / z0;// discriminant
	double D = -(a + b*y1)*(a + b*y1) + L*L * (b*b+ 1);
	if (D < 0)
	{
		theta = 0; // non - existing
	}
	else
	{
		yj = (y1 - a*b - sqrt(D)) / (b*b + 1);
		zj = a + b*yj;
		theta = atan(-zj / (y1 - yj));
		if (yj>y1)
		theta = theta + pi;
	}
	return theta;
}

void Inverse_Kinematics_Talker::calculation(double X, double Y, double Z)
{
	double x0, y0, z0;
	x0 = X;
	y0 = Y;
	z0 = Z;
	theta1_ = IKinemTh(x0, y0, z0);
	//.......................................................
	x0 = X*cos(2 * pi / 3) + Y*sin(2 * pi / 3);
	y0 = Y*cos(2 * pi / 3) - X*sin(2 * pi / 3);
	z0 = Z;
	theta2_ = IKinemTh(x0, y0, z0);
	//.......................................................
	x0 = X*cos(2 * pi / 3) - Y*sin(2 * pi / 3);
	y0 = Y*cos(2 * pi / 3) + X*sin(2 * pi / 3);
	z0 = Z;
	theta3_ = IKinemTh(x0, y0, z0);
	//.......................................................
	if (~isnan(theta1_) && ~isnan(theta2_) && ~isnan(theta3_))
		f1 = 1;
	else
		f1 = 0; // non - existing
}

void Inverse_Kinematics_Talker::inverse_kinematics(){
	setPos();
	calculation(x_, y_, z_);
}


Inverse_Kinematics_Talker::Inverse_Kinematics_Talker(int argc, char** argv){
	ROS_INFO("Inverse Kinematics Talker Initializing...");
	while(!ros::ok())
		ROS_ERROR("Something is wrong with ROS. Will keep trying...");

	// to gazebo
  	joint_gazebo_pub1 = nh_.advertise<std_msgs::Float32>("/joint/delta_1/position_cmd", 1000);
  	joint_gazebo_pub2 = nh_.advertise<std_msgs::Float32>("/joint/delta_2/position_cmd", 1000);
  	joint_gazebo_pub3 = nh_.advertise<std_msgs::Float32>("/joint/delta_3/position_cmd", 1000);


	// to rviz
  	state_pub = nh_.advertise<sensor_msgs::JointState>("joint_states", 1000);


  	endEffe_sub = nh_.subscribe("/traj/rel_posi", 1, &Inverse_Kinematics_Talker::endEffe_sub_cb, this);


  	theta1_=0;
  	theta2_=0;
  	theta3_=0;
	desiredPos.setValue(0,0,z_ed);
}
tf::Vector3 Inverse_Kinematics_Talker::getJointTheta(){
	tf::Vector3 temp;

	if(!(std::isnan(theta1_) || std::isnan(theta2_) || std::isnan(theta3_))){
		temp.setX(theta1_);
		temp.setY(theta2_);
		temp.setZ(theta3_);
		theta1_save_ = theta1_;
		theta2_save_ = theta2_;
		theta3_save_ = theta3_;
	}else{
		temp.setX(theta1_save_);
		temp.setY(theta2_save_);
		temp.setZ(theta3_save_);
	}
	// std::cout << theta1_save_ << std::endl;
	// std::cout << theta2_save_ << std::endl;
	// std::cout << theta3_save_ << std::endl;
	return temp;
}




tf::Vector3 Inverse_Kinematics_Talker::getDesiredPos(){
	return desiredPos;
}

void Inverse_Kinematics_Talker::setPos(){
	x_=desiredPos.getX();
	y_=desiredPos.getY();
	z_=desiredPos.getZ();
}

void Inverse_Kinematics_Talker::endEffe_sub_cb(const geometry_msgs::Point& msg){

	desiredPos.setValue(msg.x,msg.y,msg.z);

}



