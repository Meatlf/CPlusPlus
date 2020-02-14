#include<iostream>
#include"deep_copy_constructor.h"


DeepCopyConstructor::DeepCopyConstructor()
{
	buf = NULL;
}

DeepCopyConstructor::DeepCopyConstructor(const DeepCopyConstructor & test)
{
	buf = new char[strlen(test.buf) + 1];
}

DeepCopyConstructor::DeepCopyConstructor(const char* str) {
	buf = new char[strlen(str) + 1];	//分配堆内存
	strcpy(buf, str);					//复制字符串
}

DeepCopyConstructor::~DeepCopyConstructor()
{
	if (buf != NULL) {
		delete buf;		// 释放buf指向的堆内存
	}
}

