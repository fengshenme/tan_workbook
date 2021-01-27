/*

C++ 类构造函数 & 析构函数
C++ 类 & 对象 C++ 类 & 对象
类的构造函数
类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。
下面的实例有助于更好地理解构造函数的概念：

*/
#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();  // 这是构造函数
      Line(double len);  // 这是有参构造函数
 
   private:
      double length;
};
 
// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
// 成员函数定义，包括构造函数
Line::Line( double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
} 
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// 程序的主函数
int main( )
{
   Line line;
 
   // 设置长度
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
    Line line1(10.0);
 
   // 获取默认设置的长度
   cout << "Length of line : " << line1.getLength() <<endl;
   // 再次设置长度
   line1.setLength(6.0); 
   cout << "Length of line : " << line1.getLength() <<endl;
 
   return 0;
}

/*
使用初始化列表来初始化字段
使用初始化列表来初始化字段：

Line::Line( double len): length(len)
{
    cout << "Object is being created, length = " << len << endl;
}
上面的语法等同于如下语法：

Line::Line( double len)
{
    length = len;
    cout << "Object is being created, length = " << len << endl;
}
假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔，如下所示：

C::C( double a, double b, double c): X(a), Y(b), Z(c)
{
  ....
}
*/