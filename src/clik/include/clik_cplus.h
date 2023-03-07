#ifndef _CLIK_CPLUS_
#define _CLIK_CPLUS_

#include <ros/ros.h>
#include <Eigen/Eigen>
#include <math.h>
#include <string.h>
#include <Eigen/SVD>
#include "osqp/osqp.h"

// External inputs (root inport signals with default storage)
typedef struct {
  Eigen::Vector3d point_e_des;
  Eigen::Vector3d point_e_des_dot;
  Eigen::Vector3d point_e;
  Eigen::Vector3d point_b;
  Eigen::Vector3d point_e_b;
  Eigen::Vector3d vel_base;
  Eigen::Vector3d angular_vel_base;
  Eigen::Matrix3d rotation;
  double dtime;
} ExtU_CLIK_T;

class clik_c_
{
  public:
    clik_c_(){};

    // External inputs
    ExtU_CLIK_T CLIK_U;
    void setIntergrate( Eigen::Vector3d point_e_d){point_e_d_out_ = point_e_d;}
    void clik_solver();
    void getCLIKOut(Eigen::Vector3d& out){out = point_e_d_out_;}
    void getOffSetManipulator(double yaw_offset,Eigen::Vector3d dOffset)
    {
      yaw_offset_ = yaw_offset;
      dOffset_ = dOffset;
      rotation_delta_b_ << sin(yaw_offset), cos(yaw_offset), 0, cos(yaw_offset), sin(yaw_offset), 0, 0, 0, -1;
    }
    double xi_min[6],xi_max[6];  // 数组
    double xi_dot_min[6],xi_dot_max[6];// 数组
    double  xi_ddot_min[6],xi_ddot_max[6];   // 数组 


  private:
    void hanlde_constant();
    Eigen::Vector3d point_e_d_out_;
    Eigen::Vector3d upper_;
    Eigen::Vector3d lower_;
    Eigen::Vector3d dOffset_;//机械臂的1状态移动平台相对于飞机的误差
    double yaw_offset_;//机械臂相对机体x正方向的误差，该误差与vicon的标定直接相关
    Eigen::Matrix3d rotation_delta_b_;
    Eigen::Vector3d ped_;
};

#endif

