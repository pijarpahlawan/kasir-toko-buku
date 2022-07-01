#include "Data.h"

Data::Data(Buku *datas, int &numof_datas)
{
    this->datas = datas;
    size = numof_datas;
}

Buku *Data::search(string title)
{
    finded = false;
    index = 0;

    while (index != size)
    {
        if ((datas + index)->judul == title)
        {
            finded = true;
            break;
        }
        index++;
    }

    if (finded)
        return (datas + index);
    else
        return nullptr;
}

bool Data::isPrecede(string a, string b)
{
    int id = 0;
    while (id != (b.length() - 1) || id != (a.length() - 1))
    {
        if (b[id] < a[id])
            return true;
        else if (b[id] > a[id])
            return false;
        id++;
    }
    return id == (b.length() - 1) ? true : false;
}

void Data::sort()
{
    Buku temp;
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        temp = *(datas + i);
        j = i - 1;
        while (j >= 0 && isPrecede((datas + j)->judul, temp.judul))
        {
            *(datas + j + 1) = *(datas + j);
            j--;
        }
        *(datas + j + 1) = temp;
    }
}

void Data::validation()
{
    int i = 0;

    while (i < size)
    {
        for (i; i < size; i++)
            if ((datas + i)->jumlah == 0)
                break;
        if (i < size)
        {
            size--;
            for (int j = i; j < size; j++)
                *(datas + j) = *(datas + j + 1);
        }
    }

    ofstream write_amount("export\\amount.txt");
    write_amount << "jumlah buku saat ini = " << size;
    write_amount.close();
}