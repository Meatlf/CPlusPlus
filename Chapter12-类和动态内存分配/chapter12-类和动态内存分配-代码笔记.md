# Chapter12-类继承-代码笔记

## Project0

结论：

1）在构造函数中使用`new`为字符串申请空间，避免在类声明中预先定义字符串的长度;
2）静态成员变量`num_strings`具有共享性;
3）不同在类声明中初始化静态成员变量。

代码出现的异常：

Q：对象sports、headline1、headline2在调用析构函数时，成员变量str出现了混乱的现象。对于对象sport，程序只使用它来初始化sailor，但这种操作修改了sport。为什么会出现这些异常现象？

Q：静态成员变量num_strings的值在调用构造函数时自加1,在调用析构函数时自减1，按道理来讲，对于任意一个程序，调用构造函数和调用析构函数应该成对出现，这样静态成员变量num_strings的值不可能为负值，但是观察该程序的运行结果可以发现，最终num_strings的值竟然为-2。产生这种异常的原因是什么？

A：这表明程序“偷偷的”的调用了2次某种构造函数，而这种构造函数并没有将num_strings的值自加1。代码中有以下语句：

```c++
StringBad sailor = sports;
```

该语句等价于以下语句：

```c++
StringBad(const StringBad &);
```

这就是复制构造函数，进行对象的赋值运算时就会调用复制构造函数。

**程序清单**：

**程序清单12.2 strngbad.cpp**

**Q**：如何初始化静态成员？

**A**：

```c++
int StringBad::num_strings = 0;
```

​	**说明**：

​	1）不能在类声明中初始化静态成员函数，这是因为声明描述了如何分配内存，但并不分配内存；

​	2）对于静态类成员，可以在类声明之外使用单独的语句进行初始化，这是因为静态类成员是单独存储的，而不是对象的组成部分；

​	3）请注意，初始化语句指出了类型，并使用了作用域运算符，但没有使用关键字`static`；

​	4）静态数据成员要初始化要在方法文件中，而不是在类声明文件中进行的，这是因为类声明位于头文件中，程序可能将头文件包括在其他几个文件中。如果在头文件中进行初始化，将出现多个初始化语句副本，从而引发错误；

​	5）对于不能在类声明中初始化静态数据成员的一种例外情况（见第10章）是，静态数据成员为整型或枚举型`const`。

**警告**：在构造函数中使用`new`来分配内存时，必须在相应的析构函数中使用`delete`来释放内存。如果使用`new[]`（包括中括号），则应使用`delete[]`（包含中括号）来释放内存。

**程序清单12.3 vegnews.cpp**

**说明**:该程序将对象声明在一个内部代码块中,因为析构函数将在定义对象的代码块执行完毕时调用。如果不这么做，析构函数将在`main()`函数执行完毕时调用，导致您无法在执行窗口关闭前看到析构函数显示的消息。

### 



