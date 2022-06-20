#include "FileIO.h"

/**
 * @brief Construct a new FileIO:: FileIO object
 *
 * @param numof_datas jumlah data
 */
FileIO::FileIO(int numof_datas)
{
    this->size = numof_datas;
    datas = new std::string[this->size];
}

/**
 * @brief membaca data dari file dan mengembalikan data dalam bentuk string
 *
 * @param name nama file
 * @return std::string*
 */
std::string *FileIO::read(const char *name)
{
    file.open(name, std::ios::in);

    //! butuh penanganan error
    for (int i = 0; i < this->size; i++)
        std::getline(file, *(datas + i));

    file.close();

    return datas;
}

/**
 * @brief menulis suatu data string ke dalam file
 *
 * @param name nama file
 * @param datas data yang akan ditulis
 */
void FileIO::write(const char *name, std::string *datas)
{
    file.open(name, std::ios::out);

    //! butuh penanganan error
    for (int i = 0; i < this->size; i++)
        file << *(datas + i) << std::endl;

    file.close();
}