#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    long msecstart = tv.tv_sec*1000000 + tv.tv_usec;
    printf("second:%ld\n",tv.tv_sec);  //秒
    printf("millisecond:%ld%ld\n",tv.tv_sec*1000 , tv.tv_usec/1000);  //毫秒
    printf("microsecond:%ld%ld\n",tv.tv_sec*1000000 , tv.tv_usec);  //微秒

    for ( int i = 0; i < 100000; i++ )
   {
       printf( "vals[%d," ,i );
       if(!(i%100)){
       printf( "\n");
       }
   }

    gettimeofday(&tv,NULL);
    long msecend = tv.tv_sec*1000000 + tv.tv_usec;
    printf("\naaa----%ld \n",msecend-msecstart) ;
    printf("second:%ld\n",tv.tv_sec);  //秒
    printf("millisecond:%ld\n",tv.tv_sec*1000 + tv.tv_usec/1000);  //毫秒
    printf("microsecond:%ld\n",tv.tv_sec*1000000 + tv.tv_usec);  //微秒
    return 0;

}
