#include <stdio.h>
#include <sys/ioctl.h>

int main(int argc, char const *argv[])
{
    //定义一个数组
    char str[10];
    char *outstr;
    //从键盘获取输入
    gets(str);
    //3.在打印出来
    printf("%d\n", str);
    return 0;

}
