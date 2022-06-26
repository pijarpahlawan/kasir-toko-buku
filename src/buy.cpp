#include "declare.h"

void beli()
{
    int size = 0;
    size = calculate(size);
    Buku *books = new Buku[size];
    Buku *buku = nullptr;
    Data data(books, size);
    string title;

    // TODO: meminta judul buku yang dicari

    data.read();

    while (true)
    {
        buku = data.search(title);
        if (!buku)
        {
            // TODO: tampilkan notif kosong
            // TODO: meminta lanjut ke awal/cari lagi
            //* if awal then return
            return;
        }
        else
        {
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