#pragma once
#include "Node.h"

class Queue
{
private:
    Node *front, *rear;

public:
    Queue();
    bool isEmpty();
    void enqueue(Buku);
    Buku dequeue();
};