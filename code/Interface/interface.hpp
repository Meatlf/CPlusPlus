// Shape类为基类，自身由于有getArea()纯虚函数也是抽象类
// 私有变量：width和height
// 公有成员函数：
// getArea()	// 纯虚函数	
// setWidth()	// 设置宽度
// setHeight()	// 设置高度
class Shape
{
public:
	// 提供接口框架的纯虚函数
	virtual int getArea() = 0;
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

// Rectangle为基类Shape的派生类
// getArea()实现了矩阵面积的计算
class Rectangle : public Shape
{
public:
	int getArea()
	{
		return (width * height);
	}
};

// Triangle为基类Shape的派生类
// getArea()实现了三角形面积的计算
class Triangle : public Shape
{
public:
	int getArea()
	{
		return (width * height) / 2;
	}
};
