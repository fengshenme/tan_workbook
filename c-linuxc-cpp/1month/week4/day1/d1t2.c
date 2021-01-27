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
        return 1;
    }

    // 2.只写创建目标文件
    int fdes = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fsrc == -1)
    {
        perror("dest file open failed!");
        return 2;
    }
    // 3.读取源文件
    // 定义一个 stat 结构体 info，查询指定文件的属性;
    struct stat info;
    stat(argv[1], &info);
    int fsize = info.st_size; // 获得文件大小
    printf("file size: %d\n", fsize);
    char r_buf[5];
    int n_read = 0, count = 0, tmp=0, tmp_a =0 ;

    while (1)
    {
        bzero(r_buf, sizeof(r_buf));
        n_read = read(fsrc, r_buf, sizeof(r_buf));
        if (n_read == 0)
        {
            printf("\n");
            printf("Done\n");
            break;
        }
        // 求出已读取字节数
        count += n_read;
        // 换算出0-100区间的进度数
        tmp = count*100 / fsize ;
        // 3.每隔百分之十进度显示 
        if (tmp >= tmp_a )
        {
            tmp_a+=10;
            printf("%d ", tmp);
        }

        // 4.写入到目标文件
        write(fdes, r_buf, n_read);
    }

    close(fsrc);
    close(fdes);
    return 0;
}
