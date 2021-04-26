#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <pthread.h>
#include <fcntl.h>

int init_socket(const char *port);
void *func(void *arg);

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Missing port parameters such as: %s 6868  \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);                                    // 设置属性
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置分离属性 不需要接合
    pthread_attr_setschedpolicy(&attr, SCHED_RR);                // 调度属性设为轮播

    pthread_t tid;
    int arg = 100;
    if (pthread_create(&tid, &attr, func, (void *)&arg) != 0)
    {
        fprintf(stderr, "%d-line: pthread create failed\n", __LINE__);
    }

    init_socket(argv[1]);

    return 0;
}

void *func(void *arg)
{
    int i = 0;
    while (1)
    {
        sleep(1);
        printf("%d sec\n", i++);
    }
    pthread_exit(NULL);
}

int init_socket(const char *port)
{
    // 1）创建待连接套接字
    // 使用网际协议，我这里用的是ipv4， tcp连接使用流式套接字SOCK_STREAM
    int sofd = socket(AF_INET, SOCK_STREAM, 0);

    // 2）服务器设置IP地址时,
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    addr.sin_family = AF_INET;                // 协议
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // 填入任何ip都可以访问
    addr.sin_port = htons(atoi(port));        // 端口

    // 3）设置监听套接字
    if (bind(sofd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stderr, "%d line: bind failed\n", __LINE__);
    }
    // 将待连接套接字设置为监听套接字，并设置最大同时接收连接请求个数为5
    listen(sofd, 5);

    //客户端的地址信息
    struct sockaddr_in cliaddr;
    int cofd;
    // 阻塞等待客户端连接,
    cofd = accept(sofd, (struct sockaddr *)&cliaddr, &len);
    if (cofd == -1)
    {
        fprintf(stderr, "%d-line: accept failed \n", __LINE__);
    }

    if (cofd >= 0) //没有连接直接跳出本次循环
    {
        printf("new acceptid : %d \n", cofd);
        printf("new connection ip : %s \n", inet_ntoa(cliaddr.sin_addr));
    }

    // 4）等待服务器连接
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    struct timeval timeout;

    while (1)
    {

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        setsockopt(cofd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        memset(buf, 0, buf_s);

        if (recv(cofd, buf, buf_s, 0) == -1)
        {
            fprintf(stderr, "%d-line: time out or recv failed \n", __LINE__);
            continue;
        }

        printf("%d-line: ip-%s msg: %s \n", __LINE__, inet_ntoa(cliaddr.sin_addr), buf);

        if (strncmp(buf, "quit", 4) == 0)
            break;
    }

    //释放内存,关闭文件符
    free(buf);
    close(cofd);
    close(sofd);
    return 0;
}