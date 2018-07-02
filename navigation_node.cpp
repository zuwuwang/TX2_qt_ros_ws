#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <map>

using namespace std;

//typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
bool onSpeaking_flag = false; // get from speech,ros sub
void speechStateTrue()
{
  onSpeaking_flag = true;
  ROS_INFO("change state to true");
}

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle n;

  ROS_INFO("start...");
  //tell the action client that we want to spin a thread by default
//  MoveBaseClient ac("move_base", true);

//  //wait for the action server to come up
//  while(!ac.waitForServer(ros::Duration(5.0))){
//    ROS_INFO("Waiting for the move_base action server to come up");
//  }

//  move_base_msgs::MoveBaseGoal goal;

//  //we'll send a goal to the robot to move 1 meter forward
//  goal.target_pose.header.frame_id = "base_link";
//  //goal.target_pose.header.frame_id = "map";
//  goal.target_pose.header.stamp = ros::Time::now();

//  //goal.target_pose.pose.position.x = 7.55;
//  //goal.target_pose.pose.position.y = 1.45;
//  goal.target_pose.pose.position.x = 1;
//  goal.target_pose.pose.orientation.w = 1.0;

  map<string,geometry_msgs::Pose> myMap;
  geometry_msgs::Pose pose1;
  geometry_msgs::Pose pose2;
  geometry_msgs::Pose pose3;
  geometry_msgs::Pose pose4;
  pose1.position.x = 2.04;
  pose1.position.y = 0.445;
  pose1.orientation.w = 1;

  pose2.position.x = 4.23;
  pose2.position.y = 0.847;
  pose2.orientation.w = 1;

  pose3.position.x = 6.85;
  pose3.position.y = 1.32;
  pose3.orientation.w = 1;

  pose4.position.x = 10.02;
  pose4.position.y = 2.03;
  pose4.orientation.w =1;

  myMap.insert(make_pair("p1",pose1));
  myMap.insert(make_pair("p2",pose2));
  myMap.insert(make_pair("p3",pose3));
  myMap.insert(make_pair("p4",pose4));

  map<string,geometry_msgs::Pose>::iterator it  = myMap.begin();
    while(it != myMap.end())
      {
        if(!onSpeaking_flag)
        {
          speechStateTrue();
          //  ros::spinOnce();  // triger callback
//          goal.target_pose.pose = it->second;
            ROS_INFO("Sending goal");
            ROS_INFO("robot will go to %s",(it->first).c_str());
//            ac.sendGoal(goal);

//            ac.waitForResult();

//           if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
//               ROS_INFO("Hooray, the base moved 1 meter forward");
//           else
//              ROS_INFO("The base failed to move forward 1 meter for some reason");
           ROS_INFO("get to %s successfully",(it->first).c_str());
           it++;
           if( it == myMap.end())
           {
             it = myMap.begin();
           }
        }
       else
        {
        // ac.cancelGoal();
         ROS_INFO(" cancel send goal %s ",(it->first).c_str());
         onSpeaking_flag = false;
         ROS_INFO("set flag to false");
        }
      }
    ROS_INFO("end...");
  return 0;
}


