// fun_ptr.cpp -- pointers to functions
#include <iostream>

double calculate(double x, double y, double (*pf[3])(double, double));

double add(double x, double y) { return x + y; }
double mul(double x, double y) { return x * y; }

int main()
{
    using namespace std;
    double a, b, c, d;

    double (*pa)(double, double) = add;
    double (*pb[2])(double, double) = {add, mul};
    auto pc = pb;
    auto pd = &pb;

    cout << (*pa)(3, 4) << endl;
    cout << pb[0](3, 3) << endl;
    cout << pb[1](3, 3) << endl;
    cout << pc[0](3, 3) << endl;
    cout << pc[1](3, 3) << endl;
    cout << (*pd)[0](3, 3) << endl;
    cout << (*pd)[1](3, 3) << endl;

    while (cin >> a && cin >> b && cin >> c && cin >> d && a != 'q')
    {

        cout << calculate(a, b, pd[0]) + calculate(c, d, pd[1]) << endl;
    }

    // cin.get();
    // cin.get();
    return 0;
}

double calculate(double x, double y, double (*pf[2])(double, double))
{
    return (pf[0])(x, y) + (pf[1])(x, y) + (pf[1])(x, y);
}
