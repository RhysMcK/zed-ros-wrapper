#include <ros/ros.h>
#include <sensor_msgs/Image.h>

/**
 * This tutorial demonstrates simple receipt of ZED image messages over the ROS system.
 */


/**
 * Subscriber callbacks
 */
void imageRgbRawCallback(const sensor_msgs::Image::ConstPtr& msg) {
    ROS_INFO("RGB RAW image received from ZED - Size: %dx%d", msg->width, msg->height);
}

void imageRgbRectCallback(const sensor_msgs::Image::ConstPtr& msg) {
    ROS_INFO("RGB Rectified image received from ZED - Size: %dx%d", msg->width, msg->height);
}

void imageRightRawCallback(const sensor_msgs::Image::ConstPtr& msg) {
    ROS_INFO("Right RAW image received from ZED - Size: %dx%d", msg->width, msg->height);
}

void imageRightRectCallback(const sensor_msgs::Image::ConstPtr& msg) {
    ROS_INFO("Right Rectified image received from ZED - Size: %dx%d", msg->width, msg->height);
}

void imageLeftRawCallback(const sensor_msgs::Image::ConstPtr& msg) {
    ROS_INFO("Left RAW image received from ZED - Size: %dx%d", msg->width, msg->height);
}

void imageLeftRectCallback(const sensor_msgs::Image::ConstPtr& msg) {
    ROS_INFO("Left Rectified image received from ZED - Size: %dx%d", msg->width, msg->height);
}

/**
 * Node main function
 */
int main(int argc, char** argv) {
    /**
     * The ros::init() function needs to see argc and argv so that it can perform
     * any ROS arguments and name remapping that were provided at the command line.
     * For programmatic remappings you can use a different version of init() which takes
     * remappings directly, but for most command-line programs, passing argc and argv is
     * the easiest way to do it.  The third argument to init() is the name of the node.
     *
     * You must call one of the versions of ros::init() before using any other
     * part of the ROS system.
     */
    ros::init(argc, argv, "zed_video_subscriber");

    /**
     * NodeHandle is the main access point to communications with the ROS system.
     * The first NodeHandle constructed will fully initialize this node, and the last
     * NodeHandle destructed will close down the node.
     */
    ros::NodeHandle n;

    /**
     * The subscribe() call is how you tell ROS that you want to receive messages
     * on a given topic.  This invokes a call to the ROS
     * master node, which keeps a registry of who is publishing and who
     * is subscribing.  Messages are passed to a callback function, here
     * called imageCallback.  subscribe() returns a Subscriber object that you
     * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
     * object go out of scope, this callback will automatically be unsubscribed from
     * this topic.
     *
     * The second parameter to the subscribe() function is the size of the message
     * queue.  If messages are arriving faster than they are being processed, this
     * is the number of messages that will be buffered up before beginning to throw
     * away the oldest ones.
     */
    ros::Subscriber subRgbRaw  = n.subscribe("/zed/rgb/image_raw_color", 10, imageRgbRawCallback);
    ros::Subscriber subRgbRect = n.subscribe("/zed/rgb/image_rect_color", 10, imageRgbRectCallback);
    ros::Subscriber subRightRaw  = n.subscribe("/zed/right/image_raw_color", 10, imageRightRawCallback);
    ros::Subscriber subRightRect = n.subscribe("/zed/right/image_rect_color", 10, imageRightRectCallback);
    ros::Subscriber subLeftRaw  = n.subscribe("/zed/left/image_raw_color", 10, imageLeftRawCallback);
    ros::Subscriber subLeftRect = n.subscribe("/zed/left/image_rect_color", 10, imageLeftRectCallback);

    /**
     * ros::spin() will enter a loop, pumping callbacks.  With this version, all
     * callbacks will be called from within this thread (the main one).  ros::spin()
     * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
     */
    ros::spin();

    return 0;
}
