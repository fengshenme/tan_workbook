#include "head.h"

void *read_net(void *arg)
{
    int concetfd = *((int *)arg);
    char buf2[200];
    while (1)
    {
        bzero(buf2, sizeof(buf2));
        recv(concetfd, buf2, sizeof(buf2), 0);
        if (strlen(buf2) > 0)
        {
            printf("[%d] from server:%s ", __LINE__, buf2);
        }
        if (strncmp(buf2, "quit\n", 5) == 0)
        {
            exit(0);
        }
    }

    return  NULL;
}

int main(int argc, char const *argv[]) // ./client.out xxx.xxx.xxx.xxx 端口号
{

    // /     1）创建未连接套接字
    int so_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (so_fd == -1)
    {
        fprintf(stderr, "[%d] Failed to create unconnected socket \n", __LINE__);
    }
    
    // 2）服务器设置IP地址时，可以使用一个宏：

    struct sockaddr_in addr;

    socklen_t len = sizeof(addr);
    bzero(&addr, len);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &addr.sin_addr); //IP地址

    if (connect(so_fd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stderr, "[%d] concet failed \n", __LINE__);
    }

    pthread_t s_pid;

    if ((pthread_create(&s_pid, NULL, read_net, (void *)&so_fd)) != 0)
    {
        printf("get pthread create failed!\n");
    }

    char buf[200];
    while (1)
    {
        bzero(buf, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);

        send(so_fd, buf, sizeof(buf), 0);

        if (strncmp(buf, "quit\n", 5) == 0)
        {
            pthread_cancel(s_pid);
            break;
        }
    }

    close(so_fd);

    void *rev = NULL;
    if ((pthread_join(s_pid, rev)) != 0)
    {
        printf("pthread_join failed!\n");
    }

    return 0;
}
