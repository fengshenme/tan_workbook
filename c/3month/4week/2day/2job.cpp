#include <iostream>

using namespace std;

class circle
{
private:
public:
    float pi;
    float radius; // 半径
    circle(){}
    circle(float p, float r) : pi(p), radius(r) {}
    ~circle() {}
    float area()
    {
        return pi * radius * radius;
    }
};

class desk
{
private:
public:
    float hight;
    string color;
    desk() {}
    ~desk() {}
};

class cidesk : public circle, public desk
{
private:
public:
    cidesk(float p, float r, float hight, string c)
    {
        pi = p;
        radius = r;
        this->hight = hight;
        this->color = c;
    }

    void display()
    {
        cout << "圆桌面积:" << area() << "高度:" << hight << "颜色:" << color << endl ; 
    }
    
};


int main(int argc, char *argv[])
{
    cidesk ci(3.14, 10, 100, "黄色");

    ci.display();



    return 0;
}