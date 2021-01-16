#include <iostream>
#include <array>

using namespace std;
#include <stdlib.h>

template <class T1>
class Array
{
public:
    Array(int size)
    {
        alist = new T1[size];
        this->size = size;
        amount = 0;
    }
    Array(Array &p)
    {
        copy(p);
    }


    // 重载下标运算符，实现与普通数组一样通过下标访问元素，并且具有越界检查功能
    T1 &operator[](int n)
    {
        if (n < 0 || n >= size)
        {
            cout << "数组越界了" << endl;
         
            exit(1);
        }
        return alist[n]; // 返回下标为n的数组元素
    }
 
    //重载指针转换运算符，将Array类的对象名转换为T类型的指针，指向当前对象中的私有数组。因而可以象使用普通数组首地址一样使用Array类的对象名
    // T1*是指针转换运算符。C++语法规定，重载类型转换运算符时，不允许指定返回值类型（也不要写void）
    operator T1 *(void) const
    {
        return alist; // 返回当前对象中私有数组的首地址
    }



    //为了解决浅拷贝，我们自己重载一下=
    Array &operator=(Array &p)
    {
        //编译器默认提供的就是浅拷贝
        //alist = p.getArr();  //这行话就是编译器默认做的
        //size = p.getSize();  //这行话就是编译器默认做的

        copy(p);
        return *this;
    }

    T1 *getArr()
    {
        return alist;
    }

    int &getSize()
    {
        return size;
    }
    int getAmount()
    {
        
        return amount ;
    }

    bool addData(T1 t)
    {
        
        if (amount >= size)
        {
            cout << "array filled\n";
            return false;
        }
        
        alist[amount] = t;
        amount++;
        return true;
    }
    bool del_tail_one()
    {
        
        if (amount < 0)
        {
            cout << "array empty\n";
            return false;
        }
        
        alist[amount] = NULL;
        amount--;
        return true;
    }

    ~Array()
    {
        delete alist;
    }

private:
    T1 *alist; //数组首地址指针
    int size; //容器大小
    int amount; //已填充数量 最后数的下标
    void copy(Array &p)
    {
        //应该先判断是否有属性在堆区，如果有，先释放干净，再深拷贝。
        show(p);
        int n = p.getSize();
        //深拷贝，就是重新去堆区申请空间。
        size = n;
        amount = p.amount;
        alist = new T1[size];
        // 从rhs向本对象复制元素
        T1 *destptr = alist;
        T1 *srcptr = p.getArr();
        while (n--)
            *destptr++ = *srcptr++;
    }
};

template <class T>
void show(Array<T> &arr);

int main(int argc, char const *argv[])
{
    int i, len = 5;
    Array<int> arr(len);

    for (i = 0; i < len; i++)
    {
        arr.addData(i);
    }
    arr[1] = 1;
    cout << arr.getAmount() << " run..." <<  __LINE__ << endl;
    show(arr);
    Array<float> arrf(len);
    for (i = 0; i < len; i++)
    {
        arrf[i] = i * 0.2;
    }
    cout << "run..." << __LINE__ << endl;
    show(arrf);

    cout << __LINE__ << ":" << arr.getAmount() << endl;

    Array<int> ar = arr;
    cout << "copy=run..." << __LINE__ << endl;
    show(ar);
    Array<int> ar2(arr);
    cout << "constructor copy array run..." << __LINE__ << endl;
    show(ar);

    return 0;
}

template <class T>
void show(Array<T> &arr)
{
    int i;
    for (i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
