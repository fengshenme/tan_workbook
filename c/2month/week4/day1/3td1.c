#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *fun(void *arg)
{
    // 设置分离属性
    pthread_detach(pthread_self());
    int i;
    for (i = 0; i < 6; i++)
    {
        printf("pthread \n");
        sleep(1);
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

    if (pthread_join(tid, NULL) != 0)
    {
        printf("join error\n");
    }

    return 0;
}
