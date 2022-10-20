#ifndef END_TRJ_SOLVER
#define END_TRJ_SOLVER
#include <ros/ros.h>
#include<vector>
#include<iostream>
#include<cstring>
#include<stddef.h>
#include <Eigen/Eigen>
#include "bezier_base.h"
#include "mylib.h"
#include "log4z.h"
#include "osqp/osqp.h"
#include "type_define.h"
#include "task_plan/traj_out_msg.h"

/*  注意： 在OSQP中提供了正无穷的定义是OSQP_INFTY((c_float)1e30) */
# ifndef OSQP_INFTY
#  define OSQP_INFTY ((c_float)1e30)        // infinity
# endif /* ifndef OSQP_INFTY */


class end_effector_planning
{
public:
    end_effector_planning();
    void get_objectives(pick_object obj, path_point end_pt,  double vel_cnt,  double time_cnt);
    void get_initial_states(ini_end_effector ini_pt);
    void get_path_constraint(constraint path_constraint);
    bool trajectory_solver_QP();
    void trajectory_out(ros::Time timeNow, path_point& traj_sp);
    void time_align(ros::Time time_in);
    
private:
    vector<pick_object> obj_;
    vector<ini_end_effector> ini_pt_;
    int n_segment_ = 1;
    int traj_order_ = 12;
    int opti_min_order_ = 3;
    vector <constraint> path_constraint_;

    void get_matrix_quadratic_form();
    void get_constraint_QP();
    bool bezier_out(ros::Time timeNow, bezier bezier_in, path_point& traj_sp);
    void end_contact_out(double t, path_point& out);


    // Workspace structures
    OSQPWorkspace *work;
    OSQPSettings  *settings;
    OSQPData      *data;

    // QP form parameters
    MatrixXd quad_matrix_;
    MatrixXd A_matrix_;
    VectorXd low_vector_;
    VectorXd upp_vector_;
    path_point start_pt_;
    path_point end_pt_;
    vector<bezier> bezier_3d_;
    double time_to_hold_;

    // Bernstein base
    Bernstein bernstein_;
    double vel_cnt_;
    double time_cnt_;
    double length_to_cnt_;
    Eigen::Vector3d vector_cnt_;

    // cnt 
    Eigen::VectorXd end_coef_beizer_;
    int end_order_beizer_ = 5;
};

#endif