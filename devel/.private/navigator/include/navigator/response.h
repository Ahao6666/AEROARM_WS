// Generated by gencpp from file navigator/response.msg
// DO NOT EDIT!


#ifndef NAVIGATOR_MESSAGE_RESPONSE_H
#define NAVIGATOR_MESSAGE_RESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace navigator
{
template <class ContainerAllocator>
struct response_
{
  typedef response_<ContainerAllocator> Type;

  response_()
    : header()
    , finished_behavior(0)
    , uav_id(0)
    , behavior_received(false)
    , behavior_finished(false)  {
    }
  response_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , finished_behavior(0)
    , uav_id(0)
    , behavior_received(false)
    , behavior_finished(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int8_t _finished_behavior_type;
  _finished_behavior_type finished_behavior;

   typedef int8_t _uav_id_type;
  _uav_id_type uav_id;

   typedef uint8_t _behavior_received_type;
  _behavior_received_type behavior_received;

   typedef uint8_t _behavior_finished_type;
  _behavior_finished_type behavior_finished;





  typedef boost::shared_ptr< ::navigator::response_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::navigator::response_<ContainerAllocator> const> ConstPtr;

}; // struct response_

typedef ::navigator::response_<std::allocator<void> > response;

typedef boost::shared_ptr< ::navigator::response > responsePtr;
typedef boost::shared_ptr< ::navigator::response const> responseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::navigator::response_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::navigator::response_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::navigator::response_<ContainerAllocator1> & lhs, const ::navigator::response_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.finished_behavior == rhs.finished_behavior &&
    lhs.uav_id == rhs.uav_id &&
    lhs.behavior_received == rhs.behavior_received &&
    lhs.behavior_finished == rhs.behavior_finished;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::navigator::response_<ContainerAllocator1> & lhs, const ::navigator::response_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace navigator

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::navigator::response_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::navigator::response_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator::response_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator::response_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator::response_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator::response_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::navigator::response_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3a2625249be6a4aa28101b91b984ef1a";
  }

  static const char* value(const ::navigator::response_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3a2625249be6a4aaULL;
  static const uint64_t static_value2 = 0x28101b91b984ef1aULL;
};

template<class ContainerAllocator>
struct DataType< ::navigator::response_<ContainerAllocator> >
{
  static const char* value()
  {
    return "navigator/response";
  }

  static const char* value(const ::navigator::response_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::navigator::response_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"int8   finished_behavior\n"
"int8   uav_id\n"
"bool   behavior_received\n"
"bool   behavior_finished\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::navigator::response_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::navigator::response_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.finished_behavior);
      stream.next(m.uav_id);
      stream.next(m.behavior_received);
      stream.next(m.behavior_finished);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct response_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::navigator::response_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::navigator::response_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "finished_behavior: ";
    Printer<int8_t>::stream(s, indent + "  ", v.finished_behavior);
    s << indent << "uav_id: ";
    Printer<int8_t>::stream(s, indent + "  ", v.uav_id);
    s << indent << "behavior_received: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.behavior_received);
    s << indent << "behavior_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.behavior_finished);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NAVIGATOR_MESSAGE_RESPONSE_H
