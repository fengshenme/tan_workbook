#include <iostream>
using namespace std;

#include <stdio.h>

class student
{
public:
    string name;
    int number;


    int assign(string a, int n)
    {
        student::name = a;
        student::number = n;
        return 0;
    }

    int show()
    {
        cout << "学号" << number << "\n姓名" << name << endl;
        return 0;
    }
};

int main(int argc, const char **argv)
{

    student st;

    st.name = "张三";
    

    st.assign( "张三", 1000);

    st.number = 1009;

    st.show();

    return 0;
}