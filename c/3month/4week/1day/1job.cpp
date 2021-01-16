#include <iostream>
using namespace std;



class Date
{
    friend class Time;
    friend void display(Date &d);
public:
    Date()
    {
        date = "2020-12-03";
    }

private:
    string date;
};

class Time
{
    friend void display(Time &t);

public:
    Time()
    {
        time = " 20:09:30";
    
        time = d.date + time;
    }

    Date d;
private:
    string time;
    string date;
};

void display(Time &t)
{
    cout << "时间:" << t.time << endl;

}
void display(Date &d)
{
    cout << "日期:" << d.date ;
}

int main(void)
{
    Date d;
    Time t;

    // display(d);
    display(t);


    return 0;
}
