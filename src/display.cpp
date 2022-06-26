#include "../lib/VariadicTable.h"
#include "declare.h"

int display()
{
    int option = 0;
    int size = 0;
    Buku *books = new Buku[size];
    Data data(books, size);

    size = calculate(size);

    data.read();

    VariadicTable<int, string, int> vt({"No.", "Judul", "Harga"});
    for (int i = 0; i < size; i++)
        vt.addRow(i + 1, books->judul, books->harga);
    vt.print(cout);

    cout << "\n[1] Input data\n[2] Beli buku" << endl;
    cout << "Silahkan pilih: ";
    cin >> option;

    delete[] books;

    return option;
}