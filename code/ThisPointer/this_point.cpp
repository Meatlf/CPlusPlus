#include<iostream>
#include"this_point.h"

	Box::Box(double l = 2.0, double b = 2.0, double h = 2.0)
	{
		std::cout << "Constructor called." << std::endl;
		length = l;
		breadth = b;
		height = h;
	}

	Box * Box::get_address()
	{
		return this;
	}

	double Box::Volume()
	{
		return length * breadth * height;
	}

	int Box::compare(Box box)
	{
		return this->Volume() > box.Volume();	// 使用this指针指向Volume()成员函数
	}