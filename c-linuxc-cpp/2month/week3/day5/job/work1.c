#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TEXTSIZE 50

#define JACK 10

// 定义的消息结构体
struct mybuf
{
    long mtype;
    char mtext[TEXTSIZE];
};

static int gl_int ;
void *get(void *smgid);
void *put(void *smgid);

int main(int argc, char const *argv[])
{
    key_t key = ftok(".", 10);

    int smgid = msgget(key, IPC_CREAT | 0666);

    pthread_t get_tid, put_tid;
    int ret = pthread_create(&put_tid, NULL, put, (void *)&smgid);
    if (ret == 0)
    {
        printf("put pthread create success!\n");
    }
    if ((pthread_create(&get_tid, NULL, get, (void *)&smgid)) == 0)
    {
        printf("get pthread create success!\n");
    }

    void *rev = NULL;
    if ((pthread_join(put_tid, rev)) == 0)
    {
        printf("pthread_join success!\n");
    }
    

    msgctl(smgid, IPC_RMID, NULL); //删除消息队列
    printf("%d \n", gl_int);

    if ((pthread_join(get_tid, rev)) == 0)
    {
        printf("pthread_join success!\n");
    }
    return 0;
}

void *put(void *smgid)
{
    struct mybuf w_buf;
    while (1)
    {
        // 清空
        bzero(&w_buf, sizeof(w_buf));
        // 从键盘获取数据
        fgets(w_buf.mtext, TEXTSIZE, stdin);

        // 写入数据
        w_buf.mtype = JACK;
        msgsnd(*(int *)smgid, &w_buf, TEXTSIZE, IPC_NOWAIT);

        //退出
        if (strncmp("quit\n", w_buf.mtext, sizeof(w_buf.mtext)) == 0)
        {
            gl_int = 1100;   //测试用
            pthread_exit(&gl_int);
        }
    }
}

void *get(void *smgid)
{
    struct mybuf r_buf;

    while (1)
    {
        sleep(1);
        // 读取数据
        bzero(&r_buf, sizeof(r_buf));
        msgrcv(*(int *)smgid, &r_buf, sizeof(r_buf.mtext), JACK, IPC_NOWAIT);
        if (strlen(r_buf.mtext) > 0)
        {
            printf("%s", r_buf.mtext);
        }

        if (strncmp("quit\n", r_buf.mtext, sizeof(r_buf.mtext)) == 0)
        {
            break;
        }
    }

}