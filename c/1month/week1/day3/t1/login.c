#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    char name[20] ;
    char password[20];
    printf("用户名:");
    scanf("%s",&name);
    printf("密码:");
    scanf("%s",&password);
    char ca[9] = "zhangsan";
    char pa[7] = "123456";

    int check_name = strcmp(name,ca);
    int check_password =  strcmp(password,pa);
    
    printf("%d %d \n",check_name,check_password);

    if ( check_name == 0 && check_password == 0)
    {
        printf("welcome, %s \n",name);
    }

    if (check_name != 0)
    {
        printf("无此用户 \n");

    }

    if (check_password != 0)
    {
        printf("密码错误 \n");
    }
    
    

    return 0;
}
