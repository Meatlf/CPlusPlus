#include<iostream>
#include<string>
#include<memory>

/*

参考资料：[C++智能指针总结](https://www.cnblogs.com/wuyepeng/p/9741241.html)
*/
class Test
{
public:
	Test(std::string s);
	std::string& getStr()
	{
		return str;
	}

	void setStr(std::string s)
	{
		str = s;
	}

	void print()
	{
		std::cout << str << std::endl;
	}
	~Test();

private:
	std::string str;
};

Test::Test(std::string s)
{
	str = s;
	std::cout << "Test create" << std::endl;
}

Test::~Test()
{
	std::cout << "Test delete:" << str << std::endl;
}

std::unique_ptr<Test> fun()
{
	return std::unique_ptr<Test>(new Test("789"));	// 调用了构造函数，输出Test creat
}

// std::auto_ptr()函数的基本使用
void autoPtrTest1()
{
	std::auto_ptr<Test> ptest(new Test("123"));	// 调用构造函数输出Test create
	ptest->setStr("hello "); // 修改成员变量的值
	ptest->print();	// 输出hello
	ptest.get()->print();	// 输出hello
	ptest->getStr() += "world !";
	(*ptest).print();	// 输出hello world
	ptest.reset(new Test("123"));	// 成员函数reset()重新绑定指向的对象，而原来的对象则会被释放，所以这里会调用一次构造函数，还有调用一次析构函数释放掉之前的对象
	ptest->print();		// 输出123
}

// std::auto_ptr()指针的赋值操作
void autoPtrTest2()
{
	std::auto_ptr<Test> ptest(new Test("123"));
	std::auto_ptr<Test> ptest2(new Test("456"));

	ptest->print();
	ptest2->print();
	ptest2 = ptest;
	ptest2->print();

	ptest2.release();
	ptest2.reset();

	if (ptest.get() == NULL)
		std::cout << "ptest = NULL" << std::endl;
}

void uniquePtrTest()
{
	std::unique_ptr<Test> ptest(new Test("123"));	// 调用了构造函数，输出Test create
	std::unique_ptr<Test> ptest2(new Test("456"));	// 调用了构造函数，输出Test create
	ptest->print();									// 输出123
	//ptest2 = ptest;								// 不能直接赋值，不然会爆红
	ptest2 = std::move(ptest);						// 调用了move后，ptest2原本的对象会被释放，ptest2对象指向原本ptest对象
	ptest2->print();
	if (ptest == NULL)std::cout << "ptest = NULL\n" << std::endl;	// 因为两个unique_ptr不能指向同一内存地址，所以经过前面move后ptest会被赋值NULL，输出ptest = NULL
	Test* p = ptest2.release();						// release成员函数把ptest2指针赋值为空，但是并没有释放指针指向的内存，所以此时p指向原本ptest2指向的内存
	p->print();										// 输出123
	ptest.reset(p);									// 重新绑定对象，原来的对象会被释放掉，但是ptest对象本来就释放了，所以这里就不会再调用析构函数了
	ptest->print();									// 输出123
	ptest2 = fun();									// 这里可以用=，因为使用了移动构造函数，函数返回一个unique_ptr会自动调用移动构造函数
	ptest2->print();								// 输出789
}

void sharedPtrTest()
{
	std::shared_ptr<Test> ptest(new Test("123"));	// 调用构造函数输出Test create
	std::shared_ptr<Test> ptest2(new Test("456"));	// 调用构造函数输出Test create
	std::cout << ptest2->getStr() << std::endl;		// 输出456
	std::cout << ptest2.use_count() << std::endl;	// 显示此时资源被几个指针共享，输出1
	ptest = ptest2;									// "456"引用次数加1，“123”销毁，输出Test create
	ptest->print();									// 输出456
	std::cout << ptest.use_count() << std::endl;	// 该指针指向的资源被几个指针共享，输出2
	std::cout << ptest2.use_count() << std::endl;	// 2
	ptest.reset();									// 重新绑定对象，绑定一个空对象，当时此时指针指向的对象还有其他指针指向就不会释放该对象的内存空间
	ptest2.reset();									// 此时“456”销毁，此时指针指向的内存空间上的指针为0，就释放了该内存，输出Test delete
	std::cout << "Done!" << std::endl;
}

void makeSharedTest()
{
	std::shared_ptr<int> foo = std::make_shared<int>(10);
	// same as:
	std::shared_ptr<int> foo2(new int(10));

	auto bar = std::make_shared<int>(20);

	auto baz = std::make_shared<std::pair<int, int>>(30, 40);

	std::cout << "*foo: " << *foo << std::endl;
	std::cout << "*bar: " << *bar << std::endl;
	std::cout << "*baz: " << baz->first << ' ' << baz->second << std::endl;
}

int main()
{
	//autoPtrTest1();
	//autoPtrTest2();
	//uniquePtrTest();
	//sharedPtrTest();
	makeSharedTest();
	return 0;
}