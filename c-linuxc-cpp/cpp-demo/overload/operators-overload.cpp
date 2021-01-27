/*
C++ ++ 和 -- 运算符重载
C++ 重载运算符和重载函数 C++ 重载运算符和重载函数

递增运算符（ ++ ）和递减运算符（ -- ）是 C++ 语言中两个重要的一元运算符。

下面的实例演示了如何重载递增运算符（ ++ ），包括前缀和后缀两种用法。类似地，您也可以尝试重载递减运算符（ -- ）。

实例
*/
#include <iostream>
using namespace std;
 
class Time
{
   private:
      int hours;             // 0 到 23
      int minutes;           // 0 到 59
   public:
      // 所需的构造函数
      Time(){
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m){
         hours = h;
         minutes = m;
      }
      // 显示时间的方法
      void displayTime()
      {
         cout << "H: " << hours << " M:" << minutes <<endl;
      }
      // 重载前缀递增运算符（ ++ ）
      Time operator++ ()  
      {
         ++minutes;          // 对象加 1
         if(minutes >= 60)  
         {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
      // 重载后缀递增运算符（ ++ ）
      Time operator++( int )         
      {
         // 保存原始值
         Time T(hours, minutes);
         // 对象加 1
         ++minutes;                    
         if(minutes >= 60)
         {
            ++hours;
            minutes -= 60;
         }
         // 返回旧的原始值
         return T; 
      }
};

//++ 重载
class Check
{
  private:
    int i;
  public:
    Check(): i(0) {  }
    Check operator ++ ()
    {
        Check temp;
        temp.i = ++i;
        return temp;
    }
 
    // 括号中插入 int 表示后缀
    Check operator ++ (int)
    {
        Check temp;
        temp.i = i++;
        return temp;
    }
 
    void Display()
    { cout << "i = "<< i <<endl; }
};
 

int main()
{
   Time T1(11, 59), T2(10,40);
 
   ++T1;                    // T1 加 1
   T1.displayTime();        // 显示 T1
   ++T1;                    // T1 再加 1
   T1.displayTime();        // 显示 T1
 
   T2++;                    // T2 加 1
   T2.displayTime();        // 显示 T2
   T2++;                    // T2 再加 1
   T2.displayTime();        // 显示 T2

   Check obj, obj1;    
    obj.Display(); 
    obj1.Display();
 
    // 调用运算符函数，然后将 obj 的值赋给 obj1
    obj1 = ++obj;
    obj.Display();
    obj1.Display();
 
    // 将 obj 赋值给 obj1, 然后再调用运算符函数
    obj1 = obj++;
    obj.Display();
    obj1.Display();
   return 0;
}