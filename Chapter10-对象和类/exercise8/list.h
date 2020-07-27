// List.h -- class definition for the List ADT
#ifndef LIST_H_
#define LIST_H_

typedef unsigned int Item;

class List
{
private:
    enum {MAX = 3};    // constant specific to class
    Item items[MAX];    // holds List items
    // top表示该栈中元素的个数，而不是索引！
    int top;            // index for top List item 
public:
    List();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if List already is full, true otherwise
    bool push(const Item & item);   // add item to List
    // pop() returns false if List already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
};
#endif
