#ifndef GLOBAL_OBJECT_H
#define GLOBAL_OBJECT_H
// 第6章 C++面向对象 面试题13 main函数执行前还会执行什么代码？
#include<iostream>

class Test
{
public:
	Test();
	~Test();

private:

};

Test::Test()
{
	std::cout << "constructor of Test" << std::endl;
}

Test::~Test()
{
}
#endif