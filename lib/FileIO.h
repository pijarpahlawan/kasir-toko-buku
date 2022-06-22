#include <fstream>
#include "Queue.h"

class FileIO
{
private:
    std::fstream file;

protected:
    Buku *datas;
    int size;
    int index;

public:
    Buku *read();
    void read(Queue &);
    void write();
};