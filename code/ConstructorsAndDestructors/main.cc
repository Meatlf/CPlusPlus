/*
功能：
	C++类构造函数和析构函数的基本使用实例
说明：
     知识点包括构造函数和析构函数的声明、定义和初始化、使用初始化列表来初始化字段。
函数：

作者：tztang

参考资料：
[C++ 类构造函数 & 析构函数](http://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

日期：
2019-04-13
*/

#include <iostream>

using namespace std;

#define UseInitializationList  (1)	// 是否使用初始化列表

class Line
{
public:
	void setLength(double len);
	double getLength(void);
	Line();  // 这是构造函数声明
	Line(double len);
	~Line();
private:
	double length;
};

// 成员函数定义，包括构造函数
Line::Line(void)
{
	cout << "Object is being created" << endl;
}

#if UseInitializationList 
Line::Line(double len) :length(len) {}
#else
Line::Line(double len) {
	length = len;
}
#endif

Line::~Line(void) {
	cout << "Object is being deleted" << endl;
}

void Line::setLength(double len)
{
	length = len;
}

double Line::getLength(void)
{
	return length;
}

int main()
{
	Line line1;
	Line line2(10.0);

	// 设置长度
	line1.setLength(6.0);
	cout << "Length of line1 : " << line1.getLength() << endl;

	cout << "Length of line2 : " << line1.getLength() << endl;

	line2.setLength(12.0);
	cout << "Length of line2 : " << line2.getLength() << endl;

	return 0;
}