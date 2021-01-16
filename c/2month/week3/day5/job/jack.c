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
#define ROSE 11

struct mybuf
{
    long mtype;
    char mtext[TEXTSIZE];
};

void *send(void *arg);

int main(int argc, char const *argv[])
{
    key_t key = ftok(".", 10);

    int smgid = msgget(key, IPC_CREAT | 0666);

    pthread_t pid;

    int ret = pthread_create(&pid, NULL, send, (void *)&smgid);
    if (ret == 0)
    {
        printf("pthread create success!\n");
    }

    struct mybuf r_buf;

    while (1)
    {
        // 读取数据
        bzero(&r_buf, sizeof(r_buf));
        msgrcv(smgid, &r_buf, sizeof(r_buf.mtext), ROSE, IPC_NOWAIT);
        if (strlen(r_buf.mtext) > 0)
        {
            printf("%s", r_buf.mtext);
        }
        //退出
        if (strncmp("quit\n", r_buf.mtext, sizeof(r_buf.mtext)) == 0)
        {
            break;
        }
    }
    msgctl(smgid, IPC_RMID, NULL); //删除消息队列
    
    return 0;
}

void *send(void *arg)
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
        msgsnd(*(int *)arg, &w_buf, TEXTSIZE, IPC_NOWAIT);

        //退出
        if (strncmp("quit\n", w_buf.mtext, sizeof(w_buf.mtext)) == 0)
        {
            exit(0);
        }
    }

}