
#include <iostream>
using namespace std;

class Student
{

public:
    string name;
    int age;
    int grade;
};

class Graduate : public Student
{
public:

    Graduate(string n, int a, int g, float w)
    {
        name = n;
        age = a;
        grade = g;
        wage = w;
    }
    void display()
    {
        cout << "姓名:" << name << "年龄:" << age 
        << "分数:" << grade << "薪酬:" << wage << endl ;

    }
private:
    float wage;
};

int main()
{

    Graduate gr("abc", 19, 90, 20000.0);
    gr.display();
    

    return 0;
}
