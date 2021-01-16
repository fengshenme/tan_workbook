
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int init_socket(const char *ipaddr, const char *port);

int main(int argc, const char *argv[]) // client.out xxx.xxx.xxx.xxx 6868
{

    if (argc != 3)
    {
        fprintf(stderr, "%s <dotted-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    init_socket(argv[1], argv[2]);
}

//初始化udp套接字
int init_socket(const char *ipaddr, const char *port)
{
    // 创建未连接套接字
    int sofd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));

    // 将文本地址转化为二进制地址
    inet_pton(AF_INET, ipaddr, &addr.sin_addr);

    socklen_t len = sizeof(addr);
    // 从udp发送数据
    int buf_s = 1024;
    char *buf = malloc(buf_s);

    while (1)
    {
        memset(buf, 0, buf_s);
        fgets(buf, buf_s, stdin);
        if (strlen(buf) > 0)
        {
            int ret = sendto(sofd, buf, buf_s, 0, (struct sockaddr *)&addr, len);
            printf("%d line: sendto %s success  %d byte\n", __LINE__, ipaddr, ret);
        }

        if (strncmp(buf, "quit\n", 5) == 0)
        {
            break;
        }
        sleep(1);
    }
    close(sofd);
    free(buf);

    return sofd;
}
