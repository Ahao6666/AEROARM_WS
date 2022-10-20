// Generated by gencpp from file calibration/manipulator_modeResponse.msg
// DO NOT EDIT!


#ifndef CALIBRATION_MESSAGE_MANIPULATOR_MODERESPONSE_H
#define CALIBRATION_MESSAGE_MANIPULATOR_MODERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace calibration
{
template <class ContainerAllocator>
struct manipulator_modeResponse_
{
  typedef manipulator_modeResponse_<ContainerAllocator> Type;

  manipulator_modeResponse_()
    : result(false)  {
    }
  manipulator_modeResponse_(const ContainerAllocator& _alloc)
    : result(false)  {
  (void)_alloc;
    }



   typedef uint8_t _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::calibration::manipulator_modeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::calibration::manipulator_modeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct manipulator_modeResponse_

typedef ::calibration::manipulator_modeResponse_<std::allocator<void> > manipulator_modeResponse;

typedef boost::shared_ptr< ::calibration::manipulator_modeResponse > manipulator_modeResponsePtr;
typedef boost::shared_ptr< ::calibration::manipulator_modeResponse const> manipulator_modeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::calibration::manipulator_modeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::calibration::manipulator_modeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::calibration::manipulator_modeResponse_<ContainerAllocator1> & lhs, const ::calibration::manipulator_modeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::calibration::manipulator_modeResponse_<ContainerAllocator1> & lhs, const ::calibration::manipulator_modeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace calibration

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::calibration::manipulator_modeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::calibration::manipulator_modeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::calibration::manipulator_modeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eb13ac1f1354ccecb7941ee8fa2192e8";
  }

  static const char* value(const ::calibration::manipulator_modeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeb13ac1f1354ccecULL;
  static const uint64_t static_value2 = 0xb7941ee8fa2192e8ULL;
};

template<class ContainerAllocator>
struct DataType< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "calibration/manipulator_modeResponse";
  }

  static const char* value(const ::calibration::manipulator_modeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool result\n"
;
  }

  static const char* value(const ::calibration::manipulator_modeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct manipulator_modeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::calibration::manipulator_modeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::calibration::manipulator_modeResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CALIBRATION_MESSAGE_MANIPULATOR_MODERESPONSE_H
