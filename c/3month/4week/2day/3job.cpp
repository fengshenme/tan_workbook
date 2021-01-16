#include <iostream>

using namespace std;

class Point
{

private:
    friend ostream &operator<<(ostream &cout, Point &p);

public:
    float x;
    float y;
    Point() {}
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    ~Point() {}
};

class Circle : public Point
{
    friend ostream &operator<<(ostream &cout, Circle &c);

private:
    /* data */
public:
    float r;
    float pi;
    Circle(/* args */) {}
    Circle(float pi)
    {
        this->pi = pi;
    }
    // 设置半径
    void setRadius(float ra)
    {
        this->r = ra;
    }
    // 读取半径
    float getRadius()
    {
        return this->r;
    }
    // 计算圆面积
    float area()
    {
        return pi * r * r;
    }
    ~Circle() {}
};

class Cylinder : public Circle
{

    friend ostream &operator<<(ostream &cout, Cylinder &cy);

private:
    float h;

public:
    void setHeight(float hei)
    {
        this->h = hei;
    }
    float getHeight()
    {
        return this->h;
    }
    //表面积
    float areaCyli()
    {
        return area() * 2 + r * 2 * pi * h;
    }
    // 体积
    float voluCylin()
    {
        return area() * h;
    }
    Cylinder() {}
    ~Cylinder() {}
};

ostream &operator<<(ostream &cout, Point &p)
{
    cout << "x:" << p.x << "y:" << p.y;
    return cout;
}
ostream &operator<<(ostream &cout, Circle &c)
{
    cout << "半径:" << c.getRadius() << "圆面积" << c.area();
    return cout;
}
ostream &operator<<(ostream &cout, Cylinder &cy)
{
    cout << "圆柱表面积:" << cy.areaCyli() << "圆柱体积:" << cy.voluCylin();
    return cout;
}

int main(int argc, char *argv[])
{
    Point p(20.8, 10.0);
    Circle c(3.14);
    c.setRadius(10);
    Cylinder cy;
    cy.pi = 3.14;
    cy.setRadius(10);
    cy.setHeight(10);

    cout << p << endl;

    cout << c << endl;

    cout << cy << endl;

    return 0;
}
