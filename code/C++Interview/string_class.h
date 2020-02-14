#ifndef STRING_CLASS_H
#define STRING_CLASS_H
#include<iostream>
// 第6章 C++面向对象 面试题26 编写类String的构造函数、析构函数和赋值函数

class StringClass
{
public:
	StringClass(const char* str=NULL);						//普通构造函数
	StringClass(const StringClass &other);					//复制构造函数
	StringClass & operator = (const StringClass &other);	//赋值函数
	~StringClass();											//析构函数

private:
	char* m_String;											//保存字符串
};
#endif