#include <fstream>
#include "Queue.h"

class FileIO
{
private:
    std::fstream file;
    Buku *datas;
    int size;
    int index;

public:
    FileIO(int);
    Buku *read(const char *);
    Buku *read(const char *, Queue &);
    void write(const char *, Buku *);
    ~FileIO();
};