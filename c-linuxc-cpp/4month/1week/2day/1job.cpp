using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>



/*
count    -> 计算自定义数据类型
count_if -> 计算自定义数据类型
sort     -> 实现自定义数据类型降序

*/

struct apple
{
    string name;
    float price;
    
};

int initData(vector<struct apple> &va);

bool operator==(const struct apple &a1, const struct apple &p)
{
    if(a1.name == p.name && a1.price == p.price)
    {
        return true;
    }
    else{
        return false;
    }
}

bool mycomp(const struct apple &p)
{
    return p.price > 20;
}

void myPrint(struct apple &aa)
{
    cout << aa.name << ":" << aa.price << endl;
}

bool mysor(const struct apple &a1, const struct apple &p)
{
    return p.price < a1.price;
}

int main(int argc, char const *argv[])
{
    vector<struct apple> va;
    struct apple a2;
    initData(va);

    for_each(va.begin(), va.end(), myPrint);
    cout << "统计元素出现次数" << endl;
    cout << count(va.begin(), va.end(), va.at(0)) << endl;
    cout << "条件统计出现次数" << endl;
    cout << count_if(va.begin(), va.end(), mycomp) << endl;

    sort(va.begin(), va.end(), mysor);

    for_each(va.begin(), va.end(), myPrint);

    return 0;
}

int initData(vector<struct apple> &va)
{
    struct apple a[5];
    a[0].name = "abc";
    a[0].price = 10.2;

    a[1].name = "abc";
    a[1].price = 10.2;
    
    a[2].name = "ccc";
    a[2].price = 20.2;
    
    a[3].name = "ddd";
    a[3].price = 25.2;
    
    a[4].name = "esf";
    a[4].price = 30.2;

    va.push_back(a[0]);
    va.push_back(a[1]);
    va.push_back(a[2]);
    va.push_back(a[3]);
    va.push_back(a[4]);

    return 0;
}
