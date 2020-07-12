//exercise08.cpp --
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
// const std::array<std::string, Seasons> Snames =
//     {"Spring", "Summer", "Fall", "Winter"};
const char *Snames[4] = {"Spring", "Summer", "Fall", "Winter"};

struct Struct1
{
    double expenses[4] = {0};
};

void fillV1(double *pa);
void showV1(double *da);
void fillV2(Struct1 *sa);
void showV2(Struct1 *sa);
void method1();
void method2();

void method1()
{
    double expenses[4];
    fillV1(expenses);
    showV1(expenses);
}

void method2()
{
    Struct1 *sa = new Struct1;
    fillV2(sa);
    showV2(sa);
}

int main()
{
    // method1();
    method2();
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fillV1(double *pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}

void showV1(double *da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total: $" << total << '\n';
}

void fillV2(Struct1 *sa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> sa->expenses[i];
    }
}

void showV2(Struct1 *sa)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << sa->expenses[i] << '\n';
        total += sa->expenses[i];
    }
    std::cout << "Total: $" << total << '\n';
}
