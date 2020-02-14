#include<iostream>
#include"diff_class_and_struct.h"

CPoint::CPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

CPoint::~CPoint()
{
}

void CPoint::print1() {
	std::cout << "CPoint: (" << x << ", " << y << ")" << std::endl;
}