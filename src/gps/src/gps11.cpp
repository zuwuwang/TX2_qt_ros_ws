#include <ros/ros.h>
#include <sstream>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>   /* 文件控制定义*/
#include <termios.h> /* PPSIX 终端控制定义*/
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include "std_msgs/String.h"
#define GPS_LEN 1024

using namespace std;
typedef unsigned int UINT;  
typedef int BYTE;  
ros::Publisher nav; 
typedef struct __gprmc__  
{  
   UINT time;/* gps定位时间 */  
   char pos_state;/*gps状态位*/  
   float latitude;/*纬度 */  
   float longitude;/* 经度 */  
   float speed; /* 速度 */  
   float direction;/*航向 */  
   UINT date;  /*日期  */  
   float declination; /* 磁偏角 */  
   char dd;  
   char mode;/* GPS模式位 */  
  
}GPRMC; 

typedef struct {
    double lon;
    double lat;
} LONLAT;

      /*              当前GPS转换            */
        const double pi = 3.14159265358979324;
        const double a = 6378245.0;
        const double ee = 0.00669342162296594323;

        static double transformLat(double x, double y)
        {
            double ret = -100.0 + 2.0 * x + 3.0 * y + 0.2 * y * y + 0.1 * x * y + 0.2 * sqrt(abs(x));
            ret += (20.0 *sin(6.0 * x * pi) + 20.0 * sin(2.0 * x * pi)) * 2.0 / 3.0;
            ret += (20.0 * sin(y * pi) + 40.0 * sin(y / 3.0 * pi)) * 2.0 / 3.0;
            ret += (160.0 * sin(y / 12.0 * pi) + 320 * sin(y * pi / 30.0)) * 2.0 / 3.0;
            return ret;
        }

        static double transformLon(double x, double y)
        {
            double ret = 300.0 + x + 2.0 * y + 0.1 * x * x + 0.1 * x * y + 0.1 * sqrt(abs(x));
            ret += (20.0 * sin(6.0 * x * pi) + 20.0 * sin(2.0 * x * pi)) * 2.0 / 3.0;
            ret += (20.0 * sin(x * pi) + 40.0 * sin(x / 3.0 * pi)) * 2.0 / 3.0;
            ret += (150.0 * sin(x / 12.0 * pi) + 300.0 * sin(x / 30.0 * pi)) * 2.0 / 3.0;
            return ret;
        }
        LONLAT lat_transform(LONLAT lonlat1)
        {
            double wgLon,wgLat,mglon,mglat;
            wgLon = lonlat1.lon;
            wgLat = lonlat1.lat;
            double dLat = transformLat(wgLon - 105.0, wgLat - 35.0);
            double dLon = transformLon(wgLon - 105.0, wgLat - 35.0);
            double radLat = wgLat / 180.0 * pi;
            double magic = sin(radLat);
            magic = 1 - ee * magic * magic;
            double sqrtMagic =sqrt(magic);
            dLat = (dLat * 180.0) / ((a * (1 - ee)) / (magic * sqrtMagic) * pi);
            dLon = (dLon * 180.0) / (a / sqrtMagic * cos(radLat) * pi);
            mglat = float(wgLat + dLat);
            mglon = float(wgLon + dLon);
            LONLAT lonlat;
            lonlat.lon = mglon;
            lonlat.lat = mglat;
            return lonlat;
        }

/*    当前位置GPS读取     */
int fd=0;
int set_serial(int fd,int nSpeed, int nBits, char nEvent, int nStop);
int gps_analyse(char *buff,GPRMC *gps_data);

LONLAT cur_gps_read()
{
     int n=0;
    // int i;
    // string data;
     GPRMC gprmc;
     LONLAT cur_gps;
     char buff[GPS_LEN];
     string s="/dev/ttyUSB0";
     char* dev_name = new char; 
     strcpy(dev_name,s.c_str());
     if((fd=open(dev_name,O_RDWR|O_NOCTTY|O_NDELAY))<0)
     //if((fd=open(dev_name,O_RDWR))<0)
     {
             perror("Can't Open the ttyUSB0 Serial Port");
             cur_gps.lon=0.0;
             cur_gps.lat=0.0;
             return cur_gps;
     }
        set_serial( fd,9600,8,'N',1);
        sleep(2);
        if((n=read(fd,buff,sizeof(buff)))<0)
         {
            perror("read error");
             cur_gps.lon=0.0;
             cur_gps.lat=0.0;
            return cur_gps;
         }
         gps_analyse(buff,&gprmc);
         char c=gprmc.pos_state;
         double lon,lat;
         if(c=='A')
        {
          lon = gprmc.longitude;
          lat = gprmc.latitude;
          int a,b;
          a= (int)(lon/100);
          b= (int)(lat/100);
          lon-=a*100;
          lat-=b*100;
          lon = a+lon/60;
          lat = b+lat/60; 
        }
        else {
           lon=0.0;
           lat=0.0;
         }

        cur_gps.lon = lon;
        cur_gps.lat = lat; 
        cout<<lon<<endl;
        cout<<lat<<endl;        
        memset(&gprmc, 0 , sizeof(gprmc));
        close(fd);  
        return cur_gps;
}


int set_serial(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
    struct termios newttys1,oldttys1;

     /*保存原有串口配置*/
     if(tcgetattr(fd,&oldttys1)!=0)
     {
          perror("Setupserial 1");
          return -1;
     }
     memset(&newttys1,0,sizeof(newttys1));/* 先将新串口配置清0 */
     newttys1.c_cflag|=(CLOCAL|CREAD ); /* CREAD 开启串行数据接收，CLOCAL并打开本地连接模式 */

     newttys1.c_cflag &=~CSIZE;/* 设置数据位 */
     /* 数据位选择 */
     switch(nBits)
     {
         case 7:
             newttys1.c_cflag |=CS7;
             break;
         case 8:
             newttys1.c_cflag |=CS8;
             break;
     }
     /* 设置奇偶校验位 */
     switch( nEvent )
     {
         case '0':  /* 奇校验 */
             newttys1.c_cflag |= PARENB;/* 开启奇偶校验 */
             newttys1.c_iflag |= (INPCK | ISTRIP);/*INPCK打开输入奇偶校验；ISTRIP去除字符的第八个比特  */
             newttys1.c_cflag |= PARODD;/*启用奇校验(默认为偶校验)*/
             break;
         case 'E':/*偶校验*/
             newttys1.c_cflag |= PARENB; /*开启奇偶校验  */
             newttys1.c_iflag |= ( INPCK | ISTRIP);/*打开输入奇偶校验并去除字符第八个比特*/
             newttys1.c_cflag &= ~PARODD;/*启用偶校验*/
             break;
         case 'N': /*无奇偶校验*/
             newttys1.c_cflag &= ~PARENB;
             break;
     }
     /* 设置波特率 */
    switch( nSpeed )
    {
        case 2400:
            cfsetispeed(&newttys1, B2400);
            cfsetospeed(&newttys1, B2400);
            break;
        case 4800:
            cfsetispeed(&newttys1, B4800);
            cfsetospeed(&newttys1, B4800);
            break;
        case 9600:
            cfsetispeed(&newttys1, B9600);
            cfsetospeed(&newttys1, B9600);
            break;
        case 115200:
            cfsetispeed(&newttys1, B115200);
            cfsetospeed(&newttys1, B115200);
            break;
        default:
            cfsetispeed(&newttys1, B9600);
            cfsetospeed(&newttys1, B9600);
            break;
    }
     /*设置停止位*/
    if( nStop == 1)/* 设置停止位；若停止位为1，则清除CSTOPB，若停止位为2，则激活CSTOPB */
    {
        newttys1.c_cflag &= ~CSTOPB;/*默认为一位停止位； */
    }
    else if( nStop == 2)
    {
        newttys1.c_cflag |= CSTOPB;/* CSTOPB表示送两位停止位 */
    }

    /* 设置最少字符和等待时间，对于接收字符和等待时间没有特别的要求时*/
    newttys1.c_cc[VTIME] = 0;/* 非规范模式读取时的超时时间；*/
    newttys1.c_cc[VMIN]  = 0; /* 非规范模式读取时的最小字符数*/
    tcflush(fd ,TCIFLUSH);/* tcflush清空终端未完成的输入/输出请求及数据；TCIFLUSH表示清空正收到的数据，且不读取出来 */

     /*激活配置使其生效*/
    if((tcsetattr( fd, TCSANOW,&newttys1))!=0)
    {
        perror("com set error");
        exit(1);
    }

    return 0;
}


int gps_analyse (char *buff,GPRMC *gps_data)
{
    char *ptr=NULL;
     if(gps_data==NULL)
      {
         return -1;
      }
      if(strlen(buff)<10)
      {
         return -1;
      }
/* 如果buff字符串中包含字符"$GPRMC"则将$GPRMC的地址赋值给ptr */
      if(NULL==(ptr=strstr(buff,"$GPRMC")))
      {
         return -1;
      }
/* sscanf函数为从字符串输入，意思是将ptr内存单元的值作为输入分别输入到后面的结构体成员 */
      sscanf(ptr,"$GPRMC,%d.000,%c,%f,N,%f,E,%f,%f,%d,,,%c*",&(gps_data->time),&(gps_data->pos_state),&(gps_data->latitude),&(gps_data->longitude),&(gps_data->speed),&(gps_data->direction),&(gps_data->date),&(gps_data->mode));
      return 0;
}


      /*         目标位置GPS读取        */
LONLAT goal_gps_read(string &kw)
{
    int i = 0;
    double lonlat1[16][2] ={
        {121.388988,31.316225},//益新食堂
        {121.388876,31.317691},//山明食堂
        {121.395699,31.316344},//水秀食堂
        {121.391317,31.319263},//尔美食堂
        {121.398618,31.314854},//东区食堂
        {121.399438,31.317045},//翔英大楼
        {121.399626,31.314204},//钱伟长图书馆
        {121.392239,31.316857},//图书馆
        {121.394203,31.318374},//音乐学院
        {121.395469,31.317916},//伟长楼
        {121.397427,31.318374},//东门
        {121.389053,31.320464},//北门
        {121.396005,31.311912},//南门
        {121.387679,31.31521},//西门
        {121.39884,31.312806},//经管楼
        {121.390579,31.320478}//乐乎新楼
};
   string kw_index[16]={"益新食堂","山明食堂","水秀食堂","尔美食堂","东区食堂","翔英大楼","钱伟长图书馆","图书馆","音乐学院","伟长楼","东门","北门","南门","西门","经管楼","乐乎新楼"};
   LONLAT lonlat;
   for(;i<16;i++)
{
      if(kw.find(kw_index[i],0)!=string::npos)
	{ kw = kw_index[i];
      	  break;
	}
 }
   if(i==16)
   {     
     lonlat.lon = 0;
     lonlat.lat = 0; 
     return lonlat;
   }
   else
   {
     lonlat.lon = lonlat1[i][0];
     lonlat.lat = lonlat1[i][1]; 
     cout<<"i="<<i<<",goal.lon="<<lonlat.lon<<",goal.lat="<<lonlat.lat<<endl;
     return lonlat;
   }
}

    /*   距离计算  */
int Distance(LONLAT gps0, LONLAT gps1)
{
   double lon0, lat0, lon1, lat1;
   lon0 = gps0.lon/ 180.0 * pi;
   lat0 = gps0.lat/ 180.0 * pi;
   lon1 = gps1.lon/ 180.0 * pi;
   lat1 = gps1.lat/ 180.0 * pi;
   double dlon = lon1 - lon0; 
   double dlat = lat1 - lat0; 
   double a=(dlat/2)*(dlat/2);
   double b=(dlon/2)*(dlon/2);
   double c = sin(a) + cos(lat0) * cos(lat1) * sin(b);
   double d = 2 * asin(sqrt(c)); 
   double r = 6378245;  
   return int(round(d * r)); 
}

/*      话题订阅的回调函数     */

void cal_dis(const std_msgs::String::ConstPtr& msg)
{
 ROS_INFO("I heard!");
 string ew,sn,kw;
 kw = msg->data;
 cout<<kw;
 LONLAT cur_gps,goal_gps;
 goal_gps = goal_gps_read(kw);
 cur_gps = cur_gps_read();
 if (int(cur_gps.lon)==0)
 {
   ROS_INFO("GPS unavailable");
   return;
 }
 if (int(goal_gps.lon)==0)
 {
   ROS_INFO("NOT FOUND");
   return;
 }
 else {
 cur_gps = cur_gps_read();
 cur_gps = lat_transform(cur_gps);
 int dis;
 dis = Distance(cur_gps,goal_gps);
 if(goal_gps.lon>cur_gps.lon)
  ew="东";
 else ew = "西";
 if(goal_gps.lat>cur_gps.lat)
 sn="北";
 else sn = "南";
cout<<ew<<sn<<endl;
cout<<dis<<endl;
 //ros::NodeHandle n;
// ros::Publisher nav = n.advertise<std_msgs::String>("speechnav", 1000);
 ros::Rate loop_rate(10);
 std_msgs::String msg;
 std::stringstream ss;
 ss << kw << "在当前位置的"<<ew<<sn<<",距离当前位置"<<dis<<"米";
 msg.data = ss.str();
 cout<<msg.data<<endl;
 nav.publish(msg);
 ROS_INFO("I texted my messge.");  
    }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gps");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, cal_dis);
  nav = n.advertise<std_msgs::String>("speechnav", 1000);
  ros::spin();
  return 0;
}
    
