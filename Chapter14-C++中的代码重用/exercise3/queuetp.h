// wine.h -- defining a Student class using containment
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>
#include <string>
#include <valarray>
#include "pair.h"

template <typename Type>
class Queue
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node
    {
        Type item;
        struct Node *next;
    };
    enum
    {
        Q_SIZE = 10
    };
    // private class members
    Node *front;     // pointer to front of Queue
    Node *rear;      // pointer to rear of Queue
    int items;       // current number of items in Queue
    const int qsize; // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Type &item); // add item to end
    bool dequeue(Type &item);       // remove item from front
};
#endif
