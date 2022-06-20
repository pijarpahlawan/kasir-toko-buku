#include <fstream>

class FileIO
{
private:
    std::fstream file;
    std::string *datas;
    int size;

public:
    FileIO(int);
    std::string *read(const char *);
    void write(const char *, std::string *);
};