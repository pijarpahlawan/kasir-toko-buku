#include "../lib/VariadicTable.h"
#include "declare.h"

/**
 * @brief menampilkan buku yang tersedia
 *
 */
void display()
{
    int size = 0;
    size = calculate(size);
    Buku *books = new Buku[size];
    Data data(books, size);

    data.read();

    cout << "\t\t Kasir Toko Buku " << endl;
    cout << "\t\t*****************" << endl;
    VariadicTable<int, string, string, string> vt({"No.", "Judul", "Penulis", "Harga"});
    for (int i = 0; i < size; i++)
        vt.addRow(i + 1, (books + i)->judul, (books + i)->penulis, fprice((books + i)->harga));
    vt.print(cout, '=', '=', '=');

    delete[] books;
}