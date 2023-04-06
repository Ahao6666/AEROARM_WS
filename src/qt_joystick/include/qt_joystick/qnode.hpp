/**
 * @file /include/qt_joystick/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef qt_joystick_QNODE_HPP_
#define qt_joystick_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <QDebug>>
#include <sensor_msgs/Joy.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/State.h>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_joystick {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	void run();
  void Get_data(int *data);
  static void state_cb(const mavros_msgs::State::ConstPtr& msg);

Q_SIGNALS:
//	void loggingUpdated();
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
  ros::Publisher chatter_publisher;
  ros::Publisher joy_publisher;
  ros::Subscriber state_sub;
  ros::ServiceClient arming_client;

  float Send_data_[6] = {0,0,0,0,0,0};

};

}  // namespace qt_joystick

#endif /* qt_joystick_QNODE_HPP_ */
