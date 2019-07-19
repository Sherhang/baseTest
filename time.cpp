/*测试一段程序的运行时间，精确到微秒us*/

#include <iostream>
#include <sys/time.h>  //use  struct timeval , gettimeofday()

using namespace std;
void func();
int main()
{
    struct timeval t1, t2;
    gettimeofday(&t1, NULL);
    func();
    gettimeofday(&t2, NULL);
    long long time=(t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec-t1.tv_usec);
    cout<<"func()执行时间："<<time<<"us"<<endl;
}

void func()
{
    for (int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            int s=i*j;
}
