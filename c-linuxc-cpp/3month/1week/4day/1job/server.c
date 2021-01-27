#include "../head.h"

//管理客户端结构体
typedef struct client
{

    int clifd; //存放那些连接到服务器上的客户端的已连接套接字
    int count; //计算当前连接上服务器的人数

    struct client *next;
    struct client *prev;

} cl_node, *cp_node;

struct client *init_cli()
{

    cl_node *cli = malloc(sizeof(cl_node));

    cli->count = 1;
    cli->next = cli;
    cli->prev = cli;

    return cli;
}

int add_cli(struct client *cli, int connfd)
{

    cl_node *pos;
    int i = 1;
    for (pos = cli->next; pos != cli; pos = pos->next)
    {
        i++;
    }
    if (i <= 3)
    {
        pos = init_cli();
        pos->clifd = connfd;
        pos->next = cli->next;
        pos->prev = cli;
        cli->next->prev = pos;
        cli->next = pos;

        //3. 当前连接的人数+1
        cli->count++;
    }
    else
    {
        fprintf(stderr, "[%d] : list full now %d \n", __LINE__, cli->count);
        return -1; //满人了，添加失败
    }

    return 0;
}

int init_sock(char *port)
{
    //1. 创建TCP套接字
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //2. 绑定地址
    struct sockaddr_in srvaddr;
    socklen_t len = sizeof(srvaddr);
    bzero(&srvaddr, len);

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(atoi(port));
    srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&srvaddr, len);

    //3. 设置监听套接字
    listen(sockfd, 6);

    return sockfd;
}

int main(int argc, char *argv[])
{
    //1. 初始化客户端结构体

    cp_node cli = init_cli();

    //2. 初始化套接字
    int sockfd;
    sockfd = init_sock(argv[1]);

    //sockfd -> 监听套接字
    //3. 设置监听套接字为非阻塞属性
    int state;
    state = fcntl(sockfd, F_GETFL);
    state |= O_NONBLOCK;
    fcntl(sockfd, F_SETFL, state);

    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    int connfd, ret;
    int i;
    char buf[100];

    while (1)
    {
        //4. 不断非阻塞地等待客户端的连接
        bzero(&cliaddr, len);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);

        //5. 如果真的有人连接，则将这个人的套接字塞到数组中
        if (connfd > 0)
        {
            //6. 先将这个套接字设置为非阻塞
            state = fcntl(connfd, F_GETFL);
            state |= O_NONBLOCK;
            fcntl(connfd, F_SETFL, state);

            //7. 将这个connfd存储到数组中
            ret = add_cli(cli, connfd);
            if (ret == -1)
            {
                printf("add usr error!\n");
                close(connfd);
                continue;
            }

            //8. 输出一下是谁连接进来
            printf("new connfd:%d\n", connfd);
            printf("new connection:%s\n", inet_ntoa(cliaddr.sin_addr));
        }

        //6. 如果没有人连接，则开始询问所有连接服务器上的客户端有没有话说。
        cl_node *pos, *tmp;
        for (pos = cli->next; pos != cli; pos = pos->next)
        {
            i++;
            bzero(buf, sizeof(buf));

            //如果不是空位，而且又说话了
            if (recv(pos->clifd, buf, sizeof(buf), 0) >= 0)
            {
                printf("from %d client : %s", pos->clifd, buf);

                if (strncmp(buf, "quit", 4) == 0) //这个客户端想埋单走人
                {
                    close(pos->clifd);
                    
                    tmp = pos;
                    pos = pos->next;

                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;
                    
                    free(tmp);
                    cli->count--;
                }
            }
            else
            {
                //不是空位，又不说话，继续询问下一个客户端。
                continue;
            }
        }

    }
}