#ifndef MULTIPLE_INHERITANCE
#define MULTIPLE_INHERITANCE

#include <iostream>

// 嗣樟創ㄗ遠袨樟創ㄘ
// A->C,B->D,C->(A,B)
//價濬
class D
{
public:
	D() { std::cout << "D()" << std::endl; }
	~D() { std::cout << "~D()" << std::endl; }
protected:
	int d;
};

class B :virtual public D
{
public:
	B() { std::cout << "B()" << std::endl; }
	~B() { std::cout << "~B()" << std::endl; }
protected:
	int b;
};

class A :virtual public D
{
public:
	A() { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
protected:
	int a;
};

class C :public B, public A
{
public:
	C() { std::cout << "C()" << std::endl; }
	~C() { std::cout << "~C()" << std::endl; }
protected:
	int c;
};
#endif