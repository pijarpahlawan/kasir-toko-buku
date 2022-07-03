#include "Queue.h"

/**
 * @brief Construct a new Queue:: Queue object
 *
 */
Queue::Queue()
{
    front = rear = nullptr;
}

/**
 * @brief Mengecek apakah queue kosong
 *
 * @return true
 * @return false
 */
bool Queue::isEmpty()
{
    return front == nullptr;
}

/**
 * @brief Memasukkan data ke dalam queue
 *
 * @param data data yang akan dimasukkan ke dalam queue
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
}

/**
 * @brief Mengambil sekaligus menghapus data dari queue
 *
 * @return Buku
 */
Buku Queue::dequeue()
{
    Buku data = front->data;

    if (isEmpty())
        return {};

    Node *temp = front;
    front = front->next;

    if (isEmpty())
        rear = nullptr;

    delete temp;
    return data;
}