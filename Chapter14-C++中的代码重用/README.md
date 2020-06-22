# chapter14-C++中的代码重用

C++的一个主要目的是促进代码**重用**。公有继承是实现这种目标的机制之一，但并不是唯一的机制。本章将介绍其他方法，其一就是本身是另一个类的对象，称为包含、组合或层次化。另一种方法是使用私有或保护继承。最后，还包括类模板。

## 14.1 包含对象成员的类

**小结**：本小节主要介绍了类A的声明中private部分包含了另外一个类B的对象b，类A的对象a可以很方便的使用对象b的public方法。

首先介绍包含对象成员的类。有一些类为表示类中的组件提供了方便的途径。下面来看一个具体的例子：

学生是什么？入学者？参加研究的人？残酷现实社会的避难者？有姓名和一系列考试分数的人？显然，最后一个定义完全没有表示出人的特征，但非常适合于简单的计算机表示。因此，让我们根据该定义来开发Student类。

将学生简化成姓名和一组考试分数后，可以使用一个包含两个成员的类来表示它：一个成员用于表示姓名，另一个成员用来表示分数。对于姓名，可以使用字符数组来表示，但这将限制姓名的长度。当然，也可以使用char指针和动态内存分配，但正如第12章指出的，这将要求提供大量的指出代码。一种更好的方法是，使用一个由他人开发好的类的对象来表示。例如，可以使用一个String类(参见第12章)或标准C++string类的对象来表示姓名。较简单的选择是使用string类，因为C++库提供了这个类的所有实现代码，且其实现更完美。要使用String类，您必须在项目中包含实现文件string1.cpp。

对于考试分数，存在类似的选择。可以使用一个定长数组，这限制了数组的长度；可以使用动态内存分配并提供大量的支持代码；也可以设计一个使用动态内存分配的类来表示该数组；还可以使用标准C++库中查找一个能够表示这种数据的类。

自己开发这样的类一点问题也没有。开发简单的版本并不那么难，因为double数组和char数组有很多相似之处，因此可以根据String类来设计表示double数组的类。

当然，如果C++库提供了合适的类，实现起来更简单。C++库确实提供了一个这样的类，它就是valarray。

### 14.1.1 valarray类简介

valarray类是由头文件valarray支持的。顾名思义，这个类用于处理数值，它支持诸如将数组中所有元素的值相加以及在数组中找出最大和最小的值等操作。valarray被定义为一个模板类，以便能够处理不同的数据类型。本章后面将介绍如何定义模板类，但就现在而言，您只需知道如何使用模板类即可。

模板特性意味着声明对象时，必须指定具体的数据类型。因此，使用valarray类声明一个对象时，需要在标识符valarray后面加上一对尖括号，并在其中包含所需的数据类型：

```
valarray<int> q_values;
valarray<double> weights;
```

第4章介绍过vector和array类时，见过这种语法，它非常简单。这样类也用于存储数字，但它们提供的算术支持没有valarray多。

类特性意味着要使用valarray对象，需要了解这个类的构造函数和其他类方法。下面是几个使用其构造函数的例子：

```
double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};
valarray<double> v1;          //一个double类型数组，长度为0
valarray<int> v2(8);          //一个包含8个元素的int类型数组
valarray<int> v3<10, 8>;      //一个包含8个元素的int类型数组，没有元素初始化为10
valarray<double> v4(gpa, 4);  //一个包含4个元素的doublz类型数组，被初始化为gpa数组的前4个元素
```

从中可知，可以创建长度为零的空数组、指定长度的空数组、所有元素被初始化为指定值的数组、用常规数组中的值进行初始化的数组。在C++11中，也可使用初始化列表：

```
valarray<int> v5 = {20, 32, 17, 9};
```

下面这个类的一些方法：

- operator[]()()：让您能够访问各个元素。
- size()：返回包含的元素数。
- sum()：返回所有元素的总和。
- max()：返回最大的元素。
- min()：返回最小的元素。

还有很多其他方法，其中一些将在第16章介绍。

### 14.1.1 Student类的设计

至此，已经确定了Student类的设计计划：使用string对象来表示姓名，使用一个valarray来表示考试分数。那么如何设计呢？您可能想以公有的方式从这两个类派生出Student类，这将是多重公有继承。C++允许这样做，但在这里并不合适，因为学生与这些类之间不是is-a模型。学生不是姓名，也不是一组考试成绩。这里的关系是has-a，学生有姓名，也有一组考试分数。通常，用于建立**has-a关系**的C++技术是组合(包含)，即创建一个包含其他类对象的类。例如，可以将Student类声明为如下所示:

```c++
class Student
{
private:
    string name;
    valarray<double> scores;
...
};
```

同样，上述类将数据成员为私有的。这意味着Student类的成员函数可以使用string和valarray类的公有接口来访问和修改name和scores对象，但在类的外面不能这样做，而只能通过Student类的公有接口访问name和score（见图14.1）。对于这种情况，通常被描述为Student类获得了其成员对象的实现，但没有继承接口。例如，Student对象使用string的实现，而不是char ∗∗name或char name[26]实现来保存姓名。但Student对象并不是天生就有使用函数string operator+=()的能力。

**接口和实现**

使用公有继承时，类可以继承接口，可能还有实现(基类的纯虚函数提供接口，但不提供实现)。获得接口是is-a关系的组成部分。而使用组合，类可以获得实现，但不能获得接口。不继承接口是has-a关系的组成部分。

对于has-a关系来说，类对象不能自动获得被包含对象的接口是一件好事。例如，string类将+运算符重载为将两个字符串连接起来；但从概念上讲，将两个Student对象串接起来是没有意义的。这也是这里不使用公有继承的原因之一。另一方面，被包含的类的接口部分对新类来说可能是有意义的。例如，可能希望使用string接口中的operator<()方法将Student对象按姓名进行排序，为此可以定义Student::operator<()成员函数，它在内部使用函数string::Operator<()。下面介绍一些细节。

### 14.1.3 Student示例

现在需要提供Student类的定义，当然它应包含构造函数和一些用作Student类接口的方法。程序14.1是Student类的定义，其中所有构造函数都被定义为内联函数，它还提供了一些用于输入和输出的友元函数。

程序14.1 studentc.h

```c++
#ifndef STUDENTC_H_
#define STUDENTC_H_
#include <cstring>
#include <iostream>
#include <valarray>
using namespace std;
class Student
{
private:
    typedef valarray<double> ArrayDb;		// 新知识，类方法和友元函数可以使用ArrayDb类型
    string name;							// 新知识，类中包含对象成员
    ArrayDb scores;							// 新知识，类中包含对象成员
    ostream & arr_out(ostream & os) const;
public:
    Student() : name("Null, Student"), scores() {}
    explicit Student(const string & s) 
        : name(s), scores() {}
    explicit Student(int n): name("Null"), scores(n) {}
    Student(const string & s, int n)
        : name(s), scores(n) {}
    Student(const string & s, const ArrayDb & a)
        : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)
        : name(str), scores(pd, n) {}
    ~Student() {}
    double Average() const;
    const string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    friend istream & operator>>(istream & is, Student & stu);
    friend istream & getline(istream & is, Student & stu);
    friend ostream & operator<<(ostream & os, const Student & stu);
};

#endif
```

为简化表示，Student类的定义中包含下述typedef:

```c++
typedef valarray<double> ArrayDb;
```

这样，在以后的代码中便可以使用ArrayDb，而不是valarray，因此类方法和友元函数可以使用ArrayDb类型。将该tyepdef放在定义的私有部分意味着可以在Student类的实现中使用它，但在Student类外面不能使用。

请注意explicit的用法：

```c++
explicit Student(const string & s) 
        : name(s), scores() {}
explicit Student(int n): name("Null"), scores(n) {}
```

在本书前面讲过，可以用一个参数调用的构造函数将用作从参数类型到类类型的隐式转换函数；但这通常不是好注意。在上述第二个构造函数中，第一个参数表示数组的元素个数，而不是数组中的值，因此将一个构造函数用作int到Student的转换函数是没有意义的，所以使用explicit关闭隐式转换。如果省略该关键字，则可以编写如下所示代码：

```c++
Student doh("Homer", 10); //存储"Homer"。并创建10个元素的数组
doh = 5; //重置name为Null，重置数组为5个元素
```

如果构造函数省略了explicit，则将使用构造函数调用Studnet(5)将5转换为一个临时Student，并使用”Null”来设置成员name的值。因此赋值操作将使用临时对象替换原来的doh值。使用了explicit后，编译器将认为上述赋值运算符是错误的。

**C++和约束**

Q：在C++中包含了让程序员能够限制程序结构的特性—-使用explicit防止单参数构造函数的隐式转换，使用const限制方法修改数据，等等。为什么要有这些限制呢？

A：这样做的原因是：在编译阶段出现错误优于在运行阶段出现错误。

**1. 初始化被包含的对象**

构造函数全部使用您熟悉的成员初始化列表语法来初始化name和scores成员对象。在前面的一些例子中，构造函数用这种语法来初始化内置类型的成员：

```
Queue::Queue(int qs) : qsize(qs) {}
```

上述代码在成员初始化列表中使用的是数据成员的名称(qsize)。另外，前面介绍的示例中构造函数还使用成员初始化列表初始化派生类对象的基类部分：

```
hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs) {}
```

对于继承的对象，构造函数在成员初始化列表中使用类名来调用特定的基类构造函数。对于成员对象，构造函数则使用成员名。例如，请看程序14.3的最后一个构造函数：

```
Student(const char * str, const double * pd, int n)
            : name(str), scores(pd, n) {}
```

因为该构造函数初始化的是成员对象，而不是继承的对象，所以在初始化列表中使用的是成员名，而不是类名。初始化列表中的每一项都调用与之匹配的构造函数，即name(str)调用构造函数string(const char ∗∗)，scores(pd, n)调用构造函数ArrayDb(const double astast, int)。

如果不使用初始化列表语法，情况将如何呢？C++要求在构造对象的其他部分之前，先构建继承对象的所有成员对象。因此，如果省略初始化列表，C++将使用成员对象所属类的默认构造函数。

**初始化顺序**

当初始化列表包含多个项目时，这些项目被初始化的顺序为它们被声明的顺序，而不是它们在初始化列表中的顺序。例如，假设Student构造函数如下：

```
Student(cosnt char * str, const double * pd, int n)
        : scores(pd, n), name(str) {}
```

则name成员仍将首先被初始化，因为在类定义中它首先被声明。对于这个例子来说，初始化顺序并不重要，但如果代码使用一个成员的值作为另一个成员的初始化表达式的一部分时，初始化顺序就非常重要了。

**2. 使用被包含对象的接口**

**被包含对象的接口不是公有的，但可以在类方法中使用它**。例如，下面的代码说明了如何定义一个返回学生平均分数的函数：

```c++
double Student::Average() const
{
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}
```

上述代码定义了可由Student对象调用的方法，该方法内部使用了valarray的方法size()和sum()。这是因为scores是一个valarray对象，所以它可以调用valarray类的成员函数。总之，Student对象调用Student的方法，而后者使用被包含的valarray对象来调用valarray类的方法。

同样，可以定义一个使用string版本的<<运算符的友元函数：

```
ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << stu.name << ":\n";
    ...
}
```

因为stu.name是一个string对象，所以它将调用函数operator<<(ostream &, const string &)，该函数位于string类中。注意，operator<<(ostream & os, const Student & stu)必须是Student类的友元函数，这样才能访问name类成员。另一种方法是，在该函数中使用公有方法Name()，而不是私有数据成员name。

同样，该函数也可以使用valarray的<<实现来进行输出，不幸的是没有这样的实现；因此，Student类定义了一个私有辅助方法来处理这种任务:

```
ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}
```

通过使用这样的辅助方法，可以将零乱的细节放在一个地方，使得友元函数的编码更为整洁：

```
ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
```

辅助函数也用作其他用户级输出函数的构建块—如果您选择提供这样的函数的话。

程序14.2是Student类的类方法文件，其中包含了让您能够使用[]运算符来访问Student对象中各项成绩的方法。

程序14.2 studentc.cpp

```
#include "studentc.h"
#include <iostream>
using namespace std;

double Student::Average() const
{
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}

const string & Student::Name() const
{
    return name;
}

double & Student::operator[](int i)
{
    return scores[i];
}

double Student::operator[](int i) const
{
    return scores[i];
}

ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

istream & operator>>(istream & is, Student & stu)
{
    is >> stu.name;
    return is;
}

istream & getline(istream & is, Student & stu)
{
    getline(is, stu.name);
    return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
```

**3. 使用新的Student类**

下面编写一个小程序来测试这个Student类。出于简化的目的，该程序使用一个只包含3个Student对象的数组，其中每个对象保存5个考试成绩。另外还将使用一个不复杂的输入循环，该循环不验证输入，也不让用户中途退出。

程序14.3 use_stuc.cpp

```
#include "studentc.h"
#include <iostream>
using namespace std;

void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] = 
        {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    cout << "\n Student List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n' )
        continue;
}
```

输出：

```
Please enter the student's name: Gil Bayts
Please enter 5 quiz scores:
92 94 98 96 95
Please enter the student's name: Pat Roone
Please enter 5 quiz scores:
89 96 95 92 91
Please enter the student's name: Fleur Day
Please enter 5 quiz scores:
96 98 92 93 94

 Student List:
Gil Bayts
Pat Roone
Fleur Day

Results:
Scores for Gil Bayts:
92 94 98 96 95 
average: 95

Scores for Pat Roone:
89 96 95 92 91 
average: 92.6

Scores for Fleur Day:
96 98 92 93 94 
average: 94.6
Done.
```

## 14.2 私有继承

C++还有另一种实现has-a关系的途径—私有继承。**使用私有继承，基类的公有成员和保护成员都将称为派生类的私有成员。**这意味着基类方法将不会称为派生类对象公有接口的一部分，但可以在派生类的成员函数中使用它们。

下面更深入地探讨接口问题。使用公有继承，基类的公有方法将成为派生类的公有方法。总之，派生类将继承基类的接口；这是is-a关系的一部分。使用私有继承，基类的公有方法将成为派生类的私有方法。总之，派生类不继承基类的接口。正如从被包含对象中看到的，这种不完全继承是has-a关系的一部分。

使用私有继承，类将继承实现。例如，如果从String类派生出Student类，后者将有一个String类组件，可用于保存字符串。另外，Student方法可以使用String方法来访问String组件。

包含将对象作为一个命名的成员对象添加到类中，而私有继承将对象作为一个未被命名的继承对象添加到类中。我们将使用术语**子对象来表示通过继承或包含添加的对象。**

**因此，私有继承提供的特性与包含相同：获得实现，但不获得接口。**所以，私有继承也可以用来实现has-a关系。接下来介绍如何使用私有继承来重新设计Student类。

### 14.2.1 Student类示例（新版本）

要进行私有继承，请使用关键字private而不是public来定义类（实际上，private是默认值，因此省略访问限定符也将导致私有继承）。Student类应该从两个类派生而来，因此声明将列出这两个类：

```
class Student : private std::string, private std::valarray<double>
{
public:
...
}
```

Q：多重继承（MI）的定义？

A：使用多个基类的继承被称为多重继承。

通常，MI尤其是公有MI将导致一些问题，必须使用额外的语法规则来解决它们，它将在本章后面介绍。但在这个示例中，MI不会导致问题。

新的Student类不需要私有数据，因为两个基类已经提供了所需的所有数据成员。包含版本提供了两个被显式命名的对象成员，而私有继承提供了两个无名称的子对象成员。这是这两种方法的第一个主要区别。

**1. 初始化基类组件**

隐式地继承组件而不是成员对象将影响代码的编写，因为再也不能使用name和scores来描述对象了，而必须使用用于公有继承的技术。例如，对于构造函数，包含将使用这样的构造函数：

```
Student(const char * str, const double * pd, int n)
    : name(str), scores(pd, n) {}
```

对于继承类，新版本的构造函数将使用成员初始化列表语法，而它使用类名而不是成员名来标识构造函数：

```
Student(const char * str, const double * pd, int n)
    : std::string(str), ArrayDb(pd, n) {}
```

再这里，ArrayDb是std::valarray的别名。成员初始化列表使用std::string(str)，而不是name(str)。这是包含和私有继承之间的第二个主要区别。

程序14.4列出了新的类定义。唯一不同的地方是，省略了显式对象名称，并在内联构造函数中使用了类名，而不是成员名。

程序14.4 studenti.h

```c++
#ifndef STUDENTI_H_
#define STIDENTI_H_
#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double>					// 新知识
{
private:
    typedef std::valarray<double> ArrayDb;
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : std::string("Null Student"), ArrayDb() {}
    explicit Student(int n) : std::string("Null"), ArrayDb(n) {}
    explicit Student(const std::string & s) : std::string(s), ArrayDb() {}
    Student(const std::string & s, const ArrayDb & a)
        : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n)				
        : std::string(str), ArrayDb(pd, n) {}																		// 新知识
    ~Student() {}
    double Average() const;
    double & operator[](int i);
    double operator[](int i) const;
    const std::string & Name() const;

    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
};

#endif
```

**2. 访问基类的方法**

使用私有继承时，只能在派生类的方法中使用基类的方法。但有时候可能希望其基类工具是公有的。例如，在类声明中提出可以使用average()函数，和包含一个样，要实现这样的目的，可以在公有Student::average()函数中使用私有Student::Average()函数。包含使用对象来调用方法：

```
double Student::Average() const
{
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}
```

然而，私有继承使得能够使用类名和作用域解析运算符来调用基类的方法：

```
double Student::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
    else
        return 0;
}
```

**总之，使用包含时将使用对象名来调用方法，而使用私有继承时使用类名和作用域解析运算符来调用方法。**

**3. 访问基类对象**

使用作用域解析运算符可以访问基类的方法，但如果要使用基类对象本身，该如何做呢？例如，Student类的包含版本实现了Name()方法，它返回string对象成员name；但使用私有继承时，该string对象没有名称。那么，Student类的代码如何访问内部的string对象呢？

答案是使用强制类型转换。由于Student类是从string类派生出来的，因此可以通过强制类型转换，将Student对象转换成string对象；结果为继承而来的string对象。本书前面介绍过，指针this指向用来调用方法的对象，因此∗∗ this为用来调用方法的对象，在这个例子中，为类型为Student的对象。为避免调用构造函数创建新的对象，可使用强制类型转换来创建一个引用：

```
const string & Student::Name() const
{
    return (const string &) *this;
}
```

上述方法返回一个引用，该引用指向调用该方法的Student对象中的继承而来的string对象。

**4. 访问基类的友元函数**

用类名显式地限定函数名不适合于友元函数，这是因为友元函数不属于类。然而，可以通过显式地强制转换为基类来调用正确的函数。例如，对于下面的友元函数定义：

```
ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << (string &) stu << ":\n";
    ...    
}
```

如果plato是一个Student对象，则下面的语句将调用上述函数，stu将是指向plato的引用，而os将是指向cout的引用：

```
cout << plato;
```

下面的代码：

```
os << "Scores for " << (string &) stu << ":\n";
```

显式地将stu转换为string对象引用，进而调用函数operator<<(ostream &, const string &)。

引用stu不会自动转换为string引用。根本原因在于，在私有继承中，未进行显式类型转换的派生类引用或指针，无法赋值给基类的引用或指针。

然而，即使这个例子使用的是公有继承，也必须使用显式类型转换。原因在于，如果不使用类型转换，下述代码将于友元函数原型匹配，从而导致递归调用：

```
os << stu;
```

另一个原因是，由于这个类使用的是多重继承，编译器将无法确定应转换成哪个基类，如果两个基类都提供了函数operator<<()。

程序14.5 studenti.cpp

```
#include "studenti.h"
#include <iostream>
using namespace std;

double Student::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
    else
        return 0;
}

const string & Student::Name() const
{
    return (const string &) *this;
}

double & Student::operator[](int i)
{
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

istream & operator>>(istream & is, Student & stu)
{
    is >> (string &) stu;
    return is;
}

istream & getline(istream & is, Student & stu)
{
    getline(is, (string &) stu);
    return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << (string &) stu << ":\n";
    stu.arr_out(os);
    return os;
}
```

**5. 使用修改后的Student类**

接下来也需要测试这个新类。注意到两个版本的Student类的公有接口完全相同，因此可以使用同一个程序测试它们。

程序14.6 use_stui.cpp

```
#include <iostream>
#include "studenti.h"
using namespace std;

void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] = 
        {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    cout << "\n Student List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n' )
        continue;
}
```

输出：

```
Please enter the student's name: Gil Bayts
Please enter 5 quiz scores:
92 94 96 98 95 
Please enter the student's name: Pat Roone
Please enter 5 quiz scores:
83 89 72 78 95
Please enter the student's name: Fleur Day
Please enter 5 quiz scores:
92 93 96 98 95

 Student List:
Gil Bayts
Pat Roone
Fleur Day

Results:
Scores for Gil Bayts:
92 94 96 98 95 
average: 95

Scores for Pat Roone:
83 89 72 78 95 
average: 83.4

Scores for Fleur Day:
92 93 96 98 95 
average: 94.8
Done.
```

### 14.2.2 使用包含还是私有继承

由于既可以使用包含，也可以使用私有继承来建立has-a关系，那么应该使用哪种方法？大多数C++程序倾向于使用包含。首先，它易于理解。类声明中包含表示被包含类的显式命名对象，代码可以通过名称引用这些对象，而使用继承将是关系更抽象。其次，继承会引起很多问题，尤其从多个基类继承时，可能必须处理很多问题，如包含同名方法的独立的基类或共享祖先的独立基类。总之，使用包含不太可能遇到这样的麻烦。另外，包含能够包括多个同类的子对象。如果某个类需要3个string对象，可以使用包含声明3个独立的string成员。而继承则只能使用一个这样的对象（当对象没有名称时，将难以区分）。

然而，私有继承所提供的特性确实比包含多。例如，假设类包含保护成员（可以是数据成员，也可以是成员函数），则这样的成员在派生类中是可用的，但在继承层次结构外是不可用的。如果使用组合将这样的类包含在另一个类中，则后者将不是派生类，而是位于继承层次结构之外，因此不能访问包含成员。但通过继承得到的将是派生类，因此它能够访问保护成员。

另一种需要使用私有继承的情况是需要重新定义虚函数。派生类可以重新定义虚函数，但包含类不能。使用私有继承，重新定义的函数将只能在类中使用，而不会公有的。

**提示：**通常，应使用包含来建立has-a关系；如果新类需要访问原有类的包含成员，或需要重新定义虚函数，则应使用私有继承。

### 14.2.3 保护继承

保护继承是私有继承的变体。保护继承再列出基类时使用关键字protected:

```
class Student : protected std::string,
                protected std::valarray<double>
{...}
```

使用保护继承，基类的公有成员和保护成员都将称为派生类的保护成员。和公有继承一样，基类的接口在派生类中也是可用的，但在继承层次结构之外是不可用的。当从派生类派生出另一个类时，私有继承和保护继承之间的主要区别变呈现出来了。使用私有继承时，第三代类将不能使用基类的接口，这是因为基类的公有方法在派生类中将变成私有方法；使用保护继承，基类的公有方法在第二代中将变成受保护的，因此第三代派生类可以使用它们。

表14.1总结了公有、私有和保护继承。隐式向上转换意味着无需进行显式类型转换，就可以将基类指针或引用指向派生类对象。

[![img](https://i.imgur.com/mI5C6ZL.png)](https://i.imgur.com/mI5C6ZL.png)

### 14.2.4 使用using重新定义访问权限

使用保护派生或私有派生时，基类的公有成员将成员保护成员或私有成员。假设要让基类的方法在派生类外面可用，方法之一是定义一个使用该基类方法的派生类方法。例如，假设希望Student类能够使用valarray类的sum()方法，可以在Student类的声明中声明一个sum()方法，然后像下面这样定义该方法：

```
double Student::sum() const
{
    return std::valarray<double>::sum();
}
```

这样Student对象便能够调用Student::sum()，后者进而将valarray::sum()方法应用于被包含的valarray对象。

另一种方法是，将函数调用包装在另一个调用函数中，即**使用一个using声明(就像名称空间那样)来指出派生类可以使用特定的基类成员，即使采用的是私有派生。**例如，假设希望通过Student类能够使用valarray的min()和max()，可以在studenti.h的公有部分加入using声明：

```
class Student : private std::string, private std::valarray
{
...
public:
    using std::valarray<double>::min;
    using std::valarray<double>::max;
...
};
```

上述using使得valarray::min()和valarray::max()可用，就像它们是Student的公有方法一样：

```
cout << "high score: " << ada[i].max() << endl;
```

注意，using声明只使用成员名—-没有圆括号、函数特征标和返回类型。例如，为Student类可以使用valarray的operator[]方法，只需在Student类声明的公有部分包含下面的using声明：

```
using std::valarray<double>::operator[];
```

这将是两个版本（const和非const）都可用。这样，便可以删除Student::operator90()的原型和定义。using声明只适用于继承，而不适用于包含。

有一种老式方式用于在私有派生类中重新声明基类方法，即将方法名放在派生类的公有部分，如下所示:

```
class Student : private std::string, private std::valarray
{
...
public:
    std::valarray<double>::operator[];
...
};
```

这样看起来像不包含关键字using声明的using声明。这种方法已被摒弃，即将停止使用。因此，如果编译器支持using声明，应使用它来使派生类可以使用私有基类中的方法。

## 14.3 多重继承

Q：多重继承的定义？

A：

1）一个派生类有2个或多个基类，派生类从2个或多个基类中继承所需的属性；

2）C++为了适应这种情况，允许一个派生类同时继承多个基类。这种行为称为多重继承。

Q：如何评价多重继承？

A：

优点：自然地做到了对单继承的扩展。

缺点：结构复杂化，优化顺序模糊，功能冲突。

解决方案：C++和Python等支持多重继承，Java不支持而使用接口实现。

## 14.4 类模板

**相关章节**：本章相关章节为第4章的模板类`vector`和`array`、第10章的Stack实例、第12章的Queue实例、第16章的C++标准库模板库（STL)提供了几个功能强大而灵活的容器模板实现。

**Q**:回忆一下第10章中是如何实现Stack类支持多种类型的数据的？如何评价其做法？

**A**:第10章中通过使用`typedef`来处理Stack类要支持多种数据类型这一需求。该做法有如下2个缺点：

1）每次修改类型时都需要编辑头文件;

2）不能让`typedef`同时代表2种不同的类型。PS:由于使用`typedef`会造成这2个问题，因而需要引入`类模板`来解决这一问题。

**Q**：**函数模板**和**类模板**有什么**共性**？

**A**：

1）**参数类型不一样**，**结构都完全一样**；

2）正是因为1），使得代码具有**重用性**。

### 14.4.1 定义类模板

**Q**:关于类模板，有哪几点需要强调的？

**A**:

1）类声明的前面要加上`template<typename T>`;

2）方法实现的前面要加上`template<typename T>`;

3）类模板的声明和定义放在一个文件中，因为类模板不是函数，它们不能单独编译。模板必须与特定的模板实例化请求一起使用。

**Q**：模板类的代码开头是什么？

**A**：本节主要讲了如何声明和定义类模板。所有讲解都是为了理解程序清单14.13服务的。

```c++
// 方法1：辨识度高，优选使用
template<typename T> class Ref{
private:
public:
}

// 方法2：辨识度低，不推荐使用
template<class T> class Ref{
private:
public:
}
```

**注意**:对于类模板，必须显式地提供所需的类型，函数模板可以无需提供所需类型，因为编译器可以根据函数参数类型来确定要生成哪种函数。



