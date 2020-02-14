#ifndef INHERITANCE_H
#define INHERITANCE_H

// 基类
// 类名：Shape
// 类功能：设置矩形的长和宽
class Shape
{
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
protected:
	int width;
	int height;
};

// 基类 PaintCost
// 类名：PaintCost
// 类功能：根据面积计算涂料用费
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};

// 派生类
class Rectangle : public Shape, public PaintCost
{
public:
	int getArea()
	{
		return (width * height);
	}
};

#endif