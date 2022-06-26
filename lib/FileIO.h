#pragma once
#include "Queue.h"

class FileIO
{
private:
    fstream file;

protected:
    Buku *datas;
    int size;
    int index;

public:
    void read();
    void read(Queue &);
    void write();
};