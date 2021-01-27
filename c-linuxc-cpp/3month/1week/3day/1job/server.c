#include "head.h"


/* 服务端
*/

int main(int argc, char const *argv[])  // /.server.out 端口号
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

    
    //  htons的作用是:将无符号短整数hostshort从 主机字节顺序到网络字节顺序。
    // atoi函数将字符串端口号转为整型如 "5000" -> 500
    // 主机字节顺序与网络字节顺序相同，所以这些功能都是身份。
    // 代表服务器可以接受任何发送过来，该宏只能服务器使用，不能在客户端使用。
    // #define	INADDR_ANY  ((unsigned long int) 0x00000000)
    addr.sin_family = AF_INET;   //协议
    addr.sin_port = htons(atoi(argv[1])); //端口号
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip地址
     
    // 绑定
    if (bind(so_fd, (struct sockaddr *)&addr, len) == -1)
    {
        fprintf(stderr, "[%d]: Failed to bind socket to network address \n", __LINE__);
    }

    // 3）设置监听套接字
    if (listen(so_fd, 5) == -1)
    {
        fprintf(stderr, "[%d]: lsiten failed \n", __LINE__);
    }

    struct sockaddr_in cliaddr;
    bzero(&cliaddr, len);
    // 4）等待服务器连接
    int concetfd = accept(so_fd, (struct sockaddr *)&cliaddr, &len);

    if (concetfd > 0)
    {
        printf("concet : %d \n", concetfd);
        printf("new connection : %s \n", inet_ntoa(cliaddr.sin_addr));
    }

    // 5）畅聊
    char buf[200];
    while (1)
    {
        bzero(buf, sizeof(buf));
        
        recv(concetfd, buf, sizeof(buf), 0);

        
        if (strlen(buf) > 0)
        {
            send(concetfd, buf, sizeof(buf), 0);
            printf("[%d] from client:%s ", __LINE__, buf);
        }
        if (strncmp(buf, "quit\n", 5) == 0)
        {
            break;
        }
        
    }

    // 6）挂断
    close(so_fd);
    close(concetfd);

    return 0;
}
