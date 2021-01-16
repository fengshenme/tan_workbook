#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>



int init_sock(const char *ip, const char *port);


int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "%d line: Missing port or ip addr parameters such as: %s 127.0.0.1 6868\n", __LINE__, argv[0]);
        exit(EXIT_FAILURE);
    }
    init_sock(argv[1], argv[2]);
}

int init_sock(const char *ip, const char *port)
{
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

    int buf_s = 1024;
    char *buf = malloc(buf_s);
    while (1)
    {
        memset(buf, 0, buf_s);
        fgets(buf, buf_s, stdin);
        send(sofd, buf, buf_s, 0);
        if (strncmp(buf, "quit", 4) == 0)
        {
            break;
        }
    }

    // 释放内存,关闭文件
    free(buf);
    close(sofd);

    return 0;
}