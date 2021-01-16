#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int init_socket(const char *port);

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Missing port parameters such as: %s 6868  \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    init_socket(argv[1]);

    return 0;
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
    // 阻塞等待客户端连接,
    int cofd = accept(sofd, (struct sockaddr *)&cliaddr, &len);
    if (cofd > 0) //没有连接直接跳出本次循环
    {
        printf("new acceptid : %d \n", cofd);
        printf("new connection ip : %s \n", inet_ntoa(cliaddr.sin_addr));
    }

    // 4）等待服务器连接
    fd_set set;
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(cofd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    
    while (1)
    {
        FD_ZERO(&set);
        FD_SET(cofd, &set);

        memset(buf, 0, buf_s);
        int ret = recv(cofd, buf, buf_s, 0);
        if (ret <= 0)
        {
            fprintf(stderr, "%d-line: recv failed or time out. \n", __LINE__);
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
