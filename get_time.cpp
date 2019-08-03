#include<sys/time.h>//struct timeval
#include<time.h>//struct tm

#include<iostream>
#include"common_tool.h"
//#define DEBUG cout<<__func__<<"|"<<__LINE__<<"|"
using namespace std;
using namespace commonTool;
string get_curr_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);//step1
    uint64_t sys_sec = tv.tv_sec;
    //DEBUG<<"sys_sec="<<sys_sec<<endl;
    struct tm curr_time;
    localtime_r((time_t*)&sys_sec, &curr_time);//setp2
    string ret;
    string year,mon,mday,hour,min,sec;
    year = num2str<uint64_t>(curr_time.tm_year+1900);
    mon = num2str<uint64_t>(curr_time.tm_mon+1);
    mday = num2str<uint64_t>(curr_time.tm_mday);
    hour = num2str<uint64_t>(curr_time.tm_hour);
    min = num2str<uint64_t>(curr_time.tm_min);
    sec = num2str<uint64_t>(curr_time.tm_sec);
    if (mon.size()<2)
        mon = "0"+mon;
    if(mday.size()<2)
        mday = "0"+mday;
    if(hour.size()<2)
        hour = "0"+hour;
    if(min.size()<2)
        min = "0"+min;
    if(sec.size()<2)
        sec = "0"+sec;
    ret = year+"/"+mon+"/"+mday+"|"+hour+":"+min+":"+sec;
    return ret;

}

int main()
{
    string st;
    int i =0;
    do
    {
        string t = get_curr_time();
        if(t!=st)
        {
            cout<<t<<endl;
            ++i;
            st = t;
        }

    }while(1);
}
