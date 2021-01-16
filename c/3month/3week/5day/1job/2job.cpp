#include <iostream>

using namespace std;

class Seller
{
public:
    Seller()
    {
        cout << "无参构造" << endl;
    }

    Seller(int q, double p)
    {
        quantity = q;
        price = p;
    }

    static double discount;

    static double sum(int count, double p)
    {
        return count * p * discount;
    }

    double aver()
    {
        return price * discount;
    }

    ~Seller()
    {
        cout << "析构函数" << endl;
    }

private:
    int quantity;
    double price;
};

double Seller::discount = 1.0;

int main(int argc, char const *argv[])
{
    Seller s1(5, 23.5);
    Seller s2(12, 24.56);
    Seller s3(100, 21.5);

    cout << s1.aver() << endl;
    cout << s2.aver() << endl;
    cout << s3.aver() << endl;

    cout << Seller::sum(5, 23.5) + Seller::sum(12, 24.56) + Seller::sum(100, 21.5) << endl;

    return 0;
}
