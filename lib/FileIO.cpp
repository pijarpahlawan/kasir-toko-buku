#include "FileIO.h"

FileIO::FileIO(int numof_datas)
{
    this->size = numof_datas;
    datas = new std::string[this->size];
}

std::string *FileIO::read(const char *name)
{
    file.open(name, std::ios::in);

    //! butuh penanganan error
    for (int i = 0; i < this->size; i++)
        std::getline(file, *(datas + i));

    file.close();

    return datas;
}

// TODO: definisi

void FileIO::write(const char *name, std::string *datas)
{
    file.open(name, std::ios::out);

    //! butuh penanganan error
    for (int i = 0; i < this->size; i++)
        file << *(datas + i) << std::endl;

    file.close();
}