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
            cout << "Maaf data yang Anda Cari Tidak ada" << endl;

            // TODO: meminta lanjut ke awal/cari lagi
            cout << "\tPilihan : " << endl;
            cout << "\t1. Kembali ke Menu Utama " << endl;
            cout << "\t2. Kembali ke Pencarian" << endl;

            int pilihan;
            cout << "\tPilihan menu berdasarkan angka: " << endl;
            cin >> pilihan;
            if (pilihan == 1)
                return;
            else if (pilihan != 2)
            // notif salah
        }
        else
        {
            cout << "Buku Ditemukan!\n";
            // TODO: print buku
            cout << "Judul buku : " << book->judul << endl;
            cout << "ISBN       : " << book->isbn << endl;
            cout << "Penulis    : " << book->penulis << endl;
            cout << "Penerbit   : " << book->penerbit << endl;
            cout << "Th. Terbit : " << book->th_terbit << endl;
            cout << "Harga      : " << book->harga << endl;

            // TODO: pertanyaan jadi beli
            cout << "Apakah anda jadi membeli buku ini?  (y/t)/n";
            cin >> jawab;

            //** if jadi then
            if (jawab == 'y')
            {
                // TODO: pembayaran
                cout << "Total pembayaran anda adalah: /n" << harga;
            }
            else if (jawab != t)
                // notif salah
                else break;
            /* code */
}
}
 data.write();
// TODO: cetak nota
}