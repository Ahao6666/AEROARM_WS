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
#include "gjk.h"


#define pi  3.14150

/*  注意： 在OSQP中提供了正无穷的定义是OSQP_INFTY((c_float)1e30) */
# ifndef OSQP_INFTY
#  define OSQP_INFTY ((c_float)1e30)        // infinity
# endif /* ifndef OSQP_INFTY */

struct obstacle_mirror
{
    bool is_collision = false;
    bool was_collision = false;
    Eigen::Vector3d term_left;
    Eigen::Vector3d term_right;
    double lammda = 0;
    Eigen::Vector3d center;
    Eigen::Vector3d mirr_pos;
};



class end_effector_planning
{
public:
    end_effector_planning();
    void get_objectives(pick_object obj,  double time_to_hold);
    void get_obstacles(vector<vector<Eigen::Vector3d>> envir){envir_.assign(envir.begin(),envir.end());}
    void get_manip_offset(Eigen::Matrix3d rotation_delta_b, Eigen::Vector3d delta_offset){rotation_delta_b_=rotation_delta_b; delta_offset_ = delta_offset;}
    void get_initial_states(ini_end_effector ini_pt);
    void get_path_constraint(constraint path_constraint);
    bool trajectory_solver_QP();
    void trajectory_out(ros::Time timeNow, path_point& traj_sp);
    void time_align(ros::Time time_in);
    void get_flying_bezier(bezier bezier_in){memcpy(&bezier_flying_base_, &bezier_in, sizeof(bezier_in));}
    
private:
    vector<pick_object> obj_;
    vector<ini_end_effector> ini_pt_;
    int n_segment_ = 1;
    int traj_order_ = 12;
    int opti_min_order_ = 3;
    vector <constraint> path_constraint_;
    vector<vector<Eigen::Vector3d>> envir_;
    Eigen::Matrix3d rotation_delta_b_;
    Eigen::Vector3d delta_offset_;
    double dl_grap = 0.03;
    double tan_gamma = 0.175;
    double dt_last_step = 1.8;


    void get_matrix_quadratic_form();
    void get_constraint_QP();
    bool bezier_out(ros::Time timeNow, bezier bezier_in, path_point& traj_sp);
    void end_contact_out(double t, path_point& out);
    void QP_solver(Eigen::MatrixXd quad_matrix, Eigen::VectorXd temp_q);
    bool collision_check();
    void gjk_for_traj(ros::Time time_in);
    // bool gjk_calculate(vector<Eigen::Vector3d> obj1, vector<Eigen::Vector3d> obj);

    // Workspace structures
    OSQPWorkspace *work;
    OSQPSettings  *settings;
    OSQPData      *data;

    // QP form parameters
    MatrixXd quad_matrix_;
    MatrixXd Q_col_;
    VectorXd q_col_;
    MatrixXd A_matrix_;
    VectorXd low_vector_;
    VectorXd upp_vector_;
    path_point start_pt_;
    path_point end_pt_;
    vector<bezier> bezier_3d_;
    bezier bezier_flying_base_;
    double time_to_hold_;

    // Bernstein base
    Bernstein bernstein_;
    double length_to_cnt_;
    Eigen::Vector3d vector_cnt_;

    // cnt 
    Eigen::VectorXd end_coef_beizer_;
    int end_order_beizer_ = 5;

    // obstacle
    vector<obstacle_mirror> obs_set_;

};

#endif