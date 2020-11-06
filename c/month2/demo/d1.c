#include <stdio.h>

int 
main(int argc, char const *argv[])
{
    unsigned char uc_Temp[4]={0x12,0x34,0x56};

    unsigned long ul_temp;

    // ul_temp = uc_Temp[0]<<24 |uc_Temp[1]<<16 |uc_Temp[2]<<8 | uc_Temp[3]<<0;
    ul_temp = uc_Temp[0]<<16 |uc_Temp[1]<<8 |uc_Temp[2]<<0 ;

    printf("0x%lx \n", ul_temp);
    
    return 0;
}
