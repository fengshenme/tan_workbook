#include <iostream>
using namespace std;

class Cuboid {

private:
	int length;
	int width;
	int height;

public:

	Cuboid() {
	}  // 无参构造函数
	Cuboid(int l, int w, int h) {
		length = l;
		width = w;
		height = h;
	}

	int setLength(int l) {
		length = l;
		return 0;
	}
	int setWidth(int w) {
		width = w;
		return 0;
	}
	int setHeigth(int h) {
		height = h;
		return 0;
	}
	int sum() {
		return length * width * height;
	}

	void show() {
		cout << "三个长方体体积:" << 3 * length * width * height << endl;
	}

};

int main(int argc, char const *argv[]) {

	Cuboid c;

	c.setHeigth(10);
	c.setLength(10);
	c.setWidth(10);
	int ss = c.sum();
	cout << "体积:" << ss << endl;

	Cuboid c2(3, 3, 3);

	c2.show();

	return 0;
}
