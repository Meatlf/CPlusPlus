// usett1.cpp -- using base class and derived class
#include <iostream>
#include "tabtenn1.h"

int main ( void )
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();          // derived object uses base method
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player1.Name();           // base object uses base method
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;
// initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

// 基类指针（或引用）可以在不进行显式类型转换的情况下指向派生类对象
    TableTennisPlayer & rt = rplayer1;
    TableTennisPlayer * pt = &rplayer1;
    rt.Name();
    cout << endl;
    pt->Name();
    cout << endl;

// 不可以将基类对象和地址赋给派生类引用和指针
    // RatedPlayer & rr = player1;
    // RatedPlayer * pr = player1;

// 可以在Show()使用TableTennis参数或Ratedplayer参数
    Show(player1);
    Show(rplayer1);

// 引用兼容属性允许将基类对象初始化为派生类对象
TableTennisPlayer olaf1(player1);
TableTennisPlayer olaf2(rplayer1);

// 可以将派生对象赋给基类对象
RatedPlayer rp1(1840,"rp1","Loaf",true);
TableTennisPlayer winner = rp1;
    // std::cin.get();
    return 0;
}
