// Generated by gencpp from file carla_ackermann_control/EgoVehicleControlStatus.msg
// DO NOT EDIT!


#ifndef CARLA_ACKERMANN_CONTROL_MESSAGE_EGOVEHICLECONTROLSTATUS_H
#define CARLA_ACKERMANN_CONTROL_MESSAGE_EGOVEHICLECONTROLSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace carla_ackermann_control
{
template <class ContainerAllocator>
struct EgoVehicleControlStatus_
{
  typedef EgoVehicleControlStatus_<ContainerAllocator> Type;

  EgoVehicleControlStatus_()
    : status()
    , speed_control_activation_count(0)
    , speed_control_accel_delta(0.0)
    , speed_control_accel_target(0.0)
    , accel_control_pedal_delta(0.0)
    , accel_control_pedal_target(0.0)
    , brake_upper_border(0.0)
    , throttle_lower_border(0.0)  {
    }
  EgoVehicleControlStatus_(const ContainerAllocator& _alloc)
    : status(_alloc)
    , speed_control_activation_count(0)
    , speed_control_accel_delta(0.0)
    , speed_control_accel_target(0.0)
    , accel_control_pedal_delta(0.0)
    , accel_control_pedal_target(0.0)
    , brake_upper_border(0.0)
    , throttle_lower_border(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_type;
  _status_type status;

   typedef uint8_t _speed_control_activation_count_type;
  _speed_control_activation_count_type speed_control_activation_count;

   typedef float _speed_control_accel_delta_type;
  _speed_control_accel_delta_type speed_control_accel_delta;

   typedef float _speed_control_accel_target_type;
  _speed_control_accel_target_type speed_control_accel_target;

   typedef float _accel_control_pedal_delta_type;
  _accel_control_pedal_delta_type accel_control_pedal_delta;

   typedef float _accel_control_pedal_target_type;
  _accel_control_pedal_target_type accel_control_pedal_target;

   typedef float _brake_upper_border_type;
  _brake_upper_border_type brake_upper_border;

   typedef float _throttle_lower_border_type;
  _throttle_lower_border_type throttle_lower_border;





  typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> const> ConstPtr;

}; // struct EgoVehicleControlStatus_

typedef ::carla_ackermann_control::EgoVehicleControlStatus_<std::allocator<void> > EgoVehicleControlStatus;

typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlStatus > EgoVehicleControlStatusPtr;
typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlStatus const> EgoVehicleControlStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace carla_ackermann_control

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'carla_msgs': ['/home/rosuser/carla-ros-bridge/catkin_ws/src/ros-bridge/carla_msgs/msg'], 'carla_ackermann_control': ['/home/rosuser/carla-ros-bridge/catkin_ws/src/ros-bridge/carla_ackermann_control/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5794a514157c1217dfba31bd9e6ca33c";
  }

  static const char* value(const ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5794a514157c1217ULL;
  static const uint64_t static_value2 = 0xdfba31bd9e6ca33cULL;
};

template<class ContainerAllocator>
struct DataType< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "carla_ackermann_control/EgoVehicleControlStatus";
  }

  static const char* value(const ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n\
# Copyright (c) 2018-2019 Intel Corporation.\n\
#\n\
# This work is licensed under the terms of the MIT license.\n\
# For a copy, see <https://opensource.org/licenses/MIT>.\n\
#\n\
# This represents the control status variables of the ego vehicle control\n\
\n\
# the current control status\n\
string status\n\
\n\
# speed controller\n\
uint8   speed_control_activation_count\n\
float32 speed_control_accel_delta\n\
float32 speed_control_accel_target\n\
\n\
# acceleration controller\n\
float32 accel_control_pedal_delta\n\
float32 accel_control_pedal_target\n\
\n\
# borders for lay off pedal\n\
float32 brake_upper_border\n\
float32 throttle_lower_border\n\
";
  }

  static const char* value(const ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.speed_control_activation_count);
      stream.next(m.speed_control_accel_delta);
      stream.next(m.speed_control_accel_target);
      stream.next(m.accel_control_pedal_delta);
      stream.next(m.accel_control_pedal_target);
      stream.next(m.brake_upper_border);
      stream.next(m.throttle_lower_border);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EgoVehicleControlStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::carla_ackermann_control::EgoVehicleControlStatus_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status);
    s << indent << "speed_control_activation_count: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.speed_control_activation_count);
    s << indent << "speed_control_accel_delta: ";
    Printer<float>::stream(s, indent + "  ", v.speed_control_accel_delta);
    s << indent << "speed_control_accel_target: ";
    Printer<float>::stream(s, indent + "  ", v.speed_control_accel_target);
    s << indent << "accel_control_pedal_delta: ";
    Printer<float>::stream(s, indent + "  ", v.accel_control_pedal_delta);
    s << indent << "accel_control_pedal_target: ";
    Printer<float>::stream(s, indent + "  ", v.accel_control_pedal_target);
    s << indent << "brake_upper_border: ";
    Printer<float>::stream(s, indent + "  ", v.brake_upper_border);
    s << indent << "throttle_lower_border: ";
    Printer<float>::stream(s, indent + "  ", v.throttle_lower_border);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CARLA_ACKERMANN_CONTROL_MESSAGE_EGOVEHICLECONTROLSTATUS_H
