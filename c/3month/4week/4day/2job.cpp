#include <iostream>

using namespace std;


template<class T> int getMax(T arr[], int len)
{
    int i, j = 0;
    T tmp = arr[0];
    for ( i = 1; i < len; i++)
    {
        
        if(arr[i] > tmp)
        {
             tmp = arr[i];
             j = i  ;
        }

    }
    
    return j;
}

int main(int argc, char *argv[])
{
    int arr[] = {0, 8, 3, 2, 4, 5, 9, 7, 1, 6};
    float arr1[] = {0.0, 9.9, 8.8, 3.3, 2.2, 4.4, 5.5, 7.7, 1.1, 6.6};

    int len = 10;
    int  iv = getMax<int>(arr, len); 

    int  iv1 = getMax<float>(arr1, len); 

    cout << "最大值是第" << iv + 1 << "个元素," << "值是:" << arr[iv]<< endl;
    cout << "最大值是第" << iv1 + 1 << "个元素," << "值是:" << arr1[iv1]<< endl;

    return 0;
}
