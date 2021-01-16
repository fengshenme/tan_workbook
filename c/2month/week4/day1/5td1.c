#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *fun(void *arg)
{
    // 设置分离属性就不能阻塞
    // pthread_detach(pthread_self());
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    int i;
    for (i = 0; i < 7; i++)
    {

        sleep(1);
        printf("pthread %d \n", i);
        if (i == 4)
        {
            pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    //线程id
    pthread_t tid; //= ;
    //创建线程
    pthread_create(&tid, NULL, fun, NULL);

    sleep(2);

    pthread_cancel(tid);

    pthread_join(tid, NULL);

    //  sleep(8);

    return 0;
}
