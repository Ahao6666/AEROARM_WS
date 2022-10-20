# ifndef TRJ_SOLVER
# define TRJ_SOLVER
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





class trajectory_solver
{
public:
    trajectory_solver();
    void get_path_constraint( vector <constraint> path_constraint, path_point start_pt, path_point end_pt);
    bool trajectory_solver_QP();
    void trajectory_out(ros::Time timeNow, path_point& traj_sp);
    void bezier_result_out(vector<bezier>& bezier_3d);
    void time_align();

    
private:
    // Bernstein base
    Bernstein bernstein_;
    void get_matrix_quadratic_form();
    void get_constraint_QP();
    
    bool bezier_out(ros::Time timeNow, bezier bezier_in, path_point& traj_sp);
    // TODO: Time align
    

    // Workspace structures
    OSQPWorkspace *work;
    OSQPSettings  *settings;
    OSQPData      *data;

    vector <constraint> path_constraint_;
    vector <Eigen::Vector3d> path_;
    int traj_order_ = 8;
    int opti_min_order_ = 3;
    // QP form parameters
    MatrixXd quad_matrix_;
    MatrixXd A_matrix_;
    VectorXd low_vector_;
    VectorXd upp_vector_;
    path_point start_pt_;
    path_point end_pt_;
    vector<bezier> bezier_3d_;
};



# endif /* ifndef TRJ_SOLVER */

