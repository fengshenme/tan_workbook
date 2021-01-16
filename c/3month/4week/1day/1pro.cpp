#include <iostream>

using namespace std;

class Pesron
{
    int m_A;  //非静态成员变量         属于对象上

	static int m_B;  //静态成员变量   不属于对象上

	void func()   //非静态成员函数    不属于对象上
	{

	}

	static void func2()  //静态成员函数    不属于对象上
	{

	}
};

class Person
{
public:
    Person(int age)
    {
        this->age = age;
    }

    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;
        return *this;
    }

    int getAge()
    {
        return age;
    }

    void showPersonAge()
    {
        if (this == NULL) return ;
        
        cout << age << endl;
    }

private:
    int age;
};

int main()
{
    Pesron p;
    cout << sizeof(p) << endl;

    Person p1(10);
    Person p2(10);

    cout << p1.getAge() << endl;

    cout << p1.PersonAddAge(p2).getAge() << endl;
    cout << p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2).getAge() << endl;

    Person *p3 = NULL;

    p3->showPersonAge();

}
