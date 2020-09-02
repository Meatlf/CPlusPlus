// 参考资料：[1] [C++创建对象的两种方法（C++用new和不用new创建类对象）](https://blog.csdn.net/lz20120808/article/details/40833517)
#include <iostream>
using namespace std;

class Rec
{
public:
	Rec(int width, int height);
	~Rec();
	int getArea();

private:
	int Rwidth;
	int Rheight;
};

Rec::Rec(int width, int height)
{
}

Rec::~Rec()
{
}

int Rec::getArea()
{
}

int main(void)
{
	// 方法1
	Rec myRec(5, 5);
	cout << sizeof(myRec) << endl;

	// 方法2
	Rec *rec = new Rec(3, 4);
	rec->getArea();
	delete rec;
	return 0;
}