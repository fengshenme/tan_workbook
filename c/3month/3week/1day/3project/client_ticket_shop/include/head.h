#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#include <sys/stat.h>
#include <stdio.h>
#include <sys/mman.h>

#include <linux/fb.h>
#include <linux/input.h>

#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>

#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <semaphore.h>



#include "list.h"

typedef struct userNode
{
    char name[20];     // 用户名
    char password[20]; // 密码
    char phone[13];    //手机号

    short status;       // 0是未登录下线状态, 1是登录状态

    int account;  // 账户余额
    unsigned short vipclass; //vip等级

    pthread_mutex_t m;

    // struct buy_flight_node *bfp;  //购买的飞机票

    struct list_head head; // 内核链表


} * u_list, u_node;

//边栏
int va(char *ch);
// 首页
int index_t(const char * ip, const char *port);
//登录
int login(int sofd);
// 初始化套接字
int init_sock(const char *ip, const char *port);
// 用户注册
int user_regist(int sofd);
// 用户管理界面
int use_admin(u_node *unode, int sofd);
// 删除字符串中指定字符
int strrep(char *str, char del);
//重置密码
int repassword(int sofd);
// 航班列表
int getflight_list(u_node *unode, int sofd);
// 查询航班
int search_flight(u_node *unode, int sofd);
//打印航班
int show_flight(char (*flight)[256], int i);
// 获取航班信息的公共部分
int get_f(char *buf, char (*flight)[256], int *i);
//快速查询
int quick_searchf(u_node *unode, int sofd);
// 充值账户
int recharge(u_node *unode, int sofd);
// 余额查询
int balance_inquiry(u_node *unode, int sofd);
//购买航班
int booking_flights(u_node *unode, int sofd);
// 已购航班
int find_buyed_flight(u_node *unode, int sofd);
//打印已购航班
int ashow_flight(char (*flight)[256], int i);
// 退票
int refunded(u_node *unode, int sofd);
// 修改用户信息
int change_userinfo(u_node *unode, int sofd);
//出票
int draw_bill(u_node *unode, int sofd);

// 打印发票
int print_invoice(u_node *unode, int sofd);
//退出登录
int logout(u_node *unode, int sofd);


#endif