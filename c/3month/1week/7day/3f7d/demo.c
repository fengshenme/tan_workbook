#include <stdio.h>


//插入排序
int insertion_sort(int n, int *arr);
//冒泡排序 升序排列
int bubble_ascending_sort(int *arr);
// 降序排列
int bubble_descending_sort(int *arr);



int main(int argc, char const *argv[])
{
    int arr[9] = {1, 5, 8, 2, 3, 9, 7, 6, 4};


    bubble_ascending_sort(arr);
    // insertion_sort(9, arr);
    int i;
    for (i = 0; i < 9; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// 升序排列
int bubble_ascending_sort(int *arr)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        int flag = 0;
        for (j = 0; j < 8; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    return 0;
}

//  降序排列
int bubble_descending_sort(int *arr)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        int flag = 0;
        for (j = 0; j < 8; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    return 0;
}


int insertion_ascending_sort(int n, int *arr)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int tmp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > tmp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = tmp;
    }
    return 0;
}


