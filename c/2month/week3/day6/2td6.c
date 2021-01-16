/**
 * @file 1td6.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 使用共享内存，实现1td6给2td6发送数据，
 * 要求2td6每隔1s就打印一次共享内存上的数据。如果1td6给2td6发送了quit，
 * 大家就退出。这是读取端
 * @version 0.1
 * @date 2020-11-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TEXTSIZE 50

int main(int argc, char const *argv[])
{
    //获取一个当前未使用的ipc的key
    key_t kid = ftok(".", 10);
    //获取共享内存的键值, 表示如果key对应的共享内存不存在就创建，且权限指定为 0666，若已存在则直接获取 ID
    int shmid = shmget(kid, 1024 * 2, IPC_CREAT | 0666);

    //映射堆空间
    char *r_buf = NULL;
    // 对共享内存进行映射, 0是读写权限
    r_buf = shmat(shmid, NULL, 0);
    if (r_buf == NULL)
        printf("Memory mapping failed!\n");

    while (1)
    {

        sleep(1);
        printf("from 1dt6: %s ", r_buf);

        if (strncmp(r_buf, "quit\n", 5) == 0)
        {
            break;
        }
    }
}