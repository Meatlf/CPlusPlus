// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>   // time() prototype
#include <climits>
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;

    double target = 100;
    double dstep = 10;

    int N;             // N次测试
    int stepCount = 0; //步数
    unsigned long minSteps = ULONG_MAX;
    unsigned long maxSteps = 0;
    unsigned long sumSteps = 0;

    cout << "Enter test number N (q to quit): ";
    cin >> N;
    int n;

    for (n = 0; n < N; n++)
    {
        steps = 0;
        result.reset(0.0, 0.0);

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, VECTOR::Vector::Mode::POL);
            result = result + step;
            steps++;
        }

        minSteps = minSteps < steps ? minSteps : steps;
        maxSteps = maxSteps > steps ? maxSteps : steps;
        sumSteps += steps;
    }
    cout << "N次测试中的最多步数：" << maxSteps << endl;
    cout << "N次测试中的最少步数：" << minSteps << endl;
    cout << "N次测试中的平均步数：" << sumSteps / N << endl;
    cout << "Bye!\n";
    /* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}
