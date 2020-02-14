/*
功能：
C++拷贝构造函数的基本使用实例
说明：
（1）知识点包括拷贝构造函数的声明、定义和使用；
（2）建议使用单步调试来查看程序执行流程。
函数：

作者：tztang

参考资料：
[C++ 拷贝构造函数](http://www.runoob.com/cplusplus/cpp-copy-constructor.html)

日期：
2019-04-16
*/

#include"copy_constructor.h"

int main()
{
	Line line1(10);
	Line line2 = line1;	// 这里会调用拷贝构造函数

	display(line1);		// 这里会调用拷贝构造函数
	display(line2);		// 这里会调用拷贝构造函数

	return 0;
}