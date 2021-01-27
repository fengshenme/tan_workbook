#include <iostream>
using namespace std;

class Cpu
{

public:
	Cpu() {}
	 virtual ~Cpu() {}

	virtual int calculate(int, int) = 0;
};

class Gpu
{
private:
public:
	Gpu() {}
	virtual ~Gpu() {}
	virtual void show(int) = 0;
};

class Memory
{
private:
public:
	Memory() {}
	virtual ~Memory() {}
	virtual void repo(string) = 0;
};

class Intel : public Cpu
{
public:
	int calculate(int a, int b)
	{
		cout << "intel加法运算开始..." << endl;
		return a + b;
	}
};

class Amd : public Cpu
{
public:
	int calculate(int a, int b)
	{
		
		cout << "amd减法运算开始..." << endl;
		return a - b;
	}
};

class Kunpeng : public Cpu
{

public:
	int calculate(int a, int b)
	{
		cout << "kunpeng乘法运算开始..." << endl;
		return a * b;
	}
};

class Nvidia : public Gpu
{
public:
	void show(int a)
	{
		cout << "nvidia显示" << endl;
		cout << "++++++++++++" << a << endl;
	}
};

class Jingjiawen : public Gpu
{
public:
	void show(int a)
	{
		cout << "Jingjiawen显示" << endl;
		cout << "==========" << a << endl;
	}
};

class Apple : public Gpu
{
public:
	void show(int a)
	{
		cout << "Apple显示" << endl;
		cout << "*********" << a << endl;
	}
};

class Zhitai : public Memory
{
public:
	void repo(string a)
	{
		cout << "Zhitai存储数据保存成功" << a << endl;
	}
};

class Samsung : public Memory
{
public:
	void repo(string a)
	{
		cout << "Samsung存储数据保存成功" << a << endl;
	}
};

class Micron : public Memory
{
public:
	void repo(string a)
	{
		cout << "Micron存储数据保存成功" << a << endl;
	}
};

class Computer
{
public:
	Computer(Cpu *cpu, Gpu *gpu, Memory *mem)
	{
		this->cpu = cpu;
		this->gpu = gpu;
		this->mem = mem;
	}

	~Computer()
	{
	}

	void run(int a, int b, string str)
	{
		gpu->show(cpu->calculate(a, b));
		mem->repo(str);
	}

private:
	Cpu *cpu;
	Gpu *gpu;
	Memory *mem;
};

int main(void)
{
	Cpu *c1 = new Intel;
	Cpu *c2 = new Amd;
	Cpu *c3 = new Kunpeng;

	Gpu *g1 = new Nvidia;
	Gpu *g2 = new Jingjiawen;
	Gpu *g3 = new Apple;

	Memory *m1 = new Zhitai;
	Memory *m2 = new Samsung;
	Memory *m3 = new Micron;

	Computer ca(c1, g1, m1);
	Computer cb(c2, g2, m2);
	Computer cc(c3, g3, m3);

	int a = 20, b = 10;
	string name = "hello" ;

	ca.run(a, b, name);
	cb.run(a, b, name);
	cc.run(a, b, name);

	delete c1, c2, c3, g1, g2, g3, m1, m2, m3;

}
