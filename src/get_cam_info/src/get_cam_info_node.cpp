#include <ros/ros.h>
#include "get_cam_info.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "camera_info");
    ros::NodeHandle node_handle("~");

    get_cam_info::CameraInfo camera_info(node_handle);

    ros::spin();
    return 0;
}