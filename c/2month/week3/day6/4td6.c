/**
 * @file 1td6.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 使用共享内存，实现1td6给2td6发送数据，
 * 要求2td6每隔1s就打印一次共享内存上的数据。如果1td6给2td6发送了quit，
 * 大家就退出。这是读取端
 * 
 * todo 增加信号量 来控制写入读出
 * 
 * @version 0.1
 * @date 2020-11-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "head34.h"

int main(int argc, char const *argv[])
{
    //获取一个当前未使用的ipc的key
    key_t hid = ftok(".", 10);
    key_t eid = ftok(".", 20);
    //获取共享内存的键值, 表示如果key对应的共享内存不存在就创建，且权限指定为 0666，若已存在则直接获取 ID
    int shmid = shmget(hid, 1024 * 2, IPC_CREAT | 0666);

    //映射堆空间
    char *r_buf = NULL;
    // 对共享内存进行映射, 0是读写权限
    r_buf = shmat(shmid, NULL, 0);
    if (r_buf == NULL)
        printf("Memory mapping failed!\n");

    // 获取信号量的id 使用两个信号量元素，来分别表示“内存空间”和“数据”这两种资源， 在刚开始的时候，“内存空间”的可用数目是 1（假设将整块 SHM 当做一个资源），而“数 据”的可用数据是 0（刚开始啥也没有）
    int semid = semget(eid, 2, IPC_CREAT | 0666);

    seminit(semid, 0, 0); // 将第 0 个元素初始化为 0，代表数据
    seminit(semid, 1, 1); // 将第 1 个元素初始化为 1，代表空间

    while (1)
    {
        usleep(10 * 1000);

        sem_p(semid, 0); // 向第 0 个信号量元素申请数据资源
        //打印输出值
        printf("from 1dt6: %s ", r_buf);

        sem_v(semid, 1); // 通知空间已空置

        if (strncmp(r_buf, "quit\n", 5) == 0)
        {
            break;
        }
    }
}
