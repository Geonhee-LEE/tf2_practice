#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>



int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf2_broadcaster");
  ros::NodeHandle nh("~");

int x1, x2, x3, x4, y1, y2, y3, y4;
geometry_msgs::TransformStamped transformStamped;
geometry_msgs::TransformStamped transformStamped2;
geometry_msgs::TransformStamped transformStamped3;
geometry_msgs::TransformStamped transformStamped4;
tf2_ros::TransformBroadcaster tfb;
  ros::Rate rate(10.0);
  
  while (nh.ok()){

    nh.getParam("x1", x1) ; 
nh.getParam("y1", y1); 
nh.getParam("x2", x2);  
nh.getParam("y2", y2) ;   
nh.getParam("x3", x3) ;  
nh.getParam("y3", y3) ; 
nh.getParam("x4", x4) ; 
nh.getParam("y4", y4);
      
    
    transformStamped.header.stamp = ros::Time::now();
  //set a tf inheriting map.
  transformStamped.header.frame_id = "map";
  transformStamped.child_frame_id = "submap1";
  transformStamped.transform.translation.x = x1;
  transformStamped.transform.translation.y = y1;
  transformStamped.transform.translation.z = 0.0;
  tf2::Quaternion q;

  q.setRPY(0, 0, 0);
  transformStamped.transform.rotation.x = q.x();
  transformStamped.transform.rotation.y = q.y();
  transformStamped.transform.rotation.z = q.z();
  transformStamped.transform.rotation.w = q.w();

      
  //set a tf inheriting map.
  transformStamped2.header.frame_id = "map";
  transformStamped2.child_frame_id = "submap2";
  transformStamped2.transform.translation.x = x2;
  transformStamped2.transform.translation.y = y2;
  transformStamped2.transform.translation.z = 0.0;

  transformStamped2.transform.rotation.x = q.x();
  transformStamped2.transform.rotation.y = q.y();
  transformStamped2.transform.rotation.z = q.z();
  transformStamped2.transform.rotation.w = q.w();
 
  //set a tf inheriting map.
  transformStamped3.header.frame_id = "map";
  transformStamped3.child_frame_id = "submap3";
  transformStamped3.transform.translation.x = x3;
  transformStamped3.transform.translation.y = y3;
  transformStamped3.transform.translation.z = 0.0;

  q.setRPY(0, 0, 0);
  transformStamped3.transform.rotation.x = q.x();
  transformStamped3.transform.rotation.y = q.y();
  transformStamped3.transform.rotation.z = q.z();
  transformStamped3.transform.rotation.w = q.w();
 
  //set a tf inheriting map.
  transformStamped4.header.frame_id = "map";
  transformStamped4.child_frame_id = "submap4";
  transformStamped4.transform.translation.x = x4;
  transformStamped4.transform.translation.y = y4;
  transformStamped4.transform.translation.z = 0.0;

  q.setRPY(0, 0, 0);
  transformStamped4.transform.rotation.x = q.x();
  transformStamped4.transform.rotation.y = q.y();
  transformStamped4.transform.rotation.z = q.z();
  transformStamped4.transform.rotation.w = q.w();
tfb.sendTransform(transformStamped);
tfb.sendTransform(transformStamped2);
tfb.sendTransform(transformStamped3);
tfb.sendTransform(transformStamped4);

    rate.sleep();
    //printf("sending\n");
  }

};
