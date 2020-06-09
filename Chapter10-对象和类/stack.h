// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned int Item;

class Stack
{
private:
    enum {MAX = 3};    // constant specific to class
    Item items[MAX];    // holds stack items
    // top表示该栈中元素的个数，而不是索引！
    int top;            // index for top stack item 
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
};
#endif
