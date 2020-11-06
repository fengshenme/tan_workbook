#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define TEXTSIZE 50
#define JACK 10
#define ROSE 11

struct mybuf
{
    long mtype;
    char mtext[TEXTSIZE];
};

int main(int argc, char const *argv[])
{
    key_t key = ftok(".", 10);

    int smgid = msgget(key, IPC_CREAT | 0666);

    struct mybuf r_buf, w_buf;

    int flag = 1;


        while (flag)
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
                flag = 0;
            }
        }
        msgctl(smgid, IPC_RMID, NULL); //删除消息队列


    return 0;
}
