
/**
 * @file d6t5.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 冒泡排序,插入排序
 * 
 * todo 归并排序, 计数排序,桶排序, 计数排序
 * @version 0.1
 * @date 2020-10-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LEN 10

/**
 * @brief 插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
    一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
    从第一个元素开始，该元素可以认为已经被排序；
    取出下一个元素，在已经排序的元素序列中从后向前扫描；
    如果该元素（已排序）大于新元素，将该元素移到下一位置；
    重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
    将新元素插入到该位置后；
    重复步骤2~5。

 * 
 * @param n 
 * @param arr 
 */
void insertion_sort1(int n, int *arr);
/**
 * @brief 冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。 
    比较相邻的元素。如果第一个比第二个大，就交换它们两个；
    对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
    针对所有的元素重复以上的步骤，除了最后一个；
    重复步骤1~3，直到排序完成
 * 
 * @param n 
 * @param a 
 */
void bubble_sort(int n, int *a);
void show_arr(int *arr);

int main(int argc, char const *argv[])
{

    //  int arr[LEN] ;//= {5, 4, 1, 2, 3};
    int *arr;
    arr = (int *)malloc(LEN*sizeof(int));

    int i, j;

    srand(10);
    for (i = 0; i < LEN; i++)
    {
        j = (rand() % 100);
        arr[i] = j;
    }

    show_arr(arr);
    insertion_sort1(LEN, arr);
    show_arr(arr);
    free(arr);
    return 0;
}
void show_arr(int *arr)
{
    size_t i = 0;
    for (; i < LEN; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void insertion_sort1(int n, int *arr)
{

    int i, j;
    for (i = 1; i < n; i++)
    {
        int tmp = arr[i];
        int flag = 0;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > tmp)
            {
                arr[j + 1] = arr[j];
                arr[j] = tmp; 
                flag =1;
            }
            if(flag == 0) break;
        }
        
    }

}




// 冒泡排序
void bubble_sort(int n, int *a)
{
	// 遍历次数i： n-1 次
	int i, j,count;
	for(i = 0; i< n-1; i++)
	{
        count = 0;
		// 两两对比次数j： n-i 次
		for(j= 0; j < n-i-1; j++)
		{
             
			if(a[j]>a[j+1])
			{
				int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                count=1;
			}
		}
        if (count == 0)
        {
            break;
        }
	}

}