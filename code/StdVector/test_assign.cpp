// vector assign
// 功能:将vector里修改当前的内容,并且修改其相应的大小.
// ## 参考资料 
// [std::vector::assign](http://www.cplusplus.com/reference/vector/vector/assign/)

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign(7, 100); // 7 ints with a value of 100
    
    for (size_t i = 0; i < first.size(); i++)
		std::cout << ' ' << first[i];
	std::cout << std::endl;


    std::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    for (size_t i = 0; i < second.size(); i++)
		std::cout << ' ' << second[i];
	std::cout << std::endl;

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    for (size_t i = 0; i < third.size(); i++)
		std::cout << ' ' << third[i];
	std::cout << std::endl;

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';
    return 0;
}