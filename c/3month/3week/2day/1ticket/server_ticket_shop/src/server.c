#include "../include/head.h"

int adminlogin(char *buf, cp_list c_list);
int add_flight_ad(char *buf, cp_list c_list);

int add_thread(int so_fd, cp_list c_list)
{
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    bzero(&cliaddr, len);

    // 初始化头结点
    INIT_LIST_HEAD(&c_list->head);
    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    c_list->m = m;

    while (1)
    {
        int concetfd = accept(so_fd, (struct sockaddr *)&cliaddr, &len);

        if (concetfd > 0)
        {
            printf("%d=>concet : %d \n", __LINE__, concetfd);
            printf("%d=>new connection : %s \n", __LINE__, inet_ntoa(cliaddr.sin_addr));

            c_node *cl_n = malloc(sizeof(c_node));

            bzero(cl_n, sizeof(c_node));
            cl_n->confd = concetfd;
            strcpy(cl_n->ip, inet_ntoa(cliaddr.sin_addr));

            cl_n->m = m;
            cl_n->flist = c_list->flist;
            cl_n->ulist = c_list->ulist;
            cl_n->blist = c_list->blist;
            cl_n->pdb = c_list->pdb;

            pthread_mutex_lock(&m); // 多线程时,公共资源都需要上锁
            list_add(&cl_n->head, &c_list->head);
            pthread_mutex_unlock(&m);

            pthread_attr_t attr;
            pthread_attr_init(&attr);                                    // 设置属性
            pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置分离属性
            pthread_attr_setschedpolicy(&attr, SCHED_RR);                // 调度属性设为轮播

            // 4）等待服务器连接
            pthread_t s_pid;

            if ((pthread_create(&s_pid, &attr, read_msg, (void *)cl_n)) != 0)
            {
                printf("%d=>get pthread create failed!\n", __LINE__);
            }
        }
    }
}

int init_sock(const char *str_port)
{
    //     1）创建未连接套接字
    int so_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (so_fd == -1)
    {
        printf("[%d] Failed to create unconnected socket \n", __LINE__);
    }

    // 2）服务器设置IP地址时，可以使用一个宏：
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    bzero(&addr, len);

    addr.sin_family = AF_INET;                //协议
    addr.sin_port = htons(atoi(str_port));    //端口号
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip地址

    // 绑定
    if (bind(so_fd, (struct sockaddr *)&addr, len) == -1)
    {
        printf("[%d]: Failed to bind socket to network address \n", __LINE__);
    }

    // 3）设置监听套接字 设置可以同时访问的人为5个
    if (listen(so_fd, 10) == -1)
    {
        printf("[%d]: lsiten failed \n", __LINE__);
    }

    return so_fd;
}

void handler(void *arg) // 线程取消处理例程
{
    cp_list pos = (cp_list)arg;
    pthread_mutex_t m = pos->m;

    close(pos->confd);
    // 加锁
    pthread_mutex_lock(&m);
    list_del(&pos->head);
    // 解锁
    pthread_mutex_unlock(&m);
    free(pos);
}

void *read_msg(void *arg) // 线程例程函数
{
    int seconds = time((time_t *)NULL);
    int rets;
    cp_list pos = (cp_list)arg;

    pthread_mutex_t m = pos->m;

    // 加锁前，将 handler 压入线程取消处理例程的栈中，以防中途被取消 14
    pthread_cleanup_push(handler, (void *)pos);

    printf("%d=> new pthread runing %d \n", __LINE__, pos->confd);
    // 5）畅聊
    char buf[1024];
    while (1)
    {
        rets = time((time_t *)NULL);
        if (rets - seconds > 360) // 无操作5分钟退出连接
            break;
        bzero(buf, sizeof(buf));

        recv(pos->confd, buf, sizeof(buf), 0);
        if (strlen(buf) <= 0)
        {
            continue;
        }
        seconds = rets;
        printf("%d=>  %s \n", __LINE__, buf);
        if (strncmp(buf, "addflight", 9) == 0)
        {

            add_flight_ad(buf, pos); //添加航班函数
        }
        else if (strncmp(buf, "login", 5) == 0)
            login(buf, pos); //处理登录的函数
        else if (strncmp(buf, "adminlogin", 10) == 0)
            adminlogin(buf, pos); //处理登录的函数
        else if (strncmp(buf, "regist", 6) == 0)
            regist_s(buf, pos); // 处理注册的函数
        else if (strncmp(buf, "repass", 6) == 0)
            repassword(buf, pos); // 重置密码
        else if (strncmp(buf, "getflight_list", 14) == 0)
            flight_list(buf, pos); // 获取航班列表
        else if (strncmp(buf, "selectf", 7) == 0)
            search_flight(buf, pos); //多条件search 航班
        else if (strncmp(buf, "selectq", 7) == 0)
            search_quick(buf, pos); // 通过航班号快速查找
        else if (strncmp(buf, "recharge", 8) == 0)
            recharge(buf, pos); // 账户充值
        else if (strncmp(buf, "buyflight", 9) == 0)
            s_booking_flights(buf, pos); // 订购航班
        else if (strncmp(buf, "findacc", 7) == 0)
            balance_inquiry(buf, pos); // 余额查询
        else if (strncmp(buf, "findbuyfli", 10) == 0)
            find_buyed_flight(buf, pos); // 已购航班
        else if (strncmp(buf, "refunded", 8) == 0)
            refunded(buf, pos); // 退票
        else if (strncmp(buf, "reuserin", 8) == 0)
            change_userinfo(buf, pos); // 修改用户信息
        else if (strncmp(buf, "drawbill", 8) == 0)
            draw_bill(buf, pos); // 出票
        else if (strncmp(buf, "pinvoice", 8) == 0)
            print_invoice(buf, pos); // 打印发票票
        else if (strncmp(buf, "logout", 6) == 0)
        {
            if (logout(buf, pos) == 0) // 退出登录
            {
                close(pos->confd);
                // lock
                pthread_mutex_lock(&m);
                list_del(&pos->head);
                // unlock
                pthread_mutex_unlock(&m);
                free(pos);
                break;
            }
        }
    }

    pthread_cleanup_pop(0);
    pthread_exit(NULL);
}

int login(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");

    int flag = 0;
    char *name = strtok(p + 1, ",");
    char *password = strtok(NULL, ",");
    if (password == NULL || name == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    u_node *utmp = malloc(sizeof(u_node));

    int slen = 256;
    if (flag != -1)
    {

        strncpy(utmp->password, password, 20);
        strncpy(utmp->name, name, 20);

        if (sqllogin(c_list->pdb, utmp) == 0)
        {
            flag = 1;

            char lsmg[128];
            sprintf(lsmg, "200:%s,%s,%hd,%d,%u", utmp->name, utmp->phone, utmp->status, utmp->account, utmp->vipclass);
            printf("[%d] %s\n", __LINE__, lsmg);
            if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
            {
                flag = -1;
                printf("%d=>success msg send failed\n", __LINE__);
            }
        }
    }

    if (flag == 0 || flag != -1)
    {
        char lsmg[128] = "404:login failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    free(utmp);

    return 0;
}

int adminlogin(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");

    int flag = 0;
    char *name = strtok(p + 1, ",");
    char *password = strtok(NULL, ",");
    if (password == NULL || name == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    u_node *utmp = malloc(sizeof(u_node));

    int slen = 256;
    if (flag != -1)
    {

        strncpy(utmp->password, password, 20);
        strncpy(utmp->name, name, 20);

        if (sqllogin(c_list->pdb, utmp) == 0)
        {
            flag = 1;

            char lsmg[128];
            sprintf(lsmg, "200:%s,%s,%hd,%d,%u", utmp->name, utmp->phone, utmp->status, utmp->account, utmp->vipclass);
            printf("[%d] %s\n", __LINE__, lsmg);
            if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
            {
                flag = -1;
                printf("%d=>success msg send failed\n", __LINE__);
            }
        }
    }

    if (flag == 0 || flag != -1)
    {
        char lsmg[128] = "404:login failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    free(utmp);

    return 0;
}

int regist_s(char *buf, cp_list c_list)
{
    int flag = 0;
    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    char *name = strtok(p + 1, ",");
    char *password = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");
    int code = atoi(strtok(NULL, ","));

    if (name == NULL || password == NULL || phone == NULL)
        flag = -1;
    printf("[%d]%s\n", __LINE__, name);
    u_list ulist;
    ulist = c_list->ulist;

    printf("%d-%d\n", __LINE__, code);

    if (code == 1212 && flag == 0)
    {
        u_node *unode = malloc(sizeof(u_node));
        char sid[13];
        sprintf(sid, "%ld%d", time(0), uranda(90, 10)); //11位的id当前时间秒数加一位随机数
        // printf( "%d,%s\n", __LINE__, sid);
        strncpy(unode->id, sid, strlen(sid));

        strncpy(unode->name, name, 20);
        strncpy(unode->password, password, 20);
        strncpy(unode->phone, phone, 11);
        unode->status = 0; // Initial login status 0 just registered
        unode->account = 0;
        unode->vipclass = 0;

        unode->m = ulist->m;

        pthread_mutex_lock(&ulist->m); // lock

        add_user(unode, c_list->pdb);
        pthread_mutex_unlock(&ulist->m); // unlock

        searchall(c_list->pdb, ulist);
        show_list(ulist);
        char lsmg[20] = "200:regist success";
        // printf( "[%d]%s\n", __LINE__, unode->password);
        if (send(c_list->confd, lsmg, 30, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            flag = 1;
            printf("%d=>success msg send failed\n", __LINE__);
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[20] = "404:regist failed";
        // printf( "[%d]%s\n", __LINE__, password);
        if (send(c_list->confd, lsmg, 30, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send success\n", __LINE__);
        }
    }
    return 0;
}

int repassword(char *buf, cp_list c_list)
{
    printf("[%d]-%s\n", __LINE__, buf);
    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    int flag = 0;

    char *name = strtok(p + 1, ",");
    char *password = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");
    char *code = strtok(NULL, ",");

    if (password == NULL || name == NULL || phone == NULL || code == NULL)
        flag = -1;
    printf("[%d]flag:%d = %s\n", __LINE__, flag, name);

    u_list ulist = c_list->ulist;
    u_node *utmp = malloc(sizeof(u_node));
    int slen = 256;
    if (flag != -1 && atoi(code) == 1212)
    {
        strncpy(utmp->name, name, strlen(name));
        strncpy(utmp->phone, phone, strlen(phone));
        strncpy(utmp->password, password, 20);
        if (sqlrepass(c_list->pdb, utmp) == 0)
        {

            flag = 1;
            char lsmg[50] = "200:Password changed successfully";
            if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
            {
                printf("%d=>success msg send failed\n", __LINE__);
                return 0;
            }
            searchall(c_list->pdb, ulist);
            show_list(ulist);
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:Password changed failed";
        // printf( "[%d]%s\n", __LINE__, utmp->password);
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
            return -1;
        }
    }
    free(utmp);
    return 0;
}

int add_flight_ad(char *buf, cp_list c_list) // 添加航班
{
    // char *p = strstr(buf, ":");

    int flag = 0;
    printf("%d=>  %s \n", __LINE__, buf);
    printf("[%d]%s\n", __LINE__, buf + 9);
    char *p = strstr(buf, ":");
    char *flight_number = strtok(p + 1, ",");
    char *starting = strtok(NULL, ",");
    char *destin = strtok(NULL, ",");
    char *address = strtok(NULL, ",");
    char *ftype = strtok(NULL, ",");
    printf("[%d]%s\n", __LINE__, ftype);
    char *boardingTime = strtok(NULL, ",");
    char *pri = strtok(NULL, ",");
    char *surv = strtok(NULL, ",");

    if (flight_number == NULL || starting == NULL || destin == NULL || address == NULL || ftype == NULL || boardingTime == NULL || pri == NULL || surv == NULL)
        flag = -1;

    f_list flist;
    flist = c_list->flist;
    printf("%d-\n", __LINE__);
    if (flag == 0)
    {
        int price = atoi(pri);
        int surplusVote = atoi(surv);
        printf("%d-\n", __LINE__);

        f_node *fnode = malloc(sizeof(f_node));
        char sid[13];
        sprintf(sid, "%ld%d", time(0), uranda(90, 10)); //11位的id当前时间秒数加一位随机数
        printf("[%d]%s\n", __LINE__, sid);
        strncpy(fnode->id, sid, strlen(sid));
        strncpy(fnode->flight_number, flight_number, 20);
        strncpy(fnode->Starting, starting, 20);
        strncpy(fnode->destin, destin, 20);
        strncpy(fnode->Address, address, 20);
        fnode->ftype = ftype[0];
        strncpy(fnode->boardingTime, boardingTime, 20);
        fnode->price = price;
        fnode->surplusVote = surplusVote;
        fnode->m = flist->m;

        printf("[%d]%s,%s,%s,%s,%c,%s,%u,%u\n", __LINE__, fnode->flight_number, fnode->Starting,
               fnode->destin, fnode->Address, fnode->ftype, fnode->boardingTime, fnode->price, fnode->surplusVote);
        pthread_mutex_lock(&flist->m); // lock

        if (sqladd_flight(fnode, c_list->pdb) == 0)
        {
            flag = 1;
            search_fli_all(c_list->pdb, flist);
            show_f_list(flist);
            char lsmg[30] = "200: flight add success";
            // printf( "[%d]%s\n", __LINE__, unode->password);
            if (send(c_list->confd, lsmg, 128, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
            {
                flag = -1;
                printf("%d=>success msg send failed\n", __LINE__);
                return -1;
            }
        }
        pthread_mutex_unlock(&flist->m); // unlock

        return 0;
    }
    printf("%d-\n", __LINE__);
    if (flag == 0 || flag == -1)
    {
        char lsmg[20] = "404:flight failed";
        // printf( "[%d]%s\n", __LINE__, password);
        if (send(c_list->confd, lsmg, 30, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send success\n", __LINE__);
        }
    }

    return 0;
}

int flight_list(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    f_list ftmp, flist;
    struct list_head *pos;
    flist = c_list->flist;

    int slen = 256, count = 0;

    list_for_each(pos, &flist->head)
    {
        count++;
    }
    char lsmg[256];
    char *ltmp = malloc(25600);
    sprintf(ltmp, "200:");
    list_for_each_entry(ftmp, &flist->head, head)
    {
        bzero(lsmg, 256);
        sprintf(lsmg, "%s,%s,%s,%s,%c,%s,%u,%u\n", ftmp->flight_number, ftmp->Starting,
                ftmp->destin, ftmp->Address, ftmp->ftype, ftmp->boardingTime, ftmp->price, ftmp->surplusVote);

        // printf( "[%d]-%s\n", __LINE__, lsmg);
        strncat(ltmp, lsmg, strlen(lsmg));
    }
    if (send(c_list->confd, ltmp, 25600, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
    {
        printf("%d=>success msg send failed\n", __LINE__);
    }

    if (count <= 0)
    {
        char lsmg[128] = "404:get failed";
        printf("[%d]%s\n", __LINE__, lsmg);
        if (send(c_list->confd, lsmg, slen, 0) <= 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send success\n", __LINE__);
        }
    }
    free(ltmp);
    return 0;
}

int search_flight(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    int flag = 0;
    char *des = strtok(p + 1, ",");
    char *botime = strtok(NULL, ",");
    char *ftype = strtok(NULL, ",");
    char *price = strtok(NULL, ",");
    if (des == NULL || botime == NULL || ftype == NULL || price == NULL)
    {
        flag = -1;
        printf("%d-] str strtok failed\n", __LINE__);
    }

    f_list ftmp, flist;
    flist = c_list->flist;

    int slen = 256;

    char lsmg[256];
    char *ltmp = malloc(25600);
    sprintf(ltmp, "200:");

    list_for_each_entry(ftmp, &flist->head, head)
    {

        if (strncmp(des, ftmp->destin, strlen(ftmp->destin)) == 0 && strncmp(botime, ftmp->Address, strlen(ftmp->Address)) == 0 && *ftype == ftmp->ftype && ftmp->price < atoi(price))
        {
            bzero(lsmg, 256);
            sprintf(lsmg, "%s,%s,%s,%s,%c,%s,%u,%u\n", ftmp->flight_number, ftmp->Starting,
                    ftmp->destin, ftmp->Address, ftmp->ftype, ftmp->boardingTime, ftmp->price, ftmp->surplusVote);

            printf("[%d]-%s\n", __LINE__, lsmg);
            strncat(ltmp, lsmg, strlen(lsmg));
        }
    }
    printf("[%d]-%s\n", __LINE__, ltmp);
    if (send(c_list->confd, ltmp, 25600, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
    {
        flag = -1;
        printf(" %d->msg send failed\n", __LINE__);
    }

    if (flag < 0)
    {
        char lsmg[128] = "404:get failed";
        printf("[%d]%s\n", __LINE__, lsmg);
        if (send(c_list->confd, lsmg, slen, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send success\n", __LINE__);
        }
    }
    free(ltmp);
    return 0;
}

int search_quick(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    int flag = 0;
    char *fln = strtok(p + 1, ",");
    if (fln == NULL)
    {
        flag = -1;
        printf("%d=> str strtok failed => %s\n", __LINE__, p + 1);
    }

    f_list ftmp, flist;
    flist = c_list->flist;

    int slen = 256;

    char lsmg[256];
    char *ltmp = malloc(25600);
    sprintf(ltmp, "200:");

    list_for_each_entry(ftmp, &flist->head, head)
    {

        if (strncmp(fln, ftmp->flight_number, strlen(ftmp->flight_number)) == 0)
        {
            bzero(lsmg, 256);
            sprintf(lsmg, "%s,%s,%s,%s,%c,%s,%u,%u\n", ftmp->flight_number, ftmp->Starting,
                    ftmp->destin, ftmp->Address, ftmp->ftype, ftmp->boardingTime, ftmp->price, ftmp->surplusVote);

            printf("[%d]-%s\n", __LINE__, lsmg);
            strncat(ltmp, lsmg, strlen(lsmg));
        }
    }
    printf("[%d]-%s\n", __LINE__, ltmp);
    if (send(c_list->confd, ltmp, 25600, 0) <= 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
    {
        flag = -1;
        printf(" %d->msg send failed\n", __LINE__);
    }

    if (flag < 0)
    {
        char lsmg[128] = "404:get failed";
        printf("[%d]%s\n", __LINE__, lsmg);
        if (send(c_list->confd, lsmg, slen, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send success\n", __LINE__);
        }
    }

    free(ltmp);
    return 0;
}

int recharge(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    int flag = 0;

    char *phone = strtok(p + 1, ",");
    char *money = strtok(NULL, ",");
    char *name = strtok(NULL, ",");

    if (money == NULL || phone == NULL || name == NULL)
        flag = -1;
    // printf( "[%d]flag:%d flag,%s,%s\n", __LINE__, flag, money, phone);
    u_list utmp, ulist;
    ulist = c_list->ulist;

    int slen = 256;
    if (flag != -1)
    {
        list_for_each_entry(utmp, &ulist->head, head)
        {
            if (strncmp(phone, utmp->phone, strlen(utmp->phone)) == 0 && strncmp(name, utmp->name, strlen(utmp->name)) == 0)
            {
                char tapath[128];
                bzero(tapath, 128);
                sprintf(tapath, "data/user_db%d.txt", urand(3));
                if (file_copy("data/user_db.txt", tapath) == 0)
                    utmp->account += atoi(money);
                flag = 1;

                char lsmg[128];
                sprintf(lsmg, "200:%d", utmp->account);
                printf("[%d]%s\n", __LINE__, lsmg);
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>success msg send failed\n", __LINE__);
                }
                break;
            }
        }
        if (flag == 1)
        {

            put_user_db(ulist);
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:Password changed failed";
        printf("[%d]%s\n", __LINE__, utmp->password);
        if (send(c_list->confd, lsmg, slen, 0) <= 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    return 0;
}

// 生成0-n之间的一个随机数
int urand(int n)
{
    srand((int)time(0));
    return 1 + (int)((float)n * rand() / (RAND_MAX + 1.0));
}

int balance_inquiry(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    int flag = 0;

    char *phone = strtok(p + 1, ",");
    char *name = strtok(NULL, ",");

    if (phone == NULL || name == NULL)
        flag = -1;
    // printf( "[%d]flag:%d flag,%s,%s\n", __LINE__, flag, money, phone);
    u_list utmp, ulist;
    ulist = c_list->ulist;

    int slen = 256;
    if (flag != -1)
    {
        list_for_each_entry(utmp, &ulist->head, head)
        {
            if (strncmp(phone, utmp->phone, strlen(utmp->phone)) == 0 && strncmp(name, utmp->name, strlen(utmp->name)) == 0)
            {
                char lsmg[128];
                sprintf(lsmg, "200:%d", utmp->account);
                printf("[%d]%s\n", __LINE__, lsmg);
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>success msg send failed\n", __LINE__);
                }
                break;
            }
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:Password changed failed";
        printf("[%d]%s\n", __LINE__, utmp->password);
        if (send(c_list->confd, lsmg, slen, 0) <= 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    return 0;
}

int s_booking_flights(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");

    int flag = 0;
    char *flnum = strtok(p + 1, ",");
    printf("[%d]-%s\n", __LINE__, p + 1);
    char *fltime = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");

    if (flnum == NULL || fltime == NULL || phone == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    f_list ftmp, flist;
    u_list utmp, ulist;
    flist = c_list->flist;
    ulist = c_list->ulist;
    bfn_list btmp, blist;
    blist = c_list->blist;
    if (c_list->flist == NULL)
    {
        printf("[%d] null \n", __LINE__);
    }
    printf("[%d]%s,%s,%s\n", __LINE__, flnum, fltime, phone);

    list_for_each_entry(btmp, &blist->head, head)
    {
        if (strncmp(btmp->flight_number, flnum, strlen(btmp->flight_number)) == 0 && strncmp(btmp->phone, phone, strlen(btmp->phone)) == 0)
        {
            break;
            flag = -1;
        }
    }
    list_for_each_entry(ftmp, &flist->head, head)
    {
        // printf( "[%d]%s,%s,%s\n", __LINE__, flnum, fltime, phone);
        // printf( "[%d]%s,%s,%d\n", __LINE__, ftmp->flight_number, ftmp->Address, ftmp->surplusVote);
        if (strncmp(flnum, ftmp->flight_number, strlen(ftmp->flight_number)) == 0 && strncmp(fltime, ftmp->Address, strlen(ftmp->Address)) == 0 && ftmp->surplusVote > 0)
        {
            break;
        }
    }
    list_for_each_entry(utmp, &ulist->head, head) // 用户表的余额减少买票钱
    {

        if (strncmp(phone, utmp->phone, strlen(utmp->phone)) == 0)
        {
            printf("%d=>\n", __LINE__);
            if (utmp->account < ftmp->price)
            {
                flag = -1;
                break;
            }
        }
    }

    int slen = 256;
    if (flag != -1)
    {
        list_for_each_entry(ftmp, &flist->head, head)
        {
            // printf( "[%d]%s,%s,%s\n", __LINE__, flnum, fltime, phone);
            // printf( "[%d]%s,%s,%d\n", __LINE__, ftmp->flight_number, ftmp->Address, ftmp->surplusVote);
            if (strncmp(flnum, ftmp->flight_number, strlen(ftmp->flight_number)) == 0 && strncmp(fltime, ftmp->Address, strlen(ftmp->Address)) == 0 && ftmp->surplusVote > 0)
            {

                bfn *bnode = (bfn_list)malloc(sizeof(bfn));

                strncpy(bnode->phone, phone, 13);
                strncpy(bnode->flight_number, flnum, 10);
                strncpy(bnode->Address, fltime, 10);

                bnode->price = ftmp->price;
                bnode->flags = 0;
                bnode->m = blist->m;
                printf("[%d]%s,%s,%s\n", __LINE__, bnode->phone, bnode->flight_number, bnode->Address);

                pthread_mutex_lock(&bnode->m); // lock
                list_add(&bnode->head, &blist->head);
                sprintf(buf, "%s,%s,%s,%u,%u\n", bnode->phone, bnode->flight_number, bnode->Address, bnode->price, bnode->flags);
                FILE *bfd = open_file("data/buy_flight_db.txt");
                fputs(buf, bfd);
                fclose(bfd);
                pthread_mutex_unlock(&bnode->m); // unlock

                char tapath[128];
                pthread_mutex_lock(&flist->m);
                bzero(tapath, 128);
                sprintf(tapath, "data/flight_info%d.txt", urand(3));
                if (file_copy("data/flight_info.txt", tapath) == 0)
                    ftmp->surplusVote--;
                pthread_mutex_unlock(&flist->m);

                pthread_mutex_lock(&ulist->m);
                bzero(tapath, 128);
                sprintf(tapath, "data/user_db%d.txt", urand(3));
                if (file_copy("data/user_db.txt", tapath) == 0)
                {
                    list_for_each_entry(utmp, &ulist->head, head) // 用户表的余额减少买票钱
                    {

                        if (strncmp(bnode->phone, utmp->phone, strlen(bnode->phone)) == 0)
                        {
                            printf("%d=>\n", __LINE__);
                            utmp->account -= ftmp->price;
                        }
                    }
                }
                pthread_mutex_unlock(&ulist->m);

                char lsmg[128] = {0};
                sprintf(lsmg, "200:%s", "buy success");
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>buy success msg send failed\n", __LINE__);
                }

                flag = 1;
            }
            if (flag == 1)
            {
                put_flight_info(flist);
                put_user_db(ulist);
                break;
            }
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:login failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    return 0;
}

int put_buy_flight_db(bfn_list blist)
{
    bfn_list btmp;
    char *buf_w = malloc(1024);
    // printf( "[%d]-%s\n", __LINE__, phone);
    pthread_mutex_lock(&blist->m); // lock

    FILE *cfd = fopen("data/buy_flight_db.txt", "w");
    list_for_each_entry(btmp, &blist->head, head)
    {
        memset(buf_w, 0, 1024);

        sprintf(buf_w, "%s,%s,%s,%u,%u\n", btmp->phone, btmp->flight_number, btmp->Address, btmp->price, btmp->flags);
        if (strlen(buf_w) > 0)
        {
            fputs(buf_w, cfd);
        }
    }
    fclose(cfd);
    pthread_mutex_unlock(&blist->m); // unlock
    free(buf_w);
    return 0;
}
int put_flight_info(f_list flist)
{
    f_list ftmp;
    char *buf_w = malloc(1024);
    // printf( "[%d]-%s\n", __LINE__, phone);
    pthread_mutex_lock(&flist->m); // lock

    FILE *cfd = fopen("data/flight_info.txt", "w");
    list_for_each_entry(ftmp, &flist->head, head)
    {
        memset(buf_w, 0, 1024);

        sprintf(buf_w, "%s,%s,%s,%s,%c,%s,%u,%u\n", ftmp->flight_number, ftmp->Starting,
                ftmp->destin, ftmp->Address, ftmp->ftype, ftmp->boardingTime, ftmp->price, ftmp->surplusVote);
        if (strlen(buf_w) > 0)
        {
            fputs(buf_w, cfd);
        }
    }
    fclose(cfd);
    pthread_mutex_unlock(&flist->m); // unlock
    free(buf_w);
    return 0;
}

int put_user_db(u_list ulist)
{
    u_list utmp;
    char *buf_w = malloc(1024);

    pthread_mutex_lock(&ulist->m); // lock

    FILE *cfd = fopen("data/user_db.txt", "w");
    list_for_each_entry(utmp, &ulist->head, head)
    {
        memset(buf_w, 0, 1024);

        sprintf(buf_w, "%s,%s,%s,%hd,%d,%u\n", utmp->name, utmp->password, utmp->phone, utmp->status, utmp->account, utmp->vipclass);
        //  printf( "[%d]%s\n", __LINE__, buf_w);
        if (strlen(buf_w) > 0)
        {
            fputs(buf_w, cfd);
        }
    }
    fclose(cfd);
    pthread_mutex_unlock(&ulist->m); // unlock
    free(buf_w);

    return 0;
}

int file_copy(char *src, char *des)
{
    FILE *sfd = fopen(src, "r");
    FILE *dfd = fopen(des, "w");

    if (sfd == NULL || dfd == NULL)
    {
        printf("%d: file open or create failed\n", __LINE__);
        return -1;
    }
    char *buf = malloc(1024);
    memset(buf, 0, 1024);
    while (fgets(buf, 1024, sfd) != NULL)
    {
        if (fputs(buf, dfd) == EOF)
            return -1;
        memset(buf, 0, 1024);
    }
    free(buf);
    fclose(sfd);
    fclose(dfd);
    return 0;
}

int find_buyed_flight(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    int flag = 0;
    char *phone = strtok(p + 1, ",");
    if (phone == NULL)
    {
        flag = -1;
        printf("%d=> str strtok failed => %s\n", __LINE__, p + 1);
    }

    bfn_list btmp, blist;
    blist = c_list->blist;
    f_list ftmp, flist;
    flist = c_list->flist;

    int slen = 256;

    char lsmg[256];
    char *ltmp = malloc(25600);
    sprintf(ltmp, "200:");
    // printf( "[%d]-%s-%ld\n", __LINE__, phone, strlen(phone));
    list_for_each_entry(btmp, &blist->head, head)
    {

        if (strncmp(phone, btmp->phone, strlen(btmp->phone)) == 0)
        {
            list_for_each_entry(ftmp, &flist->head, head)
            {

                if (strncmp(btmp->flight_number, ftmp->flight_number, strlen(btmp->flight_number)) == 0)
                {
                    bzero(lsmg, 256);
                    sprintf(lsmg, "%s,%s,%s,%s,%c,%s,%u,%u\n", ftmp->flight_number, ftmp->Starting,
                            ftmp->destin, ftmp->Address, ftmp->ftype, ftmp->boardingTime, ftmp->price, btmp->flags);

                    // printf( "[%d]-%s\n", __LINE__, lsmg);
                    strncat(ltmp, lsmg, strlen(lsmg));
                }
            }
        }
    }
    // printf( "[%d]-%s\n", __LINE__, ltmp);
    if (send(c_list->confd, ltmp, 25600, 0) <= 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
    {
        flag = -1;
        printf(" %d->msg send failed\n", __LINE__);
    }

    if (flag < 0)
    {
        char lsmg[128] = "404:get failed";
        printf("[%d]%s\n", __LINE__, lsmg);
        if (send(c_list->confd, lsmg, slen, 0) > 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send success\n", __LINE__);
        }
    }
    free(ltmp);
    return 0;
}

int refunded(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");

    int flag = 0;
    char *flnum = strtok(p + 1, ",");
    printf("[%d]-%s\n", __LINE__, p + 1);
    char *fltime = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");

    if (flnum == NULL || fltime == NULL || phone == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    f_list ftmp, flist;
    u_list utmp, ulist;
    flist = c_list->flist;
    ulist = c_list->ulist;
    bfn_list btmp, blist;
    blist = c_list->blist;
    if (c_list->flist == NULL)
    {
        printf("[%d] null \n", __LINE__);
    }

    if (flag != -1)
    {
        list_for_each_entry(btmp, &blist->head, head)
        {
            if (strncmp(btmp->flight_number, flnum, strlen(btmp->flight_number)) == 0 && strncmp(btmp->phone, phone, strlen(btmp->phone)) == 0)
            {
                flag = 1;
                break;
            }
        }
    }

    int slen = 256;
    if (flag == 1)
    {
        list_for_each_entry(ftmp, &flist->head, head)
        {

            if (strncmp(flnum, ftmp->flight_number, strlen(ftmp->flight_number)) == 0 && strncmp(fltime, ftmp->Address, strlen(ftmp->Address)) == 0)
            {
                pthread_mutex_lock(&blist->m); // lock
                list_del(&btmp->head);
                pthread_mutex_unlock(&blist->m);
                free(btmp);

                char tapath[128];
                bzero(tapath, 128);

                pthread_mutex_lock(&blist->m);
                sprintf(tapath, "data/buy_flight_db%d.txt", urand(3));
                if (file_copy("data/buy_flight_db.txt", tapath) == 0)
                    printf("[%d]=>\n", __LINE__);
                pthread_mutex_unlock(&blist->m);

                pthread_mutex_lock(&flist->m);
                bzero(tapath, 128);
                sprintf(tapath, "data/flight_info%d.txt", urand(3));
                if (file_copy("data/flight_info.txt", tapath) == 0)
                    ftmp->surplusVote++;
                pthread_mutex_unlock(&flist->m);

                pthread_mutex_lock(&ulist->m);
                bzero(tapath, 128);
                sprintf(tapath, "data/user_db%d.txt", urand(3));
                if (file_copy("data/user_db.txt", tapath) == 0)
                {
                    list_for_each_entry(utmp, &ulist->head, head) // 用户表的余额减少买票钱
                    {
                        if (strncmp(phone, utmp->phone, strlen(utmp->phone)) == 0)
                        {
                            // printf( "%d=>%s\n", __LINE__, btmp->phone);
                            utmp->account += ftmp->price;
                        }
                    }
                }
                pthread_mutex_unlock(&ulist->m);

                char lsmg[128] = {0};
                sprintf(lsmg, "200:%s", "refunded success");
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>refunded success msg send failed\n", __LINE__);
                }

                put_flight_info(flist);
                put_user_db(ulist);
                put_buy_flight_db(blist);
            }
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:login failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    return 0;
}

int change_userinfo(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    printf("[%d]%s\n", __LINE__, p + 1);
    int flag = 0;

    char *oldphone = strtok(p + 1, ",");
    char *oldname = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");
    char *name = strtok(NULL, ",");

    if (oldphone == NULL || oldname == NULL)
        flag = -1;

    // printf( "[%d]flag:%d flag,%s,%s\n", __LINE__, flag, money, phone);
    u_list utmp, ulist;
    bfn_list btmp, blist;
    ulist = c_list->ulist;
    blist = c_list->blist;

    int slen = 256;
    if (flag != -1)
    {
        if (strlen(phone) <= 0)
        {
            strncpy(phone, oldphone, strlen(oldphone));
        }

        if (strlen(name) <= 0)
        {
            strncpy(name, oldname, strlen(oldname));
        }
        printf("[%d]%s-%s\n", __LINE__, phone, name);
        list_for_each_entry(utmp, &ulist->head, head)
        {
            if (strncmp(oldphone, utmp->phone, strlen(utmp->phone)) == 0 && strncmp(oldname, utmp->name, strlen(utmp->name)) == 0)
            {
                char tapath[128];
                bzero(tapath, 128);
                sprintf(tapath, "data/user_db%d.txt", urand(3));
                pthread_mutex_lock(&ulist->m);
                if (file_copy("data/user_db.txt", tapath) == 0)
                {
                    strncpy(utmp->phone, phone, sizeof(utmp->phone));
                    strncpy(utmp->name, name, sizeof(utmp->name));
                    printf("%d=>%ld\n", __LINE__, sizeof(utmp->phone));
                }
                pthread_mutex_unlock(&ulist->m);
                flag = 1;

                char lsmg[128];
                sprintf(lsmg, "200:%s,%s", utmp->phone, utmp->name);
                printf("[%d]%s\n", __LINE__, lsmg);
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>success msg send failed\n", __LINE__);
                }
                break;
            }
        }
        list_for_each_entry(btmp, &blist->head, head)
        {
            if (strncmp(oldphone, btmp->phone, strlen(btmp->phone)) == 0)
            {
                char tapath[128];
                bzero(tapath, 128);
                sprintf(tapath, "data/buy_flight_db%d.txt", urand(3));
                pthread_mutex_lock(&blist->m);
                if (file_copy("data/buy_flight_db.txt", tapath) == 0)
                {
                    strncpy(btmp->phone, phone, strlen(btmp->phone));
                    printf("%d=>%ld\n", __LINE__, sizeof(btmp->phone));
                }
                pthread_mutex_unlock(&blist->m);
                break;
            }
        }

        if (flag == 1)
        {
            put_buy_flight_db(blist);
            put_user_db(ulist);
        }

        if (flag == 0 || flag == -1)
        {
            char lsmg[128] = "404:info changed failed";
            printf("[%d]%s\n", __LINE__, utmp->password);
            if (send(c_list->confd, lsmg, slen, 0) <= 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
            {
                printf("%d=>failed msg send failed\n", __LINE__);
            }
        }
    }
    return 0;
}

int draw_bill(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");

    int flag = 0;
    char *flnum = strtok(p + 1, ",");
    printf("[%d]-%s\n", __LINE__, p + 1);
    char *fltime = strtok(NULL, ",");

    if (flnum == NULL || fltime == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    f_list ftmp, flist;
    bfn_list btmp, blist;
    blist = c_list->blist;
    flist = c_list->flist;
    if (c_list->flist == NULL)
    {
        printf("[%d] null \n", __LINE__);
    }

    int slen = 256;
    if (flag != -1)
    {
        list_for_each_entry(ftmp, &flist->head, head)
        {
            if (strncmp(ftmp->flight_number, flnum, strlen(ftmp->flight_number)) == 0 && strncmp(ftmp->Address, fltime, strlen(ftmp->Address)) == 0)
            {
                break;
            }
        }
        list_for_each_entry(btmp, &blist->head, head)
        {
            if (strncmp(btmp->flight_number, flnum, strlen(btmp->flight_number)) == 0 && strncmp(btmp->Address, fltime, strlen(btmp->Address)) == 0)
            {

                if (btmp->flags >= 1) //如果是1就是已经出过票
                    break;
                char tapath[128];
                bzero(tapath, 128);

                pthread_mutex_lock(&blist->m);
                sprintf(tapath, "data/buy_flight_db%d.txt", urand(3));
                if (file_copy("data/buy_flight_db.txt", tapath) == 0)
                    btmp->flags += 1; // 出票加1
                pthread_mutex_unlock(&blist->m);

                char lsmg[128] = {0};
                sprintf(lsmg, "200:%s,%s,%s,%s,%s,%u\n", btmp->flight_number, ftmp->Starting, ftmp->destin, btmp->Address, ftmp->boardingTime, btmp->flags);
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>refunded success msg send failed\n", __LINE__);
                }

                put_buy_flight_db(blist);
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:login failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    return 0;
}

int print_invoice(char *buf, cp_list c_list)
{
    char *p = strstr(buf, ":");
    printf("[%d]-%s\n", __LINE__, buf);
    int flag = 0;
    char *flnum = strtok(p + 1, ",");

    char *fltime = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");

    if (flnum == NULL || fltime == NULL || phone == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    bfn_list btmp, blist;
    blist = c_list->blist;
    if (c_list->blist == NULL)
    {
        printf("[%d] null \n", __LINE__);
    }

    int slen = 256;
    if (flag != -1)
    {

        list_for_each_entry(btmp, &blist->head, head)
        {
            printf("[%d] %s %s\n", __LINE__, btmp->phone, phone);
            if (strncmp(btmp->flight_number, flnum, strlen(btmp->flight_number)) == 0 && strncmp(btmp->Address, fltime, strlen(btmp->Address)) == 0 && strncmp(btmp->phone, phone, strlen(btmp->phone)) == 0)
            {
                char tapath[128];
                bzero(tapath, 128);

                if (btmp->flags < 1 && btmp->flags >= 2) //ru如果是2或是3就是已经打印过发票
                    break;

                pthread_mutex_lock(&blist->m);
                sprintf(tapath, "data/buy_flight_db%d.txt", urand(3));
                if (file_copy("data/buy_flight_db.txt", tapath) == 0)
                    btmp->flags += 1; // 出票加1
                pthread_mutex_unlock(&blist->m);

                char lsmg[128] = {0};
                sprintf(lsmg, "200:%s,%u,%u\n", btmp->flight_number, btmp->price, btmp->flags);
                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    printf("%d=>refunded success msg send failed\n", __LINE__);
                }

                put_buy_flight_db(blist);
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0 || flag == -1)
    {
        char lsmg[128] = "404:print invoice failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
    }
    return 0;
}

int logout(char *buf, cp_list c_list)
{

    char *p = strstr(buf, ":");

    int flag = 0;
    char *name = strtok(p + 1, ",");
    char *phone = strtok(NULL, ",");
    if (phone == NULL || name == NULL)
    {
        flag = -1;
        printf("[%d]%s\n", __LINE__, p + 1);
    }

    u_list utmp, ulist;
    ulist = c_list->ulist;

    int slen = 256;
    if (flag != -1)
    {
        list_for_each_entry(utmp, &ulist->head, head)
        {
            if (strncmp(name, utmp->name, strlen(utmp->name)) == 0 && strncmp(phone, utmp->phone, strlen(utmp->phone)) == 0)
            {
                // printf( "[%d]%s,%s\n", __LINE__, phone, utmp->phone);
                char tapath[128];
                bzero(tapath, 128);
                sprintf(tapath, "data/user_db%d.txt", urand(3));
                if (file_copy("data/user_db.txt", tapath) == 0)
                    ;
                // strncpy(utmp->password, password, 20);
                flag = 1;
                utmp->status = 0;
                char lsmg[128];
                sprintf(lsmg, "200:logout success ");

                if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
                {
                    flag = 1;
                    printf("%d=>success msg send failed\n", __LINE__);
                }
                break;
            }
        }
        if (flag == 1)
        {
            put_user_db(ulist);
            return 0;
        }
    }

    if (flag == 0 || flag != -1)
    {
        char lsmg[128] = "404:logout failed";
        if (send(c_list->confd, lsmg, slen, 0) < 0) //传入的链表不是头节点,而是使用节点,其confd有当前的连接id
        {
            printf("%d=>failed msg send failed\n", __LINE__);
        }
        return -1;
    }
    return 0;
}
