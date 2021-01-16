/**
 * @file 5td6.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 在进程内部创建一个新的子进程，看看会不会同时执行两件事情
 * @version 0.1
 * @date 2020-11-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    pid_t x = fork();

    while (1)
    {
        sleep(2);
        if (x > 0)
        {
            printf("parent message! \n");
            printf("pid: %d, %d, %#x  \n", getpid(), getppid(), getppid());
        }

        if (x == 0)
        {
            printf("child message \n");
        }
    }

    return 0;
}
