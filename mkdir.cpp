#include<sys/stat.h>
#include<unistd.h>
#include<iostream>
#include<sstream>
#include<vector>
#include"my_tool.h"
using namespace std;

bool makedir(const std::string& dir)
{
    stringstream ss;
    ss<<dir;
    string dir_c;
    string tmp;
    while(getline(ss,tmp ,'/') )//getline第一个参数是流。
    {
        dir_c = dir_c +tmp +"/"; 
        if(access(dir_c.c_str(), F_OK | W_OK) == 0) //如果目录已经存在，可读可写，则跳过
        {
            DEBUG<<"dir "<<dir_c<<" exists!"<<endl;
            continue;
        }
        if(mkdir(dir_c.c_str(),0777) != 0 )//返回0表示成功,失败则退出程序
        {
            DEBUG<<"mkdir fail "<<dir_c<<endl;
            return false;
        }
    }
    return true;
}

int main()
{
    string dir="log/app_log/mylog";
    makedir(dir);
}
