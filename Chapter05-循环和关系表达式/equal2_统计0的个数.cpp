// equal.cpp -- equality vs assignment
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string quizscores =
        "000000000000000000000000000000000000000000000000000000000000000000000000000000255779599783955275";

    cout << "Doing it right:\n";
    int count = 0;
    int i;
    for (i = 0; quizscores[i] != '\0'; i++)
    {
        if (quizscores[i] == '0')
            count++;
    }
    cout << "该字符串中'0'的个数为：" << count << endl;
    // cin.get();
    return 0;
}
