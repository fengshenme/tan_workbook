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

#include <errno.h>

#include <sys/ipc.h>
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

#include <string.h>

#include "list.h"
#include "sqlite3.h"

#define UNSIZE (sizeof(struct userNode))

#define LOGIN 50001
#define REGIST 50002
#define FLIGHTLIST 50003
#define ADMINLOGIN 50004
#define SELECTF 50005
#define REPASS 50006
#define SELECTQ 50007
#define RECHARG 50008
#define FINDACC 50009
#define BUYFLIGHT 50010

typedef struct userNode
{
    char id[13];             //实际用12位ID号加一个'\0'一共12个字节
    char name[20];           // 用户名
    char password[20];       // 密码
    char phone[13];          //手机号
    short status;            // 0是未登录下线状态, 1是登录状态
    int account;             // 账户余额
    unsigned short vipclass; //vip等级

    unsigned short cmd;  // 状态码
    unsigned short code; // 短信验证码

    char msg[128];

    pthread_mutex_t m; // 锁的钥匙

    struct list_head head; // 内核链表

} * u_list, u_node;

typedef struct flightNode
{
    char id[20];              //实际用12位ID号加一个'\0'一共12个字节
    char flight_number[20];   // 航班号
    char Starting[20];        // 出发地
    char destin[20];          // 目的地
    char Address[10];         // 班期
    char ftype;               // 机型
    char boardingTime[10];    //登机时间
    unsigned int price;       // 机票价格
    unsigned int surplusVote; // 剩余票

    unsigned short flags; // 用来进行逻辑删除
    unsigned short cmd;   // 状态码

    pthread_mutex_t m;
    struct list_head head; // 内核链表

} * f_list, f_node;

typedef struct buy_flight_node
{
    char id[13];
    char flight_id[13];
    char user_id[13];

    unsigned short flags; //  已出票,1  未出票未打印发票为0,已出票已打印发票为2

    pthread_mutex_t m;
    struct list_head head; // 内核链表

} * bfn_list, bfn, b_node, *b_list;

typedef struct cl_node
{
    char msg[256]; // 要发送的消息
    char ip[20];
    int so_fd; // 未连接的套接字文件描述符
    int confd; // 连接的套接字文件描述符
    pthread_mutex_t m;
    struct list_head head; // 内核链表

    sqlite3 *pdb;
    struct flightNode *flist;
    struct userNode *ulist;
    struct buy_flight_node *blist;

} c_node, *cp_list;

void *read_msg(void *arg);           // 线程函数
void handler(void *arg);             //线程取消时执行的函数
int init_sock(const char *str_port); // Initializing connection
int add_thread(int so_fd, cp_list c_list);
int regist_s(u_node *unode, cp_list c_list);    // Registered function
int login(u_node *unode, cp_list c_list);       // login function
int repassword(u_node *unode, cp_list c_list);  // Fill set password
int flight_list(u_node *unode, cp_list c_list); // 航班列表
int search_flight(char *buf, cp_list c_list);   // 条件查询
int search_quick(char *buf, cp_list c_list);    // quick search
int recharge(u_node *unode, cp_list c_list);    // 充值账户
int urand(int n);                               // 生成0-n之间的一个随机数
int uranda(int max, int min);
int s_booking_flights(u_node *unode, cp_list c_list); // 购买航班服务端
int balance_inquiry(u_node *unode, cp_list c_list);   // 余额查询
int find_buyed_flight(char *buf, cp_list c_list);     // 查询已购票
int refunded(char *buf, cp_list c_list);              // 退票

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

int sql_load_user(sqlite3 *db, u_list list_u);
int sql_load_ticket(sqlite3 *db, f_list list_f);


FILE *open_file(const char *path);
int file_copy(char *src, char *des);

sqlite3 *InitDataBase(); //初始化数据库

int add_user(u_node *c, sqlite3 *ppdb);         //增加用户
int sqladd_flight(f_node *f, sqlite3 *db);      // 增加航班
int sql_buy_flight(sqlite3 *db, b_node *bnode); // 增加购买航班的信息

int updata_user(u_node *c, sqlite3 *db);        //更新一个用户账号信息
int sql_recharge(u_node *c, sqlite3 *db);       //更新用户余额
int sql_update_account(u_node *c, sqlite3 *db); //购票后减少余额

int delete_user(sqlite3 *ppdb, char *id); //删除一个用户

int sql_login(sqlite3 *ppdb, u_node *unode);         //登录验证
int sqlrepass(sqlite3 *db, u_node *unode);           //重置密码
int sql_balance_inquiry(sqlite3 *db, u_node *unode); // 充值

int  sql_find_user_all(sqlite3 *ppdb, u_list ulist);        // 查找全部用户
int sql_find_fli_all(sqlite3 *ppdb, f_list flist); // 查找所有航班
int sql_find_flght_one(sqlite3 *db, f_node *fnode);

void show_u_list(u_list ulist);   // 显示所有用户信息,并清空列表
void show_f_list(f_list flist); // 显示所有航班信息,并清空列表

#endif