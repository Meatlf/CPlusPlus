# chapter13-类继承-代码笔记

## project0

程序清单:tabtenn0.h,tabtenn0.cpp,usett0.cpp

**Q**：如何比较标准string类要比字符数组和第12章的String类好？

**A**：与字符数组相比，标准string类更方便、更灵活、更安全，而与String类相比，标准string类更专业。

**Q**：构造函数使用第12章介绍的**成员初始化列表语法**的好处是什么？

**A**：直接使用**string的复制构造函数**,这要比先使用**string的默认构造函数**，再调用**string的赋值运算**要少1个步骤。

Q:usett0.cpp中将程序实例化中将C-风格字符串作为参数,但构造函数的形参类型被声明为const string&.为什么这种操作可行?

```c++
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
```

A:因为string类既有接受const string&作为参数的string构造函数,也有接受const char*作为参数的string构造函数.

## project1

程序清单:tabtenn1.h,tabtenn1.cpp,usett1.cpp

tabtenn1.h

1)派生类的声明

2)派生类的构造函数的2种声明方式,第1种是所有参考(包括基类部分),第2种以基类作为参数以及派生类新声明的参数.

tabtenn1.cpp

1)派生类的构造函数的2种定义方式.

usett1.cpp

1)与派生类的构造函数对应，派生类对象的初始方式也有2种;

2）派生类可以使用基类的方法，条件是方法不是私有的；

2)派生类使用基类的成员函数和派生类新声明定义的成员函数.

## exercise1

派生类不能直接访问基类的私有成员，而必须通过基类方法进行访问。具体地说，派生类构造函数必须使用基类构造函数。