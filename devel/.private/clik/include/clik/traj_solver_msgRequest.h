// Generated by gencpp from file clik/traj_solver_msgRequest.msg
// DO NOT EDIT!


#ifndef CLIK_MESSAGE_TRAJ_SOLVER_MSGREQUEST_H
#define CLIK_MESSAGE_TRAJ_SOLVER_MSGREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace clik
{
template <class ContainerAllocator>
struct traj_solver_msgRequest_
{
  typedef traj_solver_msgRequest_<ContainerAllocator> Type;

  traj_solver_msgRequest_()
    : s_scale(0.0)
    , x_upperPosition(0.0)
    , x_lowerPosition(0.0)
    , x_upperVelocity(0.0)
    , x_lowerVelocity(0.0)
    , x_upperAccelera(0.0)
    , x_lowerAccelera(0.0)
    , x_0(0.0)
    , x_n(0.0)
    , x_v0(0.0)
    , x_vn(0.0)
    , y_upperPosition(0.0)
    , y_lowerPosition(0.0)
    , y_upperVelocity(0.0)
    , y_lowerVelocity(0.0)
    , y_upperAccelera(0.0)
    , y_lowerAccelera(0.0)
    , y_0(0.0)
    , y_n(0.0)
    , y_v0(0.0)
    , y_vn(0.0)
    , z_upperPosition(0.0)
    , z_lowerPosition(0.0)
    , z_upperVelocity(0.0)
    , z_lowerVelocity(0.0)
    , z_upperAccelera(0.0)
    , z_lowerAccelera(0.0)
    , z_0(0.0)
    , z_n(0.0)
    , z_v0(0.0)
    , z_vn(0.0)  {
    }
  traj_solver_msgRequest_(const ContainerAllocator& _alloc)
    : s_scale(0.0)
    , x_upperPosition(0.0)
    , x_lowerPosition(0.0)
    , x_upperVelocity(0.0)
    , x_lowerVelocity(0.0)
    , x_upperAccelera(0.0)
    , x_lowerAccelera(0.0)
    , x_0(0.0)
    , x_n(0.0)
    , x_v0(0.0)
    , x_vn(0.0)
    , y_upperPosition(0.0)
    , y_lowerPosition(0.0)
    , y_upperVelocity(0.0)
    , y_lowerVelocity(0.0)
    , y_upperAccelera(0.0)
    , y_lowerAccelera(0.0)
    , y_0(0.0)
    , y_n(0.0)
    , y_v0(0.0)
    , y_vn(0.0)
    , z_upperPosition(0.0)
    , z_lowerPosition(0.0)
    , z_upperVelocity(0.0)
    , z_lowerVelocity(0.0)
    , z_upperAccelera(0.0)
    , z_lowerAccelera(0.0)
    , z_0(0.0)
    , z_n(0.0)
    , z_v0(0.0)
    , z_vn(0.0)  {
  (void)_alloc;
    }



   typedef double _s_scale_type;
  _s_scale_type s_scale;

   typedef double _x_upperPosition_type;
  _x_upperPosition_type x_upperPosition;

   typedef double _x_lowerPosition_type;
  _x_lowerPosition_type x_lowerPosition;

   typedef double _x_upperVelocity_type;
  _x_upperVelocity_type x_upperVelocity;

   typedef double _x_lowerVelocity_type;
  _x_lowerVelocity_type x_lowerVelocity;

   typedef double _x_upperAccelera_type;
  _x_upperAccelera_type x_upperAccelera;

   typedef double _x_lowerAccelera_type;
  _x_lowerAccelera_type x_lowerAccelera;

   typedef double _x_0_type;
  _x_0_type x_0;

   typedef double _x_n_type;
  _x_n_type x_n;

   typedef double _x_v0_type;
  _x_v0_type x_v0;

   typedef double _x_vn_type;
  _x_vn_type x_vn;

   typedef double _y_upperPosition_type;
  _y_upperPosition_type y_upperPosition;

   typedef double _y_lowerPosition_type;
  _y_lowerPosition_type y_lowerPosition;

   typedef double _y_upperVelocity_type;
  _y_upperVelocity_type y_upperVelocity;

   typedef double _y_lowerVelocity_type;
  _y_lowerVelocity_type y_lowerVelocity;

   typedef double _y_upperAccelera_type;
  _y_upperAccelera_type y_upperAccelera;

   typedef double _y_lowerAccelera_type;
  _y_lowerAccelera_type y_lowerAccelera;

   typedef double _y_0_type;
  _y_0_type y_0;

   typedef double _y_n_type;
  _y_n_type y_n;

   typedef double _y_v0_type;
  _y_v0_type y_v0;

   typedef double _y_vn_type;
  _y_vn_type y_vn;

   typedef double _z_upperPosition_type;
  _z_upperPosition_type z_upperPosition;

   typedef double _z_lowerPosition_type;
  _z_lowerPosition_type z_lowerPosition;

   typedef double _z_upperVelocity_type;
  _z_upperVelocity_type z_upperVelocity;

   typedef double _z_lowerVelocity_type;
  _z_lowerVelocity_type z_lowerVelocity;

   typedef double _z_upperAccelera_type;
  _z_upperAccelera_type z_upperAccelera;

   typedef double _z_lowerAccelera_type;
  _z_lowerAccelera_type z_lowerAccelera;

   typedef double _z_0_type;
  _z_0_type z_0;

   typedef double _z_n_type;
  _z_n_type z_n;

   typedef double _z_v0_type;
  _z_v0_type z_v0;

   typedef double _z_vn_type;
  _z_vn_type z_vn;





  typedef boost::shared_ptr< ::clik::traj_solver_msgRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::clik::traj_solver_msgRequest_<ContainerAllocator> const> ConstPtr;

}; // struct traj_solver_msgRequest_

typedef ::clik::traj_solver_msgRequest_<std::allocator<void> > traj_solver_msgRequest;

typedef boost::shared_ptr< ::clik::traj_solver_msgRequest > traj_solver_msgRequestPtr;
typedef boost::shared_ptr< ::clik::traj_solver_msgRequest const> traj_solver_msgRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::clik::traj_solver_msgRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::clik::traj_solver_msgRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::clik::traj_solver_msgRequest_<ContainerAllocator1> & lhs, const ::clik::traj_solver_msgRequest_<ContainerAllocator2> & rhs)
{
  return lhs.s_scale == rhs.s_scale &&
    lhs.x_upperPosition == rhs.x_upperPosition &&
    lhs.x_lowerPosition == rhs.x_lowerPosition &&
    lhs.x_upperVelocity == rhs.x_upperVelocity &&
    lhs.x_lowerVelocity == rhs.x_lowerVelocity &&
    lhs.x_upperAccelera == rhs.x_upperAccelera &&
    lhs.x_lowerAccelera == rhs.x_lowerAccelera &&
    lhs.x_0 == rhs.x_0 &&
    lhs.x_n == rhs.x_n &&
    lhs.x_v0 == rhs.x_v0 &&
    lhs.x_vn == rhs.x_vn &&
    lhs.y_upperPosition == rhs.y_upperPosition &&
    lhs.y_lowerPosition == rhs.y_lowerPosition &&
    lhs.y_upperVelocity == rhs.y_upperVelocity &&
    lhs.y_lowerVelocity == rhs.y_lowerVelocity &&
    lhs.y_upperAccelera == rhs.y_upperAccelera &&
    lhs.y_lowerAccelera == rhs.y_lowerAccelera &&
    lhs.y_0 == rhs.y_0 &&
    lhs.y_n == rhs.y_n &&
    lhs.y_v0 == rhs.y_v0 &&
    lhs.y_vn == rhs.y_vn &&
    lhs.z_upperPosition == rhs.z_upperPosition &&
    lhs.z_lowerPosition == rhs.z_lowerPosition &&
    lhs.z_upperVelocity == rhs.z_upperVelocity &&
    lhs.z_lowerVelocity == rhs.z_lowerVelocity &&
    lhs.z_upperAccelera == rhs.z_upperAccelera &&
    lhs.z_lowerAccelera == rhs.z_lowerAccelera &&
    lhs.z_0 == rhs.z_0 &&
    lhs.z_n == rhs.z_n &&
    lhs.z_v0 == rhs.z_v0 &&
    lhs.z_vn == rhs.z_vn;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::clik::traj_solver_msgRequest_<ContainerAllocator1> & lhs, const ::clik::traj_solver_msgRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace clik

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::clik::traj_solver_msgRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clik::traj_solver_msgRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clik::traj_solver_msgRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d2d10619491418a33c3811389a801280";
  }

  static const char* value(const ::clik::traj_solver_msgRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd2d10619491418a3ULL;
  static const uint64_t static_value2 = 0x3c3811389a801280ULL;
};

template<class ContainerAllocator>
struct DataType< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "clik/traj_solver_msgRequest";
  }

  static const char* value(const ::clik::traj_solver_msgRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 s_scale  \n"
"float64 x_upperPosition \n"
"float64 x_lowerPosition \n"
"float64 x_upperVelocity\n"
"float64 x_lowerVelocity\n"
"float64 x_upperAccelera\n"
"float64 x_lowerAccelera\n"
"float64 x_0\n"
"float64 x_n\n"
"float64 x_v0\n"
"float64 x_vn\n"
"float64 y_upperPosition \n"
"float64 y_lowerPosition \n"
"float64 y_upperVelocity\n"
"float64 y_lowerVelocity\n"
"float64 y_upperAccelera\n"
"float64 y_lowerAccelera\n"
"float64 y_0\n"
"float64 y_n\n"
"float64 y_v0\n"
"float64 y_vn\n"
"float64 z_upperPosition \n"
"float64 z_lowerPosition \n"
"float64 z_upperVelocity\n"
"float64 z_lowerVelocity\n"
"float64 z_upperAccelera\n"
"float64 z_lowerAccelera\n"
"float64 z_0\n"
"float64 z_n\n"
"float64 z_v0\n"
"float64 z_vn\n"
;
  }

  static const char* value(const ::clik::traj_solver_msgRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.s_scale);
      stream.next(m.x_upperPosition);
      stream.next(m.x_lowerPosition);
      stream.next(m.x_upperVelocity);
      stream.next(m.x_lowerVelocity);
      stream.next(m.x_upperAccelera);
      stream.next(m.x_lowerAccelera);
      stream.next(m.x_0);
      stream.next(m.x_n);
      stream.next(m.x_v0);
      stream.next(m.x_vn);
      stream.next(m.y_upperPosition);
      stream.next(m.y_lowerPosition);
      stream.next(m.y_upperVelocity);
      stream.next(m.y_lowerVelocity);
      stream.next(m.y_upperAccelera);
      stream.next(m.y_lowerAccelera);
      stream.next(m.y_0);
      stream.next(m.y_n);
      stream.next(m.y_v0);
      stream.next(m.y_vn);
      stream.next(m.z_upperPosition);
      stream.next(m.z_lowerPosition);
      stream.next(m.z_upperVelocity);
      stream.next(m.z_lowerVelocity);
      stream.next(m.z_upperAccelera);
      stream.next(m.z_lowerAccelera);
      stream.next(m.z_0);
      stream.next(m.z_n);
      stream.next(m.z_v0);
      stream.next(m.z_vn);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct traj_solver_msgRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::clik::traj_solver_msgRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::clik::traj_solver_msgRequest_<ContainerAllocator>& v)
  {
    s << indent << "s_scale: ";
    Printer<double>::stream(s, indent + "  ", v.s_scale);
    s << indent << "x_upperPosition: ";
    Printer<double>::stream(s, indent + "  ", v.x_upperPosition);
    s << indent << "x_lowerPosition: ";
    Printer<double>::stream(s, indent + "  ", v.x_lowerPosition);
    s << indent << "x_upperVelocity: ";
    Printer<double>::stream(s, indent + "  ", v.x_upperVelocity);
    s << indent << "x_lowerVelocity: ";
    Printer<double>::stream(s, indent + "  ", v.x_lowerVelocity);
    s << indent << "x_upperAccelera: ";
    Printer<double>::stream(s, indent + "  ", v.x_upperAccelera);
    s << indent << "x_lowerAccelera: ";
    Printer<double>::stream(s, indent + "  ", v.x_lowerAccelera);
    s << indent << "x_0: ";
    Printer<double>::stream(s, indent + "  ", v.x_0);
    s << indent << "x_n: ";
    Printer<double>::stream(s, indent + "  ", v.x_n);
    s << indent << "x_v0: ";
    Printer<double>::stream(s, indent + "  ", v.x_v0);
    s << indent << "x_vn: ";
    Printer<double>::stream(s, indent + "  ", v.x_vn);
    s << indent << "y_upperPosition: ";
    Printer<double>::stream(s, indent + "  ", v.y_upperPosition);
    s << indent << "y_lowerPosition: ";
    Printer<double>::stream(s, indent + "  ", v.y_lowerPosition);
    s << indent << "y_upperVelocity: ";
    Printer<double>::stream(s, indent + "  ", v.y_upperVelocity);
    s << indent << "y_lowerVelocity: ";
    Printer<double>::stream(s, indent + "  ", v.y_lowerVelocity);
    s << indent << "y_upperAccelera: ";
    Printer<double>::stream(s, indent + "  ", v.y_upperAccelera);
    s << indent << "y_lowerAccelera: ";
    Printer<double>::stream(s, indent + "  ", v.y_lowerAccelera);
    s << indent << "y_0: ";
    Printer<double>::stream(s, indent + "  ", v.y_0);
    s << indent << "y_n: ";
    Printer<double>::stream(s, indent + "  ", v.y_n);
    s << indent << "y_v0: ";
    Printer<double>::stream(s, indent + "  ", v.y_v0);
    s << indent << "y_vn: ";
    Printer<double>::stream(s, indent + "  ", v.y_vn);
    s << indent << "z_upperPosition: ";
    Printer<double>::stream(s, indent + "  ", v.z_upperPosition);
    s << indent << "z_lowerPosition: ";
    Printer<double>::stream(s, indent + "  ", v.z_lowerPosition);
    s << indent << "z_upperVelocity: ";
    Printer<double>::stream(s, indent + "  ", v.z_upperVelocity);
    s << indent << "z_lowerVelocity: ";
    Printer<double>::stream(s, indent + "  ", v.z_lowerVelocity);
    s << indent << "z_upperAccelera: ";
    Printer<double>::stream(s, indent + "  ", v.z_upperAccelera);
    s << indent << "z_lowerAccelera: ";
    Printer<double>::stream(s, indent + "  ", v.z_lowerAccelera);
    s << indent << "z_0: ";
    Printer<double>::stream(s, indent + "  ", v.z_0);
    s << indent << "z_n: ";
    Printer<double>::stream(s, indent + "  ", v.z_n);
    s << indent << "z_v0: ";
    Printer<double>::stream(s, indent + "  ", v.z_v0);
    s << indent << "z_vn: ";
    Printer<double>::stream(s, indent + "  ", v.z_vn);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLIK_MESSAGE_TRAJ_SOLVER_MSGREQUEST_H
