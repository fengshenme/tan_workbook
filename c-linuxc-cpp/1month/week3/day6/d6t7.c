#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) // 输入两个参数，用法类似于 Shell 命令：cp file1 file2 16
    {
        printf("Usage: %s <src> \n", argv[0]);
        exit(1);
    }
    struct stat info;
     stat(argv[1], &info);
     int fsize = info.st_size;
     printf("%d\n", fsize);
    return 0;
}
