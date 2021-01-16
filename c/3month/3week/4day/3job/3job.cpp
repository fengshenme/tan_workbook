#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int num;
     Student(){}  // 无参构造函数
    Student(string n, int c, int g)
    {
        name = n;
        num = c;
        grade = g;
    }
    void show()
    {
        cout << "姓名:" << name;
        cout << "\n学号:" << num;
        cout << "\n成绩:" << grade << endl;
    }

private:
    int grade;
};

int main(int argc, char const *argv[])
{

    
    Student("li", 1, 99).show(); 
    
    
    Student s2("lt", 3, 88);

    s2.show();

    Student s1("by", 9, 88);

    s1.show();

    return 0;
}
