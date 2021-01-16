#include "head.h"

//边栏
int va(char *ch);
// 首页
int index_t();
//登录
int login(int sofd);
// 初始化套接字
int init_sock(const char *ip, const char *port);
// 用户注册
int user_regist(int sofd);
// 用户管理界面
int use_admin(char *name, int sofd);
// 删除字符串中指定字符
int strrep(char *str, char del);
//重置密码
int repassword(int sofd);
// 航班列表
int getflight_list(char *name, int sofd);
// 查询航班
int search_flight(char *name, int sofd);
//打印航班
int show_flight(char (*flight)[256], int i);
// 获取航班信息的公共部分
int get_f(char *buf, char (*flight)[256], int *i);
//快速查询
int quick_searchf(char *name, int sofd);

int main(int argc, char const *argv[])
{
    //     const char *ip = "192.168.24.82";
    // const char *port = "6868";
    if (argc != 3)
    {
        fprintf(stderr, "%d] %s <ip addr> <port> \n", __LINE__, argv[0]);
        exit(EXIT_FAILURE);
    }

    int sofd = init_sock(argv[1], argv[2]);
    index_t(sofd);

    close(sofd);
    return 0;
}

int index_t(int sofd)
{
    va("=");
    printf("\t\t火星机场购票系统\n");
    printf(" 1) 登录\t 2) 注册\t 3) 忘记密码\t \n");
    va("=");
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

int va(char *ch)
{
    int i;
    for (i = 0; i < 75; i++)
    {
        printf("%s", ch);
    }
    printf("\n");
    return 0;
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
    va("=");
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
    va("=");
    printf("您好: %s用户\t\t用户中心\n", name);
    printf(" 1.航班列表\t 2. 查询航班\t 3. 快速查询\t \n");
    printf(" 4.订购航班\t 5. 退票改签\t 6. 查询余额\t \n");
    printf(" 7.充值账户\t 8. 修改信息\t 9. 取票服务\t \n");
    printf(" 10.打印发票\t 11. 聊天功能\t 12. 朋友圈\t \n");
    printf(" 13.退出登录\t\t \n");
    va("=");
    printf("请选择对应服务 ,输入对应数字序号进入:");
    short num;
    scanf("%hd", &num);
    while (getchar() != '\n')
        ;
    switch (num)
    {
    case 1:
        printf("您选择了航班列表\n");
        getflight_list(name, sofd);

        break;
    case 2:
        printf("您选择了查询航班\n");
        search_flight(name, sofd);
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
    va("=");
    printf("\t\t密码找回\t\n");
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    char *name = malloc(20);
    char *password = malloc(20);
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

int getflight_list(char *name, int sofd)
{
    int buf_s = 1024;
    char *buf = malloc(buf_s);
    char(*flight)[256] = calloc(256, 200);
    int i = 0;

    bzero(buf, buf_s);
    bzero(flight, 256 * 200);

    sprintf(buf, "getflight_list:all");

    if (send(sofd, buf, strlen(buf), 0) <= 0)
    {
        printf("[%d] send failed\n", __LINE__);
    }
    while (1)
    {

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }

        get_f(buf, flight, &i);
    }

    show_flight(flight, i);

    free(flight);
    // 释放内存,关闭文件
    free(buf);
    use_admin(name, sofd);
    return 0;
}

int search_flight(char *name, int sofd)
{
    char des[20];
    char botime[20];
    char ftype;
    char price[8];
    char(*flight)[256] = calloc(256, 200);
    int i = 0;

    bzero(flight, 256 * 200);

    int buf_s = 1024;
    char *buf = malloc(buf_s);

    bzero(des, 20);
    bzero(botime, 20);
    bzero(price, 8);
    printf("目的地:");
    fgets(des, 20, stdin);
    printf("出发日期:");
    fgets(botime, 20, stdin);
    printf("机型:");
    scanf("%c", &ftype);
    while (getchar() != '\n')
        ;
    printf("价格以下:");
    fgets(price, 8, stdin);

    bzero(buf, buf_s);
    sprintf(buf, "selectf:%s,%s,%c,%s", des, botime, ftype, price);
    strrep(buf, '\n');

    while (1)
    {

        if (send(sofd, buf, strlen(buf), 0) <= 0)
        {
            printf("get send failed\n");
        }

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        get_f(buf, flight, &i);
    }
    if (i > 0)
    {
        show_flight(flight, i);
    }
    else
    {
        printf("没有符合条件的航班....");
    }

    use_admin(name, sofd);
    // 释放内存,关闭文件
    free(buf);
    free(flight);
    return 0;
}



int quick_searchf(char *name, int sofd)
{
    va("=");
    printf("\t\t快速查询\t\n");
    char fln[10];
    char(*flight)[256] = calloc(256, 200);
    int i = 0;

    bzero(flight, 256 * 200);

    int buf_s = 1024;
    char *buf = malloc(buf_s);

    bzero(fln, 10);
    printf("输入航班号:");
    fgets(fln, 20, stdin);

    bzero(buf, buf_s);
    sprintf(buf, "selectq:%s", fln);
    strrep(buf, '\n');

    while (1)
    {

        if (send(sofd, buf, strlen(buf), 0) <= 0)
        {
            printf("get send failed\n");
        }

        bzero(buf, buf_s);
        recv(sofd, buf, buf_s, 0);

        if (strlen(buf) <= 0)
        {
            continue;
        }
        get_f(buf, flight, &i);
    }

    if (i > 0)
    {
        show_flight(flight, i);
    }
    else
    {
        printf("没有符合条件的航班....");
    }

    use_admin(name, sofd);
    // 释放内存,关闭文件
    free(buf);
    free(flight);
    return 0;
}

// 获取航班信息的公共部分
int get_f(char *buf, char (*flight)[256], int *i)
{
    printf("%d-%s\n", __LINE__, buf);
    if (atoi(buf) == 200) //成功的头部信息是200
    {
        char *p = strstr(buf, ":");
        printf("[%d] 信息获取成功-%s\n", __LINE__, p + 1);
        // char *np = strstr(p + 1, ":");

        char *pp = strtok(p + 1, "\n"); // 获取到第一条航班信息
        if (pp != NULL)
        {
            strncpy(flight[*i], pp, 256);
            i++;
        }

        while (pp != NULL)
        {
            pp = strtok(NULL, "\n");
            if (pp != NULL)
            {
                strncpy(flight[*i], pp, 256);
                i++;
            }
        }
        return 0;
    }

    if (atoi(buf) == 404)
    {
        printf("航班信息获取失败....\n");
        return -1;
    }
    return 0;
}

int show_flight(char (*flight)[256], int i)
{
    va("=");
    printf("\t\t航班列表\t\n");
    va("=");
    printf("\n");
    va("*");
    printf("航班号\t起点站\t\t出发站\t班期\t\t机型\t起飞时间 票价\t余票\n");
    int j;
    for (j = 0; j < i; j++)
    {
        //  flight[i] 指针变量相当于flight + 1指针变量访问的第一个维度元素
        //   printf("%d-%s\n",__LINE__,flight[j] );
        char *pp = strtok(flight[j], ",");
        if (pp != NULL)
        {
            printf("%s\t", pp);
        }
        pp = strtok(NULL, ",");
        if (pp != NULL)
        {
            printf("%s\t", pp);
        }
        printf("--->\t");

        while (pp != NULL)
        {
            pp = strtok(NULL, ",");
            if (pp != NULL)
            {
                printf("%s\t", pp);
            }
        }
        printf("\n");
    }
    return 0;
}