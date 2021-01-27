#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

int init_socket(const char *port);
void sigfun(int sig);

static int sofd;

int main(int argc, const char *argv[]) // server.out 6868
{

    if (argc != 2)
    {
        fprintf(stderr, "%s <dotted-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    init_socket(argv[1]);
}

//信号处理函数
void sigfun(int sig)
{
    printf("%d-%d\n", __LINE__, sig);
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    // 从udp读取数据
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    memset(buf, 0, buf_s);
    if (recvfrom(sofd, buf, buf_s, 0, (struct sockaddr *)&cliaddr, &len) > 0)
    {
        // inet_ntoa 将二进制地址转化为文本地址
        printf("%d line\nfrom ip:%s msg %s\n", __LINE__, inet_ntoa(cliaddr.sin_addr), buf);
    }

    if (strncmp(buf, "quit\n", 5) == 0)
    {
        free(buf);
        close(sofd);
        exit(EXIT_FAILURE);
    }
    
    free(buf);
}

//初始化udp套接字
int init_socket(const char *port)
{
    // 创建未连接套接字
    sofd = socket(AF_INET, SOCK_DGRAM, 0);

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

    signal(SIGIO, sigfun);

    //4. 设置套接字的属主
    fcntl(sofd, F_SETOWN, getpid());

    //5. 激活信号驱动IO
    int state;
    state = fcntl(sofd, F_GETFL);
    state |= O_ASYNC;
    fcntl(sofd, F_SETFL, state);

    while (1)
    pause();

    

    return 0;
}