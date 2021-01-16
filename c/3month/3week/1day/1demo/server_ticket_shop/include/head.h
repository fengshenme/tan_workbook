#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>

#include <linux/fb.h>
#include <linux/input.h>

#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

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

#include <string.h>

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

typedef struct flightNode
{
    char flight_number[20];   // 航班号
    char Starting[20];        // 出发地
    char destin[20];          // 目的地
    char Address[10];         // 班期
    char type;                // 机型
    char boardingTime[10];    //登机时间
    unsigned int price;       // 机票价格
    unsigned int surplusVote; // 剩余票

    pthread_mutex_t m;
    struct list_head head; // 内核链表

} * f_list, f_node;

typedef struct buy_flight_node
{
    char phone[13];    //购买人手机号
    char flight_number[10]; // 航班号
    char Address[10];       // 班期
    unsigned int price;     // 机票价格

    unsigned short flags;  //  已出票,1 已打印发票是2, 未出票未打印发票为0,已出票已打印发票为3
    pthread_mutex_t m;
    struct list_head head; // 内核链表

}  *bfn_list, bfn;


typedef struct cl_node
{
    char msg[256]; // 要发送的消息
    char ip[20];
    int so_fd; // 未连接的套接字文件描述符
    int confd; // 连接的套接字文件描述符
    pthread_mutex_t m;
    struct list_head head; // 内核链表

    struct flightNode *flist;
    struct userNode *ulist;
    struct buy_flight_node *blist;

} c_node, *cp_list;

void *read_msg(void *arg);           // 线程函数
void handler(void *arg);             //线程取消时执行的函数
int init_sock(const char *str_port); // Initializing connection
int add_thread(int so_fd, cp_list c_list);
int regist_s(char *buf, cp_list c_list);          // Registered function
int login(char *buf, cp_list c_list);             // login function
int repassword(char *buf, cp_list c_list);        // Fill set password
int flight_list(char *buf, cp_list c_list);       // 航班列表
int search_flight(char *buf, cp_list c_list);     // 条件查询
int search_quick(char *buf, cp_list c_list);      // quick search
int recharge(char *buf, cp_list c_list);          // 充值账户
int urand(int n);                                 // 生成0-n之间的一个随机数
int s_booking_flights(char *buf, cp_list c_list); // 购买航班服务端
int balance_inquiry(char *buf, cp_list c_list);   // 余额查询
int find_buyed_flight(char *buf, cp_list c_list); // 查询已购票
int refunded(char *buf, cp_list c_list);          // 退票

int put_flight_info(f_list flist);     // flight_info数据更新
int put_buy_flight_db(bfn_list blist); // buy_flight_db数据更新
int put_user_db(u_list ulist);         //user_bd数据更新

int change_userinfo(char *buf, cp_list c_list); //修改用户信息
int draw_bill(char *buf, cp_list c_list);       //出票
int print_invoice(char *buf, cp_list c_list);   //打印发票
int logout(char *buf, cp_list c_list);

int load_user(u_list list_u);
int load_ticket(f_list list_f);
int load_buy_bill(bfn_list blist);

FILE *open_file(const char *path);
int file_copy(char *src, char *des);

#endif