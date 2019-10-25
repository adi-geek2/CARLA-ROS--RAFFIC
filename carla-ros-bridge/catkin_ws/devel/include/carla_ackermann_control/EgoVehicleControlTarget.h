// Generated by gencpp from file carla_ackermann_control/EgoVehicleControlTarget.msg
// DO NOT EDIT!


#ifndef CARLA_ACKERMANN_CONTROL_MESSAGE_EGOVEHICLECONTROLTARGET_H
#define CARLA_ACKERMANN_CONTROL_MESSAGE_EGOVEHICLECONTROLTARGET_H


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
struct EgoVehicleControlTarget_
{
  typedef EgoVehicleControlTarget_<ContainerAllocator> Type;

  EgoVehicleControlTarget_()
    : steering_angle(0.0)
    , speed(0.0)
    , speed_abs(0.0)
    , accel(0.0)
    , jerk(0.0)  {
    }
  EgoVehicleControlTarget_(const ContainerAllocator& _alloc)
    : steering_angle(0.0)
    , speed(0.0)
    , speed_abs(0.0)
    , accel(0.0)
    , jerk(0.0)  {
  (void)_alloc;
    }



   typedef float _steering_angle_type;
  _steering_angle_type steering_angle;

   typedef float _speed_type;
  _speed_type speed;

   typedef float _speed_abs_type;
  _speed_abs_type speed_abs;

   typedef float _accel_type;
  _accel_type accel;

   typedef float _jerk_type;
  _jerk_type jerk;





  typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> const> ConstPtr;

}; // struct EgoVehicleControlTarget_

typedef ::carla_ackermann_control::EgoVehicleControlTarget_<std::allocator<void> > EgoVehicleControlTarget;

typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlTarget > EgoVehicleControlTargetPtr;
typedef boost::shared_ptr< ::carla_ackermann_control::EgoVehicleControlTarget const> EgoVehicleControlTargetConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace carla_ackermann_control

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'carla_msgs': ['/home/rosuser/carla-ros-bridge/catkin_ws/src/ros-bridge/carla_msgs/msg'], 'carla_ackermann_control': ['/home/rosuser/carla-ros-bridge/catkin_ws/src/ros-bridge/carla_ackermann_control/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f1f09cb4036d07c40bb9c47fb2889e9c";
  }

  static const char* value(const ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf1f09cb4036d07c4ULL;
  static const uint64_t static_value2 = 0x0bb9c47fb2889e9cULL;
};

template<class ContainerAllocator>
struct DataType< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
{
  static const char* value()
  {
    return "carla_ackermann_control/EgoVehicleControlTarget";
  }

  static const char* value(const ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n\
# Copyright (c) 2018-2019 Intel Corporation.\n\
#\n\
# This work is licensed under the terms of the MIT license.\n\
# For a copy, see <https://opensource.org/licenses/MIT>.\n\
#\n\
# This represents the target speed/accel values of the ego vehicle\n\
\n\
float32 steering_angle\n\
float32 speed\n\
float32 speed_abs\n\
float32 accel\n\
float32 jerk\n\
";
  }

  static const char* value(const ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.steering_angle);
      stream.next(m.speed);
      stream.next(m.speed_abs);
      stream.next(m.accel);
      stream.next(m.jerk);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EgoVehicleControlTarget_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::carla_ackermann_control::EgoVehicleControlTarget_<ContainerAllocator>& v)
  {
    s << indent << "steering_angle: ";
    Printer<float>::stream(s, indent + "  ", v.steering_angle);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "speed_abs: ";
    Printer<float>::stream(s, indent + "  ", v.speed_abs);
    s << indent << "accel: ";
    Printer<float>::stream(s, indent + "  ", v.accel);
    s << indent << "jerk: ";
    Printer<float>::stream(s, indent + "  ", v.jerk);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CARLA_ACKERMANN_CONTROL_MESSAGE_EGOVEHICLECONTROLTARGET_H
