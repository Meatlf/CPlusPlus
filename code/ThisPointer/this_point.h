#ifndef THIS_POINT_H
#define THIS_POINT_H
class Box
{
public:
	// 构造函数定义
	Box(double l , double b , double h);
	Box* get_address();
	double Volume();
	int compare(Box box);
private:
	double length;     // Length of a box
	double breadth;    // Breadth of a box
	double height;     // Height of a box
};

#endif