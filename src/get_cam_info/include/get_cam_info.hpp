#pragma once

#include <ros/ros.h>
#include <sensor_msgs/CameraInfo.h>


namespace get_cam_info
{
class CameraInfo
{
  public:
    /*!
     * Constructor.
     * @param nodeHandle the ROS node handle.
     */
    CameraInfo(ros::NodeHandle& t_node_handle);

  private:
    /*!
     * Reads and verifies the ROS parameters.
     * @return true if successful.
     */
    bool readParameters();

    /*!
     * ROS message filter callback method.
     * @param t_image the received Image message.
     */
    void topicCallback(const ros::TimerEvent& );

    //! ROS node handle.
    ros::NodeHandle& m_node_handle;

    //! Camera topic name.
    std::string camera_info;

    //! Intrinsic parameters.
    std::vector<double> m_intrinsic_parameters;

    //! Distortion coefficients.
    std::vector<double> m_distortion_coefficients;

    //! Timer subscriber.
    ros::Timer timer_subscriber;

    //! Parameter publisher.
    ros::Publisher m_parameter_publisher;
};

}  // namespace aesk_camera_driver
