/*
功能：
C++接口（抽象类）的基本使用实例
说明：
可以通过单步调试和查看“参考资料”学习或复习C++接口（抽象类）
函数：

作者：tztang

参考资料：
[C++接口（抽象类）](http://www.runoob.com/cplusplus/cpp-interfaces.html)

日期：
2019-05-03
*/
#include <iostream>
#include"interface.hpp"

int main(void)
{
	Rectangle Rect;
	Triangle  Tri;

	Rect.setWidth(5);
	Rect.setHeight(7);
	
	// 输出对象的面积
	std::cout << "Total Rectangle area: " << Rect.getArea() << std::endl;

	Tri.setWidth(5);
	Tri.setHeight(7);
	
	// 输出对象的面积
	std::cout << "Total Triangle area: " << Tri.getArea() << std::endl;

	return 0;
}