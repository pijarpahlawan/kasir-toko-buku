#include "FileIO.h"

/**
 * @brief Membaca data buku di dalam database
 *
 * @return Buku*
 */
Buku *FileIO::read()
{
    index = 0;

    // data dari file
    file.open("database.csv", std::ios::in);
    //! butuh penanganan error
    while (!file.eof())
    {
        std::getline(file, (datas + index)->judul, ',');
        std::getline(file, (datas + index)->isbn, ',');
        std::getline(file, (datas + index)->penulis, ',');
        std::getline(file, (datas + index)->penerbit, ',');
        std::getline(file, (datas + index)->th_terbit, ',');
        file >> (datas + index)->harga;
        index++;
    }
    file.close();

    return datas;
}

/**
 * @brief Membaca data dari database dan dari inputan user terbaru
 *
 * @param new_datas inputan user terbaru
 */
void FileIO::read(Queue &new_datas)
{
    index = 0;

    // data dari file
    file.open("database.csv", std::ios::in);
    //! butuh penanganan error
    while (!file.eof())
    {
        std::getline(file, (datas + index)->judul, ',');
        std::getline(file, (datas + index)->isbn, ',');
        std::getline(file, (datas + index)->penulis, ',');
        std::getline(file, (datas + index)->penerbit, ',');
        std::getline(file, (datas + index)->th_terbit, ',');
        file >> (datas + index)->harga;
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

/**
 * @brief Menulis data buku ke dalam database
 *
 */
void FileIO::write()
{
    file.open("database.csv", std::ios::out);

    //! butuh penanganan error
    for (int i = 0; i < size; i++)
    {
        i != 0 ? file << std::endl : file;
        file << (datas + i)->judul << ',';
        file << (datas + i)->isbn << ',';
        file << (datas + i)->penulis << ',';
        file << (datas + i)->penerbit << ',';
        file << (datas + i)->th_terbit << ',';
        file << (datas + i)->harga;
    }

    file.close();
}
