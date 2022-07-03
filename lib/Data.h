#pragma once
#include "FileIO.h"

/**
 * @brief kelas pengolahan data
 *
 */
class Data : public FileIO
{
private:
    bool finded;
    bool isPrecede(string, string);

public:
    Data(Buku *, int &);
    Buku *search(string);
    void sort();
    void validation();
};