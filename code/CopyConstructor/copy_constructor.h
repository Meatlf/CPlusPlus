#ifndef _COPY_CONSTRUCTOR_H
#define _COPY_CONSTRUCTOR_H
#include <iostream>

using namespace std;

class Line
{
public:
	int getLength(void);
	Line(int len);             // 简单的构造函数
	Line(const Line &obj);      // 拷贝构造函数
	~Line();                     // 析构函数

private:
	int *ptr;
};
void display(Line obj);
#endif