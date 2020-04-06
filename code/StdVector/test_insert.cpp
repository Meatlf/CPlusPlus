// vector insert
// 功能:使用insert在vector中插入新元素.
// ## 参考资料 
// [std::vector::insert](http://www.cplusplus.com/reference/vector/vector/insert/)

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    for (it = myvector.begin(); it < myvector.end(); it++)
		  std::cout << ' ' << *it;
  	std::cout << std::endl;

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());
    for (it = myvector.begin(); it < myvector.end(); it++)
		  std::cout << ' ' << *it;
  	std::cout << std::endl;

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end();it++)
      std::cout <<' '<< *it;
    std::cout << '\n';

    return 0;
}