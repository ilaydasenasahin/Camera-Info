cmake_minimum_required(VERSION 3.0.2)
project(get_cam_info)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR /usr/share/OpenCV)

# Get the information about this package's buildtime dependencies
find_package(catkin REQUIRED COMPONENTS 
  roscpp
  rospy
  std_msgs
)
add_library(cam_info_pub
  src/get_cam_info.cpp
) 
# Declare the message files to be built
#add_message_files(FILES
#  MyMessage1.msg
#  MyMessage2.msg
#)
catkin_package(
  INCLUDE_DIRS 
  include
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}

)
# define executable using MyMessage1 etc.
add_executable(get_cam_info src/get_cam_info.cpp src/get_cam_info_node.cpp)
target_compile_features(get_cam_info INTERFACE cxx_std_11)
add_dependencies(cam_info_pub ${catkin_EXPORTED_TARGETS})
add_dependencies(get_cam_info ${catkin_EXPORTED_TARGETS})

target_link_libraries(get_cam_info ${catkin_LIBRARIES})
target_link_libraries(cam_info_pub ${catkin_LIBRARIES})