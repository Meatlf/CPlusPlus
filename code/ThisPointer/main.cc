/*
功能：
C++ this指针的基本使用实例
说明：
知识点包括this 指针的声明、定义和使用。
函数：

作者：tztang

参考资料：
[C++ this指针](http://www.runoob.com/cplusplus/cpp-this-pointer.html)

最近修改日期：
2019-04-20
*/

#include <iostream>
#include"this_point.h"

int main(void)
{
	Box Box1(3.3, 1.2, 1.5);    // Declare box1
	Box Box2(8.5, 6.0, 2.0);    // Declare box2

	if (Box1.compare(Box2))
	{
		std::cout << "Box2 is smaller than Box1" << std::endl;
	}
	else
	{
		std::cout << "Box2 is equal to or larger than Box1" << std::endl;
	}

	// Box* 定义指针p接受对象box的get_address()成员函数的返回值，并打印
	Box* p = Box1.get_address();
	std::cout << p << std::endl;

	p = Box2.get_address();
	std::cout << p << std::endl;
	return 0;
}