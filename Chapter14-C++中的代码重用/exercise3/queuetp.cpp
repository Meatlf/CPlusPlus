// studentc.cpp -- Student class using containment
#include <iostream>
#include "queuetp.h"

// Queue methods
template <typename Type>
Queue<Type>::Queue(int qs) : qsize(qs)
{
    front = rear = NULL; // or nullptr
    items = 0;
}

template <typename Type>
Queue<Type>::~Queue()
{
    Node *temp;
    while (front != NULL) // while queue is not yet empty
    {
        temp = front;        // save address of front item
        front = front->next; // reset pointer to next item
        delete temp;         // delete former front
    }
}

template <typename Type>
bool Queue<Type>::isempty() const
{
    return items == 0;
}

template <typename Type>
bool Queue<Type>::isfull() const
{
    return items == qsize;
}

template <typename Type>
int Queue<Type>::queuecount() const
{
    return items;
}

// Add item to queue
template <typename Type>
bool Queue<Type>::enqueue(const Type &item)
{
    if (isfull())
        return false;
    Node *add = new Node; // create node
                          // on failure, new throws std::bad_alloc exception
    add->item = item;     // set node pointers
    add->next = NULL;     // or nullptr;
    items++;
    if (front == NULL) // if queue is empty,
        front = add;   // place item at front
    else
        rear->next = add; // else place at rear
    rear = add;           // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
template <typename Type>
bool Queue<Type>::dequeue(Type &item)
{
    if (front == NULL)
        return false;
    item = front->item; // set item to first item in queue
    items--;
    Node *temp = front;  // save location of first item
    front = front->next; // reset front to next item
    delete temp;         // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}