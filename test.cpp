#include <iostream>
#include "my_tool.h"
using namespace std;
using namespace myTool;

int main()
{
    string s1 ="20";
    string s2 = "001010";
    
    cout <<"10--->16 "<<  m2n(s1, 10, 16) <<endl;
    cout <<"10--->8 " << m2n(s1, 10, 8) <<endl;
    cout <<"10--->2 " << m2n(s1, 10, 2) <<endl;
    cout <<"10--->10 " << m2n(s1, 10, 10) <<endl;
    cout <<s2<<" 2--->16 " << m2n(s2, 2, 16) <<endl;
    cout <<s1<< " 16--->10 " << m2n(s1, 16, 10) <<endl;
    cout <<s1<< " 8--->2 " << m2n(s1, 8, 2) <<endl;
    cout <<s1<< " 8--->10 " << m2n(s1, 8, 10) <<endl;

}
