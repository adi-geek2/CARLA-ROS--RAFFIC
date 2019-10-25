// Generated by gencpp from file carla_msgs/CarlaControl.msg
// DO NOT EDIT!


#ifndef CARLA_MSGS_MESSAGE_CARLACONTROL_H
#define CARLA_MSGS_MESSAGE_CARLACONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace carla_msgs
{
template <class ContainerAllocator>
struct CarlaControl_
{
  typedef CarlaControl_<ContainerAllocator> Type;

  CarlaControl_()
    : command(0)  {
    }
  CarlaControl_(const ContainerAllocator& _alloc)
    : command(0)  {
  (void)_alloc;
    }



   typedef int8_t _command_type;
  _command_type command;



  enum {
    PLAY = 0,
    PAUSE = 1,
    STEP_ONCE = 2,
  };


  typedef boost::shared_ptr< ::carla_msgs::CarlaControl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::carla_msgs::CarlaControl_<ContainerAllocator> const> ConstPtr;

}; // struct CarlaControl_

typedef ::carla_msgs::CarlaControl_<std::allocator<void> > CarlaControl;

typedef boost::shared_ptr< ::carla_msgs::CarlaControl > CarlaControlPtr;
typedef boost::shared_ptr< ::carla_msgs::CarlaControl const> CarlaControlConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::carla_msgs::CarlaControl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::carla_msgs::CarlaControl_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace carla_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'carla_msgs': ['/home/rosuser/carla-ros-bridge/catkin_ws/src/ros-bridge/carla_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::carla_msgs::CarlaControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::carla_msgs::CarlaControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_msgs::CarlaControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_msgs::CarlaControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_msgs::CarlaControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_msgs::CarlaControl_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::carla_msgs::CarlaControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "30f228b2c28301e4ee4bc6cc67050acb";
  }

  static const char* value(const ::carla_msgs::CarlaControl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x30f228b2c28301e4ULL;
  static const uint64_t static_value2 = 0xee4bc6cc67050acbULL;
};

template<class ContainerAllocator>
struct DataType< ::carla_msgs::CarlaControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "carla_msgs/CarlaControl";
  }

  static const char* value(const ::carla_msgs::CarlaControl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::carla_msgs::CarlaControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n\
# Copyright (c) 2019 Intel Corporation.\n\
#\n\
# This work is licensed under the terms of the MIT license.\n\
# For a copy, see <https://opensource.org/licenses/MIT>.\n\
#\n\
\n\
int8 PLAY = 0\n\
int8 PAUSE = 1\n\
int8 STEP_ONCE = 2\n\
\n\
int8 command\n\
\n\
";
  }

  static const char* value(const ::carla_msgs::CarlaControl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::carla_msgs::CarlaControl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CarlaControl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::carla_msgs::CarlaControl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::carla_msgs::CarlaControl_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    Printer<int8_t>::stream(s, indent + "  ", v.command);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CARLA_MSGS_MESSAGE_CARLACONTROL_H
