#include "ros/ros.h"
#include <signal.h>
#include <ros/time.h>
#include <fstream>
#include <string>
#include <vector>
#include "geometry_msgs/Twist.h"
#include "move_base_msgs/MoveBaseActionGoal.h"

using namespace std;
FILE *stream;
int num_geometry_msgs=0;
int num_move_base_msgs=0;
char mark[4]={'x','y','z','w'};
char c='\n';
void cmd_velCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
   vector<float> linear,angular; 
   linear.push_back(msg->linear.x);
   linear.push_back(msg->linear.y);
   linear.push_back(msg->linear.z); 
   angular.push_back(msg->angular.x);
   angular.push_back(msg->angular.y);
   angular.push_back(msg->angular.z);
   fprintf(stream,"%s\n","linear:");
    for(int i=0;i<3;i++)
   { 
    fprintf(stream,"%s%c%s%f%s","linear.",mark[i],"=",linear[i]," , ");
   }
   fprintf(stream,"%c%s\n",c,"angular:");
    for(int i=0;i<3;i++)
   { 
    fprintf(stream,"%s%c%s%f%s","angular.",mark[i],"=",angular[i]," , ");
   }
   fprintf(stream,"%c",c);
    num_geometry_msgs++;
}

void goalCallback(const move_base_msgs::MoveBaseActionGoal::ConstPtr& msg)
{
     //time stamp;
     //stamp=msg->header.stamp;
     vector<float> position,orientation;
     position.push_back(msg->goal.target_pose.pose.position.x);
     position.push_back(msg->goal.target_pose.pose.position.y);
     position.push_back(msg->goal.target_pose.pose.position.z);
     orientation.push_back(msg->goal.target_pose.pose.orientation.x);
     orientation.push_back(msg->goal.target_pose.pose.orientation.y);
     orientation.push_back(msg->goal.target_pose.pose.orientation.z);
     orientation.push_back(msg->goal.target_pose.pose.orientation.w);
   //cout<<stamp<<"\n";
   fprintf(stream,"%s\n","position:");
    for(int i=0;i<3;i++)
   { 
    fprintf(stream,"%s%c%s%f%s","position.",mark[i],"=",position[i]," , ");
   }
   fprintf(stream,"%c%s\n",c,"orientation:");
   for(int i=0;i<4;i++)
   { 
    fprintf(stream,"%s%c%s%f%s","orientation.",mark[i],"=",orientation[i]," , ");
   }
   fprintf(stream,"%c",c);
   num_move_base_msgs++;
}

 void mySigintHandler(int sig)
{
  ROS_INFO("stop recording");
  fprintf(stream,"%s%d\n","The number of num_move_base_msgs:",num_move_base_msgs);
  fprintf(stream,"%s%d","The number of num_geometry_msgs:",num_geometry_msgs);
  fclose(stream);                   
  ros::shutdown();
}

template<typename T> string toString(const T& t)
{
    ostringstream oss;  //创建一个格式化输出流
    oss<<t;             //把值传递如流中
    return oss.str();  
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "record_data", ros::init_options::NoSigintHandler);
    ros::NodeHandle n;
/*
    cout<<"Enter your filename:(e.g helloworld)";
    char filename[50];
    scanf("%s",filename);
    strcat(filename,".txt");*/
    char* filename = new char;
    string s = toString(ros::Time::now());
    strcpy(filename,s.c_str());
    strcat(filename,".txt");
    ROS_INFO("start recording");
    stream = fopen(filename, "w" );
    signal(SIGINT, mySigintHandler);
   
     ros::Subscriber sub1=n.subscribe("/move_base/goal",1000,goalCallback);
     ros::Subscriber sub2=n.subscribe("/cmd_vel",1000,cmd_velCallback);
     ros::spin();
    
    return 0;
}

