#include "../lib/VariadicTable.h"
#include "declare.h"
#include "ctime"

void printBook(Buku *book)
{
    cout << "Judul buku : " << book->judul << endl;
    cout << "ISBN       : " << book->isbn << endl;
    cout << "Penulis    : " << book->penulis << endl;
    cout << "Penerbit   : " << book->penerbit << endl;
    cout << "Th. Terbit : " << book->th_terbit << endl;
    cout << "Harga      : " << fprice(book->harga) << endl;
}

void printStruk(Buku buku, Queue &list, int money_in, int money_out, int total)
{
    int receipt_number = 1;
    ofstream write;
    ifstream read;
    string line;

    while (true)
    {
        read.open("export\\history\\receipt" + to_string(receipt_number) + ".txt");
        if (read)
        {
            receipt_number++;
            read.close();
        }
        else
        {
            read.close();
            break;
        }
    }

    time_t now = time(0);
    char *dt = ctime(&now);

    write.open("export\\history\\receipt" + to_string(receipt_number) + ".txt");
    write << "\t\t\t======================" << endl;
    write << "\t\t\t| KWITANSI PEMBELIAN |" << endl;
    write << "\t\t\t======================" << endl;
    write << "Tanggal : " << dt << endl;
    VariadicTable<string, int, string, string> vt({"Judul Buku", "Jumlah Buku", "Harga Satuan", "Total"});
    while (!list.isEmpty())
    {
        buku = list.dequeue();
        vt.addRow(buku.judul, buku.jumlah, fprice(buku.harga), fprice((buku.jumlah * buku.harga)));
    }
    vt.print(write, '_', '-', '-');
    write << "Jumlah tagihan     : " << fprice(total) << endl;
    write << "Uang dibayarkan    : " << fprice(money_in) << endl;
    write << "Kembalian          : " << fprice(money_out) << endl;
    write << "\t\t===================================" << endl;
    write << "\t\tTerimakasih Telah Membeli Buku Kami" << endl;
    write << "\t\t===================================" << endl;
    write.close();

    read.open("export\\history\\receipt" + to_string(receipt_number) + ".txt");
    while (getline(read, line))
    {
        std::cout << line << "\n";
    }
    read.close();
}

void beli()
{
    char answer = '\0';
    int option = 0;
    int jumlah_beli = 0;
    int inputuang = 0;
    int kembalian = 0;
    int total = 0;
    string cari;
    Queue list_beli;
    Buku *book = nullptr;
    Buku buku_dibeli;
    int size = 0;
    size = calculate(size);
    Buku *books = new Buku[size];
    Data data(books, size);

    data.read();

find:
    system("cls");
    cout << "========== PENCARIAN BUKU ==========\n";
    cout << "Masukkan Judul Buku yang Akan Dicari: ";
    cin.ignore();
    getline(cin, cari);
    book = data.search(cari);
    if (!book)
    {
        while (true)
        {
            system("cls");
            cout << "Maaf data yang Anda Cari Tidak ada" << endl;
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
            {
                system("cls");
                cout << "Error" << endl;
                cout << "Tekan enter untuk kembali menginputkan...";
                cin.get();
            }
        }
    }
    else
    {
        while (true)
        {
            system("cls");
            printBook(book);
            cout << "Apakah anda jadi membeli buku ini?  (y/t) : ";
            cin >> answer;

            if (answer == 'y')
            {
                system("cls");
                cout << "Masukkan jumlah buku yang akan dibeli: ";
                cin >> jumlah_beli;

                if (book->jumlah - jumlah_beli < 0)
                {
                    system("cls");
                    cout << "Stok kurang" << endl;
                    cin.ignore();
                    cin.get();
                }
                else
                {
                    buku_dibeli = *(book);
                    buku_dibeli.jumlah = jumlah_beli;
                    list_beli.enqueue(buku_dibeli);
                    book->jumlah = book->jumlah - jumlah_beli;
                    total = total + (book->harga) * jumlah_beli;
                }
                while (true)
                {
                    system("cls");
                    cout << "Apakah anda ingin membeli lagi? (y/t) : ";
                    cin >> answer;

                    if (answer == 'y')
                    {
                        goto find;
                    }
                    else if (answer == 't')
                    {
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Error" << endl;
                        cin.ignore();
                        cin.get();
                    }
                }
                while (true)
                {
                    system("cls");
                    cout << "Harga total: " << fprice(total) << endl;
                    cout << "Masukan Jumlah Uang Pembayaran : ";
                    cin >> inputuang;

                    kembalian = inputuang - total;
                    if (kembalian < 0)
                    {
                        system("cls");
                        cout << "Maaf uang anda kurang" << endl;
                        cout << "Silahkan Masukan Kembali" << endl;
                        cin.ignore();
                        cin.get();
                    }
                    else if (kembalian > 0)
                    {
                        cout << "Kembalian : " << fprice(kembalian) << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    else
                    {
                        cout << "Terima kasih" << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                }
                system("cls");
                printStruk(buku_dibeli, list_beli, inputuang, kembalian, total);
                cin.get();
                break;
            }
            else if (answer == 't')
                break;
            else
            {
                system("cls");
                cout << "error" << endl;
                cin.ignore();
                cin.get();
            }
        }
    }

    data.validation();
    data.write();
}
