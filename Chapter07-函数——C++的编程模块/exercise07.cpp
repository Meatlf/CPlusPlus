// exercise07.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
double *fill_array(double ar[], int limit);
void show_array(const double ar[], const double *ar_end); // don't change data
void revalue(double r, double ar[], double *ar_end);

int main()
{
    using namespace std;
    double properties[Max];

    double *ar_end = fill_array(properties, Max);
    show_array(properties, ar_end);
    if (ar_end != properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, ar_end);
        show_array(properties, ar_end);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

double *fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0) // signal to terminate
            break;
        ar[i] = temp;
    }
    return ar + i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], const double *ar_end)
{
    using namespace std;
    const double *pt;
    int i = 0;
    for (pt = ar; pt != ar_end; pt++)
    {
        cout << "Property #" << i++ << ": $";
        cout << *pt << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], double *ar_end)
{
    double *pt;
    for (pt = ar; pt != ar_end; pt++)
        *pt *= r;
}
