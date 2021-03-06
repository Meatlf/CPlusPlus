/*
功能：
	C++多态的基本使用实例
说明：
	可以通过单步调试和查看“参考资料”学习或复习C++多态
函数：

作者：tztang

参考资料：
[C++ 多态](http://www.runoob.com/cplusplus/cpp-polymorphism.html)

日期：
2019-04-24
*/
#include"polymorphism.hpp"

// 程序的主函数
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	// 存储矩形的地址
	shape = &rec;
	// 调用矩形的求面积函数 area
	shape->area();

	// 存储三角形的地址
	shape = &tri;
	// 调用三角形的求面积函数 area
	shape->area();

	return 0;
}