#include "ros/ros.h"
#include <record/lonlat.h>
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
#include "string.h"
#include <sys/types.h>
#include <unistd.h>
#define GPS_LEN 1024
using namespace std;
typedef unsigned int UINT;
typedef int BYTE;
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

typedef struct __lonlat__{
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
       GPRMC gprmc;
       LONLAT cur_gps;
       char buff[GPS_LEN];
       string s="/dev/ttyUSB0";
       char* dev_name = new char;
       strcpy(dev_name,s.c_str());
       if((fd=open(dev_name,O_RDWR|O_NOCTTY|O_NDELAY))<0)
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



int main(int argc, char **argv)
{
  ros::init(argc, argv, "gpspub");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<record::lonlat>("sendgps", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    record::lonlat msg;
    LONLAT cur_gps;
    cur_gps = cur_gps_read();
     if (int(cur_gps.lon)==0)
    {
    msg.lon = 121.399626;
    msg.lat = 31.314204;
    pub.publish(msg);
    }
  else
  {
  cur_gps = lat_transform(cur_gps);
  msg.lon = cur_gps.lon;
  msg.lat = cur_gps.lat;
  pub.publish(msg);
  }  
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
