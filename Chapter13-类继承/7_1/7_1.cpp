// 7_1
// 说明：公有继承
// 为了简洁起见，Point类和Rectangle类都没有提够构造函数
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    Rectangle rect;
    rect.initRectangle(2, 3, 20, 10);
    rect.move(3, 2);
    cout << "The data of rect(x,y,w,h):" << endl;
    cout << rect.getX() << "," << rect.getY() << "," << rect.getW() << "," << rect.getH() << endl;
    return 0;
} 