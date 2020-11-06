#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[20] = "hello,123";
    char  inp[12] ;
    printf("请输入姓名:");
    scanf("%s",&inp);while (getchar()!='\n');

    str[6] = 0;
    str[7] = 0;
    str[8] = 0;

    int j=0;
    while (inp[j] != '\0') 
    {
        str[j+6]=inp[j];
        j++;
    }
    
    printf("%s \n",str);
    
    return 0;
}
