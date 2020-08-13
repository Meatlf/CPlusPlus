// 例11-1 使用width控制输出宽度
#include <iostream>
using namespace std;

int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    for(int i = 0; i < 4; i++) {
        cout.width(10);
        cout << values[i] << endl;
    }
    return 0;
}