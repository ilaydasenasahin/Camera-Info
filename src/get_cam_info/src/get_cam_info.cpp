#include "get_cam_info.hpp"

namespace get_cam_info
{
CameraInfo::CameraInfo(ros::NodeHandle& t_node_handle)
  : m_node_handle(t_node_handle)
{
    if (!readParameters())
    {
        ROS_ERROR("Could not read parameters.");
        ros::requestShutdown();
    }

    timer_subscriber = m_node_handle.createTimer(ros::Duration(0.1), &CameraInfo::topicCallback, this);

    m_parameter_publisher = m_node_handle.advertise<sensor_msgs::CameraInfo>("camera_info", 1000);

    ROS_INFO("Successfully launched node.");
}

bool CameraInfo::readParameters()
{
    if (!m_node_handle.getParam("camera_info", camera_info))
    {
        return false;
    }
    if (!m_node_handle.getParam("K", m_intrinsic_parameters))
    {
        return false;
    }
    if (!m_node_handle.getParam("D", m_distortion_coefficients))
    {
        return false;
    }
    return true;
}

void CameraInfo::topicCallback(const ros::TimerEvent&)
{
    sensor_msgs::CameraInfo cam_info ;

    cam_info.header.frame_id = "ilayda";
    cam_info.header.stamp = ros::Time::now();
    cam_info.D = m_distortion_coefficients;
    
    for(int i=0 ; i<9 ; i++){
        cam_info.K[i] = m_intrinsic_parameters[i];
    }
    
    m_parameter_publisher.publish(cam_info);
    
}
}