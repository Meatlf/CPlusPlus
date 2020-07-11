// exercise03.cpp --
// 功能：
// 说明：使用到了后续章节里的模板类
#include <iostream>
#include <cstring>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void pass_by_value(box b)
{
    cout << b.maker << endl;
    cout << b.height << endl;
    cout << b.width << endl;
    cout << b.length << endl;
    b.volume = b.height * b.width * b.length;
    cout << b.volume << endl
         << endl;
}

void pass_by_address(box *b)
{
    cout << b->maker << endl;
    cout << b->height << endl;
    cout << b->width << endl;
    cout << b->length << endl;
    b->volume = b->height * b->width * b->length;
    cout << b->volume << endl
         << endl;
}

int main()
{
    box b1 = {"Box1", 50, 50, 50};
    pass_by_value(b1);
    box b2 = {"Box2", 100, 100, 100};
    pass_by_address(&b2);
    return 0;
}
