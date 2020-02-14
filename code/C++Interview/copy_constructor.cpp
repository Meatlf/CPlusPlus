#include<iostream>
#include"copy_constructor.h"

TestCopyConstructor::TestCopyConstructor(int x)
{
	a = x;
}

TestCopyConstructor::TestCopyConstructor(const TestCopyConstructor& test) {
	std::cout << "copy constructor" << std::endl;
	a = test.a;
}

TestCopyConstructor::~TestCopyConstructor()
{
}

void fun1(TestCopyConstructor test) {
	std::cout << "fun1()..." << std::endl;
}

TestCopyConstructor fun2() {
	TestCopyConstructor t(2);
	std::cout << "fun2()..." << std::endl;
	return t;
}