#include "declare.h"

void beli()
{
    int size = 0;
    size = calculate(size);
    Buku *books = new Buku[size];
    Buku *book = nullptr;
    Data data(books, size);
    string cari;

    data.read();

    while (true)
    {
        cout << "========== PENCARIAN BUKU ==========\n";
        cout << "Masukkan Judul Buku yang Akan Dicari: ";
        getline(cin, cari);
        book = data.search(cari);
        if (!book)
        {
            cout << "Buku Tidak Ditemukan\n";
            // TODO: tampilkan notif kosong
            // TODO: meminta lanjut ke awal/cari lagi
            //* if awal then return
            return;
        }
        else
        {
            cout << "Buku Ditemukan!\n";
            // TODO: print buku
            // TODO: pertanyaan jadi beli
            //** if jadi then
            // TODO: pembayaran
            // TODO: beli lagi?
            //* if !beli_lagi then break
            //** else (if awal then return)
        }
    }
    data.write();
    // TODO: cetak nota
}