#include <iostream>

using namespace std;

class Coord  //类声明
{
private:
    double x;
    double y;

public:
    int setXcoor(double cx);

    int setYcoor(double cy);

    int getXcoor();
    int getYcoor();
};

int main(int argc, char const *argv[])
{
    Coord c;

    c.setXcoor(3.99);
    c.setYcoor(9.99);

    cout << "x = " << c.getXcoor() << "\ny = " << c.getYcoor() << endl;

    return 0;
}

// 类实现
int Coord ::setXcoor(double cx)
{
    x = cx;
    return 0;
}

int Coord ::setYcoor(double cy)
{
    y = cy;
    return 0;
}

int Coord ::getXcoor()
{
    return x;
}
int Coord ::getYcoor()
{
    return y;
}
