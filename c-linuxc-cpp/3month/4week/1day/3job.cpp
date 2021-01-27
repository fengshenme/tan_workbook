#include <iostream>
using namespace std;

class Timeu
{

    friend ostream& operator<<(ostream &cout, Timeu myint);
public:
    Timeu()
    {
        minute = 0;
        second = 0;
    }

    Timeu &operator++() // 前置++
    {
        ++second;
        if (second >= 59)
        {
            second = 0;
            minute++;
            cout << minute << "min" << second << "sec" << endl;
        }
        return *this;
    }
    Timeu operator++(int) //占位符后置++
    {
        Timeu te = *this;
        second++;
        if (second >= 59)
        {
            second = 0;
            minute++;
            cout << minute << "min" << second << "sec" << endl;
        }
        return te;
    }

private:
    long minute;
    int second;
};

//重载<<运算符
ostream& operator<<(ostream &cout, Timeu myint)
{
	cout << myint.minute << ":";
	cout << myint.second << endl;
	return cout;
}

int main()
{

    Timeu tu;

    int i;

    for (i = 0; i < 70; i++)
    {
         ++tu ;
    }
    cout << tu << endl;
    for (i = 0; i < 70; i++)
    {
         tu++ ;
    }
    cout << tu << endl;
}
