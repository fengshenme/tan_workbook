#include <stdio.h>

// 冒泡排序
void bubble_sort(int n, int *a);
void bubble_sort2(int n, int *a);

void show_array(int len, int *a);

int main(int argc, char const *argv[])
{
	int arr[8] = {4, 3, 7, 2, 5, 1, 8, 6};
    int len = 8;
	show_array(len, arr);

	// 冒泡排序
	bubble_sort2(len, arr);

	show_array(len, arr);

	return 0;
}

// 冒泡排序
void bubble_sort2(int n, int *a)
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
// 冒泡排序
void bubble_sort(int n, int *a)
{
	// 遍历次数i： n-1 次
	int i, j;
	for(i = 0; i< n-1; i++)
	{
		// 两两对比次数j： n-i 次
		for(j= 0; j < n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
			}
		}
	}
}

// 显示数组所有数据
void show_array(int len, int *a)
{
	int i;
	for(i=0; i<len; i++)
		printf("%d ", a[i]);
	printf("\n");
}








