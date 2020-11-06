#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//2.使用系统IO实现文件复制功能。
int main(int argc, char const *argv[])
{
    if (argc != 3) // 输入两个参数，用法类似于 Shell 命令：cp file1 file2 16
    {
        printf("Usage: %s <src> <dst>\n", argv[0]);
        exit(1);
    }
    //1.只读打开源文件
    int fsrc = open(argv[1], O_RDONLY);
    if (fsrc == -1)
    {
        perror("src file open failed!");
        return 0;
    }

    // 2.只写创建目标文件
    int fdes = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
    if (fsrc == -1)
    {
        perror("dest file open failed!");
        return 0;
    }
    // 3.读取源文件
    // 定义一个 stat 结构体 info，查询指定文件的属性;
    struct stat info;
    stat(argv[1], &info);
    int fsize = info.st_size;
    char src_str[fsize];
    read(fsrc, src_str, fsize);
    // 4.写入到目标文件
    write(fdes, src_str, fsize);

    close(fsrc);
    close(fdes);
    return 0;
}
