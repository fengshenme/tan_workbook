#include <iostream>

using namespace std;

class Shape
{
public:
    virtual float area() = 0;
};

class Circle : public Shape
{

private:
    float r;
    float pi;

public:
    float area()
    {
        cout << "圆面积:" << pi * r * r << endl;
        return pi * r * r;
    }

    void setValue(float r, float pi)
    {
        this->r = r;
        this->pi = pi;
    }
};

class Square : public Shape
{
private:
    float len;

public:
    Square() {}
    Square(float l) : len(l) {}
    float area()
    {
        cout << "正方形:" << len * len << endl;
        return len * len;
    }
};

class Rectangle : public Shape
{
private:
    float lenght;
    float width;

public:
    Rectangle() {}
    Rectangle(float l, float w) : lenght(l), width(w) {}
    float area()
    {
        cout << "长方形:" << lenght * width << endl;
        return lenght * width;
    }
};

class Trapezoid : public Shape
{
private:
    float topl;
    float boml;
    float hei;

public:
    Trapezoid() {}
    Trapezoid(float l, float w, float h) : topl(l), boml(w), hei(h) {}
    float area()
    {
        cout << "等腰梯形:" << (topl + boml) * hei / 2 << endl;
        return (topl + boml) * hei / 2;
    }
};

class Triangle : public Shape
{
private:
    float top;
    float hei;

public:
    Triangle() {}
    Triangle(float t, float h) : top(t), hei(h) {}
    float area()
    {
        cout << "等腰三角形面积和:" << top * hei / 2 << endl;
        return top * hei / 2;
    }
};

int main()
{
    Shape *s[5];
    s[0] = new  Circle;
    s[1] = new Square(10);
    s[2] = new Rectangle(8, 10);
    s[3] = new Trapezoid(5, 8, 10);
    s[4] = new Triangle(10, 20);

    ((Circle *)s[0])->setValue(10, 3.14);

    
   
    float number =  s[0]->area() + s[1]->area() + s[2]->area() + s[3]->area() + s[4]->area() ;

    cout << "五个图形总面积:" << number << endl;

    return 0;
}
