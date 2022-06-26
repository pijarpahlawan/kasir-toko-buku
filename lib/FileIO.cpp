#include "FileIO.h"

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
        index++;
    }
}

void FileIO::write()
{
    file.open("database.csv", ios::out);

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
