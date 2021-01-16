#include <stdio.h>
#include <string.h>
#include <signal.h>

// 定义一个信号集，然后清空，再将SIGUSR1加入到集合中，判断这个信号在不在集合中。
int main(int argc, char const *argv[])
{
    sigset_t set;             //定义一个信号集
    sigemptyset(&set);        // 然后清空
    sigaddset(&set, SIGUSR1); // SIGUSR1加入到集合中

    if (sigismember(&set, SIGUSR1) == 1) //判断这个信号在不在集合中。
    {
        printf("sign exist\n");
    }

    return 0;
}
