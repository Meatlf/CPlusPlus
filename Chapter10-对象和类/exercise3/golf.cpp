#include"golf.h"

// class golf
// {
// private:
//     /* data */
//     char fullname[Len];
//     int handicap;
// public:
//     golf();
//     golf(const char * name, int hc);

//     void handicap(int hc);

//     void showgolf(int hc);

//     void showgolf();

//     ~golf();
// };

golf::golf()
{
    char* name = new char [25];
    int hc;
    cout << "Please input name: ";
    cin >> name;
    cout << "Please input handicap:";
    cin >> hc;
    strcpy(fullname_, name);
    handicap_ = hc;
}

golf::golf(const char * name, int hc)
{
    strcpy(fullname_, name);
    handicap_ = hc;
}
