#include"auto_pick.h"

auto_pick::auto_pick(/* args */)
{
    // 【服务】调取指定时间的期望轨迹，如果超过轨迹的时间域，则为终点值。
    traj_result_server = nh_.advertiseService("trajectory_result", &auto_pick::traj_out_call,this);
    end_result_server = nh_.advertiseService("end_effector_result", &auto_pick::end_out_call,this);
    tool_chatter_pub = nh_.advertise<std_msgs::String>("chatter_tool", 1000);
    double yaw_offset;
    nh_.param<double>("/clik/yaw_offset_",yaw_offset_,-1.571589f);
    nh_.param<double>("/clik/x_offset",delta_offset_(0),0.010374f);
    nh_.param<double>("/clik/y_offset",delta_offset_(1),-0.026177f);
    nh_.param<double>("/clik/z_offset",delta_offset_(2),0.140462f);
    rotation_delta_b_ << sin(yaw_offset_), cos(yaw_offset_), 0, cos(yaw_offset_), sin(yaw_offset_), 0, 0, 0, -1;
    nh_.param<double>("/task_plan/time_to_hold",time_hold_,2.0f);
    nh_.param<double>("/task_plan/velocity_to_reach",vel_reach_,0.02f);
    nh_.param<double>("/task_plan/velocity_to_reach",acc_reach_,0.1f);

    nh_.param<double>("/task_plan/vel_end_effector",vel_end_,0.5f);
    nh_.param<double>("/task_plan/acc_end_effector",acc_end_,1.0f);
    

    // 读取目标位置和方向
    objects_.clear();
    XmlRpc::XmlRpcValue object_position,constrant_angle,attitude;
    nh_.getParam("/auto_pick/position",object_position);
    nh_.getParam("/auto_pick/constrant_angle",constrant_angle);
    nh_.getParam("/auto_pick/attitude",attitude);
    get_object_vector(object_position,constrant_angle,attitude);
    num_objects_ = objects_.size();
    end_plan_.resize(num_objects_);
    XmlRpc::XmlRpcValue start_load,end_load,num_poly_load,corridor_load;
    nh_.getParam("/auto_pick/start_pt",start_load);
    nh_.getParam("/auto_pick/end_pt",end_load);
    nh_.getParam("/auto_pick/num_polyhedron",num_poly_load);
    nh_.getParam("/auto_pick/corridor",corridor_load);
    // 读取安全通道信息
    get_path_cooridor(start_load, end_load, num_poly_load, corridor_load);
    hold_manipulator_set_ << 0, 0, -0.14;
    hold_manipulator_set_ = rotation_delta_b_*hold_manipulator_set_ + delta_offset_;
    // 读取障碍物信息
    XmlRpc::XmlRpcValue obstacle_load;
    nh_.getParam("/auto_pick/obstacle",obstacle_load);
    get_obstalces(obstacle_load);
    // 计算预接触点
    cont_end_pt_.resize(num_objects_);
    for (size_t i = 0; i < num_objects_; i++)
    {
        cont_end_pt_[i].pos = objects_[i].pos ;//Eigen::Vector3d(1.5,1.5,-1);//
        cont_end_pt_[i].acc = Eigen::Vector3d(0,0,0);
        cont_end_pt_[i].vel =  Eigen::Vector3d(0,0,0);//Eigen::Vector3d(0,0,0);//
    }

    set_work_space(Eigen::MatrixXd::Identity(3,3),
                                     Eigen::Vector3d(0.06,0.06,-0.15),
                                     Eigen::Vector3d(-0.06,-0.06,-0.30),
                                     0.5*(Eigen::Vector3d(0.06,0.06,-0.15) + Eigen::Vector3d(-0.06,-0.06,-0.30)));
}

void auto_pick::set_work_space(Eigen::MatrixXd A_w, Eigen::VectorXd b_u_w, 
                                                                    Eigen::VectorXd b_l_w, Eigen::Vector3d center)
{
    workspace_.A_w = A_w;
    workspace_.b_u_w = b_u_w;
    workspace_.b_l_w = b_l_w;
    workspace_.center = center;
}

bool auto_pick::traj_out_call(task_plan::traj_out_msgRequest& request,task_plan::traj_out_msgResponse& response)
{
    // time align
    if (!task_begin_flag_)
    {
        task_begin_flag_ = true;
        flying_plan_.time_align();
        time_align_for_end();// 这个时候计算早结束了，只是用于修改调用时间
        ROS_INFO("Trajectory of the quadcopter is sending!");
    }
    
    path_point traj_sp;
    flying_plan_.trajectory_out(request.times, traj_sp);
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
    // ROS_INFO("%f\t%f\t%f\n",response.x,response.y,response.z);
    return 1;
}


bool auto_pick::end_out_call(task_plan::traj_out_msgRequest& request,task_plan::traj_out_msgResponse& response)
{
    response.flag_begin = false;
    if (task_begin_flag_)
    {
        path_point traj_sp;
        for (size_t i = 0; i < num_objects_; i++)
        {
            if ((request.times.toSec() > ini_end_st_[i].time_begin.toSec()) &&
            (request.times.toSec() < ini_end_st_[i].time_begin.toSec() + constrant_manipulation_[i].s_scale   +  time_hold_))
            {
                end_plan_[i].trajectory_out(request.times, traj_sp);
                response.flag_begin = true;
                response.x    = traj_sp.pos[0];
                response.y    = traj_sp.pos[1];
                response.z    = traj_sp.pos[2];

                response.dx   = traj_sp.vel[0];
                response.dy   = traj_sp.vel[1];
                response.dz   = traj_sp.vel[2];

                response.ddx  = traj_sp.acc[0]; 
                response.ddy  = traj_sp.acc[1];
                response.ddz  = traj_sp.acc[2];
                // ROS_INFO("End_effector:%f\t%f\t%f\n",response.x,response.y,response.z);
                break;
            }
        }   
    }
    for (size_t i = 0; i < num_objects_; i++) //更新
    {

        if ( (ros::Time::now() <gripper_open_time_[i]) & (ros::Time::now() > gripper_open_time_[i] -ros::Duration(0.5)) )
        {
        // 控制机械抓
            std_msgs::String char2tool;
            std::stringstream temp;
            temp <<  "A111";
            char2tool.data = temp.str();
            tool_chatter_pub.publish(char2tool);
            std:: cout << "机械抓抓取！" <<std::endl;
        }
    } 
   
    
    return 1;
}

void auto_pick::time_align_for_end()
{
    vector<bezier> bezier_3d;
    gripper_open_time_.clear();
    flying_plan_.bezier_result_out(bezier_3d);// 调取飞行平台轨迹的结果
    for (size_t i = 0; i < num_objects_; i++) //更新
    {
        ini_end_st_[i].time_begin = bezier_3d[index_obj_reach_[i]].times - ros::Duration(constrant_manipulation_[i].s_scale );
        end_plan_[i].time_align(ini_end_st_[i].time_begin);
        gripper_open_time_.push_back(bezier_3d[index_obj_reach_[i]].times);
    } 
}


void auto_pick::get_object_vector(XmlRpc::XmlRpcValue &position,XmlRpc::XmlRpcValue &angle,XmlRpc::XmlRpcValue &attitude)
{
    pick_object temp_pos;
    if (position.size() == angle.size() == attitude.size())
    {
        ROS_INFO("The number of objects is %d ", (int)position.size());
        for (size_t i = 0; i < position.size(); i++)
        {
            XmlRpc::XmlRpcValue data_list1(position[i]);
            temp_pos.pos = Eigen::Vector3d(data_list1[0],data_list1[1],data_list1[2]);
            temp_pos.constrant_angle = double(angle[i]);
            XmlRpc::XmlRpcValue data_list3(attitude[i]);
            Eigen::Vector3d temp_vec = Eigen::Vector3d(data_list3[0],data_list3[1],data_list3[2]);
            temp_pos.get_euler(temp_vec);
            std::cout <<"-----------Objects---------------" <<std::endl;
            std::cout <<temp_pos.pos <<std::endl;
            std::cout <<temp_pos.rotation <<std::endl;
            objects_.push_back(temp_pos);
        }
    }
    else
    {
        ROS_ERROR("The object data inputed by the YAML file is wrong!");
    }
}

void auto_pick::generate_reachable_space()
{
    reachable_space_.clear();
    Eigen::Vector3d dst_end_quad = rotation_delta_b_ * workspace_.center + delta_offset_;
    for (size_t i = 0; i < num_objects_; i++)
    {
        constraint temp;
        temp.s_scale = time_hold_ + 2.0;
        temp.upper_vel = vel_reach_*Eigen::Vector3d(1,1,1);
        temp.lower_vel  = vel_reach_*Eigen::Vector3d(-1,-1,-1);
        temp.upper_acc = acc_reach_*Eigen::Vector3d(1,1,1);
        temp.lower_acc = vel_reach_*Eigen::Vector3d(-1,-1,-1);
        temp.A_pos.setIdentity(3,3);
        temp.b_u_pos.resize(3);
        temp.b_u_pos = cont_end_pt_[i].pos - objects_[i].rotation*dst_end_quad + 1.0*(workspace_.b_u_w - workspace_.center);
        temp.b_l_pos.resize(3);
        temp.b_l_pos  = cont_end_pt_[i].pos - objects_[i].rotation*dst_end_quad + 1.0*(workspace_.b_l_w  - workspace_.center);
        reachable_space_.push_back(temp);
    }
}


void auto_pick::corridor_management()
{
    generate_reachable_space(); // 生成无人机的接触和工作空间
    std::cout << "The reachable space  have been generateed for quadcopter." << std::endl;
    int num_corr = corridor_rev_.size();
    bool btemp;
    // reachable_space_[0].show();
    vector<int> temp_object_in_polyhedron;
    temp_object_in_polyhedron.clear();
    for (int i = 0; i < num_objects_; i++)
    {
        for (int j = 0; j < num_corr; j++)
        {
            btemp = corridor_rev_[j].is_in(0.5*(reachable_space_[i].b_u_pos + reachable_space_[i].b_l_pos));
            if (btemp)
            {
                temp_object_in_polyhedron.push_back(j);
                break;
            }
        }
    }
    if (temp_object_in_polyhedron.size() != num_objects_)
    {
        ROS_ERROR("The objects are not in the corridor!");
    }
    
    corridor_.clear();
    index_obj_reach_.clear();
    std::cout << "The places of the objects are analysed."<< std::endl;
    for (size_t i = 0; i < num_corr; i++)
    {
        corridor_.push_back(corridor_rev_[i]);
        for (size_t j = 0; j < num_objects_; j++)
        {
            if (i== temp_object_in_polyhedron[j])
            {
                corridor_.push_back(reachable_space_[j]);
                index_obj_reach_.push_back(corridor_.size() - 1);
                corridor_.push_back(corridor_rev_[i]);
            }
        }
    }
}
void auto_pick::show_corridor()
{
    int num = corridor_.size();
    for (size_t i = 0; i < num; i++)
    {
        std::cout << i << "th polyhedron:" << std::endl;
        corridor_[i].show();
    }
    
}

void auto_pick::calculate_initial_end(ros::Time time_in, pick_object po_in, ini_end_effector& out_ini)
{
    out_ini.time_begin = time_in;
    flying_plan_.trajectory_out(out_ini.time_begin, out_ini.pt);
    Eigen::Vector3d r_g(po_in.rotation(0,0), po_in.rotation(1,0),  po_in.rotation(2,0));
    Eigen::Vector3d r3 = out_ini.pt.acc + Eigen::Vector3d(0,0,9.8);
    r3 = 1 / r3.norm()  * r3 ;
    Eigen::Vector3d r2 = r3.cross(r_g);
    r2 =  1 / r2.norm()  * r2 ;
    Eigen::Vector3d r1 = r2.cross(r3);
    Eigen:: Matrix3d R;
    R<< r1,r2,r3;

    out_ini.pt.pos = out_ini.pt.pos + R * hold_manipulator_set_;

}

void auto_pick::solver_for_trajectory()
{
    // 计算飞行平台的轨迹
    corridor_management();
    // show_corridor();
    std::cout << "Corridor  have been loaded for quadcopter." << std::endl;
    flying_plan_.get_path_constraint(corridor_, start_pt_, end_pt_);
    std::cout << "Constraints  have been set for quadcopter." << std::endl;
    flying_plan_.trajectory_solver_QP();

    // show_corridor();
    
    // 计算末端轨迹的初始状态
    ini_end_st_.clear();
    double  during_B_G = 4.0 * 4.0 / 2.0;
    ini_end_effector temp_sta;
    vector<bezier> bezier_3d;
    flying_plan_.bezier_result_out(bezier_3d);
    cout << "number of the objects is " << num_objects_ << std::endl;
    for (size_t i = 0; i < num_objects_; i++)
    {
        
        temp_sta.time_begin = bezier_3d[index_obj_reach_[i]].times - ros::Duration(during_B_G);
        calculate_initial_end(temp_sta.time_begin, objects_[i], temp_sta);
        ini_end_st_.push_back(temp_sta);//这个时候的初始时间没有什么意义
    }
    
    // 接触点为 cont_end_pt_
   


    // 计算抓取的约束
    constrant_manipulation_.clear();
    constraint cons_temp;
    for (size_t i = 0; i < num_objects_; i++)
    {
        cons_temp.s_scale = during_B_G;
        cons_temp.upper_vel = vel_end_  * Eigen::Vector3d(1,1,1);
        cons_temp.lower_vel  = -vel_end_  * Eigen::Vector3d(1,1,1);
        cons_temp.upper_acc = acc_end_  * Eigen::Vector3d(1,1,1);
        cons_temp.lower_acc  = -acc_end_  * Eigen::Vector3d(1,1,1);
        cons_temp.A_pos.setIdentity(3,3);
        cons_temp.b_u_pos = max_vector(ini_end_st_[i].pt.pos,  cont_end_pt_[i].pos) + Eigen::Vector3d(0.1, 0.1, 0.1);//Eigen::Vector3d(2, 2, 0);//
        cons_temp.b_l_pos =  min_vector(ini_end_st_[i].pt.pos,  cont_end_pt_[i].pos) - Eigen::Vector3d(0.1, 0.01, 0.1);//Eigen::Vector3d(-2, -2, -2);//
        constrant_manipulation_.push_back(cons_temp);
    }

    // 计算末端的轨迹
    for (size_t i = 0; i < num_objects_; i++)
    {
        // std::cout << "-------------------------起点-------------------------" << std::endl;
        // ini_end_st_[i].pt.vel.setZero();
        // ini_end_st_[i].pt.acc.setZero();
        // ini_end_st_[i].pt.show();
        // // std::cout << "-----------------------是否在约束中-----------------------" << std::endl;
        // // std::cout << constrant_manipulation_[i].is_in( ini_end_st_[i].pt.pos) << std::endl;
        // std::cout << "-------------------------终点-------------------------" << std::endl;
        // cont_end_pt_[i].vel.setZero();
        // cont_end_pt_[i].acc.setZero();
        // cont_end_pt_[i].show();
        
        // std::cout << "-----------------------是否在约束中-----------------------" << std::endl;
        // constrant_manipulation_[i].show();
        // std::cout << constrant_manipulation_[i].is_in( cont_end_pt_[i].pos) << std::endl;
        // std::cout << constrant_manipulation_[i].is_in( ini_end_st_[i].pt.pos) << std::endl;

        // 拟合飞行平台数据
        path_point temp_pp;
        vector<Eigen::Vector3d> point_flying_base;
        int order = 12;
        for (size_t j = 0; j < order; j++)
        {
            ros::Time timeTem = ini_end_st_[i].time_begin + ros::Duration( j*constrant_manipulation_[i].s_scale/(order-1));
            flying_plan_.trajectory_out(timeTem, temp_pp);
            point_flying_base.push_back(temp_pp.pos);
        }

        vector<double> time_flying_base;
        for (size_t j = 0; j < order; j++)
        {
            time_flying_base.push_back(j*constrant_manipulation_[i].s_scale/(order-1));
        }
        bezier  bezier_flying(12, during_B_G,  ini_end_st_[i].time_begin);
        Berizer_fit(point_flying_base, time_flying_base,  bezier_flying);
        
        // std::cout << "---------------------------------------------------" << std::endl;
        end_plan_[i].get_objectives(objects_[i], time_hold_);
        end_plan_[i].get_obstacles(envir_);
        end_plan_[i].get_flying_bezier(bezier_flying);
        end_plan_[i].get_manip_offset(rotation_delta_b_, delta_offset_);
        end_plan_[i].get_initial_states(ini_end_st_[i]);
        end_plan_[i].get_path_constraint(constrant_manipulation_[i]);
        end_plan_[i].trajectory_solver_QP();
    }
}

Eigen::VectorXd auto_pick::max_vector(Eigen::VectorXd v1, Eigen::VectorXd v2)
{
    Eigen::VectorXd out_v(v2.size());
    if (v1.size() == v2.size())
    {
        for (size_t i = 0; i < v1.size(); i++)
        {
            out_v[i] = max(v1[i], v2[i]);
        }
        return out_v;
    }
    else
    {
        ROS_ERROR("Function max_vector is wrong, scince the rows of the inputs are different!");
    } 
}

Eigen::VectorXd auto_pick::min_vector(Eigen::VectorXd v1, Eigen::VectorXd v2)
{
    Eigen::VectorXd out_v(v2.size());
    if (v1.size() == v2.size())
    {
        for (size_t i = 0; i < v1.size(); i++)
        {
            out_v[i] = min(v1[i], v2[i]);
        }
        return out_v;
    }
    else
    {
        ROS_ERROR("Function min_vector is wrong, scince the rows of the inputs are different!");
    } 
}
void auto_pick::get_path_cooridor(XmlRpc::XmlRpcValue &start,XmlRpc::XmlRpcValue &end,XmlRpc::XmlRpcValue &num_polyhedron,XmlRpc::XmlRpcValue &corridor)
{
    start_pt_.pos = Eigen::Vector3d( start["pos"][0], start["pos"][1], start["pos"][2]);
    start_pt_.vel = Eigen::Vector3d( start["vel"][0], start["vel"][1], start["vel"][2]);
    start_pt_.acc = Eigen::Vector3d( start["acc"][0], start["acc"][1], start["acc"][2]);
    end_pt_.pos = Eigen::Vector3d( end["pos"][0], end["pos"][1], end["pos"][2]);
    end_pt_.vel = Eigen::Vector3d( end["vel"][0], end["vel"][1], end["vel"][2]);
    end_pt_.acc = Eigen::Vector3d( end["acc"][0], end["acc"][1], end["acc"][2]);
    std::cout << "Start point:" << std::endl;
    start_pt_.show();
    std::cout << "End point:" << std::endl;
    end_pt_.show();
    int num_poly = num_polyhedron;
    constraint temp;
    corridor_rev_.clear();
    // std::cout << "Safty corridor:" << std::endl;
    for (size_t i = 0; i < num_poly; i++)
    {
        temp.s_scale = corridor[i]["s_scale"];
        temp.upper_vel = Eigen::Vector3d( corridor[i]["upper_vel"][0], corridor[i]["upper_vel"][1], corridor[i]["upper_vel"][2]);
        temp.lower_vel = Eigen::Vector3d( corridor[i]["lower_vel"][0], corridor[i]["lower_vel"][1], corridor[i]["lower_vel"][2]);
        temp.upper_acc = Eigen::Vector3d( corridor[i]["upper_acc"][0], corridor[i]["upper_acc"][1], corridor[i]["upper_acc"][2]);
        temp.lower_acc = Eigen::Vector3d( corridor[i]["lower_acc"][0], corridor[i]["lower_acc"][1], corridor[i]["lower_acc"][2]);
        int row = corridor[i]["A_pos"]["row"];
        int col = corridor[i]["A_pos"]["col"];
        Eigen::MatrixXd A_temp(row,col);
        for (size_t k = 0; k < row; k++)
        {
            for (size_t j = 0; j < col; j++)
            {
                A_temp(k,j) = corridor[i]["A_pos"]["data"][k*col+j];
            }
        }
        temp.A_pos = A_temp;
        temp.b_u_pos = Eigen::Vector3d( corridor[i]["b_u_pos"][0], corridor[i]["b_u_pos"][1], corridor[i]["b_u_pos"][2]);
        temp.b_l_pos = Eigen::Vector3d( corridor[i]["b_l_pos"][0], corridor[i]["b_l_pos"][1], corridor[i]["b_l_pos"][2]);
        std::cout << i <<"th poly has been loaded." << std::endl;
        // temp.show();
        corridor_rev_.push_back(temp);
    }
}
 void auto_pick::get_obstalces(XmlRpc::XmlRpcValue &obstalces)
 {
    envir_.clear();
    for (size_t i = 0; i < obstalces.size(); i++)
    {
        vector<Eigen::Vector3d> temp;
        temp.clear();
        for (size_t j = 0; j < obstalces[i]["points"].size(); j++)
        {
            temp.push_back(Eigen::Vector3d(obstalces[i]["points"][j][0], obstalces[i]["points"][j][1], obstalces[i]["points"][j][2]));
        }
        envir_.push_back(temp);
    }
 }

void auto_pick::test()
{
    solver_for_trajectory();
    std:: cout << "计算已经结束" <<std::endl;
    // 控制机械抓
    std_msgs::String char2tool;
    std::stringstream temp;
    temp <<  "A110";
    char2tool.data = temp.str();
    tool_chatter_pub.publish(char2tool);
    std:: cout << "机械抓电磁铁打开！" <<std::endl;
}

bool auto_pick::Berizer_fit(vector<Eigen::Vector3d> P, vector<double> t,  bezier& bezier_flying)
{
    int length = t.size();  //向量长度
    int order = bezier_flying.order;
    double tau;         //tau系数，与时间有关
    double binomial_coff;   //二项式系数，为C(n,i)
    Eigen::MatrixXd B(order+1, length);
    //构建B矩阵
    for(int i=0; i<length; i++){
        tau = (t[i]-t[0]) / (t[length-1]-t[0]);
        for(int j = 0; j<=order; j++){
            binomial_coff = factorial(order) / (factorial(j) * factorial(order-j));
            B(j,i) = binomial_coff * pow(tau,j) * pow((1-tau),(order-j));
        }
    }
    // std::cout<<B<<std::endl;
    Eigen::MatrixXd B_inv = pseudoInverse(B);   //求B矩阵的伪逆
    // std::cout<<B_inv<<std::endl;
    
    // 将P从向量转化为矩阵,用于相乘
    Eigen::MatrixXd P_matrix(3,length);
    for(int i=0; i<3; i++){
        for(int j = 0; j<length; j++){
            P_matrix(i,j) = P[j][i];
        }
    }

    Eigen::MatrixXd C(3,order+1);  //最终需要的C矩阵
    C = P_matrix * B_inv;

    for (size_t i = 0; i < order+1; i++)
    {
        bezier_flying.coef_x[i] = C(0,i);
    }
    for (size_t i = 0; i < order+1; i++)
    {
        bezier_flying.coef_y[i] = C(1,i);
    }
    for (size_t i = 0; i < order+1; i++)
    {
        bezier_flying.coef_z[i] = C(2,i);
    }
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "traj_solver");
    ros::NodeHandle auto_node;
    ROS_INFO("Read to solve trajectory!");
    auto_pick pick_object;
    pick_object.test();
    ros::spin();
}




