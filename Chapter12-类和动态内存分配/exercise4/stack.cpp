#include <cstring>
#include "stack.h"

Stack::Stack(const Stack &st)
{
    pitems = new Item[MAX];
    top = -1;
    memcpy(pitems, st.pitems, st.top * sizeof(Item));
    // size = 0;
}

Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX - 1;
}

// push() returns false if stack already is full, true otherwise
// add item to stack
bool Stack::push(const Item &item)
{
    if (top < MAX - 1)
    {
        pitems[++top] = item;
        return true;
    }
    return false;
}

// pop() returns false if stack already is empty, true otherwise
// pop top into item
bool Stack::pop(Item &item)
{
    if (top >= 0)
    {
        top--;
        return true;
    }
    return false;
}

Stack &Stack::operator=(const Stack &st)
{
    pitems = new Item[MAX];
    top = -1;
    memcpy(pitems, st.pitems, st.top * sizeof(Item));
    // size = 0;
}