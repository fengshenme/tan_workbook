#include <iostream>
#include <array>

using namespace std;

template <class T1, int len>
class Array
{
public:
    Array()
    {
        alist = new T1[len];
    }

    T1 sum()
    {
        T1 count;
        int i;

        for (i = 0; i < len; i++)
        {
            count += alist[i];
        }
        return count;
    }

    // 重载下标运算符，实现与普通数组一样通过下标访问元素，并且具有越界检查功能
    T1& operator[](int n)
    {
        return alist[n]; // 返回下标为n的数组元素
    }

    //重载指针转换运算符，将Array类的对象名转换为T类型的指针，指向当前对象中的私有数组。因而可以象使用普通数组首地址一样使用Array类的对象名 
    // T1*是指针转换运算符。C++语法规定，重载类型转换运算符时，不允许指定返回值类型（也不要写void）
    operator T1* (void) const
    {
        return alist; // 返回当前对象中私有数组的首地址
    }
    ~Array()
    {
        delete alist;
    }
private:
    T1 *alist;
};

int main(int argc, char const *argv[])
{
    Array<int, 5> arr;
    int i, len = 5;
    for (i = 0; i < len; i++)
    {
        arr[i] = i;
    }

    cout << arr.sum() << endl;
    Array<float, 5> arrf;
    for (i = 0; i < len; i++)
    {
        arrf[i] = i * 0.2;
    }

    cout << arrf.sum() << endl;

    for ( i = 0; i < len; i++)
    {
        cout << arrf[i] << " ";
    }
    cout << endl   ; 

    return 0;
}
