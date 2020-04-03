#include <windows.h>
#include <iostream>
 
using namespace std;
 
int main()
{
 
	DWORD time_start, time_end;
	
	/* 获取开始时间 */
	time_start = GetTickCount(); //从操作系统启动经过的毫秒数
 
	for ( int i = 0; i < 100; i++ )
   {
       printf( "vals%d," ,i );
       if(!(i%100)){
       printf( "\n");
       }
   }
 
	time_end = GetTickCount();
 
	cout << "Time = " << (time_end - time_start) << "ms\n ";
 
	return 0;

}