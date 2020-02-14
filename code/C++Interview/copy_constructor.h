#ifndef COPY_CONSTRUCTOR_H
#define COPY_CONSTRUCTOR_H
// 第6章 C++面向对象 面试题22 复制构造函数是什么？什么是深度复制和浅复制

class TestCopyConstructor
{
public:
	TestCopyConstructor(int x);
	TestCopyConstructor(const TestCopyConstructor& test);
	~TestCopyConstructor();

private:
	int a;
};

void fun1(TestCopyConstructor test);

TestCopyConstructor fun2();
#endif