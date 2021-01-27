#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#include <sys/time.h>
#include <sys/types.h>

int va();
int index_t();
int login(int sofd);

int init_sock();

int main(int argc, char const *argv[])
{
    index_t();
    return 0;
}

int index_t()
{
    va();
    printf("\t\t火星机场购票系统\n");
    printf(" 1) 登录\t 2) 注册\t 3) 忘记密码\t \n");
    va();
    printf("请选择对应服务 ,输入对应数字序号进入:");
    int sofd = init_sock();
    short num;
    scanf("%hd", &num);
    while (getchar() != '\n')
        ;
    switch (num)
    {
    case 1:
        printf("您选择了登录\n");

        login(sofd);
        break;
    case 2:
        printf("您选择了注册\n");
        break;
    case 3:
        printf("您选择了忘记密码\n");
        break;

    default:
        break;
    }

    return 0;
}

int va()
{
    int i;
    for (i = 0; i < 60; i++)
    {
        printf("=");
    }
    printf("\n");
    return 0;
}

int init_sock()
{
    const char *ip = "192.168.24.82";
    const char *port = "6868";
    //ipv4 tcp连接
    int sofd = socket(AF_INET, SOCK_STREAM, 0);

    // 将文本ip转换为二进制网络字节数
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr_in);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));
    // AF_INET 使用ipv4
    inet_pton(AF_INET, ip, &addr.sin_addr);

    if (connect(sofd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stdin, "[%d] line : connect failed \n", __LINE__);
    }
    return sofd;
}

int login(int sofd)
{

    int buf_s = 1024;
    char *buf = malloc(buf_s);
    struct timeval timeout;

    bzero(buf, buf_s);
    char name[20];
    char password[20];
    bzero(name, 20);
    bzero(password, 20);

    printf("用户名:");
    scanf("%s", name);
    while (getchar() != '\n')
        ;

    printf("密码:");
    fgets(password, 20, stdin);

    sprintf(buf, "login:%s,%s", name, password);

    if (send(sofd, buf, strlen(buf), 0) > 0)
    {
        printf("send success\n");
    }

    if (strncmp(buf, "quit", 4) == 0)
    {
        return 1;
    }

    bzero(buf, buf_s);
    recv(sofd, buf, buf_s, 0);
    printf("from client:%s", buf);
    if (strncmp(buf, "succ", 4) == 0)
    {
        printf("登录成功\n");
    }

    if (strncmp(buf, "fail", 4) == 0)
    {
        printf("登录失败是否退出[y/n]");
        char y;
        scanf("%c", &y);
        if (y == 'y')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    // 释放内存,关闭文件
    free(buf);
    close(sofd);

    return 0;
}