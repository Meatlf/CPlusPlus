// fowl.cpp  -- auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>

int main()
{
    using namespace std;
#if 0
    auto_ptr<string> films[5] =
    {
        auto_ptr<string> (new string("Fowl Balls")),
        auto_ptr<string> (new string("Duck Walks")),
        auto_ptr<string> (new string("Chicken Runs")),
        auto_ptr<string> (new string("Turkey Errors")),
        auto_ptr<string> (new string("Goose Eggs"))
    };
    auto_ptr<string> pwin;
#else
    shared_ptr<string> films[5] =
        {
            shared_ptr<string>(new string("Fowl Balls")),
            shared_ptr<string>(new string("Duck Walks")),
            shared_ptr<string>(new string("Chicken Runs")),
            shared_ptr<string>(new string("Turkey Errors")),
            shared_ptr<string>(new string("Goose Eggs"))};
    shared_ptr<string> pwin;
#endif
    pwin = films[2]; // films[2] loses ownership

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;
    cout << "The winner is " << *pwin << "!\n";
    // cin.get();
    return 0;
}
