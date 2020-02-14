/*
功能：
C++继承的基本使用实例
说明：
可以通过单步调试和查看“参考资料”学习或复习C++重载
函数：

作者：tztang

参考资料：
[C++ 继承](http://www.runoob.com/cplusplus/cpp-inheritance.html)

日期：
2019-05-03
*/

#include <iostream>
#include"inheritance.hpp"
#include"multiple_inheritance.hpp"

int main(void)
{
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);

	area = Rect.getArea();

	// 输出对象的面积
	std::cout << "Total area: " << area << std::endl;

	std::cout << "Total paint cost: $" << Rect.getCost(area) << std::endl;

	std::cout << "Hello World!" << std::endl;
	C c;	// D, B, A, C
	std::cout << sizeof(c) << std::endl;
	return 0;
}