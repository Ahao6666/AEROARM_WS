#ifndef AUTO_PICK
#define AUTO_PICK

#include "type_define.h"
#include "end_effector_planning.h"
#include "std_msgs/String.h"
#include"trajectory_solver.h"

class auto_pick
{
public:
    auto_pick(/* args */);
    void test();


private:
    ros::NodeHandle nh_;
    ros::ServiceServer traj_result_server;
    ros::ServiceServer end_result_server;
    ros::Publisher tool_chatter_pub;

    void corridor_management(); // 管理和整理安全通道，主要是添加了接触和可达空间
    void generate_reachable_space();// 生成接触和可达空间
    void solver_for_trajectory();// 生成轨迹
    Eigen::VectorXd max_vector(Eigen::VectorXd v1, Eigen::VectorXd v2);
    Eigen::VectorXd min_vector(Eigen::VectorXd v1, Eigen::VectorXd v2);
    void time_align_for_end();
    void show_corridor();
    void set_work_space(Eigen::MatrixXd A_w, Eigen::VectorXd b_u_w, Eigen::VectorXd b_l_w, Eigen::Vector3d center);

    bool traj_out_call(task_plan::traj_out_msgRequest& request,task_plan::traj_out_msgResponse& response);
    bool end_out_call(task_plan::traj_out_msgRequest& request,task_plan::traj_out_msgResponse& response);
    void get_object_vector(XmlRpc::XmlRpcValue &position,XmlRpc::XmlRpcValue &angle,XmlRpc::XmlRpcValue &attitude);
    void get_path_cooridor(XmlRpc::XmlRpcValue &start,XmlRpc::XmlRpcValue &end,XmlRpc::XmlRpcValue &num_polyhedron,XmlRpc::XmlRpcValue &corridor);
    void get_obstalces(XmlRpc::XmlRpcValue &obstalces);
    bool Berizer_fit(vector<Eigen::Vector3d> P, vector<double> t,  bezier& bezier_flying);
    void calculate_initial_end(ros::Time time_in, pick_object po_in, ini_end_effector& out_ini);
    vector<end_effector_planning> end_plan_;
    trajectory_solver flying_plan_;

    vector<pick_object>  objects_; 
    vector<constraint> corridor_rev_;
    vector<constraint> corridor_;
    vector<constraint> reachable_space_;
    vector<constraint> contact_begin_space_;
    vector<constraint> constrant_manipulation_;
    vector<path_point> cont_end_pt_;
    vector<int> index_obj_polyhedron_;
    vector<int> index_obj_reach_;
    vector<ini_end_effector> ini_end_st_;
    vector<vector<Eigen::Vector3d>> envir_;
    workspace workspace_;
    path_point start_pt_, end_pt_;
    int num_objects_;

    // constrants 
    double vel_end_,acc_end_; // end-effector constrants
    double time_hold_;
    // 重要参数
    double vel_reach_; // from launch file
    double acc_reach_;// from launch file

    // Params
    Eigen::Matrix3d rotation_delta_b_;
    Eigen::Vector3d delta_offset_;
    double yaw_offset_;
    Eigen::Vector3d hold_manipulator_set_;

    bool task_begin_flag_ = false;

    vector<ros::Time> gripper_open_time_;



};




















#endif