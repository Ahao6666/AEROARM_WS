// Generated by gencpp from file clik/traj_out_msgRequest.msg
// DO NOT EDIT!


#ifndef CLIK_MESSAGE_TRAJ_OUT_MSGREQUEST_H
#define CLIK_MESSAGE_TRAJ_OUT_MSGREQUEST_H


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
struct traj_out_msgRequest_
{
  typedef traj_out_msgRequest_<ContainerAllocator> Type;

  traj_out_msgRequest_()
    : times()  {
    }
  traj_out_msgRequest_(const ContainerAllocator& _alloc)
    : times()  {
  (void)_alloc;
    }



   typedef ros::Time _times_type;
  _times_type times;





  typedef boost::shared_ptr< ::clik::traj_out_msgRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::clik::traj_out_msgRequest_<ContainerAllocator> const> ConstPtr;

}; // struct traj_out_msgRequest_

typedef ::clik::traj_out_msgRequest_<std::allocator<void> > traj_out_msgRequest;

typedef boost::shared_ptr< ::clik::traj_out_msgRequest > traj_out_msgRequestPtr;
typedef boost::shared_ptr< ::clik::traj_out_msgRequest const> traj_out_msgRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::clik::traj_out_msgRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::clik::traj_out_msgRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::clik::traj_out_msgRequest_<ContainerAllocator1> & lhs, const ::clik::traj_out_msgRequest_<ContainerAllocator2> & rhs)
{
  return lhs.times == rhs.times;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::clik::traj_out_msgRequest_<ContainerAllocator1> & lhs, const ::clik::traj_out_msgRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace clik

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::clik::traj_out_msgRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::clik::traj_out_msgRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clik::traj_out_msgRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clik::traj_out_msgRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clik::traj_out_msgRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clik::traj_out_msgRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::clik::traj_out_msgRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0a97ae2341ad1b2d6f0203e8c93f2964";
  }

  static const char* value(const ::clik::traj_out_msgRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0a97ae2341ad1b2dULL;
  static const uint64_t static_value2 = 0x6f0203e8c93f2964ULL;
};

template<class ContainerAllocator>
struct DataType< ::clik::traj_out_msgRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "clik/traj_out_msgRequest";
  }

  static const char* value(const ::clik::traj_out_msgRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::clik::traj_out_msgRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time times\n"
;
  }

  static const char* value(const ::clik::traj_out_msgRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::clik::traj_out_msgRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.times);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct traj_out_msgRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::clik::traj_out_msgRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::clik::traj_out_msgRequest_<ContainerAllocator>& v)
  {
    s << indent << "times: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.times);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLIK_MESSAGE_TRAJ_OUT_MSGREQUEST_H
