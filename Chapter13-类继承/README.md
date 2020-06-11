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

**Q**：基类和派生类的**概念**？

**A**：从一个类派生出另一个类时，原始类称为**基类**，继承类称为**派生类**。

Webtown俱乐部决定跟踪乒乓球会会员。作为俱乐部的首席程序员，需要设计一个简单的TableTennisPlayer类。如程序13.1和13.2所示。

**程序清单**：程序清单 13.1 tabtenn0.h、13.2 tabtenn0.cpp、13.3 usett0.cpp 介绍了关于**一个基类的声明、定义、使用**用于本节后续内容的阐述。

程序13.1 tabtenn0.h

```c++
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using std::string;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none",
              const string & ln = "none",
              bool ht = false);
    void Name() const;
    bool HasTable() const {return hasTable;}
    void ResetTable(bool v) {hasTable = v;}
};

#endif
```

程序13.2 tabtenn0.cpp

```c++
#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn,
    const string & ln, bool ht):firstname(fn), 
        lastname(ln),hasTable(ht) {}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
```

构造函数使用了第12章介绍的**初始化列表语法**，但也可以像下面这样做：

```c++
TableTennisPlayer::TableTennisPlayer(const string & fn,
                    const string & ln, bool ht)
{
    firstname = fn; 
    lastname = ln;
    hasTable = ht; 
}
```

这将首先为firstname调用string的默认构造函数，再调用string的赋值运算符将fitstname设置为fn，但初始化列表语法可以减少一个步骤，它直接使用string的复制构造函数将firstname初始化为fn。

程序13.3 usett0.cpp

```c++
#include <iostream>
#include "tabtenn0.h"

int main()
{
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player2.Name();
        if (player2.HasTable())
                cout << ": has a table.\n";
        else
                cout << ": hasn't a table.\n";

    return 0;
}
```

输出：

```
Blizzard, Chuck: has a table.
Boomdea, Tara: hasn't a table.
```

注意到该程序实例化对象将C-风格字符串作为参数：

```
TableTennisPlayer player1("Chuck", "Blizzard", true);
TableTennisPlayer player2("Tara", "Boomdea", false);
```

初始化列表语法但构造函数的形参类型被声明为const string &。这导致类型不匹配，但与第12章创建的String类一样，string类有一个将const char *作为参数的构造函数，使用C-风格字符串初始化string对象，将自动调用这个构造函数。总之，可见string对象或C-风格字符串作为构造函数TableTennisPlayer的参数；将前者作为参数时，将调用接受const string &作为参数的string构造函数，而将后者作为参数，将调用接受const char**作为参数的string构造函数。

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

具体代码见P502。

**结论**：

1）通常，C++不允许将一种类型的地址赋值给另一种类型的指针，也不允许一种类型的引用指向另一种类型；

2）但是，指向基类的引用或指针可以引用派生类对象，而不必进行显示类型转换；

**Q**:什么叫向上强制转换(upcasting)?

**A**:

1）将派生类引用或指针转换为基类引用或指针称为向上强制转换,这使公有继承不需要进行显式类型转换；

2）向上强制转换具有传递性。

**Q**:什么叫向下强制转换(downcasting)?

**A**:

1）将基类引用或指针转换为派生引用或指针称为向下强制转换,这使公有继承需要进行显式类型转换；

2）向下强制转换不安全。

### 13.4.2 虚成员函数和动态联编

结论：

1）编译器对非虚方法使用静态联编；

2）编译器对虚方法使用动态联编。

#### 1.为什么有两种类型的联编以及为什么默认为静态联编

**结论**：回答这个标题，要从效率和概念模型这2个方面回答：

1）效率：静态联编效率更高；

2）模型概念：如果要在派生类中重新定义基类的方法,则将它设置为虚方法;否则,设置为非虚方法.

#### 2.虚函数的工作原理

Q:如何理解虚函数的工作原理?

A:关键的思想是指针,具体理解见书中图 13.5.

Q:使用虚函数具有有哪些内存和执行速度的成本?

A:

1)每个对象都将增大,增大量为存储地址的空间;

2)对于每个类,编译器都创建一个**虚函数地址表(数组)**;

3)对于每个函数调用,都需要执行一项额外的操作,即到表中查找地址.

Q：虚函数地址表（virtual function table, vtbl）（数组）的定义？

A：编译器处理虚函数的方法是：给每一个对象添加一个隐藏成员，隐藏成员中保存了一个指向函数地址数组的指针，这种数组称为虚函数表。

### 13.4.3 有关虚函数注意事项

小结：本小节主要介绍了使用虚函数的注意事项，具体见P505～507。

## 13.5 访问控制：protected

**小结**：

1）private和protected之间的区别只有在**基类派生的类**中才会表现出来；

2）派生类的成员可以直接访问基类的保护成员，但不能直接访问基类的私有成员；

3）因此，对于外部世界来说，保护成员的行为与私有成员类似，但对于派生类来说，保护成员的行为与公有成员相似；

4）保护数据成员可以简化代码编写，但是存在可以被派生类随意修改的缺陷；

5）一般不使用保护数据成员，而使用保护方法。

例如，假如Brass类将balance成员声明为保护的：

```c++
class Brass
{
protected:
    double balance;
};
```

在这种情况下，BrassPlus类可以直接访问balance，而不需要使用Brass方法。例如，可以这样编写BrassPlus::Withdraw()的核心：

```c++
void BrassPlus::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive; with drawal canceled.\n"
    else if (amt <= balance)						// 可以直接使用保护型变量blance
        balance -= amt
    else if ( amt <= balance + maxLoan - owesBank)
    {
        double advance = amt - balance;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposite(advance);
        balance -= amt;
    }
    else
        cout << "Credit limit exceed. Transaction cancelled.\n";
}
```

使用保护数据成员可以简化代码的编写工作，但存在设计缺陷。例如，继续以BrassPlus为例，如果balance是受保护的，则可以按下面的方式编写代码：

```c++
void BrassPlus::Reset(double amt)
{
    balance = amt;
}
```

Brass类被设计成只能通过Deposit()和Withdraw()才能修改修改balance。但对于BrassPlusd对象，Reset()方法将忽略Withdraw()中的保护措施，实际上使balance称为公有变量。

**警告：**最好对类数据成员采用私有访问控制，不要使用保护访问控制；同时通常基类方法使派生类能够访问基类数据。

然而，对于成员函数来说，保护访问控制很有用，它让派生类能够访问公众不能使用的内部函数。

## 13.6 抽象基类

**Q**：为什么要有抽象基类（abstract base class）的概念？

**A**：抽象基类也是属于类继承的范畴，书中使用圆和椭圆的关系说明了抽象基类的必要性。圆可以派生于椭圆，然而有的椭圆的方法而圆使用不到，因而直接使用派生类不是很好的办法。如果直接声明定义圆类，这样就忽略了圆类和椭圆类之间的关系，这样也不好。因而，将圆类和椭圆类共有的方法进一步抽象，形成抽象基类。

**Q**：如何声明抽象基类？

**A**：使用纯虚函数（pure virtual function）。

Q：如何声明虚函数？

A：纯虚函数声明的结尾处为=0。C++通过使用纯虚函数提供未实现的函数。

```c++
class BaseClass
{
    private:
        double x,y;
    public:
        virtual ~BaseClass();
        //纯虚函数
        virtual void Move()const=0;   
}
```

**结论**：**当类声明中包含纯虚函数时，则不能创建该类的对象。这里的理念是，包含纯虚函数的类只能作基类。**要成为真正的抽象基类(abstract base class,ABC),必须至少包含一个纯虚函数。原型中的=0使虚函数成为纯虚函数。

例如，也许所有的基类方法都与Move()一样，可以在基类中进行定义，但您仍需要将这个声明为抽象的。在这种情况下，可以将原型声明为虚的：

```c++
void Move(int nx, ny) = 0;
```

这将使基类成为抽象的，但您仍可以实现文献中提供的方法：

```c++
void BaseEllipse::Move(int nx, ny) {x = nx, y =ny; }
```

**总之，在原型中使用=0指出类是一个抽象基类，在类中可以不定义该函数。**ABC描述的是至少使用一个纯虚函数的接口，从ABC派生出的类将根据派生类的具体特征，使用常规虚函数来实现这种接口。

### 13.6.1 应用ABC概念

将ABC概念用于Brass和BrassPlus账户。首先定义一个名为AcctABC的ABC。这个类包含Brass和BrassPlus类共有的所有方法和数据成员，而那些在BrassPlus类和Brass类中的行为不同的方法应被声明为虚函数。至少应有一个虚函数是纯虚函数，这样才能使AcctABC称为抽象类。

程序13.11的头文件声明了AcctABC类、Brass类和BrassPlus类。为帮助派生类访问基类数据，AcctABc提供了一些保护方法：派生类方法可以调用这些方法，但它们并不是派生类对象的公有接口的组成部分。AcctABC还提供一个保护成员函数，用于处理格式化。另外，AcctABC类还有两个纯虚函数，所以它确实是抽象类。

程序13.11 acctabc.h

```c++
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <string>
#include <iostream>
using std::string;

class AcctABC
{
private:
    string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const string & FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const string & s = "Nullbody", long an = -1,
        double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;		// 纯虚函数
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0;			// 纯虚函数
    virtual ~AcctABC() {}
};

class Brass : public AcctABC
{
public:
    Brass(const string & s = "Nullbody", long an = -1,
        double bal = 0.0) : AcctABC(s, an, bal) {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const string & s = "Nullbody", long an = -1, 
          double bal = 0.0, double ml = 500,
          double r = 0.10);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.10);
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif
```

程序13.12 acctabc.cpp

```c++
#include "acctabc.h"
#include <iostream>
using namespace std;

AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if ( amt < 0 )
        cout << "Negative deposit not allowed; deposite is cancelled.\n";
    else    
        balance += amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}


void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive; "
             << "withdrawal cancelled.\n";
    else if (amt <= Balance())
        Withdraw(amt);
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal cancelled.\n";
}

void Brass::ViewAcct() const 
{
    Formatting f = SetFormat();
    cout << "Barss client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

BrassPlus::BrassPlus(const string & s, long an, double bal,
        double ml, double r): AcctABC(s, an ,bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
        : AcctABC(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    Restore(f);
}
```

保护方法FullName()和AcctNum()提供了对数据成员fullName和acctNum的只读访问，使得可以进一步定制每个派生类的ViewAcct()。

这个版本在设置输出格式方面做了两项改进。前一个版本使用两个函数调用来设置输出格式，并使用一个函数调用来恢复格式：

```c++
format initialState = setFormat();
precis prec = cout.precision(2);
...
restore(initialState, prec);
```

这个版本定义了一个结构，用于存储两项格式设置；并使用该结构来设置和恢复格式，因此只需要两个函数调用：

```c++
struct Formatting
{
    std::ios_base::fmtflags flag;
    std::streamsize pr;
};

Formatting f = SetFormat();
...
Restore(f);
```

因此代码更整洁。

旧版本存在的问题是，setFormat()和restore()都是独立的函数，这些函数与客户定义的同名函数发生冲突。解决这种问题的方式有多种，一种方式是将这些函数声明为静态的，这样它们将归文件brass.cpp及其继任acctabc.cpp私有。另一种方式是，将这些函数以及结构Formatting放在一个独立的名称空间中。但这个示例探讨的主题之一是保护访问权限，因此将这些结构和函数放在了类定义的保护部分。这使得它们对基类和派生类可用，同时向外隐藏了它们。

对于Brass和BrassPlus账户的这种实现，使用方式与旧实现相同，因为类方法的名称和接口都与以前一样。例如，为程序13.10能够使用新的实现，需要采取下面的步骤将usebrass2.cpp转换为usebrass3.cpp

- 使用acctabc.cpp而不是brass.cpp来连接usebrass.cpp

- 包含文件acctabc.h，而不是brass.h

- 将下面的代码替换

  Brass * p_clients[CLIENTS];

替换为：

```c++
AcctABC * p_clients[CLIENTS];
```

程序13.13usebrass3.cpp

```c++
#include <iostream>
#include "acctabc.h"
#include <string>
const int CLIENTS = 4;
using namespace std;

int main()
{
    AcctABC * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";    
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
             << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                 << "as a decimal fraction: ";
            cin>> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, 
                            tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done!\n";
    return 0;
}
```

该程序的行为与非抽象基类版本相同，因此如果输入与给程序13.10提供的输入相同，输出也将相同。

### 13.6.2 ABC理念

设计ABC之前，首先应开发一个模型–指出编程问题所需的类以及它们之间相互关系。一种学院派思想认为，如果要设计类继承层次，则只能将那些不会被用作基类的类设计为具体的类。

**ABC要求具体派生类覆盖其纯虚函数–迫使派生类遵循ABC所设置的接口规则。这种模型在基于组件的编程模式中很常见，在这种情况下，使用ABC使组件设计人员能够制定“接口约定”，这样确保了从ABC派生的所有组件都至少支持ABC指定的功能。**

## 13.7 继承和动态分配

继承是怎样与动态内存分配(使用new和delete)进行互动的呢？例如，如果基类使用动态内存分配，并重新定义赋值运算符或复制构造函数，这将怎么影响派生类的实现呢？这个问题的答案取决于派生类的属性。如果派生类也使用动态内存分配，那么就需要学习几个新的小技巧。下面来看看这两种情况。

### 13.7.1 第一种情况：派生类不使用new

小结：当派生类不使用new时，则不需要显示析构函数、复制构造函数和赋值运算符。

假设基类使用了动态内存分配：

```
class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA &);j
    virtual ~baseDMA();
    baseDMA & operator=(cosnt baseDMA & rs);
...
};
```

声明中包含了构造函数使用new时需要的特殊方法：析构函数、复制构造函数和重载赋值运算符。

现在，从baseDMA派生出lackDMA类，而后者不使用new，也未包含其他一些不常用的、需要特殊处理的设计特性：

```
class lackDMA : pulic baseDMA
{
private:
    char color[40];
public:
...
}
```

是否需要为lackDMA类定义显式析构函数、复制构造函数和赋值运算符呢？不需要。

首先，来看是否需要析构函数。如果没有定义析构函数，编译器将定义一个不执行任何操作的默认构造函数。实际上，派生类的默认构造函数总是要进行一些操作的：执行自身的代码后调用基类析构函数。因为我们假设lackDMA成员不执行任何特殊操作，所以默认析构函数是合适的。

接着来看赋值构造函数。第12章介绍过，默认复制构造函数执行成员复制，这对于动态内存分配来说是不合适的。但对于新的lackDMA成员来说是合适的。因此只需考虑继承的basedDMA对象。要知道，成员复制将根据数据类型采用相应的复制方式，因此，将long复制到long中通过使用常规复制完成的；但复制类成员或继承的类组件时，则是使用该类的复制构造函数完成的。所以，lackDMA类的默认复制构造函数使用显式baseDMA复制构造函数来复制lackDMA对象的baseDMA部分。因此，默认复制构造函数对于新的lackDMA成员来说是合适的，同时对于继承的baseDMA对象来说也是合适的。

对于赋值来说，也是如此。类的默认赋值运算符将自动使用基类的赋值运算符来对基类组件进行赋值。因此，默认赋值运算符也是合适的。

派生类对象的这些属性也适用于本身对象的类成员。例如，第10章介绍过，实现Stock类时，可以使用string对象而不是char数组来存储公司名称。标准string类和本书前面创建的String类一样，也采用动态内存分配。现在，读者知道了为何这不会引发问题。Stock的默认复制构造函数将使用string的复制构造函数来复制对象company成员；Stock的默认赋值运算符将使用strig的赋值运算符来给对象的company成员赋值；而Stock的析构函数将自动调用string的析构函数。

### 12.7.2 第二种情况：派生类使用new

假设派生类使用了new:

```
class hasDMA : public baseDMA
{
private:
    char * style;
public:
...
};
```

在这种情况下，必须为派生类定义显式析构函数、赋值用品认识和复制构造函数。下面依次考虑这些方法。

派生类析构函数自动调用基类的析构函数，故其自身的职责是对派生类构造函数执行的工作进行清理。因此hasDMA析构函数必须释放指针style管理的内存，并依赖于basdDMA的析构函数来释放指针label管理的内存。

```
baseDMA::~baseDMA()
{
    delete [] label;
}

hasDMA::~hasDMA()
{
    delete [] style;
}
```

接下来看复制构造函数。BaseDMA的复制构造函数遵循用char数组的常规模式，即使用strlen()来获悉存储C-风格字符串所需的空间、分配足够的内存（字符数加上存储空字符所需的1字节）并使用函数strcpy()将原始字符串赋值到目的地：

```
baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}
```

hasDMA复制构造函数只能访问hasDMA的数据，因此它必须调用baseDMA复制构造函数来处理共享的baseDMA数据：

```
hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs)
{
    style = new char[std::strlen(hs.style + 1)];
    stdJ::strcpy(style, hs.style);
}
```

需要注意的一点是，成员初始化列表将一个hasDMA引用传递给baseDMA构造函数。没有参数类型为hasDMA引用的base构造函数，也不需要这样的构造函数。因为复制构造函数baseDMA有一个baseDMA引用参数，而基类可以指向派生类型。因此baseDMA复制构造函数将使用hasDMA参数的baseDMA部分来构造新对象的baseDMA部分。

接下来看赋值运算符。BaseDMA赋值运算符遵循下述常规模式：

```
baseDMA & baseDMA::operator(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + r];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
```

由于hasDMA也使用动态内存分配，所以它需要一个显式赋值运算符。作为hasDMA的方法，它只能直接访问hasDMA的数据。然而，派生类的显式赋值运算符必须负责所有的baseDMA基类对象的赋值，可以通过显式调用基类赋值运算符来完成这项工作，如下所示：

```
hasDMA & hasDMA::operator=(cosnt hasDMA & hs)
{ 
    if ( this == &hs)
        return *this;
    baseDMA::operator=(hs);
    delete [] style;
    style = new char [std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
```

下述语句看起来有点奇怪：

```
baseDMA::operator=(hs);
```

但是通过使用函数表示法，而不是运算符表示法，可以使用作用域解析运算符。实际上，该语句的含义如下：

```
*this = hs;  //使用baseDMA::operator=();
```

当然，编译器将忽略注释，所以使用后面的代码时，编译器将使用hasDMA::operator=()，从而形程递归调用。使用函数表示使得赋值运算符被正确调用。

总之，当基类和派生类都采用动态内存分配时，派生类的析构函数、复制构造函数和赋值运算符都必须使用相应的基类方法来处理基类元素。这种要求通过三种不同的方式来满足。对于析构函数，这是自动完成的；对于构造函数，这是通过在初始化成员列表中调用基类的复制构造函数来完成的；如果不这样做，将自动调用基类的默认构造函数。对于赋值运算符，这是通过使用作用域解析运算符乡试第调用基类的赋值运算符来完成的。

### 13.7.3 使用动态内存分配和友元的继承示例

为演示这些有关继承和动态分配的概念，我们将刚才介绍过的baseDMA、lackDMA和hasDMA类集成到一个示例中。程序13.14是这些类的头文件。除前面介绍的内容外，这个头文件还包含一个友元函数，以说明派生类如何访问基类的友元。

程序13.14 dma.h

```
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};


class lackDMA : public baseDMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lackDMA(const char * c = "blank", const char * l = "null",
             int r = 0);
    lackDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lackDMA & rs);
};

class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * c = "none", const char * l = "null",
            int r = 0);
    hasDMA(const char * c, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    hasDMA & operator=(const hasDMA & hs);
    ~hasDMA();
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif
```

程序13.15 dma.cpp

```
#include <iostream>
#include "dma.h"
#include <cstring>
using namespace std;

baseDMA::baseDMA(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

ostream & operator<<(ostream & os, const baseDMA & rs)
{
    os << "Label: " << rs.label << endl;
    os << "Rating: " << rs.rating << endl; 
    return os;
}

lackDMA::lackDMA(const char * c, const char * l, int r) : baseDMA(l, r)
{
    strncpy(color, c, COL_LEN-1);
    color[COL_LEN-1] = '\0';
}

lackDMA::lackDMA(const char * c, const baseDMA & rs) : baseDMA(rs)
{
    strncpy(color, c, COL_LEN-1);
    color[COL_LEN-1] = '\0';
}

ostream & operator<<(ostream & os, const lackDMA & rs)
{
    os << (const baseDMA &) rs;
    os << "Color: " << rs.color << endl;
    return os;
}

hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & hs) : baseDMA(hs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

ostream & operator<<(ostream & os, const hasDMA & rs)
{
    os << (const baseDMA &) rs;
    os << "Style: " << rs.style << endl;
    return os;
}
```

在程序13.14和13.15中，需要注意的特性是，派生类如何使用基类的友元。例如，请考虑下面这个hasDMA类的友元：

```
friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
```

作为hasDMA类的友元，该函数能够访问style成员。然而，还存在一个问题：该函数如不是baseDMA类的友元，那它如何访问成员label和rating呢？答案是使用baseDMA类的友元函数operator<<()。

下一个问题是，因为友元不是成员函数，所以不能使用作用域解析运算符指出使用哪个函数。这个问题的解决办法是使用强制类型转换，以便匹配原型能够选择正确的函数。因此代码将参数const hasDMA & 转换成类型const baseDMA &的参数：

```
ostream & operator<<(ostream & os, const hasDMA & rs)
{
    os << (const baseDMA &) rs;
    os << "Style: " << rs.style << endl;
    return os;
}
```

程序13.16是一个测试小程序。

程序13.16 usedma.cpp

```
#include "dma.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    baseDMA shirt("Portabelly", 8);
    lackDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Display baseDMA object:\n";
    cout << shirt << endl;
    cout << "Display lackDMA object:\n";
    cout << balloon << endl;
    cout << "Display hasDMA object:\n";
    cout << map << endl;
    lackDMA balloon2(balloon);
    cout << "Result of lackDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Resutl of hasDMA assignment:\n";
    cout << map2 << endl;
    return 0;
}
```

输出：

```
Display baseDMA object:
Label: Portabelly
Rating: 8

Display lackDMA object:
Label: Blimpo
Rating: 4
Color: red

Display hasDMA object:
Label: Buffalo Keys
Rating: 5
Style: Mercator

Result of lackDMA copy:
Label: Blimpo
Rating: 4
Color: red

Resutl of hasDMA assignment:
Label: Buffalo Keys
Rating: 5
Style: Mercator
```