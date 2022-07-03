#pragma once
#include "Node.h"

// kelas queue
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