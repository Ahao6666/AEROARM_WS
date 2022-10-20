#include "flying_platform_planning.h"


flying_platform_planning::flying_platform_planning( )
{
    set_work_space(Eigen::MatrixXd::Identity(3,3),
                                     Eigen::Vector3d(0.08,0.08,-0.15),
                                     Eigen::Vector3d(-0.08,-0.08,-0.30),
                                     0.5*(Eigen::Vector3d(0.08,0.08,-0.15) + Eigen::Vector3d(-0.08,-0.08,-0.30)));
}

void flying_platform_planning::get_manipulator_offset(double yaw_offset, Eigen::Vector3d delta_offset)
{
    yaw_offset_ = yaw_offset;
    delta_offset_ = delta_offset;
    rotation_delta_b_ << -sin(yaw_offset_), cos(yaw_offset_), 0, cos(yaw_offset_), sin(yaw_offset_), 0, 0, 0, -1;
}

void flying_platform_planning::get_pick_task_param(double time_reach, double time_contact, double time_hold, 
                                                        double vel_reach,double vel_cont, double rate_cont_reach)
{
    time_reach_ = time_reach;
    time_contact_ = time_contact;
    time_hold_ = time_hold;
    vel_reach_ = vel_reach;
    vel_cont_ = vel_cont;
    rate_cont_reach_ = rate_cont_reach;
}


void flying_platform_planning::trajectory_out(ros::Time timeNow, path_point& traj_sp)
{
    trajectory_solver_.trajectory_out(timeNow, traj_sp);
    // std::cout << i<<std::endl;
}

void flying_platform_planning::get_objectives(vector<pick_object> obj)
{
    obj_.clear();
    obj_.assign(obj.begin(),obj.end());
}

void flying_platform_planning::get_constrants(vector<constraint> cons, path_point start_pt, path_point end_pt)
{
    trajectory_solver_.get_path_constraint(cons, start_pt, end_pt);
}

void flying_platform_planning::generate_reachable_space()
{
    Eigen::Vector3d dst_end_quad = rotation_delta_b_ * workspace_.center + delta_offset_;
    int n_obj = obj_.size();
    for (size_t i = 0; i < n_obj; i++)
    {
        constraint temp;
        temp.s_scale = time_reach_;
        temp.upper_vel = vel_reach_*Eigen::Vector3d(1,1,1);
        temp.lower_vel  = vel_reach_*Eigen::Vector3d(-1,-1,-1);
        temp.upper_acc << 1,1,1;
        temp.lower_acc << -1,-1,-1;
        temp.A_pos.setIdentity(3,3);
        temp.b_u_pos.resize(3);
        temp.b_u_pos = obj_[i].pos - dst_end_quad + workspace_.b_u_w;
        temp.b_l_pos.resize(3);
        temp.b_l_pos  = obj_[i].pos - dst_end_quad + workspace_.b_l_w;
        reachable_space_.push_back(temp);
        constraint temp_cont;
        temp_cont.s_scale = time_contact_;
        temp_cont.upper_vel << vel_reach_*Eigen::Vector3d(1,1,1);
        temp_cont.lower_vel << vel_reach_*Eigen::Vector3d(-1,-1,-1);
        temp_cont.upper_acc << 1,1,1;
        temp_cont.lower_acc << -1,-1,-1;
        temp_cont.A_pos.setIdentity(3,3);
        temp_cont.b_u_pos.resize(3);
        temp_cont.b_u_pos = obj_[i].pos - dst_end_quad + rate_cont_reach_ * workspace_.b_u_w;
        temp_cont.b_l_pos.resize(3);
        temp_cont.b_l_pos  = obj_[i].pos - dst_end_quad + rate_cont_reach_ * workspace_.b_l_w;
        contact_begin_space_.push_back(temp_cont);
    }
}


void flying_platform_planning::set_work_space(Eigen::MatrixXd A_w, Eigen::VectorXd b_u_w, 
                                                                                                    Eigen::VectorXd b_l_w, Eigen::Vector3d center)
{
    workspace_.A_w = A_w;
    workspace_.b_u_w = b_u_w;
    workspace_.b_l_w = b_l_w;
    workspace_.center = center;
}

bool flying_platform_planning::traj_out_call(task_plan::traj_out_msgRequest& request,task_plan::traj_out_msgResponse& response){
    // time align
    if (!task_begin_flag)
    {
        task_begin_flag = true;
        trajectory_solver_.time_align();
    }
    
    path_point traj_sp;
    trajectory_solver_.trajectory_out(request.times, traj_sp);
    response.x    = traj_sp.pos[0];
    response.y    = traj_sp.pos[1];
    response.z    = traj_sp.pos[2];

    response.dx   = traj_sp.vel[0];
    response.dy   = traj_sp.vel[1];
    response.dz   = traj_sp.vel[2];

    response.ddx  = traj_sp.acc[0]; 
    response.ddy  = traj_sp.acc[1];
    response.ddz  = traj_sp.acc[2];
    response.flag_begin = true;
    ROS_INFO("%f\t%f\t%f\n",response.x,response.y,response.z);
    return 1;
}
void flying_platform_planning::run()
{
    trajectory_solver_.trajectory_solver_QP();
}

void flying_platform_planning::bezier_result_out(vector<bezier>& bezier_3d)
{
    trajectory_solver_.bezier_result_out(bezier_3d);
}

// void flying_platform_planning::move_stage_planning()
// {
//     pick_object obj1;
//     obj1.pos  = Eigen::Vector3d(8,7,-0.9);
//     obj1.constrant_angle = 0.17; // rad
//     obj1.rotation = Eigen::Matrix3d::Identity();
//     get_objectives(obj1);
//     vector<constraint> path_constraint;
//     constraint cons_1;
//     cons_1.s_scale = 20.0;
//     cons_1.upper_vel << 1,1,1;
//     cons_1.lower_vel << -1,-1,-1;
//     cons_1.upper_acc << 1,1,1;
//     cons_1.lower_acc << -1,-1,-1;
//     cons_1.A_pos.setIdentity(3,3);
//     cons_1.b_u_pos.resize(3);
//     cons_1.b_u_pos<< 2,2,0;
//     cons_1.b_l_pos.resize(3);
//     cons_1.b_l_pos<< -2,-2,-2;
//     path_constraint.push_back(cons_1);
//     constraint cons_2;
//     cons_2.s_scale = 20.0;
//     cons_2.upper_vel << 1,1,1;
//     cons_2.lower_vel << -1,-1,-1;
//     cons_2.upper_acc << 1,1,1;
//     cons_2.lower_acc << -1,-1,-1;
//     cons_2.A_pos.setIdentity(3,3);
//     cons_2.b_u_pos.resize(3);
//     cons_2.b_u_pos<< 4,6,0;
//     cons_2.b_l_pos.resize(3);
//     cons_2.b_l_pos<< 1,0,-2;
//     path_constraint.push_back(cons_2);
//     constraint cons_3;
//     cons_3.s_scale = 20.0;
//     cons_3.upper_vel << 1,1,1;
//     cons_3.lower_vel << -1,-1,-1;
//     cons_3.upper_acc << 1,1,1;
//     cons_3.lower_acc << -1,-1,-1;
//     cons_3.A_pos.setIdentity(3,3);
//     cons_3.b_u_pos.resize(3);
//     cons_3.b_u_pos<< 7,10,0;
//     cons_3.b_l_pos.resize(3);
//     cons_3.b_l_pos<< 3,4,-2;
//     path_constraint.push_back(cons_3);
//     constraint cons_4;
//     cons_4.s_scale = 20.0;
//     cons_4.upper_vel << 1,1,1;
//     cons_4.lower_vel << -1,-1,-1;
//     cons_4.upper_acc << 1,1,1;
//     cons_4.lower_acc << -1,-1,-1;
//     cons_4.A_pos.setIdentity(3,3);
//     cons_4.b_u_pos.resize(3);
//     cons_4.b_u_pos<< 10,8,0;
//     cons_4.b_l_pos.resize(3);
//     cons_4.b_l_pos<< 6,5,-2;
//     path_constraint.push_back(cons_4);
    
//     // generate reachable and contact sapce
//     generate_reachable_space();
//     // contact space
//     path_constraint.push_back(contact_begin_space_[0]);
    
//     // reachable sapce
//     path_constraint.push_back(reachable_space_[0]);

//     // // contact space
//     path_constraint.push_back(contact_begin_space_[0]);

//     constraint cons_5;
//     cons_5.s_scale = 20.0;
//     cons_5.upper_vel << 1,1,1;
//     cons_5.lower_vel << -1,-1,-1;
//     cons_5.upper_acc << 1,1,1;
//     cons_5.lower_acc << -1,-1,-1;
//     cons_5.A_pos.setIdentity(3,3);
//     cons_5.b_u_pos.resize(3);
//     cons_5.b_u_pos<< 15,7,0;
//     cons_5.b_l_pos.resize(3);
//     cons_5.b_l_pos<< 8,6,-2;
//     path_constraint.push_back(cons_5);

//     Eigen::Vector3d p_start(0,0,0);
//     Eigen::Vector3d p_end(14,6.5,-1);
//     path_point start_pt;
//     path_point end_pt;
//     start_pt.pos = p_start;
//     start_pt.vel.setZero();
//     start_pt.acc.setZero();
//     end_pt.pos = p_end;
//     end_pt.vel.setZero();
//     end_pt.acc.setZero();
//     trajectory_solver_.get_path_constraint(path_constraint, start_pt, end_pt);
//     trajectory_solver_.trajectory_solver_QP();
// }

