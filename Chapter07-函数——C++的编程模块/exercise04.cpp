// exercise04.cpp -- probability of winning
#include <iostream>
// Note: some implementations require double instead of long double
long double probability(unsigned numbers[2], unsigned picks[2]);

int main()
{
    using namespace std;
    unsigned total[2], choices[2];
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while ((cin >> total[0] >> choices[0]) && choices[0] <= total[0] && (cin >> total[1] >> choices[1]) && choices[1] <= total[1])
    {
        cout << "You have one chance in ";
        cout << probability(total, choices); // compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    // cin.get();
    // cin.get();
    return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers[2], unsigned picks[2])
{
    long double result[2] = {1.0, 1.0}; // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers[0], p = picks[0]; p > 0; n--, p--)
        result[0] = result[0] * n / p;
    for (n = numbers[1], p = picks[1]; p > 0; n--, p--)
        result[1] = result[1] * n / p;

    return result[0] * result[1];
}
