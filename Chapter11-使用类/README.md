# 第11章 使用类

## 本章内容包括:

- 运算符重载
- 友元函数
- 重载<<运算符,以便于用于输出
- 状态成员
- 使用rand()生成随机值
- 类的自动转换和强制类型转换
- 类转换函数

本章首先介绍运算符重载，它允许将标准C++运算符(如+和=)用于类对象。然后介绍友元，这种C++机制使得非成员函数可以访问私有数据。最后，介绍如何命令C++对类执行自动类型转换。

**相关章节**：第10章。

Q：如何更好的掌握C++的新特性？

A：如果函数使用常规参数而不是引用参数，将发生什么情况呢？如果忽略了析构函数，又将发生什么情况呢？

**学习方法**：

1）不要害怕犯错误，因为在解决问题的过程中学到的知识，比生搬硬套而不犯错误要多得多（然而，不要认为所有的错误都会让人增长见识）；

2）学习本章知识最好的最好方法是，在我们**自己开发的C++程序**中使用其中的新特性。对这些新特性有了充分的认识后，就可以添加其他C++特性了。

3）C++创始人Bjarne Stroustrup在一次C++专业程序员大会上所建议的：“轻松地使用这种语言。不要觉得必须使用所有的特性，不要在第一次学习时试图使用所有的特性。“

##  11.1 运算符重载

**小结**：本节主要介绍了运算符重载的技术背景、语法。本质上来讲，运算符重载是用于相同类的不同对象之间计算的方法。

**相关章节**：第8章的函数重载和函数多态

**Q**：为什么需要运算符重载？

**A**：使得同个类的不同对象之间也可以实现加减等运算。

**Q**：如何**理解**运算符重载？

**A**：运算符重载是一种形式的C++**多态**。

**Q**：运算符重载函数的语法？

**A**：

```c++
operator op(argument-list)
```

例如，operator+()重载+运算符，operator∗∗()重载∗∗运算符。op必须是有效的C++运算符，不能虚构一个新的符号。例如，不能有operator@()这样的函数，因为C++中没有@运算符。然而，operator[]()函数重载[]运算符，因为[]运算符是数组索引运算符。

例如，假设有一个Salesperson类，并为它定义了一个opeartor+()成员函数，以重载+运算符，以便能够将两个Saleperson对象的销量相加，则如果district2、sid和sara都是Salesperson类对象，便可以编写这样的等式：

```
district2 = sid + sara;
```

编译发现，操作数是Salesperson类对象，因此使用相应的运算符函数替换上述运算符：

```c++
district2 = sid.operator+(sara);
```

该函数将隐式地使用sid（因为它强调了方法），而显式地使用sara（因为他被作为参数传递），来计算总和，并返回这个值。当然最重要的是，可以使用简便的+运算符表示法，而不必使用笨拙的函数表示法。

##  11.2 计算时间：一个运算重载示例

**小结**：本小节介绍了关于运算符重载的示例，并无新知识。

如果今天早上在Priggs的账户上花费了2个小时35分钟，下午又花费了2小时40分钟，则总共花了多少时间？这个示例与加法的概念很吻合，但要相加的单位(小时与分钟的混合)与内置的类型不匹配。第7章通过定义一个travel_time结构和将这种结构相加的sum()函数来处理类似的情况。现在将其推广，采用一个使用方法来处理加法的Time类。首先使用一个名为Sum()的常规方法，然后介绍如何将其转换为重载运算符。程序11.1列出了这个类声明。

程序11.1 mytime0h

```c++
#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time & t) const;		// 需要关注的方法
    void Show() const;
};

#endif
```

程序11.2 mytime0.cpp

```c++
#include <iostream>
#include "mytime0.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours = minutes / 60;
    minutes = minutes % 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time & t) const		// 需要关注的方法
{
    Time sum;								// sum为局部变量
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes.";
}
```

Q：对于Sum()函数，为什么这里参数是引用，但返回类型却不是引用？

A：

1）将参数声明为引用的目的是为了提供效率。如果直接传递Time对象，代码的功能将相同，但传递引用的速度更快，使用的内存将更少。

2）然而，返回值不是引用。因为函数将创建一个新的Time对象(sum)，来表示另两个Time对象的和。返回对象(如代码所做的那样)将创建副本对象，而调用函数可以使用它。然而，如果返回类型是为Time &，则引用的将是sum对象。但由于sum是局部变量，在函数结束时将被函数，因此引用将指向一个不存在的对象。使用返回类型Time意味着程序将在删除sum之前构造它的拷贝，调用函数将得到该拷贝。

**注意**：**不要返回指向局部变量或临时对象的引用**。函数执行完毕后，局部变量和临时对象将消失，引用将指向不存在的数据。

程序11.3 usetime0.cpp

```c++
#include <iostream>
#include "mytime0.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;
    return 0;
}
```

输出：

```shell
[root@localhost ~]# g++ mytime0.cpp usetime0.cpp -o file
[root@localhost ~]# ./file
planning time = 0 hours, 0 minutes.
coding time = 2 hours, 40 minutes.
fixing time = 5 hours, 55 minutes.
coding.Sum(fixing) = 8 hours, 35 minutes.
```

### 11.2.1 添加加法运算符

**程序清单**：

1）程序清单11.4 mytime1.h、11.5 mytime1.cpp说明了如何声明和定义”运算符成员函数“。具体而言，程序清单11.4和11.5分别是对11.2和11.5的改进，将`Time::Sum()`的名称改为`Time::operate+()`即可。

2）程序清单11.6 usetime1.cpp说明了使用加法运算符的两种方法，具体如下：

```c++
total = coding.operator+(fixing);	// 方法1：与一般成员函数一致的使用方法
total = coding + fixing;			// 方法2：运算符表示法
```

**提示**：如果t1、t2、t3都是Time对象，以下运算是合法的，需要理解原因，书本中也详细说明了。

```c++
t4 = t1 + t2 + t3;
```

将Time类转换为重载的加法运算符很容易，只要将Sum()的名称改为operator + ()即可。这样做是对的。只要把运算符(这里为+)放到operator的后面，并将结果用作方法名即可。在这里，可以在标识符中使用字母、数字或下划线之外的其他支付。程序11.4和程序11.5反映了这些细微的修改。

程序11.4 mytime1.h

```c++
#ifndef MYTIME1_H_
#define MYTIME1_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;	// 需要注意的方法
    void Show() const;
};

#endif
```

程序11.5 mytime1.cpp

```c++
#include <iostream>
#include "mytime1.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours = minutes / 60;
    minutes = minutes % 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const		// 需要注意的方法
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes.";
}
```

程序11.6 usetime1.cpp

```c++
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;					// 需要注意
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);		// 需要注意
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    return 0;
}
```

输出：

```shell
planning time = 0 hours, 0 minutes.
coding time = 2 hours, 40 minutes.
fixing time = 5 hours, 55 minutes.
coding + fixing = 8 hours, 35 minutes.
more fixing time = 3 hours, 28 minutes.
morefixing.operator+(total) = 12 hours, 3 minutes.
```

总之，operator+()函数的名称使得可以使用函数表示法或运算符表示法来调用它。编译器根据操作的类型来确定如何做：

```c++
int a, b, c;
Time A, B, C;
c = a + b; //使用整型加法
C = A + B; //使用为Time对象定义的加法
```

可以将两个以上的对象相加吗？例如，如果t1,t2,t3,t4都是Time对象，可以这样做吗：

```c++
t4 = t3 + t2 + t1;
```

为回答这个问题，来看一些上述语句将如何被转换为函数调用。由于+是从左向右的运算符，因此上述语句首先被转换成如下这样：

```c++
t4 = t3.operator+(t2+t1);
```

然后，函数参数本身被转换成一个函数调用，如下：

```c++
t4 = t3.operator(t2.operator+(t1));
```

上述语句合法。函数调用t2.operator+(t1)返回一个Time对象，后者是t2和t1的和。然而，该对象成为函数调用t3.operator+()的参数，该调用返回t3与表示t2和t1之和的Time对象的和。总之，最后的返回值为t1、t2和t3之和。

### 11.2.2 重载限制

**小结**：多数C++运算符都可以重载，可以重载的运算符见表11.1。这就说明有些运算符是不可以重载的。

多数C++运算符都可以用这样的方式重载。重载的运算符（有些例外情况）不必是成员函数，但必须至少有一个操作数是用户定义的类型。下面详细介绍C++对用户定义的运算符重载的限制。

1. 重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。因此，不能将减法运算符(-)重载为计算两个doulbe值的和，而不是它们的差。虽然，这种限制将对创造性有所影响，但可以确保程序正常运行。

2. 使用运算符时不能违反运算符原来的句法规则。例如，不能将求模运算符(%)重载成使用一个操作数：

   int x;
   Time shiva;
   % x; //错误语法
   % shiva; //错误语法

同样，不能修改运算符的优先级。因此，如果将加法运算符重载成为两个类相加，则新的运算符与原来的加号具有相同的优先级。

1. 不能创建新运算符。例如，不能定义operator∗∗∗∗()函数来表示求幂。
2. 不能重载下面的运算符：

- sizof sizeof运算符。
- . 成员运算符。
- .∗∗ 成员指针运算符。
- :: 作用域解析运算符
- ?: 条件运算符
- typeid 一个RTTI运算符
- const_cast 强制类型转换运算符
- dynamic_cast 强制类型转换运算时
- reinterpret_cast 强制类型转换运算符
- static_cast 强制类型转换运算符

然而表11.1中所有的运算符都可以重载。

1. 表11.1中的大多数运算生都可以通过成员或非成员函数进行重载，但下面的运算符只能通过成员函数进行重载。

- = 赋值运算符
- () 函数调用运算符
- [] 下表运算符
- -> 通过指针访问类成员的运算符

表11.1

可重载的运算符

| +    | -    | *    | /    | %    | ^    |
| :--- | ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |      |
| &    | \|   | ~=   | !    | =    | <    |
| ---- | ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |      |
| >    | +=   | -=   | * =  | /=   | %=   |
| ---- | ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |      |
| ^=   | &=   | ==   | <<   | >>   | >>=  |
| ---- | ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |      |
| <<=  | ==   | !=   | <=   | >=   | &&   |
| ---- | ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |      |
| \|\| | ++   | –    | ,    | ->*  | ->   |
| ---- | ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |      |
| ()   | []   | new  | delete | new[] | delete[] |
| ---- | ---- | ---- | ------ | ----- | -------- |
|      |      |      |        |       |          |

除了这些限制外，还应在重载运算符时遵循一些明智的限制。例如，不要将∗∗运算符重载成交换两个Time对象的数据成员。表示法中没有任何内容可以表明交换对象的运算符完成的工作，因此最好定义一个其名称具有说明性的类方法，如Swap()。

### 11.2.3 其他重载运算符

**程序清单**：程序清单11.7 mytime2.h、11.8 mytime2.cpp、11.9 usetime2.cpp说明了创建`operator-()`和`operator*()`的方法，其实都和之前的`operator+()`一样的。

还有一些其他的操作对Time类来说是有意义的。例如，可能要将两个时间相减或将时间乘以一个因子，这需要重载减法和乘法运算符。这和重载加法运算符的技术相同，即创建operator-()和operator∗∗()方法。即，将下面的原型添加到类声明中：

```c++
Time operator-(const Time & t) const;
Time operator*(const Time & t) const;
```

程序11.7 mytime2.h

```c++
#ifndef MYTIME2_H_
#define MYTIME2_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const;
    void Show() const;
};

#endif
```

程序11.8 mytime2.cpp

```c++
#include <iostream>
#include "mytime2.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours = minutes / 60;
    minutes = minutes % 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes +  60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = (minutes + hours * 60) * mult;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes.";
}
```

程序11.9 usetime2.cpp

```c++
#include <iostream> 
#include "mytime2.h"

int main()
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;
    total.Show();
    cout << endl;

    cout << "weeding time - waxing time = ";
    diff = weeding - waxing;
    diff.Show();
    cout << endl;

    cout << "adjusted work time = " ;
    adjusted = total * 1.5;
    adjusted.Show();
    cout << endl;
    return 0;
}
```

输出：

```shell
[root@localhost ~]# g++ mytime1.cpp usetime2.cpp -o file
[root@localhost ~]# ./file
weeding time = 4 hours, 35 minutes.
waxing time = 2 hours, 47 minutes.
total work time = 7 hours, 22 minutes.
weeding time - waxing time = 1 hours, 48 minutes.
adjusted work time = 11 hours, 3 minutes.
```

## 11.3 友元

**Q**：为什么需要**友元**的概念?

**A**：由于C++控制对**类对象私有部分**的访问.通常,公有类方法提供唯一的访问路径,但是有时候这种限制太严格,以致于不适合特定的编程问题.在这种情况下,C++提供了另外一种形式的访问权限:友元.

**Q**：友元的**分类**？

**A**：友元分为3种，分别为：

1）友元函数；

2）友元类；

3）友元成员函数。

**Q**：为何**需要**友元？

**A**：在为类重载二元运算符时（带两个参数的运算符）常常需要友元：

```c++
A = B * 2.75;
A = B.operator*(2.75);	// 与上一行代码等价

A = 2.75 * B;			// cannot correspond to a member function
```

​	**说明**：左侧的操作数应是调用对象。

**Q**：如何解决`A = 2.75 * B`非法的问题？

**A**：使用**非成员函数**（记住，大多数运算符都可以通过成员或非成员函数来重载）。非成员函数不是由对象调用的，它使用的所有值（包括对象）都是显式参数。

这样，编译器能够将下面的表达式：

```c++
A = 2.75 * B;
```

与下面的**非成员函数调用匹配**：

```c++
A = operator*(2.75, B);
```

该函数的**原型**如下：

```c++
Time operator*(double m, const Time & t);
```

对于非成员重载运算符函数来说，运算符表达式左侧的操作数对应于运算符函数的第一个参数，运算符表达式右侧的操作数对应于运算符函数的第二个参数。而原来的成员函数则按相反的顺序处理操作数，即double值乘以Time值。

使用非成员函数可以按所需的顺序获取操作数，但引发一个问题：**非成员函数不能直接访问类的私有数据，至少常规非成员函数不能访问**。然而，有一类特殊的非成员函数可以访问类的私有成员，它们被成为友元函数。

​		**说明**：常规的非成员函数不能直接访问类的私有数据。然而是可以用特殊的非成员函数来解决之一问题，这种函数被称为友元函数。

### 11.3.1 创建友元

**小结**：本小节介绍了如何声明和定义友元函数、友元和类的关系。

**Q**：如何**声明**友元？

**A**：**将友元放在类声明中**，并在原型声明前加上关键字`friend`：

```c++
friend Time operator*(double m, const Time & t);	// goes in class declaration
```

​	**说明**：

​	1）虽然`operator*()`函数是在类声明中声明的,但它不是成员函数,因此不能使用成员运算符来调用;

​	2）虽然`operator*()`函数不是成员函数，但它与成员函数的访问权限相同。

**Q**：如何**定义**友元？

**A**：因为友元函数不是成员函数，所有**不要使用`Time::`限定符**。另外，**不要在定义中使用关键字`friend`**，定义应该如下(书本中的代码段中的`mult`应为`m`：

```c++
Time operator*(double m, const Time & t)	// friend not used in definition
{
    Time result;
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
```

**友元是否有悖于OOP**

乍一看，可能会认为友元违反了OOP数据隐藏的原则，因为友元机制允许非成员函数访问私有数据。然而，这个观点太片面。相反，应将友元函数看作类的扩展接口的组成部分。只有类声明可以决定哪一个函数是友元函数，因此类声明仍然控制了哪些函数可以访问私有数据。总之，类方法和友元知识表达类接口的两种不同机制。

实际上，按上面的方式定义进行修改（交换乘法操作的顺序），可以将这个友元函数编写为非友元函数：

```c++
Time operator*(double m, const Time & t)
{
    return t * m;
}
```

原来的版本显式地访问t.minutes和t.hours，所以他必须是友元。这个版本Time对象t作为一个整体使用，让成员函数来处理私有制，因此不必是友元函数。然而，将该版本作用友元也是一个好主意。最重要的是，他将该作为正式类接口的组成部分。其次，如果以后发现需要函数直接访问私有数据，则只要修改函数定义即可，而不必修改类原型。

**提示**：如果要为类重载运算符，并将非类的项作为其第一个操作数，则可以用友元函数来反转操作数的顺寻。

### 11.3.2 常用的友元：重载<<运算符

**小结**：本小节介绍了重载<<运算符的技术背景、定义、使用。

一个很有用的特性，可以对<<运算符进行重载，使之能与cout一起来显式对象的内容。与前面介绍的示例相比，这个重载要复杂些，因为我们分两步来完成。

假设trip是一种Time对象。为显式Time的值，前面使用的是Show()。然而，如果可以像下面这样操作将更好：

```c++
cout << trip;
```

之所以可以这样做，是因为<<是可被重载的C++运算符之一。实际上，它已经被重载很多次了。最初，<<运算符是C和C++的位运算符，将值中的位左移。ostream类对该运算符进行了重载，将其转换为一个输出工具。前面讲过，cout是一个ostream对象，它是智能的，能够识别所有的C++基本类型。这是因为对于每种基本类型，ostream中都包含了相应的重载的operator>>()定义。即，一个定义使用int参数，一个定义使用double参数等等。因此要使cout能够识别cout对象，一种方法是将一个新的函数运算符定义添加到ostream类声明中。但修改ostream文件是个危险的注意，这样做会在标准接口上浪费时间。相反，通过Time类声明来让Time类知道如何使用cout。

**程序清单**：程序清单11.10 mytime3.h、11.11 mytime3.cpp、11.12 usetime3.cpp共同构成了重载<<运算符的helloworld。

**相关章节**：第6、8、13章。

**Q**：重载<<运算符的**技术背景**是什么？

**A**：使得<<运算符能与`cout`一起来显示对象的内容。

**提示**：一般来说，要重载<<运算符来显示c_name的对象,可使用一个友元函数,其定义如下:

```c++
ostream & operator<<(ostream & os, const c_name & obj)
{
	os << ...;	// display object contents
	return os;
}
```

**1. <<的第一种重载版本**

要使Time类知道使用cout，必须使用友元函数。这是因为下面这样的语句使用两个对象，其中第一个是ostream对象(cout):

```c++
cout << trip;
```

如果使用一个Time成员函数来重载<<,Time对象将是第一个操作数，就像使用成员函数重载∗∗运算符那样。这意味着必须这样使用<<:

```c++
trip << cout;
```

这样会令人迷惑。但通过使用友元函数，可以像下面这样重载运算符：

```c++
void operator<<(ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
}
```

这样做可以使用下面的语句：

```c++
cout << trip;
```

友元还是非友元

新的Time类声明使operator<<()函数成为Time类的一个友元函数。但该函数不是ostream类的友元。operator<<()函数接受一个ostream参数和一个Time参数，因此表面看起来它必须同时是两个类的友元。然而，看看代码会发现，尽管该函数访问了Time对象的各个成员，但从始至终都将ostream对象看作一个整体使用。因为operator<<()访问了Time对象的私有成员，所以它必须是Time的友元。但由于它并不直接访问ostream对象的私有成员，所以并不一定必须是ostream类的友元。这样，就不需要修改ostream的定义。

不知道其他ostream函数?

另一个ostream对象是cerr，它将输出发送到标准输出流—默认为显示器，但在UNIX、Linux和Windows命令行环境中，可以标准错误流重定向到文件中。另外，第6章介绍的ofstream对象将输出写入文件中。通过继承(参见第13章），ofstream对象可以使用ostream的方法。这样，便可以使用operator<<()定义来将Time的数据写入到文件和屏幕上，为此，只需传递一个经过适当初始化的ofstream对象(而不是cout对象)。

调用cout << trip应使用cout对象本身，而不是它的拷贝，因此该函数按引用来传递该对象。这样，表达式cout<<trip将导致ost成员cout的一个别名；而表达式cerr<<trip将导致os成为cerr的一个别名。Time对象可以按值或按引用来创建，因为这两种形式都使函数能够使用对象的值。按引用传递使用的内存和时间都比按值传递少。

**2. <<的第二种重载版本**

前面介绍的实现存在一个问题。就像下面这样的语句可以正常工作：

```c++
cout << trip;
```

但这种实现不允许像通常那样将重新定义的<<运算符与cout一起使用：

```c++
cout << "Trip time: " << trip << "(Tuesday)\n"; //错误
```

要理解这样做不可行的原因及必须如何做才能使其可行，首先需要了解关于cout操作的一点知识。请看下面的语句：

```c++
int x = 5;
int y = 8;
cout << x << y;
```

C++从左到右读取输出语句，意味着它等同于：

```c++
(cout << x) << y;
```

正如iostream中定义的那样，<<运算符要求左边是一个ostream对象。显然，因为cout是ostream对象，所以表达式cout<<x满足这种要求。然而，因为表达式cout<<x位于<<y的左侧，所以输出语句也要求该表达式是一个ostream对象。因此，ostream类将operator<<()函数实现为返回一个指向ostream对象的引用。具体说，它返回一个指向调用对象(这里是cout)的引用。因此，表达式(cout<<x)本身就是ostream对象cout，从而可以位于<<运算符的左侧。

可以对友元函数采用相同的方法。只要修改operator<<()函数，让它返回ostream对象的引用即可：

```c++
ostream & operator<<(ostream & os, const Time & t)
{
    os << t.hours << " hours. " <<  t.minutes << " minutes.";
    return os;
}
```

注意返回类型是ostream &。这意味着该函数返回ostream对象的引用。因为函数开始执行时，程序传递了一个转向引用给它，这样做的最终结果时，函数的返回值就是传递给它的对象。及，下面的入局：

```c++
cout << trip;
```

将被转换为下面的调用：

```c++
operator<<(cout, trip);
```

而该调用函数返回cout对象。因此，下面的语句可以正常工作：

```
cout << "Trip time: " << trip << "(Tuesday)\n";
```

有趣的是，这个operator<<()版本还可用于将输出写入文件中：

```c++
#include <fstream>
ofstream fout;
fout.open("savetime.txt");
Time trip(12, 40);
fout << trip;
```

其中最后一条语句将转换为这样：

```c++
operator<<(fout, trip);
```

另外，正如第8章指出的，类继承属性让ostream引用能够指向ostream对象和ofstream对象。

**提示：**一般来说，要重载<<运算符来显式c_name对象，可使用一个友元函数，其定义如下：

```c++
ostream & operator<<(ostream & os, const c_name & obj)
{
    os << ...;
    return os;
}
```

程序11.10列出了修改后的类定义，其中包括operator*()和operator<<()这两个友元函数。他将一个友元函数作为内联函数。

程序11.10 mytime3.h

```c++
#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const;
    friend Time operator*(double mult, const Time & t)						// 新知识
        { return t * mult;}
    friend std::ostream & operator<<(std::ostream & os, const Time & t);	// 新知识
};

#endif
```

程序11.11 mytime3.cpp

```c++
#include <iostream>
#include "mytime3.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours = minutes / 60;
    minutes = minutes % 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes +  60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = (minutes + hours * 60) * mult;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)		// 新知识
{
    os << t.hours << " hours, " << t.minutes << "minutes.";
    return os;
}
```

程序11.12 usetime3.cpp

```c++
#include <iostream>
#include "mytime3.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 46);
    Time temp;

    cout << "Aida and Tosca: \n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;		// 新知识

    return 0;
}
```

输出：

```shell
Aida and Tosca: 
3 hours, 35minutes.; 2 hours, 46minutes.
Aida + Tosca: 6 hours, 21minutes.
Aida * 1.17: 4 hours, 11minutes.
10.0 * Tosca: 27 hours, 40minutes.
```

## 11.4 重载运算符：作为成员函数还是非成员函数

**注意**：非成员函数实现运算符重载所需的参数数目与运算符使用的操作数目相同；而成员函数实现运算符重载的参数数目少一个，因为其中的一个操作数是被隐式地传递的调用对象。

对于很多运算符来说，可以选择使用成员函数或非成员函数来实现运算符重载。一般来说，非成员函数应该是友元函数，这样它才能直接访问类的私有数据。例如，Time类的加法运算符在Time类声明中的原型如下：

```c++
Time operator+(const Time & t) const;
```

这个类也可以使用下面的原型：

```c++
friend Time operator(const Time &t1, const Time & t2);
```

加法运算符需要两个操作数。对于成员函数版本来说，一个操作数通过this指针隐式地传递，另一个通过操作数作为函数参数显式地传递；对于友元版本来说，两个操作数都作为参数传递。

记住两个格式必须选择一种格式，而不能同时选择两种格式。因为这两种格式都与同一个表达式匹配，同时定义这两种格式将被视为二义性，导致编译错误。

## 11.5 再谈重载：一个矢量类

描述矢量需要两个数：

- 可以用大小(长度)和方向(角度)描述矢量；
- 可以用分量x和y表示矢量。

程序11.13列出了这个类的声明。为复习名称空间，该清单见类声明放在VECTOR名称空间中。另外，该程序使用枚举创建了两个常量(RECT和POL)，用于标识两种表示法。

程序11.13 vector.h

```c++
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
namespace VECTOR
{
    class Vector
    {    
    public:
        enum Mode {RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}				
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector & b) const;		// 以下6个方法为新知识
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif
```

注意，程序中4个报告分量值的函数（xval()到angval()）是在类中声明的，因此自动成为内联函数。

程序14利用名称空间的开放性，将方法定义添加到VECTOR名称空间中。另外，C++的内置数学函数在使用角度时以弧度为单位，所以函数在度和弧度之间进行转换。

程序11.14 vector.cpp

```c++
#include <iostream>
#include <cmath>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);


    //private methods;
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    //public methods;
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
                mode = form;
                if (form == RECT)
                {
                        x = n1;
                        y = n2;
                        set_mag();
                        set_ang();
                }
                else if (form == POL)
                {
                        mag = n1;
                        ang = n2 / Rad_to_deg;
                        set_x();
                        set_y();
                }
                else
                {
                        cout << "Incorrect 3rd argument to Vector() -- ";
                        cout << "vector set to 0\n";
                        x = y = mag = ang = 0.0;
                        mode = RECT;
                }
    }

    Vector::~Vector()
    {}

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector & b) const	// 以下代码为新
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x*n ,y*n);
    }

    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y  << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m, a) = (" << v.mag << ", " << v.ang << ")";
        }
        else
            os << "Vector object mode is invalid!";
        return os;
    }
}
```

reset方法并非必不可少。假设shove是一个Vector对象，您编写了如下代码：

```c++
shove.reset(100, 300);
```

可以使用构造函数来得到相同的结果：

```c++
shove = Vector(100, 300);
```

然而，reset()直接修改shove的内容，而使用构造函数将增加额外的步骤：创建一个临时对象，然后将其赋值给shove。

### 11.5.1 使用状态成员

Vectore类存储了矢量的直角坐标和极坐标。它使用名为mode的成员来控制使用构造函数、reset()方法和重载operator<<()函数使用哪种形式，其中枚举RECT表示直角坐标模式(默认值)，POL表示极坐标模式。这样的成员被称为状态成员，因为这种成员描述的是对象所处的状态。

由构造函数的代码可知，第三个参数RECT或省略了，则将输入解释为直角坐标；如果为POL，则将输入解释为极坐标：

```c++
Vector folly(3.0, 4.0);
Vector foolery(20.0, 30.0, VECTOR::Vector::POL);
```

标识符POL的作用域为类，因此类定义可使用未限定的名称。但全限定名为VECTOR::Vector::POL，因为POL是在Vector类中定义的，而Vector是在名称空间VECTOR中定义的。

operator<<()函数也是用模式来确定如何显式值。由于operator<<()是一个友元函数，而不在作用域内，因此必须使用Vector::RECT，而不能直接使用RECT。因为友元函数在名称空间VECTOR中，因此无需使用全限定名VECTOR::Vector::RECT。

### 11.5.2 为Vector类重载算术运算符

在使用x,y坐标时，将两个矢量相加将非常简单，只要将两个x分量相加，得到最终的x分量，将两个y分量相加得到y分量即可。根据描述，可以使用如下代码：

```c++
Vector Vector::operator+(const Vector & b) const
{
    Vector sum;
    sum.x = x + b.x;
    sum.y = y + b.y;
    return sum;
}
```

如果对象只存储x和y分量，则这很好。遗憾的是，上述代码无法设置极坐标值。可以通过添加另外一些代码来解决这个问题：

```c++
Vector Vector::operator+(const Vector & b) const
{
    Vector sum;
    sum.x = x + b.x;
    sum.y = y + b.y;
    sum.set_ang(sum.x, sum.y);
    sum.set_mag(sum.x, sum.y);
    return sum;
}
```

然而，使用构造函数来完成这种工作，将更简单，更可靠：

```c++
Vector Vector::operator+(const Vecotr & b) const
{
    return Vector(x + b.x, y + b.y);
}
```

上述的代码将新的x和y分量传递给Vector构造函数是，而后者将使用这些值来创建无名的新对象，并返回这个对象的副本。这确保了新的Vector对象是根据构造函数的标准规则创建的。

**提示：**如果方法通过计算得到一个新的类对象，则应考虑是否可以使用类构造函数来完成这种工作。

**1. 乘法**

将矢量与一个数相乘，将使该矢量加长或缩短。因此，将矢量乘以3得到的矢量的长度为原来的三倍，而角度不变。要在Vector类中实现矢量的这种行为很容易。对于极坐标，只要将长度进行伸缩，并保持角度不变；对于直角坐标，只需要将x和y分量进行伸缩。

```
Vector  Vector::operator*(double n) const
{
    return Vector(x * n, y * n);
}
```

和重载加法一样，上述代码允许构造函数使用新的x和y分量来创建正确的Vector对象。上述函数用于处理Vector值和double相乘。可以像Time示例那样，使用一个内联友元函数来处理double与Vector相乘：

```
friend Vector Vector::operator*(double n, const Vector & a) 
{
    return a * n;
}
```

**2. 对已重载的运算符进行重载**

在C++中，-(负号)运算符有两种函数。首先，使用两个操作数，它是减法运算符。其次，使用一个操作数时，它是负号运算符。对于矢量来说，这两种操作都是有意义的，因此Vector类有这两种操作。

要从矢量A中减去矢量B，只要将分量相减即可，因此重载减法与重载加法相似。

操作的顺序非常重要。下面的语句：

```
diff = v1 - v2;
```

将转换为下面的成员函数调用：

```
diff = v1.operator-(v2);
```

这意味着将从隐私矢量参数减去显式参数创建的矢量。

接下来，看一元负号运算符，它只有一个操作数。下面时定义：

```
Vector Vector::operator-() const
{
    return Vector(-x, -y);
}
```

现在，operator-()有两种不同的定义，这是可行的，因为它们的特征标(参数)不同。

### 11.5.3 对于实现的说明

Vector类中，所有接口都只要能够显示这两种表示，并返回各个值。内部实现可以完全不同。因此，可以只存储x和y分量，而返回矢量的长度的magval()方法可以根据x和y的值来计算出长度，而不是查找对象中存储的这个值。这种方法改变了实现，但用户接口没有改变。将接口和实现分离时OOP的目标之一。

这两种实现各有利弊。存储数据意味着对象将占据更多的内存；但查找数据的速度比较快。如果应用经常访问矢量的这两种表示，则这个例子采用的实现比较合适。

### 11.5.4 使用Vector来模拟随机漫步

程序11.15是一个小程序，它使用了Vector类。该程序模拟了著名的醉鬼走路问题。实际上，醉鬼被认为是一个有许多健康问题的人，而不是大家娱乐消遣的谈资，因此这个问题通常被成为随机漫步问题。其意思，将一个领到街灯柱下。这个人开始走动，但没走一部的方向都是随机的。这个问题的一种表述时，这个人走到离灯柱50英尺的地方需要多少步。从矢量的角度，这相当于不断将方向随机的矢量相加，直到长度超过50英尺。

程序11.15 randwalk.cpp

```
#include <iostream>
#include "vector.h"
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit):";
    while (cin >> target)
    {
        cout << "Ener step length: ";
        if (!(cin >> dstep))
            break;
        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << "steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << "or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit):";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}
```

输出：

```
Enter target distance (q to quit):100
Ener step length: 5
After 246steps, the subject has the following location:
(x, y) = (85.9784, 54.1236)
or
(m, a) = (101.596, 0.56183)
Average outward distance per step = 0.41299
Enter target distance (q to quit):200     
Ener step length: 5
After 1087steps, the subject has the following location:
(x, y) = (-57.2303, 193.208)
or
(m, a) = (201.506, 1.85877)
Average outward distance per step = 0.185378
Enter target distance (q to quit):q
Bye!
```

**程序说明**

首先，需要指出的时，在程序11.15中使用VECTOR名称空间非常方便。下面using声明使Vector类的名称可用：

```
using VECTOR::Vector;
```

接下来谈谈随机数。标准ANSI C库(C++也有)中有一个rand()函数，它返回一个从0到某个值(取决于实现)之间的随机数。该程序使用求模运算来获得一个0~359的角度值。

rand()函数将一种算法用于一个初始种子值来获得随机数，该随机数用在下一次函数调用的种子，以此类推。这些数实际上使伪随机数，因此10次连续的调用通常生成10个同样的随机数。然而，srand()函数允许覆盖默认的种子值，重新启动另一个随机序列。该程序使用time(0)的返回值来设置种子。time(0)返回当前时间，通常从某一个日期开始的秒数。因此，下面的语句在每次运行程序时，都将设置不同的种子，是随机数看上去更为随机：

```
srand(time(0));
```

头文件cstdlib包含了srand()和rand()的原型，而ctime包含了time()的原型。

顺便说一句，在将一系列位置存储到文件中很容易。首先包含头文件fstream，声明一个ofstream对象，将其同一个文件关联起来：

```
#include <fstream>

ofstream fout;
fout.open("thewalk.txt");

four << resutl << endl;
```

这将调用友元函数operator<<(fout, result)，导致引用参数os指向fout，从而将输出写入文件中。

## 11.6 类的自动转换和强制类型转换

**相关章节**：第3章中的类型转换和磅转换为英石的程序。