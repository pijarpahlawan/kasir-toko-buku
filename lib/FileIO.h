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
    string capitalize(const string &);

public:
    void read();
    void read(Queue &);
    void write();
};