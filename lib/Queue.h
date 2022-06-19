#include "Node.h"

class Queue
{
private:
    Node *front, *rear;
    static int limit;

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(Buku);
    Buku dequeue();
};