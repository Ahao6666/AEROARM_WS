#include <ros/ros.h>
#include "std_msgs/String.h"

#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define UDPPORT 6000
#define SERVERIP "192.168.50.83"
#define TRIDACTYLISM_PORT 6001
#define TRIDACTYLISM_IP "192.168.50.61"
#define SPHERICAL_PORT 6002
#define SPHERICAL_IP "192.168.50.62"
#define PARALLEL_PORT 6003
#define PARALLEL_IP "192.168.50.63"
#define TOOTH_PORT 6004
#define TOOTH_IP "192.168.50.64"

using namespace std;
class Socket
{
public:
	int server_fd_;												 // 文件描述符
	float flag_command = 0;										 // 指令处理标志位
	void Socket_Connect(void);									 // Socket连接函数
	void DataHanding(void);										 // 处理客户端数据函数
	void ChatterCallback(const std_msgs::String::ConstPtr &msg); // 遥控器回调函数
	void Timer_Callback(const ros::TimerEvent &);				 // 心跳包定时器中断函数

private:
	int timer_count_; // 定时器计数
	char send_data_[512];
	char recv_data_[512];

	struct sockaddr_in server_addr_; // Socket地址
	struct sockaddr_in client_addr_tridactylism_;
	struct sockaddr_in client_addr_spherical_;
	struct sockaddr_in client_addr_parallel_;
	struct sockaddr_in client_addr_tooth_;

	unsigned int server_addr_length_; // 结构体长度
	unsigned int client_addr_length_;
};

void Socket::Socket_Connect(void)
{
	if ((server_fd_ = socket(AF_INET, SOCK_DGRAM, 0)) < 0) //创建套接字
	{
		perror("socket() error");
	}

	//设置服务端地址、监听端口，和客户端地址、发送端口
	bzero(&server_addr_, sizeof(server_addr_)); //本机，上位机
	server_addr_.sin_family = AF_INET;
	server_addr_.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr_.sin_port = htons(UDPPORT);
	server_addr_length_ = sizeof(server_addr_);

	bzero(&client_addr_tridactylism_, sizeof(client_addr_tridactylism_)); //三指软体爪
	client_addr_tridactylism_.sin_family = AF_INET;
	client_addr_tridactylism_.sin_addr.s_addr = inet_addr(TRIDACTYLISM_IP);
	client_addr_tridactylism_.sin_port = htons(TRIDACTYLISM_PORT);
	client_addr_length_ = sizeof(client_addr_tridactylism_);

	bzero(&client_addr_spherical_, sizeof(client_addr_spherical_)); //球形软体爪
	client_addr_spherical_.sin_family = AF_INET;
	client_addr_spherical_.sin_addr.s_addr = inet_addr(SPHERICAL_IP);
	client_addr_spherical_.sin_port = htons(SPHERICAL_PORT);

	bzero(&client_addr_parallel_, sizeof(client_addr_parallel_)); //平行刚性爪
	client_addr_parallel_.sin_family = AF_INET;
	client_addr_parallel_.sin_addr.s_addr = inet_addr(TRIDACTYLISM_IP);
	client_addr_parallel_.sin_port = htons(TRIDACTYLISM_PORT);

	bzero(&client_addr_tooth_, sizeof(client_addr_tooth_)); //带齿刚性爪
	client_addr_tooth_.sin_family = AF_INET;
	client_addr_tooth_.sin_addr.s_addr = inet_addr(SPHERICAL_IP);
	client_addr_tooth_.sin_port = htons(SPHERICAL_PORT);

	// 套接字端口复用，用来重新连接
	int opt = 1;
	setsockopt(server_fd_, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));

	// 绑定监听端口
	if (bind(server_fd_, (struct sockaddr *)&server_addr_, server_addr_length_) < 0)
		perror("bind() error");

	ROS_INFO_STREAM("succeeded in creating the socket!");
}

//处理接收客户端的数据
void Socket::DataHanding(void)
{
	bzero(recv_data_, sizeof(recv_data_)); // 清空接收数组

	if (flag_command)
	{
		int recv_length = 0;
		switch (send_data_[1])
		{
		case '1':
			if ((recv_length = recvfrom(server_fd_, recv_data_, sizeof(recv_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_tridactylism_, &client_addr_length_)) > 0)
			{
				ROS_INFO("receive data1: %s", recv_data_);

				// 返回数据判断指令是否被执行，未执行则再次发送指令数据，直到客户端响应为止（通信正常不丢帧只会跑一次）
				if (recv_data_[0] == send_data_[0] && recv_data_[1] == send_data_[1] && recv_data_[2] == send_data_[2] && recv_data_[3] == send_data_[3])
				{
					flag_command = 0;
					bzero(send_data_, sizeof(send_data_)); // 清空发送数组
				}
			}
			break;
		case '2':
			if ((recv_length = recvfrom(server_fd_, recv_data_, sizeof(recv_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_spherical_, &client_addr_length_)) > 0)
			{
				ROS_INFO("receive data2: %s", recv_data_);

				if (recv_data_[0] == send_data_[0] && recv_data_[1] == send_data_[1] && recv_data_[2] == send_data_[2] && recv_data_[3] == send_data_[3])
				{
					flag_command = 0;
					bzero(send_data_, sizeof(send_data_));
				}
			}
			break;
		case '3':
			if ((recv_length = recvfrom(server_fd_, recv_data_, sizeof(recv_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_parallel_, &client_addr_length_)) > 0)
			{
				ROS_INFO("receive data3: %s", recv_data_);

				if (recv_data_[0] == send_data_[0] && recv_data_[1] == send_data_[1] && recv_data_[2] == send_data_[2] && recv_data_[3] == send_data_[3])
				{
					flag_command = 0;
					bzero(send_data_, sizeof(send_data_));
				}
			}
			break;
		case '4':
			if ((recv_length = recvfrom(server_fd_, recv_data_, sizeof(recv_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_tooth_, &client_addr_length_)) > 0)
			{
				ROS_INFO("receive data4: %s", recv_data_);

				if (recv_data_[0] == send_data_[0] && recv_data_[1] == send_data_[1] && recv_data_[2] == send_data_[2] && recv_data_[3] == send_data_[3])
				{
					flag_command = 0;
					bzero(send_data_, sizeof(send_data_));
				}
			}
			break;
		default:
			break;
		}
	}
}

/* 	私有数据协议
	示例：char型“A101”
	解析：第一位：帧头“A”
	     第二位：选择通信的工具，1三指软体爪，2球形软体爪，3平行刚性爪，4带齿刚性爪
		 第三位：电磁铁开关，0断开分离，1吸合对接
		 第四位：抓取控制，0松开，1抓取
	回调函数在控制端通过接口直接发数据，这里进行处理
*/
void Socket::ChatterCallback(const std_msgs::String::ConstPtr &msg)
{
	ROS_INFO_STREAM("Writing to serial port:" << msg->data);
	strcpy(send_data_, msg->data.c_str()); // msg->data.c_str()将回调函数数据复制到发送数组里面，send_data_赋值
	flag_command = 1;
}

//定时器回调函数，指令未处理重发
void Socket::Timer_Callback(const ros::TimerEvent &)
{
	if (flag_command)
	{
		int send_length = 0;
		switch (send_data_[1])
		{
		case '1':
			if ((send_length = sendto(server_fd_, send_data_, strlen(send_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_tridactylism_, client_addr_length_)) < 0)
				perror("sendto() error");
			break;
		case '2':
			if ((send_length = sendto(server_fd_, send_data_, strlen(send_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_spherical_, client_addr_length_)) < 0)
				perror("sendto() error");
			break;
		case '3':
			if ((send_length = sendto(server_fd_, send_data_, strlen(send_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_parallel_, client_addr_length_)) < 0)
				perror("sendto() error");
			break;
		case '4':
			if ((send_length = sendto(server_fd_, send_data_, strlen(send_data_), MSG_DONTWAIT, (struct sockaddr *)&client_addr_tooth_, client_addr_length_)) < 0)
				perror("sendto() error");
			break;
		default:
			break;
		}
		ROS_INFO("send switch instruction: %s", send_data_);
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener_tool");
	ros::NodeHandle n;

	Socket UDP;
	ros::Subscriber sub = n.subscribe("chatter_tool", 1000, &Socket::ChatterCallback, &UDP);
	ros::Timer timer = n.createTimer(ros::Duration(1), &Socket::Timer_Callback, &UDP); // 定时器每1s执行一次
	ros::Rate loop_rate(10);														   // 10HZ运行，减小内存占用
	std_msgs::String recive;

	UDP.Socket_Connect(); // 建立socket

	while (ros::ok())
	{
		UDP.DataHanding();

		ros::spinOnce();
		loop_rate.sleep();
	}

	//关闭套接字，使用close() 函数释放资源；
	close(UDP.server_fd_);

	ros::spin();
	return 0;
}
