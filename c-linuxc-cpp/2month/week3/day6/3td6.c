/**
 * @file 1td6.c
 * @author tan wei feng (1015956962@163.com)
 * @brief  使用共享内存，实现1td6给2td6发送数据，
 * 要求2td6每隔1s就打印一次共享内存上的数据。如果1td6给2td6发送了quit，
 * 大家就退出。这是发送端
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
    char *w_buf = NULL;

    // 对共享内存进行映射
    w_buf = shmat(shmid, NULL, 0);
    if (w_buf == NULL)
        printf("Memory mapping failed!\n");

    // 获取信号量的id 使用两个信号量元素，来分别表示“内存空间”和“数据”这两种资源， 在刚开始的时候，“内存空间”的可用数目是 1（假设将整块 SHM 当做一个资源），而“数 据”的可用数据是 0（刚开始啥也没有）
    int semid = semget(eid, 2, IPC_CREAT | 0666);

    seminit(semid, 0, 0); // 将第 0 个元素初始化为 0，代表数据
    seminit(semid, 1, 1); // 将第 1 个元素初始化为 1，代表空间

    while (1)
    {

        sem_p(semid, 1); // 向第 1 个信号量元素申请内存空间资源

        // 从键盘读取数据存入共享内存
        fgets(w_buf, TEXTSIZE, stdin);
        //打印输出值

        sem_v(semid, 0); // 增加代表数据资源的第0个信号量元素的值

        if (strncmp(w_buf, "quit\n", 5) == 0)
        {
            break;
        }
    }

    // 解除映射
    shmdt(w_buf);

    return 0;
}
