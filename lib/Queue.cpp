#include "Queue.h"
#define max 2

/**
 * @brief Construct a new Queue:: Queue object
 *
 */
Queue::Queue()
{
    front = rear = nullptr;
}

/**
 * @brief Memeriksa queue kosong atau tidak
 *
 * @return true
 * @return false
 */
bool Queue::isEmpty()
{
    return front == nullptr;
}

/**
 * @brief Memeriksa queue penuh atau tidak
 *
 * @return true
 * @return false
 */
bool Queue::isFull()
{
    return limit == max;
}

/**
 * @brief Memasukkan data buku di dalam queue
 *
 * @param data data buku
 */
void Queue::enqueue(Buku data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (isEmpty())
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;

    limit++;
}

/**
 * @brief Mengambil data buku urutan pertama
 *
 * @return Buku
 */
Buku Queue::dequeue()
{
    Buku data = front->data;

    if (isEmpty())
        return;

    Node *temp = front;
    front = front->next;

    if (isEmpty())
        rear = nullptr;

    limit--;

    delete temp;
    return data;
}