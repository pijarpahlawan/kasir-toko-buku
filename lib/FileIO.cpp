#include "FileIO.h"

string FileIO::capitalize(const string &str)
{
    string result = str;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        // 32 = karakter spasi; 45 = karakter tanda hubung; 46 = karakter titik; 97 s/d 122 = lower case
        if ((i == 0 || result[i - 1] == 32 || result[i - 1] == 45 || result[i - 1] == 46) && result[i] > 96 && result[i] < 123)
        {
            result[i] = result[i] - 32;
        }
        else if (!(i == 0 || result[i - 1] == 32 || result[i - 1] == 45 || result[i - 1] == 46) && result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

void FileIO::read()
{
    string var_conv = "";
    index = 0;

    // data dari file
    file.open("export\\database.csv", ios::in);
    //! butuh penanganan error
    while (file.peek() != ifstream::traits_type::eof())
    {
        getline(file, (datas + index)->judul, ',');
        getline(file, (datas + index)->isbn, ',');
        getline(file, (datas + index)->penulis, ',');
        getline(file, (datas + index)->penerbit, ',');
        getline(file, (datas + index)->th_terbit, ',');
        getline(file, var_conv, ',');
        (datas + index)->harga = stoi(var_conv);
        getline(file, var_conv);
        (datas + index)->jumlah = stoi(var_conv);
        index++;
    }
    file.close();
}

void FileIO::read(Queue &new_datas)
{
    string var_conv = "";
    index = 0;

    // data dari file
    file.open("export\\database.csv", ios::in);
    //! butuh penanganan error
    while (file.peek() != ifstream::traits_type::eof())
    {
        getline(file, (datas + index)->judul, ',');
        getline(file, (datas + index)->isbn, ',');
        getline(file, (datas + index)->penulis, ',');
        getline(file, (datas + index)->penerbit, ',');
        getline(file, (datas + index)->th_terbit, ',');
        getline(file, var_conv, ',');
        (datas + index)->harga = stoi(var_conv);
        getline(file, var_conv);
        (datas + index)->jumlah = stoi(var_conv);
        index++;
    }
    file.close();

    // data dari inputan user
    while (!new_datas.isEmpty())
    {
        *(datas + index) = new_datas.dequeue();
        (datas + index)->judul = capitalize((datas + index)->judul);
        index++;
    }
}

void FileIO::write()
{
    file.open("export\\database.csv", ios::out);

    //! butuh penanganan error
    for (int i = 0; i < size; i++)
    {
        i != 0 ? file << endl : file;
        file << (datas + i)->judul << ',';
        file << (datas + i)->isbn << ',';
        file << (datas + i)->penulis << ',';
        file << (datas + i)->penerbit << ',';
        file << (datas + i)->th_terbit << ',';
        file << (datas + i)->harga << ',';
        file << (datas + i)->jumlah;
    }

    file.close();
}
