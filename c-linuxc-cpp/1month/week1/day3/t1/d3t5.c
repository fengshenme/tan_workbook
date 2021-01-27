#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[20] = "hello,123";

    char str2[20] = {0} ;
    char str3[20] = {0} ; 
    strcpy(str2,str1);
    strncpy(str3,str1,20);
    printf("1:%s\n",str2); 
    printf("2:%s\n",str3); 

    if (strcmp(str2,str1)==0)
    {
        /* code */
        printf("same\n");
    }
    else
    {
        printf("Diffrent\n");
        /* code */
    }
    
    
    strcat(str2,str1);
    strncat(str3,str1,sizeof(str3)-strlen(str3)-1);
    printf("3:%s\n",str2); 
    printf("4:%s\n",str3);

    return 0;
}
