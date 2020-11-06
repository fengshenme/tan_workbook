#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    pid_t x = fork();
    int i;

    if (x == 0)  // 子进程进行的代码
    {
        for (i = 0; i < 10; i++)
        {
            sleep(1);
            printf("apple! \n");
        }
    }

    if (x > 0) // 父进程进行的代码
    {
        for (i = 0; i < 5; i++)
        {
            sleep(2);
            printf("hello! \n");
        }
    }

    return 0;
}
