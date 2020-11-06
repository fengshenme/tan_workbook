#include <stdio.h>

#define SEQ_LEN 10

// 显示顺序表(Sequence table)
// n表示数据下标
int seq_show(int *p, int n);
// 插入到数据到顺序表中
void seq_add(int new_data, int *p, int *n);
// 从顺序表中删除数据
void seq_del(int del_data, int *p, int *n);

// 插入到数据到顺序表中(有序插入)
void seq_add_ans(int new_data, int *p, int *n);

int main(void)
{
    // 1.初始化顺序表
    // A.定义一个数组，用于存储数据（数据域）
    int arr[10] = {0};
    // B.定义一个整型变量，用于存储最后一个数据的下标（下标域）
    int i = -1; // -1表示当前无数据

    // 2.操作顺序表
    int num; //num用来记录用户输入的数字
    while (1)
    {
        fprintf(stderr, "Pls Input: ");
        scanf("%d", &num);
        while (getchar() != '\n')
            ;

        if (num > 0)
        {
            // 2.1 增加该数据到顺序表中
            // seq_add(num, arr, &i);
            seq_add_ans(num, arr, &i);
        }
        else if (num < 0)
        {
            // 2.2 从顺序表中删除该数据的绝对值
            seq_del(-num, arr, &i);
        }
        else
        {
            // 2.3 退出程序
            printf("ByeBye~\n");
            return 0;
        }
        // 2.4 显示顺序表中的数据
        seq_show(arr, i);
    }

    return 0;
}

// 插入到数据到顺序表中(有序插入)
void seq_add_ans(int new_data, int *p, int *n)
{
    // 1.判断顺序表是否已满
    // 1.判断顺序表是否已满？
    if (*n == SEQ_LEN - 1)
    {
        printf("Full!\n");
        return;
    }
    // 2.遍历顺序表，找出比新数据更大的数，记录下标
    int i;
    for (i = 0; i <= *n; i++)
    {
        if (p[i] > new_data)
        {
            break;
        }
    }

    // 3.下标以后的数据全部往后挪动（从最后一个数据开始）
    int j;
    for (j = *n; j > i; j--)
    {
          p[j+1] = p[j];
    }
    

    // 4.将新数据写入到指定下标
    p[i] = new_data;
    // 5.下标域++
    (*n)++;
}

// 数据的显示
int seq_show(int *p, int n)
{
    printf("======DATA=====\n");
    int i;
    for (i = 0; i <= n; i++) // 0 ~ n
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}

// 数据的添加
void seq_add(int new_data, int *p, int *n)
{
    // 1.判断顺序表是否已满？
    if (*n == SEQ_LEN - 1)
    {
        printf("Full!\n");
        return;
    }

    // 2.将数据写入到顺序表中
    // （写入位置：下标域+1）
    p[*n + 1] = new_data;

    // 3.下标域++
    (*n)++;
}

// 从顺序表中删除数据
void seq_del(int del_data, int *p, int *n)
{
    // 1.判断顺序表是否为空？
    // （判断下标域不等于-1）
    if (*n == -1)
    {
        printf("Empty!\n");
        return;
    }

    // 2.遍历顺序表，对比欲删除的数据，记录下标
    int i;
    for (i = 0; i <= *n; i++)
    {
        if (p[i] == del_data)
            break;
    }
    // 2.1 如果遍历完毕都没有找到（上述循环没有提前跳出）
    if (i == *n + 1)
        return;

    // 3.根据这个下标，将后面的数据往前覆盖，直到下标域。

    // 假设 *n:4	i:1
    // p[1] = p[2];
    // p[2] = p[3];
    // p[3] = p[4];
    // for(j=1; j<4; j++)

    int j;
    for (j = i; j < *n; j++)
        p[j] = p[j + 1];

    // 4.下标域--
    (*n)--;
}
