#include <iostream>

using namespace std;

// int selectSort(int arr[], int len) //选择排序
// {
//     int i, j;
//     for (i = 0; i < len; i++)
//     {
//         int tmp = arr[i];
//         for (j = i; j > 0; j--)
//         {
//             if (arr[j - 1] > tmp)
//                 break;
//             arr[j] = arr[j - 1];
//         }
//         arr[j] = tmp;
//     }

//     return 0;
// }

template <typename T>
int selectSort(T arr[], int len) //选择排序
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        T tmp = arr[i];
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > tmp)
                break;
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }

    return 0;
}

template <typename T>
void show(T arr[], int len);

int main()
{
    int arr[] = {0, 8, 3, 2, 4, 5, 9, 7, 1, 6};
    //
    // char str[] = "ajegcbdfhi";
    char str[] = {'a', 'j', 'e', 'g', 'c', 'b', 'd', 'f', 'h', 'i'};

    int len = 10;

    cout << "排序前:";
    show(arr, len);
    selectSort<int>(arr, len);
    cout << "排序后:";
    show(arr, len);

    cout << "排序前:";
    show(str, len);
    selectSort<char>(str, len);
    cout << "排序后:";
    show(str, len);

    return 0;
}

template <typename T>
void show(T arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}