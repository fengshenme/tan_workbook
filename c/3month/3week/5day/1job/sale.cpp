#include <iostream>
using namespace std;

//定义一个销售员类
class Sale{
public:
	Sale(int num,int quantity,float price)
	{
		m_Num = num;
		m_Quantity = quantity;
		m_Price = price;

		total_Quantity += quantity;
		total_Sum += quantity*price;
	}

	static float show_sum()
	{
		return total_Sum;
	}

	static float Get_Average()
	{
		return total_Sum/total_Quantity;
	}

private:
	int m_Num;      //销售员号
	int m_Quantity; //销售件数
	float m_Price;  //销售单价
	static float total_Quantity;  //商店销售总件数
	static float total_Sum;       //商店销售总金额
};

//静态成员变量必须类内声明，类外初始化
float Sale::total_Quantity = 0;
float Sale::total_Sum = 0;

int main()
{
	Sale s1(101,5,23.5);
	Sale s2(102,12,24.56);
	Sale s3(103,100,21.5);

	cout << "该商店总销售额:" << Sale::show_sum() << endl;
	cout << "该商店平均价:" << Sale::Get_Average() << endl;
	return 0;
}