/*@2940563940@qq.com
 **/
//commonTool.h
#pragma once
#include <iostream>
#include <sstream>
#include <bitset>
#include <sys/time.h>    //struct itimerval, setitimer()

//宏定义
#define DEBUG  cout<<"[DEBUG]"<<__DATE__<<"|"<<__TIME__<<"|"<<__FILE__<<"|"<<__func__<<"|"<<__LINE__<<": "
#define ERROR  cout<<"[ERROR]"<<__DATE__<<"|"<<__TIME__<<"|"<<__FILE__<<"|"<<__func__<<"|"<<__LINE__<<": "

#define Connect(x,y) x##y //连接xy,demo:int n = Connect(123,456);//n=123456;string str= Connect(123.abc);
#define ToString(x) #x  //给x加上双引号,没什么用
#define MEM_B( x ) ( *( (char *) (x) ) )   //得到指定地址上的一个字节长度的元素 
#define UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )//小写字母转大写
#define LOWCASE( c ) ( ((c) >= 'A' && (c) <= 'Z') ? ((c) + 0x20) : (c) )//大写字母转小写
#define INC_SAT( val ) (val = ((val)+1 > (val)) ? (val)+1 : (val))  //防止溢出
#define OFFSETOF(type, field) ((size_t)&(((type *)0)->field)) //得到一个field在结构体中的偏移量，demo:int l=OFFSET(A,a);
#define FSIZ( type, field ) sizeof( ((type *) 0)->field ) //得到一个结构体中field的字节数
//#define ARR_SIZE(a) (sizeof((a)) / sizeof((a[0]))) //返回数组长度, 有问题TODO

using namespace std;

namespace commonTool
{
    //数字转字符串
    //demo: int a = str2num<int>(string("-01.23"));
    template<class T>
    T str2num(const string& str)
    {
        stringstream ss;
        T num;
        ss << str;
        ss >> num;
        return num;
    }
    
    //demo: double num=-23.1; string str = num2str(num);
    //也可以指定T的类型，str = num2str<int>(num);
    template<class T>
    string num2str(const T& num)
    {
        stringstream ss;
        ss << num;
        string str;
        ss >> str;
        return str;
    }

    //进制转换，输入输出都是string,默认10-->2,支持2,8,10,16进制。
    //demo: string str = "01010101"; cout<< m2n(str,2,16) <<endl;
    string m2n(string& str_in, int format_in = 10, int format_out = 2)
    {
        if(str_in.size()==0) return "";
        if(format_in == format_out) return str_in;
        stringstream ss;
        switch (format_in)
        {
            case 16:
                ss << hex << str_in;
                break;
            case 8:
                ss << oct << str_in;
                break;
            case 2:
                {
                    unsigned int d=0;
                    for(int i=0; i<str_in.size(); ++i)
                    {
                        d = d*2+(str_in[i]-'0');
                    }
                    ss << d;
                }
                break;
            default:
                ss << str_in;
        }
        long long a;
        ss >> a;
        cout << "debug " <<a<<endl;
        stringstream ss1;
        switch (format_out)
        {
            case 16:
                ss1 << hex << a;
                break;
            case 8:
                ss1 << oct << a;
                break;
            case 2:
                {
                    ss1 << bitset<64>(a) ;
                    string ret = ss1.str();
                    for(int i=0; i<ret.size(); ++i)
                    {
                        if(ret[i] != '0')
                            return ret.substr(i);
                    }
                }
                break;
            default:
                ss1 << a;
        }
        return ss1.str();
    }
}
