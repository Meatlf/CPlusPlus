#ifndef POLYMORPHISM
#define POLYMORPHISM

#include <iostream> 

// 多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。

// 基类
class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	virtual int area()	// 多态的一般使用方式
	{
		std::cout << "Parent class area :" << std::endl;
		return 0;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		std::cout << "Rectangle class area :" << std::endl;
		return (width * height);
	}
};

class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		std::cout << "Triangle class area :" << std::endl;
		return (width * height / 2);
	}
};
#endif