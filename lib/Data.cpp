#include "Data.h"

/**
 * @brief Construct a new Data:: Data object
 *
 * @param datas data buku
 * @param numof_datas jumlah judul buku
 */
Data::Data(Buku *datas, int &numof_datas)
{
    this->datas = datas;
    size = numof_datas;
}

/**
 * @brief mencari judul buku yang sama dengan target
 *
 * @param title target judul
 * @return Buku*
 */
Buku *Data::search(string title)
{
    title = capitalize(title);
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

/**
 * @brief menentukan judul mana yang didahulukan dalam urutan
 *
 * @param a judul 1
 * @param b judul 2
 * @return true
 * @return false
 */
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

/**
 * @brief mengurutkan judul buku sesuai abjad
 *
 */
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

/**
 * @brief memvalidasi jumlah buku di dalam database yang 0 akan dihapus
 *
 */
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