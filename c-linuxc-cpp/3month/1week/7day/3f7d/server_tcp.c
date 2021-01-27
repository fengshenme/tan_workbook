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
#include <time.h>

int init_socket(const char *port);
void *func(void *arg);
int bubble_descending_sort(int len, int *arr);

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

    // 给套接字添加非阻塞属性
    int state;
    state = fcntl(sofd, F_GETFL); // state就是文件描述符原有的属性
    state |= O_NONBLOCK;          // 通过位运算给state添加非阻塞属性
    fcntl(sofd, F_SETFL, state);  // 将新属性添加到文件描述符中
    // 4）等待服务器连接
    fd_set set;
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    struct timeval timeout;

    int cofd[20] = {-1};
    int i = 1;
    while (1)
    {

        // 非阻塞等待客户端连接,
        cofd[i] = accept(sofd, (struct sockaddr *)&cliaddr, &len);

        if (cofd[i] > 0)
        {
            printf("new acceptid : %d \n", cofd[i]);
            printf("new connection ip : %s \n", inet_ntoa(cliaddr.sin_addr));
            i++;
            bubble_descending_sort(i, cofd);
        }

        FD_ZERO(&set);

        int k;
        for (k = 0; k < i; k++)
        {
            FD_SET(cofd[k], &set);
        }

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        // cofd 数组是降序排列,首元素是最大的
        int ret = select(cofd[0] + 1, &set, NULL, NULL, &timeout);

        if (ret < 0)
        {
            fprintf(stderr, "%d-line: select failed \n", __LINE__);
            continue;
        }

        if (ret == 0)
        {
            printf("time out. \n");
            continue;
        }

        for (k = 0; k < i; k++)
        {
            int tmp = cofd[k];

            if (tmp == -1)
            {
                continue;
            }

            if (FD_ISSET(tmp, &set) == 0)
            {
                continue;
            }

            memset(buf, 0, buf_s);

            if (recv(tmp, buf, buf_s, 0) <= 0)
            {
                // fprintf(stderr, "%d-line: recv failed \n", __LINE__);
                continue;
            }

            printf("%d-line: ip-%s msg: %s \n", __LINE__, inet_ntoa(cliaddr.sin_addr), buf);

            if (strncmp(buf, "quit", 4) == 0)
            {
                tmp = -1;
                bubble_descending_sort(i, cofd);
                i--;
                close(tmp);
                continue;
            }
        }
    }

    //释放内存,关闭文件符
    free(buf);

    close(sofd);
    return 0;
}

//  降序排列
int bubble_descending_sort(int len, int *arr)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        int flag = 0;
        for (j = 0; j < len - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    return 0;
}