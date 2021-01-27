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
    char phone[11];    //手机号
    char status;   // 0是未登录下线状态, 1是登录状态

    pthread_mutex_t m;
    struct list_head head; // 内核链表

} * u_list, u_node;

typedef struct flightNode
{
    char flight_number[20]; // 航班号
    char Starting[20];      // 出发地
    char destin[20];        // 目的地
    char Address[10];       // 班期
    char type;           // 机型
    char boardingTime[10];  //登机时间
    unsigned int price;              // 机票价格
    unsigned int surplusVote;        // 剩余票

    pthread_mutex_t m;
    struct list_head head; // 内核链表

} * f_list, f_node;

int load_user(u_list list_u);
int load_ticket(f_list list_f);
FILE * open_file( const char *path);
int file_copy(char *src, char *des);

#endif