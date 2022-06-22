#include "FileIO.h"

/**
 * @brief Construct a new FileIO:: File IO object
 *
 * @param numof_datas jumlah buku
 */
FileIO::FileIO(int numof_datas)
{
    size = numof_datas;
    this->datas = new Buku[size];
}

/**
 * @brief Membaca data buku dari file .csv
 *
 * @param name nama file dengan ekstensi csv
 * @return Buku*
 */
Buku *FileIO::read(const char *name)
{
    index = 0;
    // data dari file
    file.open(name, std::ios::in);
    //! butuh penanganan error
    while (!file.eof())
    {
        std::getline(file, (this->datas + index)->judul, ',');
        std::getline(file, (this->datas + index)->isbn, ',');
        std::getline(file, (this->datas + index)->penulis, ',');
        std::getline(file, (this->datas + index)->penerbit, ',');
        std::getline(file, (this->datas + index)->th_terbit, ',');
        file >> (this->datas + index)->harga;
        index++;
    }
    file.close();

    return this->datas;
}

/**
 * @brief Membaca data dari file dan data baru dari user
 *
 * @param name nama file dengan ekstensi csv
 * @param datas data baru dari user
 * @return Buku*
 */
Buku *FileIO::read(const char *name, Queue &datas)
{
    index = 0;
    // data dari file
    file.open(name, std::ios::in);
    //! butuh penanganan error
    while (!file.eof())
    {
        std::getline(file, (this->datas + index)->judul, ',');
        std::getline(file, (this->datas + index)->isbn, ',');
        std::getline(file, (this->datas + index)->penulis, ',');
        std::getline(file, (this->datas + index)->penerbit, ',');
        std::getline(file, (this->datas + index)->th_terbit, ',');
        file >> (this->datas + index)->harga;
        index++;
    }
    file.close();

    // data dari inputan user
    while (index != size)
    {
        *(this->datas + index) = datas.dequeue();
        index++;
    }

    return this->datas;
}

/**
 * @brief Menulis data ke dalam file .csv
 *
 * @param name nama file dengan ekstensi csv
 * @param datas data buku yang akan dimasukkan ke file
 */
void FileIO::write(const char *name, Buku *datas)
{
    file.open(name, std::ios::out);

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

/**
 * @brief Destroy the FileIO:: FileIO object
 *
 */
FileIO::~FileIO()
{
    delete[] datas;
}