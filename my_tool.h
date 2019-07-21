#pragma once
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

namespace myTool
{
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
