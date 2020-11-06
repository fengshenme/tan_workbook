#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert_num(int *count, int *arr, int num);
void del_num(int *count, int *arr, int num);
void show(int *arr, int count);
void sort(int *arr, int count);

/**
* // 你好
* ! 警告
* * 突出显示
* TODO  待办事项
* ? 查询
1.编写一个顺序表的操作代码（数组：int arr[10]）
scanf输入一个正数n，写入n到数组中
负数-n，将对应的n删除。
每次输入操作后，将数组中的元素打印出来。（不打印0）
6	7	8	0	0	0	0	0	0	0
打印678
当输入-7时，打印 68		
（写入时需判断是否已满、删除时判断是否已空）
*/
int main(int argc, char const *argv[])
{

    int arr[10], num, count = 1;
    bzero(arr, 10 * sizeof(int));
    // 1.循环输入
    while (1)
    {
        // 添加入数组
        scanf("%d", &num);
        while (getchar() != '\n')
            ;
        // 判断是否已满, 判断是否已空
        if (count <= 10 && num > 0)
            insert_num(&count, arr, num);
        else if (num < 0)
            del_num(&count, arr, num);
        else if (num == 0)
            exit(0);
        else if (count > 10)
            printf("数组已满\n");
        else if (count <= 1)
            printf("数组已空\n");
    }
    return 0;
}

void insert_num(int *count, int *arr, int num)
{
    int i; // 1 2 3
    for (i = 0; i < *count; i++)
    {

        if (arr[i] == 0)
            arr[i] = num;
    }
    (*count)++;
    sort(arr, *count);
    show(arr, *count);
}


void del_num(int *count, int *arr, int num)
{
    int j;
    for (j = 0; j < *count; j++)
    {
        if (arr[j] == -num)
        {
            arr[j] = 0;
            (*count)--;
            int k;
            for (k = j; k < *count; k++)
            {
                if (k == 9)
                    arr[k] = 0;
                else
                    arr[k] = arr[k + 1];
            }
        }
    }
    sort(arr, *count);
    show(arr, *count);
}

void sort(int *arr, int count)
{
    int tmp, i, j;
    for (i = 0; i < count-1; i++)
    {
        for (j = 0; j < count-1-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void show(int *arr, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (arr[i] != 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
    
}