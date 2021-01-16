#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int init_socket(const char *port);


int main(int argc, const char *argv[]) // server.out 6868
{

    if (argc != 2)
    {
        fprintf(stderr, "%s <dotted-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    init_socket(argv[1]);
}

//初始化udp套接字
int init_socket(const char *port)
{
    // 创建未连接套接字
    int sofd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    socklen_t len = sizeof(addr);
    // 绑定套接字与网络地址
    if (bind(sofd, (struct sockaddr *)&addr, len) == -1)
    {
        /* code */
        fprintf(stderr, "error line:[%d] bind faild \n ", __LINE__);
    }

    struct sockaddr_in cliaddr;
    // 从udp读取数据
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    while (1)
    {
        memset(buf, 0, buf_s);
        if (recvfrom(sofd, buf, buf_s, 0, (struct sockaddr *)&cliaddr, &len) > 0)
        {
            // inet_ntoa 将二进制地址转化为文本地址
            printf("%d line\n from ip:%s msg%s\n", __LINE__, inet_ntoa(cliaddr.sin_addr), buf);
        }

        if (strncmp(buf, "quit\n", 5) == 0)
        {
            break;
        }
    }

    close(sofd);
    free(buf);
    return 0;
}