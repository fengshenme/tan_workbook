#include "head.h"

typedef struct cl_node
{
    int so_fd;     // 未连接的套接字文件描述符
    int confd;     // 连接的套接字文件描述符
    char msg[256]; // 要发送的消息
    char ip[20];
    struct list_head head; // 内核链表

} c_node, *cp_list;


void *read_msg(void *arg);

int main(int argc, char const *argv[]) // /.server.out 端口号
{

    //     1）创建未连接套接字
    int so_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (so_fd == -1)
    {
        fprintf(stderr, "[%d] Failed to create unconnected socket \n", __LINE__);
    }

    // 2）服务器设置IP地址时，可以使用一个宏：
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    bzero(&addr, len);

    addr.sin_family = AF_INET;                //协议
    addr.sin_port = htons(atoi(argv[1]));     //端口号
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip地址

    // 绑定
    if (bind(so_fd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stderr, "[%d]: Failed to bind socket to network address \n", __LINE__);
    }

    // 3）设置监听套接字 设置可以同时访问的人为5个
    if (listen(so_fd, 5) == -1)
    {
        fprintf(stderr, "[%d]: lsiten failed \n", __LINE__);
    }

    //大结构体链表起始
    cp_list c_list = malloc(sizeof(c_node));
    // 初始化头结点
    INIT_LIST_HEAD(&c_list->head);

    struct sockaddr_in cliaddr;
    bzero(&cliaddr, len);
    // 4）等待服务器连接
    pthread_t s_pid;

    if ((pthread_create(&s_pid, NULL, read_msg, (void *)c_list)) != 0)
    {
        printf("get pthread create failed!\n");
    }

    while (1)
    {
        int concetfd = accept(so_fd, (struct sockaddr *)&cliaddr, &len);

        if (concetfd > 0)
        {
            printf("concet : %d \n", concetfd);
            printf("new connection : %s \n", inet_ntoa(cliaddr.sin_addr));

            c_node *cl_n = malloc(sizeof(c_node));

            bzero(cl_n, sizeof(c_node));
            cl_n->confd = concetfd;
            strcpy(cl_n->ip, inet_ntoa(cliaddr.sin_addr));

            list_add(&cl_n->head, &c_list->head);
        }
    }

    // 6）挂断
    close(so_fd);

    void *rev = NULL;
    if ((pthread_join(s_pid, rev)) != 0)
    {
        printf("pthread_join failed!\n");
    }

    return 0;
}

void *read_msg(void *arg)
{

    cp_list c_list = (cp_list)arg;

    cp_list n, pos, tmp;
    // 5）畅聊
    char buf[200];
    while (1)
    {
        
        list_for_each_entry_safe(pos, n, &c_list->head, head)
        {
            bzero(buf, sizeof(buf));
            recv(pos->confd, buf, sizeof(buf), 0);
            if (strlen(buf) > 0)
            {
                char *p = strstr(buf, ":");
                if (p == NULL)
                {
                    printf("[%d] from client %d :%s ", __LINE__, pos->confd , buf);
                    
                    if (strncmp(buf, "quit\n", 5) == 0)
                    {
                        
                        close(pos->confd);
                        list_del(&pos->head);
                        free(pos);
                        break;
                    }
                }
                else
                {
                    int fd = atoi(buf);
                    list_for_each_entry(tmp, &c_list->head, head)
                    {
                        if (tmp->confd == fd)
                        {
                            send(fd, p + 1, sizeof(buf), 0);
                        }
                    }
                }
            }
        }
    }
}
