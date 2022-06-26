#pragma once
#include "FileIO.h"

class Data : public FileIO
{
private:
    bool finded;
    bool isPrecede(string, string);

public:
    Data(Buku *, int &);
    Buku *search(const char *);
    void sort();
};