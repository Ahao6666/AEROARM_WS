#include"end_effector_planning.h"

end_effector_planning::end_effector_planning()
{
    settings  = (OSQPSettings *)c_malloc(sizeof(OSQPSettings));
    data  = (OSQPData *)c_malloc(sizeof(OSQPData));
}

void end_effector_planning::get_objectives(pick_object obj, path_point end_pt,  double vel_cnt, double time_cnt)
{
    obj_.clear();
    obj_.push_back(obj);
    end_pt_ = end_pt;
    Eigen::Vector3d temp = obj.pos - end_pt.pos;
    length_to_cnt_ = temp.norm();
    vector_cnt_ = 1/length_to_cnt_ * temp;
    vel_cnt_ = vel_cnt;
    time_cnt_ = time_cnt;
    time_to_hold_ = time_to_hold_;
    end_coef_beizer_.resize(end_order_beizer_+1);
    end_coef_beizer_[0] = 0;
    end_coef_beizer_[5] = length_to_cnt_;
    end_coef_beizer_[1] = vel_cnt_/end_order_beizer_ + end_coef_beizer_[0];
    end_coef_beizer_[4] = end_coef_beizer_[5];
    end_coef_beizer_[2] = 2.0*end_coef_beizer_[1]- end_coef_beizer_[0];
    end_coef_beizer_[3] = 2.0*end_coef_beizer_[4]- end_coef_beizer_[5];
}

void end_effector_planning::end_contact_out(double t, path_point& out)
{
    double b_out_p = 0;
    double b_out_v = 0;
    double b_out_a = 0;

    t = t/time_cnt_;

    if (t>1)
    {
        t = 1;
        std::cout << "End effector contact trajectory generator is run out time!" << std::endl;
    }
    double temp;
    for (size_t i = 0; i < end_order_beizer_ + 1; i++)
    {
        temp = combinatorial(end_order_beizer_, i);
        b_out_p = b_out_p + end_coef_beizer_[i] * temp * pow(t,i) * pow(1-t, end_order_beizer_-i);
    }
    for (size_t i = 0; i < end_order_beizer_ ; i++)
    {
        temp = combinatorial(end_order_beizer_ - 1, i);
        b_out_v = b_out_v + end_order_beizer_*(end_coef_beizer_[i+1] - end_coef_beizer_[i]) * temp * pow(t,i) * pow(1-t, end_order_beizer_ - 1-i);
    }
    for (size_t i = 0; i < end_order_beizer_ - 1 ; i++)
    {
        temp = combinatorial(end_order_beizer_ - 2, i);
        b_out_a = b_out_a + end_order_beizer_ * (end_order_beizer_-1) * (end_coef_beizer_[i+2] - 2.0 * end_coef_beizer_[i+1] + end_coef_beizer_[i]) * temp * pow(t,i) * pow(1-t, end_order_beizer_ - 2-i);
    }
    out.pos = end_pt_.pos + b_out_p * vector_cnt_;
    out.vel  = end_pt_.vel + 1.0/time_cnt_ * b_out_v * vector_cnt_;
    out.acc = end_pt_.acc + 1.0/(time_cnt_ * time_cnt_) * b_out_a * vector_cnt_;
}

void end_effector_planning::get_initial_states(ini_end_effector ini_pt)
{
    ini_pt_.push_back(ini_pt);
    start_pt_ = ini_pt_[0].pt;
}

void  end_effector_planning::get_matrix_quadratic_form()
{
    int _poly_order_min = 8;
    int _poly_order_max = 12;
    if(bernstein_.setParam(_poly_order_min, _poly_order_max, 3) == -1) 
    {
    ROS_ERROR(" The trajectory order is set beyond the library's scope, please re-set ");
    }
    MatrixXd MQM = bernstein_.getMQM()[traj_order_];

    int n_segment = path_constraint_.size();
    std::cout << "n_segment = " << n_segment << endl;

    MatrixXd quad_m, quad_0;
    diagonal_expansion(MQM, MQM,quad_m);
    diagonal_expansion(quad_m, MQM,quad_m);

    for (size_t i = 0; i < n_segment; i++)
    {
        quad_0 = 1.0/(double) pow(path_constraint_[i].s_scale,  2*opti_min_order_ - 3) * quad_m;
        diagonal_expansion(quad_matrix_, quad_0, quad_matrix_);
    }
}

void  end_effector_planning::get_path_constraint( constraint path_constraint)
{
    path_constraint_.clear();
   path_constraint_.push_back(path_constraint);
   // 位置约束已经没有太多的用了，其他的约束还是很重要。
}

void end_effector_planning::get_constraint_QP()
{
    // 初始化曲线参数
    int ctrl_num = traj_order_ + 1;
    int ctrl_3d_num = 3* ctrl_num;

    // 求A约束矩阵
    int n_segment = path_constraint_.size();
    A_matrix_.resize(0,0);
    low_vector_.resize(0);
    upp_vector_.resize(0);
    int row_cout = 0;

    // 单位矩阵和向量
    Eigen::VectorXd vec_one= Eigen::VectorXd::Ones(ctrl_num);
    Eigen::MatrixXd matr_ctrl_num_ident = MatrixXd::Identity(ctrl_num,ctrl_num);

    // 安全通道约束
    for (size_t i = 0; i < n_segment; i++)
    {
        // 安全通道位置约束
        // for x,y,z
        int m1 = path_constraint_[i].A_pos.rows(); 
        int n1  = path_constraint_[i].A_pos.cols(); // n1=3, represents 3d trajectory
        if (n1!=3)
        {
            ROS_ERROR("Column of A is wrong!");
        }
        
        // Set b_l<=AX<=b_u for single cooridor
        Eigen::MatrixXd matr_temp(ctrl_num,ctrl_3d_num);//Note: 3 and N must be the same.
        
        Eigen::MatrixXd  A_old;
        Eigen::MatrixXd A_single(0,0);

       for (size_t j = 0; j < m1; j++)
       {
           matr_temp <<  path_constraint_[i].A_pos(j,0) * path_constraint_[i].s_scale * matr_ctrl_num_ident, 
                                           path_constraint_[i].A_pos(j,1)*path_constraint_[i].s_scale *matr_ctrl_num_ident, 
                                           path_constraint_[i].A_pos(j,2)*path_constraint_[i].s_scale *matr_ctrl_num_ident;
            A_old = A_single;
            A_single.resize((j+1)*ctrl_num,ctrl_3d_num);
            A_single<<A_old,matr_temp;
       }
       // add  b_l<=AX<=b_u into A_matrix_
       diagonal_expansion(A_matrix_, A_single, A_matrix_);

       row_cout = row_cout + m1*ctrl_num;
       
        for (size_t j = 0; j < m1; j++)
        {
            vector_expansion(low_vector_,  path_constraint_[i].b_l_pos[j]*vec_one,   low_vector_);
            vector_expansion(upp_vector_,  path_constraint_[i].b_u_pos[j]*vec_one, upp_vector_);
        }
    }
    Eigen::MatrixXd mat_tep;//储存每次计算结果
    Eigen::MatrixXd mat_tep_1;// 储存每个安全多面体结果
    Eigen::MatrixXd mat_tep_2(0,0);// 储存整个安全通道上的结果
    // 速度和加速度约束
    Eigen::MatrixXd Mat_v(ctrl_num - 1, ctrl_num);
    Eigen::MatrixXd Mat_a(ctrl_num - 2, ctrl_num);
    Mat_v.setZero();
    Mat_a.setZero();
    for (size_t i = 0; i < ctrl_num - 1; i++)
    { 
        Mat_v(i,i) = -1.0;
        Mat_v(i,i+1) =   1.0;
    }
    for (size_t i = 0; i < ctrl_num - 2; i++)
    { 
        Mat_a(i,i) = 1.0;
        Mat_a(i,i+1) =  -2.0;
        Mat_a(i,i+2) =  1.0;
    }
    for (size_t i = 0; i < n_segment; i++)
    {
        // 速度
        diagonal_expansion(traj_order_*Mat_v, traj_order_*Mat_v, mat_tep);
        diagonal_expansion(mat_tep, traj_order_*Mat_v, mat_tep);
        mat_tep_1 = mat_tep;
        row_cout = row_cout + 3*(ctrl_num-1);
        for (size_t j = 0; j < 3; j++)
        {
            vector_expansion(low_vector_,  path_constraint_[i].lower_vel[j]*Eigen::VectorXd::Ones(ctrl_num-1),   low_vector_);
            vector_expansion(upp_vector_,  path_constraint_[i].upper_vel[j]*Eigen::VectorXd::Ones(ctrl_num-1), upp_vector_);
        }
        // 加速度
        double temp1 = (traj_order_*(traj_order_-1))/path_constraint_[i].s_scale;
        diagonal_expansion(temp1*Mat_a, temp1*Mat_a, mat_tep);
        diagonal_expansion(mat_tep, temp1*Mat_a, mat_tep);
        row_expansion(mat_tep_1, mat_tep, mat_tep_1);
        row_cout = row_cout + 3*(ctrl_num-2);
        for (size_t j = 0; j < 3; j++)
        {
            vector_expansion(low_vector_,  path_constraint_[i].lower_acc[j]*Eigen::VectorXd::Ones(ctrl_num-2),   low_vector_);
            vector_expansion(upp_vector_, path_constraint_[i].upper_acc[j]*Eigen::VectorXd::Ones(ctrl_num-2), upp_vector_);
        }
        diagonal_expansion(mat_tep_2, mat_tep_1, mat_tep_2);
    }
    row_expansion(A_matrix_, mat_tep_2, A_matrix_);
    // 连续性约束, 三阶连续
    Eigen::MatrixXd Mat_continue((n_segment-1)*3*3,n_segment*ctrl_3d_num);
    Eigen::VectorXd V_continue((n_segment-1)*3*3);
    V_continue.setZero();
    
    Mat_continue.setZero();
    int shit_index = 0;
    int num;
    for (size_t i = 0; i < n_segment - 1; i++)
    {
        // 位置连续
        for (size_t j = 0; j < 3; j++)
        {
            num =  shit_index + (j+1)*ctrl_num - 1;
            Mat_continue(9*i+j, num) = 1.0 * path_constraint_[i].s_scale;
            num =  shit_index + ctrl_3d_num + j*ctrl_num;
            Mat_continue(9*i+j, num) = -1.0 * path_constraint_[i+1].s_scale;
        }
        // 速度连续
        for (size_t j = 0; j < 3; j++)
        {
            num =  shit_index + (j+1)*ctrl_num - 2;
            Mat_continue(9*i + 3+ j, num) = -1.0 ;
            num =  shit_index + (j+1)*ctrl_num - 1;
            Mat_continue(9*i + 3+ j, num) = 1.0 ;
            num =  shit_index + ctrl_3d_num + j*ctrl_num;
            Mat_continue(9*i + 3 + j, num) = 1.0 ;
            num =  shit_index + ctrl_3d_num + j*ctrl_num + 1;
            Mat_continue(9*i + 3 + j, num) = -1.0 ;
        }
        // 加速度连续
        for (size_t j = 0; j < 3; j++)
        {
            num =  shit_index + (j+1)*ctrl_num - 3;
            Mat_continue(9*i + 6 + j, num) = 1.0 / path_constraint_[i].s_scale;
            num =  shit_index + (j+1)*ctrl_num - 2;
            Mat_continue(9*i + 6 + j, num) = -2.0 / path_constraint_[i].s_scale;
            num =  shit_index + (j+1)*ctrl_num - 1;
            Mat_continue(9*i + 6 + j, num) = 1.0 / path_constraint_[i].s_scale;
            num =  shit_index + ctrl_3d_num + j*ctrl_num;
            Mat_continue(9*i + 6 + j, num) = -1.0/ path_constraint_[i+1].s_scale;
            num =  shit_index + ctrl_3d_num + j*ctrl_num + 1;
            Mat_continue(9*i + 6 + j, num) = 2.0/ path_constraint_[i+1].s_scale;
            num =  shit_index + ctrl_3d_num + j*ctrl_num + 2;
            Mat_continue(9*i + 6 + j, num) = -1.0/ path_constraint_[i+1].s_scale;
        }
        shit_index += ctrl_3d_num;
        // std::cout<<"--------------Mat_continue---------------"<<std::endl;
        // std::cout<<Mat_continue<<std::endl;
    }
    
    row_expansion(A_matrix_, Mat_continue,  A_matrix_);
    vector_expansion(low_vector_, V_continue,   low_vector_);
    vector_expansion(upp_vector_, V_continue, upp_vector_);

    // 路径点约束
    Eigen::MatrixXd Mat_path(18,n_segment*ctrl_3d_num);
    Mat_path.setZero();
    Eigen::VectorXd Vec_path(18);
    Vec_path.setZero();
    for (size_t i = 0; i < 3; i++)// 起点位置约束
    {
        num = i*ctrl_num;
        Mat_path(i, num) = 1.0 *  path_constraint_[0].s_scale;
    }
    for (size_t i = 0; i < 3; i++)// 起点速度约束
    {
        num = i*ctrl_num;
        Mat_path(i + 3, num) = - 1.0 *  traj_order_;
        num = i*ctrl_num + 1;
        Mat_path(i + 3, num) =   1.0 *  traj_order_;
    }
    for (size_t i = 0; i < 3; i++)// 起点加速度约束
    {
        num = i*ctrl_num;
        Mat_path(i + 6, num) =   1.0 *  traj_order_ * (traj_order_ - 1) / path_constraint_[0].s_scale;
        num = i*ctrl_num + 1;
        Mat_path(i + 6, num) =   -2.0 *  traj_order_ * (traj_order_ - 1) / path_constraint_[0].s_scale;
        num = i*ctrl_num + 2;
        Mat_path(i + 6, num) =   1.0 *  traj_order_ * (traj_order_ - 1) / path_constraint_[0].s_scale;
    }
    int end_element = path_constraint_.size() - 1;
    for (size_t i = 0; i < 3; i++)// 终点位置约束
    {
        num = n_segment*ctrl_3d_num - 1 - (2 -i) * ctrl_num;
        Mat_path(i + 9, num) = 1.0 *  path_constraint_[end_element].s_scale;
    }
    for (size_t i = 0; i < 3; i++)// 终点速度约束
    {
        num = n_segment*ctrl_3d_num - 1 - (2-i) * ctrl_num -1;
        Mat_path(i + 12, num) = - 1.0*traj_order_ ;
        num = n_segment*ctrl_3d_num - 1 - (2-i) * ctrl_num;
        Mat_path(i + 12, num) =   1.0*traj_order_;
    }
    for (size_t i = 0; i < 3; i++)// 终点加速度约束
    {
        num = n_segment*ctrl_3d_num - 1 - (2-i) * ctrl_num -2;
        Mat_path(i + 15, num) =   1.0 *  traj_order_ * (traj_order_ - 1)/path_constraint_[end_element].s_scale;
        num = n_segment*ctrl_3d_num - 1 - (2-i) * ctrl_num -1;
        Mat_path(i + 15, num) =  -2.0 *  traj_order_ * (traj_order_ - 1)/path_constraint_[end_element].s_scale;
        num = n_segment*ctrl_3d_num - 1 - (2-i) * ctrl_num;
        Mat_path(i + 15, num) =   1.0 *  traj_order_ * (traj_order_ - 1)/path_constraint_[end_element].s_scale;
    }
    Vec_path << start_pt_.pos, start_pt_.vel, start_pt_.acc, end_pt_.pos, end_pt_.vel, end_pt_.acc;
    row_expansion(A_matrix_, Mat_path,  A_matrix_);
    vector_expansion(low_vector_, Vec_path,   low_vector_);
    vector_expansion(upp_vector_, Vec_path, upp_vector_);
}

bool end_effector_planning::trajectory_solver_QP()
{
    get_matrix_quadratic_form();
    get_constraint_QP();

    csc temp_Q;
    matrix_upptriangular(quad_matrix_, quad_matrix_);
    matrix_to_csc trans_mat_csc(quad_matrix_,temp_Q);
    csc temp_A;
    matrix_to_csc trans_mat_csc_2(A_matrix_, temp_A);
    Eigen::VectorXd temp_q(A_matrix_.cols());
    temp_q.setZero();

    // Exitflag
    c_int exitflag = 0;

    // Populate data
    if (data) {
        data->n = A_matrix_.cols(); // 变量个数
        data->m = A_matrix_.rows();  // A矩阵的行
        data->P = &temp_Q; // P只需要记录上三角矩阵即可,认为是对称矩阵
        data->q = new c_float[temp_q.size()];
        for (size_t i = 0; i < temp_q.size(); i++)
        {
            data->q[i] = temp_q[i];
        }
        data->A = &temp_A; // 需要全部记录
        data->l = new c_float[low_vector_.size()];
        for (size_t i = 0; i < low_vector_.size(); i++)
        {
            data->l[i] = low_vector_[i];
        }
        data->u = new c_float[upp_vector_.size()];
        for (size_t i = 0; i < upp_vector_.size(); i++)
        {
            data->u[i] = upp_vector_[i];
        }
    }
    // std::cout<<"--------------quad_matrix_---------------"<<std::endl;
    // std::cout<<quad_matrix_<<std::endl;
    // std::cout<<"--------------A_matrix---------------"<<std::endl;
    // std::cout<<A_matrix_<<std::endl;
    // std::cout<<"--------------upp_vector_---------------"<<std::endl;
    // std::cout<<upp_vector_<<std::endl;
    // std::cout<<"--------------low_vector_---------------"<<std::endl;
    // std::cout<<low_vector_<<std::endl;
    // std::cout<<"low_vector_ 's size = "<< low_vector_.size()<<std::endl;
    // std::cout<<"A_matrix_ 's rows = "<< A_matrix_.rows()<<std::endl;

    // Define solver settings as default
    if (settings) osqp_set_default_settings(settings);

    // Setup workspace
    exitflag = osqp_setup(&work, data, settings);

    // Solve Problem
    osqp_solve(work);
    //   path_constraint_.size();
    bezier_3d_.resize(path_constraint_.size());
    ros::Time Now_time = ros::Time::now();

    for (size_t i = 0; i < path_constraint_.size(); i++)
    {
        bezier_3d_[i].scale  = path_constraint_[i].s_scale;
        bezier_3d_[i].order = traj_order_;
        bezier_3d_[i].times = Now_time;
        Now_time = Now_time +   ros::Duration( bezier_3d_[i].scale);
        bezier_3d_[i].coef_x = new double[traj_order_+1];
        for (size_t j = 0; j < traj_order_+1; j++)
        {
            bezier_3d_[i].coef_x[j] = work->solution->x[i*3*(traj_order_+1) + j];
        }
        bezier_3d_[i].coef_y = new double[traj_order_+1];
        for (size_t j = 0; j < traj_order_+1; j++)
        {
            bezier_3d_[i].coef_y[j] = work->solution->x[i*3*(traj_order_+1) + (traj_order_+1) + j];
        }
        bezier_3d_[i].coef_z = new double[traj_order_+1];
        for (size_t j = 0; j < traj_order_+1; j++)
        {
            bezier_3d_[i].coef_z[j] = work->solution->x[i*3*(traj_order_+1) + 2*(traj_order_+1) + j];
        }
        // std::cout << "----------------"<< i <<"th segment trajectory."<<"----------------------"<< std::endl;
        // std::cout << "-------------------x-------------------"<< std::endl;
        // vector_show(bezier_3d_[i].coef_x, traj_order_+1);
        // std::cout << "-------------------y-------------------"<< std::endl;
        // vector_show(bezier_3d_[i].coef_y, traj_order_+1);
        // std::cout << "-------------------z-------------------"<< std::endl;
        // vector_show(bezier_3d_[i].coef_z, traj_order_+1);
    }
}

void end_effector_planning::trajectory_out(ros::Time timeNow, path_point& traj_sp)
{
    if (timeNow.toSec() >= bezier_3d_[0].times.toSec()  )
    {
        bezier_out(timeNow, bezier_3d_[0], traj_sp);
    }
    if ((timeNow.toSec() >= bezier_3d_[0].times.toSec() +  bezier_3d_[0].scale) && (timeNow.toSec() <= bezier_3d_[0].times.toSec() +  bezier_3d_[0].scale + time_cnt_))
    {
        double t = timeNow.toSec() - (bezier_3d_[0].times.toSec() +  bezier_3d_[0].scale);
        end_contact_out( t, traj_sp);
    }
    if (timeNow.toSec() >= bezier_3d_[0].times.toSec() +  bezier_3d_[0].scale + time_cnt_)
    {
        end_contact_out( 1.0, traj_sp);
    }
}

void end_effector_planning::time_align(ros::Time time_in)
{
    if (bezier_3d_.size() == 1)
    {
        bezier_3d_[0].times = time_in;
    }
    else
    {
        ROS_ERROR("End-effector planning is wrong at first step!"); // set the task time based on beginning time.
    }
}

bool end_effector_planning::bezier_out(ros::Time timeNow, bezier bezier_in, path_point& traj_sp)
{
    VectorXd CList   = bernstein_.getC()[bezier_in.order];
    VectorXd CvList = bernstein_.getC_v()[bezier_in.order];
    VectorXd CaList = bernstein_.getC_a()[bezier_in.order];

    // 初始化
    traj_sp.pos.setZero();
    traj_sp.vel.setZero();
    traj_sp.acc.setZero();

    // 计算， 需要判断是否在时间域
    double t =  (timeNow.toSec() - bezier_in.times.toSec())/bezier_in.scale;
    if (t >1)
    {
        traj_sp.pos[0] =  bezier_in.scale *bezier_in.coef_x[bezier_in.order] ;
        traj_sp.pos[1] =  bezier_in.scale *bezier_in.coef_y[bezier_in.order] ;
        traj_sp.pos[2] =  bezier_in.scale *bezier_in.coef_z[bezier_in.order] ;
        traj_sp.vel[0] =  bezier_in.order * (bezier_in.coef_x[bezier_in.order] - bezier_in.coef_x[bezier_in.order-1]) ;
        traj_sp.vel[1] =  bezier_in.order * (bezier_in.coef_y[bezier_in.order] - bezier_in.coef_y[bezier_in.order-1]) ;
        traj_sp.vel[2] =  bezier_in.order * (bezier_in.coef_z[bezier_in.order] - bezier_in.coef_z[bezier_in.order-1]) ;
        traj_sp.acc[0]=  1.0 / bezier_in.scale * bezier_in.order * (bezier_in.order - 1) 
                                       * (bezier_in.coef_x[bezier_in.order]  - 2*bezier_in.coef_x[bezier_in.order-1]  + bezier_in.coef_x[bezier_in.order-2] );
        traj_sp.acc[1]=  1.0 / bezier_in.scale * bezier_in.order * (bezier_in.order - 1) 
                                       * (bezier_in.coef_y[bezier_in.order]  - 2*bezier_in.coef_y[bezier_in.order-1]  + bezier_in.coef_y[bezier_in.order-2] );
        traj_sp.acc[2]=  1.0 / bezier_in.scale * bezier_in.order * (bezier_in.order - 1) 
                                       * (bezier_in.coef_z[bezier_in.order]  - 2*bezier_in.coef_z[bezier_in.order-1]  + bezier_in.coef_z[bezier_in.order-2] );
        return 0;
    }
    else
    {
        for (size_t i = 0; i < (bezier_in.order+1); i++)
        {
            traj_sp.pos[0]  += bezier_in.scale *bezier_in.coef_x[i] * CList(i) * pow(t, i) * pow((1 - t), (bezier_in.order - i) );
            traj_sp.pos[1]  += bezier_in.scale *bezier_in.coef_y[i] * CList(i) * pow(t, i) * pow((1 - t), (bezier_in.order - i) );
            traj_sp.pos[2]  += bezier_in.scale *bezier_in.coef_z[i] * CList(i) * pow(t, i) * pow((1 - t), (bezier_in.order - i) );
            if (i<bezier_in.order)
            {
                traj_sp.vel[0] += CvList(i) * bezier_in.order * (bezier_in.coef_x[i+1] - bezier_in.coef_x[i]) * pow(t, i) * pow((1 - t), (bezier_in.order - 1 - i) );
                traj_sp.vel[1] += CvList(i) * bezier_in.order * (bezier_in.coef_y[i+1] - bezier_in.coef_y[i]) * pow(t, i) * pow((1 - t), (bezier_in.order - 1 - i) );
                traj_sp.vel[2] += CvList(i) * bezier_in.order * (bezier_in.coef_z[i+1] - bezier_in.coef_z[i]) * pow(t, i) * pow((1 - t), (bezier_in.order - 1 - i) );
            }
            if (i<bezier_in.order-1)
            {
                traj_sp.acc[0] += 1.0 / bezier_in.scale * CaList(i) * bezier_in.order * (bezier_in.order - 1) 
                                                * (bezier_in.coef_x[i+2]  - 2*bezier_in.coef_x[i+1]  + bezier_in.coef_x[i] ) * pow(t, i) * pow((1 - t), (bezier_in.order - 2 - i) );
                traj_sp.acc[1] += 1.0 / bezier_in.scale * CaList(i) * bezier_in.order * (bezier_in.order - 1) 
                                                * (bezier_in.coef_y[i+2]  - 2*bezier_in.coef_y[i+1]  + bezier_in.coef_y[i] ) * pow(t, i) * pow((1 - t), (bezier_in.order - 2 - i) );
                traj_sp.acc[2] += 1.0 / bezier_in.scale * CaList(i) * bezier_in.order * (bezier_in.order - 1) 
                                                * (bezier_in.coef_z[i+2]  - 2*bezier_in.coef_z[i+1]  + bezier_in.coef_z[i] ) * pow(t, i) * pow((1 - t), (bezier_in.order - 2 - i) );
            }
        }
        return 1;
    }
}


