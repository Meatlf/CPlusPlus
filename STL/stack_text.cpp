/*
功能：
C++ std::Stack的基本使用实例
说明：

函数：

时间复杂度：

作者：tztang

参考资料：
[C++——std::Stack](https://blog.csdn.net/zy2317878/article/details/79739922)
日期：
2019-05-26
*/

#include<iostream>
#include<stack>
#include<vector>
#include<deque>

void test0()
{
	std::deque<int> mydeque(3, 100);	// deque with 3 elements
	std::vector<int> myvector(2, 200);	// vector with 2 elements

	std::stack<int> first;				// empty stack
	std::stack<int> second(mydeque);	// stack initialized to copy of deque

	std::stack<int, std::vector<int>>third;	// empty stack using vector
	std::stack<int, std::vector<int>>fourth(myvector);

	std::cout << "size of first:" << first.size() << '\n';
	std::cout << "size of second:" << second.size() << '\n';
	std::cout << "size of third:" << third.size() << '\n';
	std::cout << "size of fourth:" << fourth.size() << '\n';

	return;
}

void test_stack_empty()
{
	std::stack<int> mystack;
	int sum(0);

	int i = 1;
	for (;i <= 10;i++)mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "Total:" << sum << '\n';
	return;
}

int main()
{
	test0();
	test_stack_empty();
	system("pause");
	return 0;
}