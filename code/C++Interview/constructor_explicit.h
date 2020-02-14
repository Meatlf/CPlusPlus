#ifndef CONSTRUCTOR_EXPLICIT_H
#define CONSTRUCTOR_EXPLICIT_H
// 第6章 C++面向对象 面试题18 构造函数explicit与普通构造函数的区别

class CommonConstructor1
{
public:
	CommonConstructor1(int n);
	~CommonConstructor1();

private:
	int num;
};

class ExplicitConstructor2
{
public:
	explicit ExplicitConstructor2(int n);		// explicit(显示）构造函数
	~ExplicitConstructor2();

private:
	int num;
};
#endif