#include "../lib/VariadicTable.h"
#include "declare.h"

void printStruk(Buku buku, Queue &list)
{
    // TODO: cetak nota
    cout << "Tanggal :........." << endl;
    VariadicTable<string, int, int, int> vt({"Judul Buku", "Jumlah Buku", "Harga Satuan", "Total"});
    while (!list.isEmpty())
    {
        buku = list.dequeue();
        vt.addRow(buku.judul, buku.jumlah, buku.harga, (buku.jumlah * buku.harga));
    }
    vt.print(cout, '_', '-', '-');
}

void beli()
{
    int inputuang = 0;
    int kembalian = 0;
    int option = 0;
    int size = 0;
    int jumlah_beli = 0;
    int jumlah_pembelian = 0;
    char answer = '\0';
    size = calculate(size);
    Buku *books = new Buku[size];
    Buku *book = nullptr;
    Buku buku_dibeli;
    Data data(books, size);
    string cari;
    Queue list_beli;

    data.read();

find:
    cout << "========== PENCARIAN BUKU ==========\n";
    cout << "Masukkan Judul Buku yang Akan Dicari: ";
    cin.ignore();
    getline(cin, cari);
    book = data.search(cari);
    if (!book)
    {
        while (true)
        {
            cout << "Maaf data yang Anda Cari Tidak ada" << endl;

            // TODO: meminta lanjut ke awal/cari lagi
            cout << "Pilihan : " << endl;
            cout << "[1] Kembali ke Menu Utama " << endl;
            cout << "[2] Kembali ke Pencarian" << endl;
            cout << "Pilihan menu berdasarkan angka: ";
            cin >> option;
            if (option == 1)
                break;
            else if (option == 2)
                goto find;
            else
                cout << "Error" << endl;
        }
    }
    else
    {
        while (true)
        {
            // TODO: print buku
            cout << "Judul buku : " << book->judul << endl;
            cout << "ISBN       : " << book->isbn << endl;
            cout << "Penulis    : " << book->penulis << endl;
            cout << "Penerbit   : " << book->penerbit << endl;
            cout << "Th. Terbit : " << book->th_terbit << endl;
            cout << "Harga      : " << book->harga << endl;

            // TODO: pertanyaan jadi beli
            cout << "Apakah anda jadi membeli buku ini?  (y/t) : ";
            cin >> answer;

            //** if jadi then
            if (answer == 'y')
            {
                cout << "Masukkan jumlah buku yang akan dibeli: ";
                cin >> jumlah_beli;

                if (book->jumlah - jumlah_beli < 0)
                {
                    cout << "Stok kurang" << endl;
                }
                else
                {
                    buku_dibeli = *(book);
                    buku_dibeli.jumlah = jumlah_beli;
                    list_beli.enqueue(buku_dibeli);
                    book->jumlah = book->jumlah - jumlah_beli;
                    // TODO: pembayaran
                    while (true)
                    {
                        cout << "Harga total: " << (book->harga) * jumlah_beli << endl;
                        cout << "Masukan Jumlah Uang Pembayaran : ";
                        cin >> inputuang;

                        kembalian = inputuang - (book->harga) * jumlah_beli;
                        if (kembalian < 0)
                        {
                            cout << "Maaf uang anda kurang" << endl;
                            cout << "Silahkan Masukan Kembali" << endl;
                        }
                        else if (kembalian > 0)
                        {
                            cout << "Kembalian : " << kembalian << endl;
                            break;
                        }
                        else
                        {
                            cout << "Terima kasih" << endl;
                            break;
                        }
                    }
                    jumlah_pembelian++;
                }
                while (true)
                {
                    cout << "Apakah anda ingin membeli lagi? (y/t) : ";
                    cin >> answer;

                    if (answer == 'y')
                    {
                        goto find;
                    }
                    else if (answer == 'n')
                    {
                        break;
                    }
                    else
                        cout << "Error" << endl;
                }
                break;
            }
            else if (answer == 'n')
                break;
            else
                cout << "error" << endl;
        }
    }

    if (jumlah_pembelian > 0)
    {
        printStruk(buku_dibeli, list_beli);
    }

    data.validation();
    data.write();
}