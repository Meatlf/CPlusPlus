// 例11-2使用setw操纵符指定宽度
// 说明：setw操纵符默认右对齐
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    for (int i = 0; i < 4; i++)
      cout << setw(6) << names[i] 
     << setw(10) << values[i] << endl;
    return 0;
}