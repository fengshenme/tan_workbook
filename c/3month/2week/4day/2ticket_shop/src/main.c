#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#include <sys/time.h>
#include <sys/types.h>

int va();
int index_t();
int login(int sofd);

int init_sock();
int user_regist(int sofd);
int use_admin(char *name, int sofd);
int strrep(char *str, char del);

int repassword(int sofd);

int main(int argc, char const *argv[])
{
    int sofd = init_sock();
    index_t(sofd);

    close(sofd);
    return 0;
}

int index_t(int sofd)
{
    va();
    printf("\t\t火星机场购票系统\n");
    printf(" 1) 登录\t 2) 注册\t 3) 忘记密码\t \n");
    va();
    printf("请选择对应服务 ,输入对应数字序号进入:");

    short num;
    scanf("%hd", &num);
    while (getchar() != '\n')
        ;
    switch (num)
    {
    case 1:
        printf("您选择了登录\n");

        login(sofd);
        break;
    case 2:
        printf("您选择了注册\n");
        if (user_regist(sofd) == -1)
            index_t(sofd);
        break;
    case 3:
        printf("您选择了忘记密码\n");
        repassword(sofd);
        break;

    default:
        break;
    }

    return 0;
}

int va()
{
    int i;
    for (i = 0; i < 60; i++)
    {
        printf("=");
    }
    printf("\n");
    return 0;
}

int init_sock()
{
    const char *ip = "192.168.24.82";
    const char *port = "6868";
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
    return sofd;
}

int login(int sofd)
{

    int buf_s = 1024;
    char *buf = malloc(buf_s);
    while (1)
    {

        bzero(buf, buf_s);
        char name[20];
        char password[20];
        bzero(name, 20);
        bzero(password, 20);

        printf("用户名:");
        fgets(name, 20, stdin);
        strrep(name, '\n');
        printf("密码:");
        fgets(password, 20, stdin);

        sprintf(buf, "login:%s,%s", name, password);
        strrep(buf, '\n');

        if (send(sofd, buf, strlen(buf), 0) > 0)
        {
            printf("send success\n");
        }

        if (strncmp(buf, "quit", 4) == 0)
        {
            break;
        }

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 登录成功-%s\n", __LINE__, p + 1);
            use_admin(name, sofd);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("密码或账号错误,是否重置密码[y/n]");
            char y;
            scanf("%c", &y);
            if (y == 'y')
            {
                index_t(sofd);
            }
            else
            {
                continue;
            }
        }
    }
    // 释放内存,关闭文件
    free(buf);

    return 0;
}

int user_regist(int sofd)
{
    va();
    printf("\t欢迎注册成为鲲鹏航空公司的用户\t\n");
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    while (1)
    {

        bzero(buf, buf_s);
        char name[20];
        char password[20];
        char npassword[20];
        bzero(name, 20);
        bzero(password, 20);

        printf("用户名:");
        fgets(name, 20, stdin);
        strrep(name, '\n');
        printf("密码:");
        fgets(password, 20, stdin);
        printf("请再次输入密码:");
        fgets(npassword, 20, stdin);

        if (strncmp(password, npassword, 20) != 0)
        {
            printf("两次密码不一致请重新输入\n");
            continue;
        }
        char tel[20];
        printf("手机号:");
        fgets(tel, 20, stdin);
        if (strlen(tel) != 12)
        {
            printf("电话号码格式不对,重新填写\n");
            continue;
        }
        printf("手机短信验证码:(目前1212)");
        char code[5];
        fgets(code, 5, stdin);

        sprintf(buf, "regist:%s,%s,%s,%s", name, password, tel, code);
        strrep(buf, '\n');
        // printf("%d -%s\n", __LINE__, buf);
        if (send(sofd, buf, strlen(buf), 0) > 0)
        {
            printf("regist msg send success\n");
        }

        if (strncmp(buf, "quit", 4) == 0)
        {
            break;
        }

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 注册成功,请登录-%s\n", __LINE__, p + 1);
            index_t(sofd);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("注册失败,是否重新注册[y/n]");
            char y[2];
            scanf("%s", y);
            if (strncmp(y, "y", 2) == 0)
            {
                continue;
            }
            if (strncmp(y, "n", 2) == 0)
            {
                return -1;
            }
        }
    }
    // 释放内存,关闭文件
    free(buf);

    return 0;
}

int use_admin(char *name, int sofd)
{
    va();
    printf("您好: %s用户\t\t用户中心\n", name);
    printf(" 1.航班列表\t 2. 查询航班\t 3. 快速查询\t \n");
    printf(" 4.订购航班\t 5. 退票改签\t 6. 查询余额\t \n");
    printf(" 7.充值账户\t 8. 修改信息\t 9. 取票服务\t \n");
    printf(" 10.打印发票\t 11. 聊天功能\t 12. 朋友圈\t \n");
    printf(" 13.退出登录\t\t \n");
    va();
    printf("请选择对应服务 ,输入对应数字序号进入:");
    short num;
    scanf("%hd", &num);
    while (getchar() != '\n')
        ;
    switch (num)
    {
    case 1:
        printf("您选择了航班列表\n");
        getflight_list(sofd);

        break;
    case 2:
        printf("您选择了查询航班\n");
        break;
    case 3:
        printf("您选择了快速查询\n");
        break;

    default:
        break;
    }

    return 0;
}

int strrep(char *str, char del) // 删除指定字符
{
    int i, j, k = strlen(str);
    for (i = 0; i < k; i++)
    {
        if (str[i] == del)
        {
            for (j = i; j < k; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
            k--;
        }
    }
    return 0;
}

int repassword(int sofd)
{
    va();
    printf("\t\t密码找回\t\n");
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    char *name  = malloc(20);
    char *password  = malloc(20);
    char *tel = malloc(20);
    char code[5];
    while (1)
    {

        bzero(buf, buf_s);
        
        bzero(name, 20);
        bzero(password, 20);
        bzero(tel, 20);
        bzero(code, 5);

        printf("用户名:"); // 15800998866
        fgets(name, 20, stdin);
        strrep(name, '\n');

        printf("手机号:");
        fgets(tel, 20, stdin);
        if (strlen(tel) != 12)
        {
            printf("电话号码格式不对,重新填写\n");
            continue;
        }
        printf("手机短信验证码:(目前1212)");
        fgets(code, 7, stdin);

        printf("新密码:");
        fgets(password, 20, stdin);
        
        sprintf(buf, "repass:%s,%s,%s,%s", name, password, tel, code);
        strrep(buf, '\n');
         printf("[%d] -%s\n", __LINE__, buf);
         
        
        
        // printf("%d -%s\n", __LINE__, buf);
        if (send(sofd, buf, strlen(buf), 0) > 0)
        {
            printf("repass msg send success\n");
        }

        if (strncmp(buf, "quit", 4) == 0)
        {
            break;
        }

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        char *p = strstr(buf, ":");
        if (atoi(buf) == 200)
        {
            printf("[%d] 密码重置成功,请登录-%s\n", __LINE__, p + 1);
            index_t(sofd);
            break;
        }

        if (atoi(buf) == 404)
        {
            printf("密码重置失败,是否重新设置[y/n]");
            char y[2];
            scanf("%s", y);
            if (strncmp(y, "y", 2) == 0)
            {
                continue;
            }
            if (strncmp(y, "n", 2) == 0)
            {
                return -1;
            }
        }
        
    }
    free(password);
    free(name);
    free(tel);
    free(buf);
    return 0;
}


int getflight_list(int sofd)
{
    va();
    printf("\t\t航班列表\t\n");
    va();
    
}


