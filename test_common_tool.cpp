#include <iostream>
#include "common_tool.h"
using namespace std;
using namespace commonTool;

int main()
{
    {
        struct A{
            int a;
            char b;
            long c;
        };
        cout<<"define测试："<<endl;
        DEBUG<<endl;
        int num= 0x123456;
        char a = MEM_B((&num));
        cout<<hex<<"a="<<int(a)<<endl;
        a ='a';
        char b=UPCASE(a);
        char c=LOWCASE(b);
        cout <<a<<" "<<b<<" "<<c<<endl;
        cout << "OFFSETOF "<<OFFSETOF(A,c)<<endl;//8，按照4字节对齐
        
    }
    {
        cout<<"m2n测试："<<endl;
        string s1 ="2147483647";
        string s2 = "001010";    
        cout <<"10--->16 "<<  m2n(s1, 10, 16) <<endl;
        cout <<"10--->8 " << m2n(s1, 10, 8) <<endl;
        cout <<"10--->2 " << m2n(s1, 10, 2) <<endl;
        cout <<"10--->10 " << m2n(s1, 10, 10) <<endl;
        cout <<s2<<" 2--->16 " << m2n(s2, 2, 16) <<endl;
        cout <<s1<< " 16--->10 " << m2n(s1, 16, 10) <<endl;
        cout <<s1<< " 8--->2 " << m2n(s1, 8, 2) <<endl;
        cout <<s1<< " 8--->10 " << m2n(s1, 8, 10) <<endl;
        cout <<s1<< " 10--->16 " << m2n(s1, 10, 16) <<endl;
        cout<<hex<<str2num<int32_t>(s1)<<endl;

    }
}
