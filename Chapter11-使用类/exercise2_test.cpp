// exercise1_test.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include<fstream>
#include<string>
#include "vect2.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target = 100;
    double dstep = 20;

    string filename("exercise2_test.txt");
    
    ofstream fout(filename.c_str());
    fout<<"Target Distance: "<<target<<endl;
    fout<<"Step Size: "<<dstep<<endl;

    while (result.magval() < target)
    {
        direction = rand() % 360;
        dstep = rand() % 20;
        step.reset(dstep, direction,VECTOR::Vector::POL);
        result = result + step;
        fout<<steps<<": (x,y) = ("<<result.xval()<<","<<result.yval()<<")"<<endl;
        steps++;
    }
    fout << "After " << steps << " steps, the subject "
        "has the following location:\n";
    fout << result << endl;
    result.polar_mode();
    fout << " or\n" << result << endl;
    fout << "Average outward distance per step = "
        << result.magval()/steps << endl;
    steps = 0;
    result.reset(0.0, 0.0);

    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0; 
}
