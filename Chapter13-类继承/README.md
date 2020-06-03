# 第 13 章 类继承

**Q**：为什么需要**类继承**？

**A**：为了解决代码的**重用性**和**可扩展性**的问题。需要注意的是面向对象编程的主要目的之一是提供具有**复用性**的代码。

**Q**：类继承可以**完成哪些工作**？

**A**：在已有类的基础上**添加功能**、可以给类**添加数据**、可以**修改类方法的行为**。

**Q**：类继承有哪些**特性**？

**A**：

1）**自己使用**：可以在只用于类方法的头文件和编译后代码，仍可以使用库中的类派生出新的类；

2）**给别人使用**：在不公开实现的情况下将自己的类分发给其他人，同时允许他们在类中添加新特性。

## 13.1 一个简单的基类

**小结**：本节主要介绍了**继承类的概念和语法**、**派生类构造函数的要点（派生类初始化的语法）**、**使用派生类的语法**、**派生类和基类之间的特殊关系**等。

**程序清单**：程序清单 13.1 tabtenn0.h、13.2 tabtenn0.cpp、13.3 usett0.cpp 介绍了关于**一个基类的声明、定义、使用**用于本节后续内容的阐述。

**Q**：基类和派生类的**概念**？

**A**：从一个类派生出另一个类时，原始类称为**基类**，继承类称为**派生类**。

### 13.1.1 派生一个类

**小结**：本小节主要介绍了**如何声明一个派生类**，精华就在该小节里的一段代码。

**Q**：从基类派生出派生类的**语法**是什么？

**A**：

```c++
// RatedPlayer派生类,从基类TableTenisPlayer派生出来
class RatedPlayer: public TableTennisPlayer
```

**Q**：派生类到底从基类**继承了什么**呢？

**A**：派生类对象存储了基类的数据成员（派生类继承了基类的实现）、派生类对象可以使用基类的方法（派生类继承了基类的接口）。书本中图 13.1 很好了展示了这一特性。

**Q**：既然是继承，那么派生类也因该有自己新的东西？

**A**：派生类需要自己的**构造函数**、派生类可以根据需要**添加**额外的**数据成员**和**成员函数**。

**Q**：如何理解派生类的构造函数？

**A**：派生类的构造函数必须给新成员（如果有的话）和继承的成员提供数据。有两种方法，第 1 种是**每个成员对应一个参数**，第 2 种是**使用基类名作为参数，该参数包括基类成员变量，**具体见书本。

### 13.1.2 构造函数：访问权限的考虑

**小结**：本小节主要了讲了**如何初始化派生类的构造函数**，由于本小节代码零碎且短小，因而需加以整理。

**Q**：如何通过**成员初始化列表**来初始化派生类的构造函数？

**A**：具体代码如下。其中:TableTennisPlayer 是**成员初始化列表**,它是可执行的代码,调用 TableTennisPlayer 构造函数。

```c++
// 派生类的构造函数
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
	const string & ln, bool ht) : TabeleTennisPlayer(fn, ln, ht)
{
    rating = r;
}

// 调用派生类的构造函数
RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
```

**Q**：如果派生类的构造函数省略成员初始化列表，情况将如何？

**A**：1)具体代码如下:

```c++
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
	const string & ln, bool ht) // 没有初始化列表会怎样？
{
	rating = r;
}
```

 2)派生类构造函数的初始化必须首先创建基类对象，如果不通过初始化列表调用基类构造函数，程序将调用基类的默认构造函数。因此上述代码与下面等效：

```c++
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
	const string & ln, bool ht)	// : TableTennisPlayer()
{
	rating = r;
}
```

**Q**：如何**成员名**来初始化派生类的构造函数？

**A**：

```c++
// 方法1
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
	: TableTennisPlayer(tp)
{
	rating = r;
}

// 方法2
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
	: TableTennisPlayer(tp)， rating(r)
{
}
```

**Q**：派生类如何**访问基类的私有成员**呢？

**A**：派生类不能直接访问基类的私有成员，而**必须通过基类方法**进行访问。具体地说，派生类构造函数必须使用基类构造函数。

**声明**:创建派生类对象时，程序首先创建基类对象。

**Q**：有关派生类构造函数有哪些**要点**？

**A**：具体如下：

 1）首先创建基类对象；

 2）派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数；

 3）派生类构造函数应初始化派生类新增的数据成员。

**注意**：

1)创建派生类对象时，程序首先调用基类构造函数，然后再调用派生类构造函数；

2）基类构造函数负责初始化继承的数据成员；派生类构造函数主要用于初始化新增的数据成员；

3）派生类的构造函数总是调用一个基类构造函数；

4）可以使用初始化器列表语法指明要使用的基类构造函数，否则将使用默认的基类构造函数；

5）派生类对象过期时，程序将首先调用派生类构造函数，然后再调用基类构造函数。

**注意**：

成员初始化列表只能用于构造函数。

### 13.1.3 使用派生类

**小结**：本小节通过 3 个程序介绍了派生类的 Helloworld。

**程序清单**：程序清单 13.4 tabtenn1.h、13.5 tabtenn1.cpp、13.6 usett1.cpp 共同构成了派生类的 Helloworld。

1）程序清单 13.4 介绍了派生类的声明的语法、派生类可以拥有（也应该拥有）新的成员变量和成员函数；

2）程序清单 13.5 介绍了派生类构造函数 2 种初始化的方法；

3）程序清单 13.6 介绍了派生类初始化构造函数的具体实现、派生类的对象使用基类成员函数和基类的对象使用基类成员函数没有任何区别。

由于基类和派生类是相关的，所以把其类声明放在一起更合适。同样地，最好也将这两个类的方法定义放在一起。

阅读该小结的代码，需要注意的是，基类和派生类是如何使用基类的 public 方法的。

### 13.1.4 派生类和基类之间的特殊关系

小结：本小节主要介绍了派生类和基类一个重要的特殊关系，即在基类方法不是私有的情况下，派生类对象可以使用基类的方法。

**Q**：派生类和基类之间有哪些特殊的关系？

**A**：

1）**派生类对象可以使用基类的方法，条件是方法不是私有的**：

```c++
RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
rpalyer1.Name();	// derived object uses base method
```

2）**基类指针（或引用）可以在不进行显示类型转换的情况下指向（引用）派生类对象**：

```c++
RatedPlayer rplayer1(1140, "Mallory", "Duck", true);     // 派生类
TableTennisPlayer & rt = replayer;											// 基类
TableTennisPlayer * pt = &rplayer;
rt.Name();		// invoke Name() with reference
pt->Name();		// invoke Name() with pointer
```

3）然而，基类指针（或引用）只能用于调用基类方法：

```c++
TableTennisPlayer player("Betsy", "Bloop", true);
RatedPlayer & rr = player;		// NOT ALLOWED
RatedPlayer * pr = player;		// NOT ALLOWED
```

4）不可以将基类对象引用和地址赋给派生类引用和指针。

**Q**：我们知道了基类引用或指针类型是可以指向派生类对象的，如何使用这一特性呢？

**A**：

1）基类或派生类对象可以作为基类的引用或指针作为参数的函数的输入参数；

2）引用兼容性属性可以将基类对象初始化为派生类对象中基类部分；

3）同样，可以将派生对象赋值给基类对象，在这种情况下，程序将使用隐式重载赋值运算符。

**结论**：由于基类引用和指针可以指向派生类对象，就可以得到基类引用定义的函数或指针参数可以用于基类对象或派生类对象：

```c++
void Show(const TableTennisPlayer & rt)				// funciton with pointer parameter
{
	...
}
TableTennisPlayer player1("Tara", "Boomdea", false);
RatedPlayer rplayer1(1140, "Mallory", "Duck", ture);
Show(player1);	// works with TableTennisPlayer * argument
Show(rplayer1); // works with RatedPlayer * argument
```

## 13.2 继承：is-a 关系

**Q**：C++有哪几种继承方式？

**A**：公有继承、保护继承和私有继承。

**Q**：公有继承和 is-a 有什么关系？

**A**：

1）公有继承是继承关系中最常用的方式，它建立了一种 is-a 关系，即派生类对象也是一个基类对象，可以对基类对象执行的任何操作，也可以对派生类对象执行；

2）公有继承是 is-a 关系，而不是 has-a、is-like-a、is-implemented-as-a（作为...来实现）、uses-a 的关系。

## 13.3 多态公有继承

**Q**：多态的技术背景是什么？

**A**：当希望同一个方法在派生类和基类中的行为是不同的。换句话来说，方法的行为应取决于调用该方法的对象。因而就引入了**多态**的概念。

**Q**：多态的概念是什么？

**A**：同一个方法的行为随上下文而异。

**Q**：用哪些手段实现**多态公有继承**？

**A**：

1）在派生类中重新定义基类的方法；

2）使用虚方法。

### 13.3.1 开发 Brass 类和 BrassPlus 类

**程序清单13.7**：

1）通过程序清单 13.7 介绍了**虚方法（virtual method）的声明**，其关键字为`virtual`：

```c++
class Brass
{
 public:
	virtual void Withdraw(double amt);
}
```

2）程序将**根据对象是基类对象还是派生类对象**来确定使用哪个版本：

```c++
Brass dom("Dominic Banker", 11224, 4183.45);
BrassPlus dot("Dorothy Banker", 12118, 2592.00);
dom.ViewAcct();		// use Brase::ViewAcct()
dot.ViewAcct();		// use BrasePlus::ViewAcct()
```

3）如果方法是通过**引用或指针**而不是对象调用的，将分为如下两种情况：

1. 如果方法**没有使用关键字`virtual`**，程序将根据引用类型或指针类型选择方法；

```c++
// behavior with non-virtual ViewAcct()
// methond chosen according to reference type
Brass dom("Dominic Banker", 11224, 4183.45);	 // use Brass::ViewAcct()
BrassPlus dot("Dorothy Banker", 12118, 2592.00); // use Brass::ViewAcct()
Brass & b1_ref = dom;
Brass & b2_ref = dot;
b1_ref.ViewAcct();		// use Brass::ViewAcct()
b2_ref.ViewAcct();		// use Brass::ViewAcct()
```

2. 如果方法**使用 virtual**，程序将根据**引用或指针指向的对象的类型**来选择方法：

```c++
// behavior with non-virtual ViewAcct()
// methond chosen according to reference type
Brass dom("Dominic Banker", 11224, 4183.45);     // use Brass::ViewAcct()
BrassPlus dot("Dorothy Banker", 12118, 2592.00); // use Brass::ViewAcct()
Brass & b1_ref = dom;
Brass & b2_ref = dot;
b1_ref.ViewAcct();      // use Brass::ViewAcct()
b2_ref.ViewAcct();      // use BrassPlus::ViewAcct()
```

4）基类声明了一个**虚析构函数**，这样做是为了确保释放派生对象时，按正确的顺序调用析构函数，本章后面讲详细介绍这个问题。

1.类实现

**程序清单**： 通过程序清单 13.8 brass.cpp 说明了如何**定义虚函数**。关于定义虚构函数有如下几点声明：

1）关键字 virtual 只用于类声明的方法原型中，而没有用于程序清单 13.8 的方法定义中；

2）无访问基类私有数据的权限。派生类不能直接访问基类的私有数据，而必须使用基类的公有方法才能访问这些数据；

3）派生类构造函数在初始化基类私有数据时，采用的是成员初始化列表语法：

```c++
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
```

4）非构造喊不能使用成员初始化列表语法，但派生类方法可以调用公有的基类方法，具体代码见P496；

5）某方法设置为`virtual`，表示该方法在基类和派生类中实现的方法是不同的。在派生类中该方法可以调用基类中的该方法，但是需要加上域解析运算符来调用基类方法，具体代码见P496；

6）如果派生类没有重新定义某方法，则不需要作用域解析符，具体代码见P497。

2.使用 Brass 和 BrassPlus 类

**程序清单**：清单 13.9 usebrass1.cpp 使用了一个 Brass 对象和一个 BrassPlus 对象来测试类定义，相关程序清单有 13.7 和 13.8。

3.演示虚方法的行为

**程序清单13.10**：

1）假设要同时管理 Brass 和 BrassPlus 账户，如果能使用同一个数组来保存 Brass 和 BrassPlus 对象，将很有帮助，但这是不可能的。数组中所有元素的类型必须相同，而 Brass 和 BrassPlus 是不同的类型。然而，可以创建指向 Brass 的指针数组。这样，每个元素的类型都相同，但由于使用的是公有继承模型，因此 Brass 指针既可以指向 Brass 对象，也可以指向 BrassPlus 对象。因此，可以使用一个数组来表示多种类型的对象；

2）假设某个方法设置为`virtual`，在基类和派生类中实现均不同。如果数组成员指向的是基类对象，则使用基类方法，如果数组指向派生类对象，则使用派生类中的方法。

4.为何需要虚析构函数

**小结**：本小节通过结合程序程序清单 13.10 说明了虚析构函数的必要性。

**Q**：为何需要虚析构函数？

**A**：使用虚析构函数可以确保正确的析构函数序列被调用，具体见P501。

## 13.4 静态联编和动态联编

函数名联编（binding）：将源代码中的函数调用解释为执行特定的函数代码块被称为函数名联编。

静态联编（static binding）：在编译过程中进行联编。

动态联编（dynamic binding）：在程序运行时进行联编。

### 13.4.1 指针和引用类型的兼容性

Q:什么叫向上强制转换(upcasting)?

A:将派生类引用或指针转换为基类引用或指针称为向上强制转换,这使公有继承不需要进行显式类型转换.

### 13.4.2 虚成员函数和动态联编

1.为什么有两种类型的联编以及为什么默认为静态联编

如果要在派生类中重新定义基类的方法,则将它设置为虚方法;否则,设置为非虚方法.

2.虚函数的工作原理

Q:如何理解虚函数的工作原理?

A:关键的思想是指针,具体理解见书中图 13.5.

Q:使用虚函数具有有哪些内存和执行速度的成本?

A:

1)每个对象都将增大,增大量为存储地址的空间;

2)对于每个类,编译器都创建一个虚函数地址表(数组);

3)对于每个函数调用,都需要执行一项额外的操作,即到表中查找地址.