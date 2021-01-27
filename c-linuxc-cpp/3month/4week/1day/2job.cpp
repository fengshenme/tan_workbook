#include <iostream>
using namespace std;

class Student
{

public:
    Student(int num, string n, int g)
    {
        this->num = num;
        name = n;
        grade = g;
    }

    bool operator>(Student &s)
    {
        return grade > s.grade ? true : false;
    }

private:
    int num;
    string name;
    int grade;
};

int main(void)
{

    Student s1(1, "a", 80);
    Student s2(2, "b", 70);

    if (s1 > s2)
    {
        cout << "s1 成绩 s2 好" << endl;
    }
    else
    {
        cout << "s1 成绩 s2 差" << endl;
    }

    return 0;
}
