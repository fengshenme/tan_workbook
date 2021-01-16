#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>

#define J2R 10
#define R2J 11
#define TEXTSIZE 50

struct buf
{
    long mtype;
    char mtext[TEXTSIZE];
};

int main(int argc, char const *argv[])
{
    // 1.创建消息队列key值
    key_t key;
    key = ftok(".", 10);

    // 2.根据key值去申请id号
    int msgid;
    msgid = msgget(key, IPC_CREAT | 0666);

    struct buf r_buf, w_buf;
    // 3. 带着这条队列去产生一个子进程
    pid_t x;
    x = fork();
    if (x > 0)
    {
        bzero(&w_buf, sizeof(w_buf));

        fgets(w_buf.mtext, TEXTSIZE, stdin);

        w_buf.mtype = J2R;
        int ret = msgsnd(msgid, &w_buf, sizeof(w_buf.mtext), IPC_NOWAIT);
        if (ret == -1)
        {
            exit(-1);
        }
        
    }

    return 0;
}
