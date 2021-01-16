#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>

#define TEXTSIZE 50

union semun //自定义的信号量操作联合体
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};

/**
 * @brief 信号量初始化
 * 
 * @param semid 信号量 ID
 * @param semnum 信号量元素序号（数组下标）
 * @param value 当 cmd 为 IPC_INFO 时使用
 */
void seminit(int semid, int semnum, int value) // 
{
    union semun a;
    a.val = value;
    semctl(semid, semnum, SETVAL, a);
}

/**
 * @brief //p操作 减操作
 * 
 * @param semid 信号量 ID
 * @param semnum 信号量元素序号（数组下标）
 */
static void sem_p(int semid, int semnum) 
{
    struct sembuf op;
    op.sem_num = semnum;
    op.sem_op = -1;
    op.sem_flg = 0;

    semop(semid, &op, 1);
}

/**
 * @brief v操作 加操作
 * 
 * @param semid 信号量 ID
 * @param semnum 信号量元素序号（数组下标）
 */
static void sem_v(int semid, int semnum) 
{
    struct sembuf op;
    op.sem_num = semnum;
    op.sem_op = 1;
    op.sem_flg = 0;

    semop(semid, &op, 1);
}

