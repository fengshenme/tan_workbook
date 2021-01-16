#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char *path);
//# 2.使用一下 fread函数，分别读取 99/100/101个字节的文件 要求全部读取完毕之后，打印出来。
int main(int argc, char const *argv[])
{
    // 1.打开文件
    FILE *fa;
    FILE *fb;
    FILE *fc;
    fa = open_file("a.txt");
    fb = open_file("b.txt");
    fc = open_file("c.txt");
    // 定义缓冲区指针
    char str_a[99];
    char str_b[100];
    char str_c[101];
    // 从指定文件读取若干个数据块
    fread(str_a, 9, 11, fa);
    fread(str_b, 10, 10, fb);
    fread(str_c, 1, 101, fc);

    //打印出来
    printf("a.txt:%s\n", str_a);
    printf("b.txt:%s\n", str_b);
    printf("c.txt:%s\n", str_c);

    // 关闭文件
    fclose(fa);
    fclose(fb);
    fclose(fc);
    return 0;
}

FILE *open_file(char *path)
{
    FILE *fp = fopen(path, "r"); // 以只读方式打开文件，要求文件必须存在
    if (fp == NULL)
    {
        perror("open file fialed!");
        exit(1);
    }
    return fp;
}