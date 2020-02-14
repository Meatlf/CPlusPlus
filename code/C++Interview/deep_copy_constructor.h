#ifndef DEEP_COPY_CONSTRUCTOR_H
#define DEEP_COPY_CONSTRUCTOR_H
// 第6章 C++面向对象 面试题22 复制构造函数是什么？什么是深度复制和浅复制

class DeepCopyConstructor
{
public:
	DeepCopyConstructor();
	DeepCopyConstructor(const DeepCopyConstructor& test);
	DeepCopyConstructor(const char* str);
	~DeepCopyConstructor();
	char* buf;

private:
};
#endif