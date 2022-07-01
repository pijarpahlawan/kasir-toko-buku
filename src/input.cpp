#include "declare.h"

void questions(Queue &data)
{
    Buku buku;
    cout << "Masukkan judul buku    : ";
    cin.ignore();
    getline(cin, buku.judul);
    cout << "Masukkan nomor ISBN    : ";
    getline(cin, buku.isbn);
    cout << "Masukkan nama penulis  : ";
    getline(cin, buku.penulis);
    cout << "Masukkan nama penerbit : ";
    getline(cin, buku.penerbit);
    cout << "Masukkan tahun terbit  : ";
    getline(cin, buku.th_terbit);
    cout << "Masukkan harga buku    : ";
    cin >> buku.harga;
    cout << "Masukkan jumlah buku   : ";
    cin >> buku.jumlah;
    data.enqueue(buku);
}

int request(Queue &data)
{
    char option = '\0';
    int size = 0;

    while (true)
    {
        system("cls");
        questions(data);
        cout << "\nIngin menginputkan lagi? (y/t)" << endl;
        cin >> option;
        size++;
        if (option == 't')
            break;
    }

    size = calculate(size);

    return size;
}

void input()
{
    Queue new_data;
    int size = request(new_data);
    Buku *books = new Buku[size];
    Data data(books, size);

    data.read(new_data);
    data.sort();
    data.write();

    delete[] books;
}
