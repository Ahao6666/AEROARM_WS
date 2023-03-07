#include "clik_cplus.h"
#include "mylib.h"

void clik_c_::hanlde_constant()
{
    double xi[6] = {CLIK_U.point_b[0],CLIK_U.point_b[1],CLIK_U.point_b[2],ped_[0],ped_[1],ped_[2]};
    double obser_cons_low[6],obser_cons_up[6];
    for (size_t i = 0; i < 6; i++)
    {
        obser_cons_low[i] = 2* xi_ddot_max[i]*xi[i]/xi_dot_min[i]-2*xi_ddot_max[i]*xi_min[i]/xi_dot_min[i];
        obser_cons_up[i]  = 2* xi_ddot_min[i]*xi[i]/xi_dot_max[i]-2*xi_ddot_min[i]*xi_max[i]/xi_dot_max[i];
    }
    double xi_cons_low[6],xi_cons_up[6];
    for (size_t i = 0; i < 6; i++)
    {
        xi_cons_low[i] = (xi_min[i]-xi[i])/CLIK_U.dtime;
        xi_cons_up[i]  = (xi_max[i]-xi[i])/CLIK_U.dtime;
    }
    
    double  l_cons[9],u_cons[9];
    for (size_t i = 0; i < 6; i++)
    {
        l_cons[3+i] = max_3(xi_cons_low[i],xi_dot_min[i],obser_cons_low[i]);
        u_cons[3+i] = min_3(xi_cons_up[i],xi_dot_max[i],obser_cons_up[i]);
    }

    upper_(0) =  u_cons[6];
    upper_(1) =  u_cons[7];
    upper_(2) =  u_cons[8];
    lower_(0) =  l_cons[6];
    lower_(1) =  l_cons[7];
    lower_(2) =  l_cons[8];
}


void anti_symmetry(Eigen::Vector3d  input, Eigen::Matrix3d&  output){
    output<< 0, -input(2),input(1),
             input(2), 0, -input(0),
             -input(1), input(0), 0;
}
void sat( double& in, double min,double max)
{
    in = (in < min) ? min : in;
    in = (in > max)? max : in;
}

void clik_c_::clik_solver(){
    ped_ = rotation_delta_b_.transpose() * (CLIK_U.point_e_b - dOffset_);
    hanlde_constant();

    Eigen::Vector3d  temp = CLIK_U.rotation*CLIK_U.point_e_b;
    Eigen::Matrix3d temp_m;
    anti_symmetry(temp, temp_m);
    Eigen::Vector3d  p_clik;
    Eigen::Matrix3d rotation_delta2world = CLIK_U.rotation * rotation_delta_b_;
    p_clik = rotation_delta2world.transpose() * (CLIK_U.point_e_des_dot - 1.3*(CLIK_U.point_e - CLIK_U.point_e_des) - CLIK_U.vel_base + temp_m* CLIK_U.angular_vel_base);
    for (size_t i = 0; i < 3; i++)
    {
        sat(p_clik(i), lower_(i), upper_(i));
    }
    point_e_d_out_ =  point_e_d_out_ + p_clik * CLIK_U.dtime;
}
