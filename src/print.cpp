#include "declare.h"

void print(Buku *data)
{
    if (data)
    {
        cout << "Judul buku : " << data->judul << endl;
        cout << "ISBN       : " << data->isbn << endl;
        cout << "Penulis    : " << data->penulis << endl;
        cout << "Penerbit   : " << data->penerbit << endl;
        cout << "Th. Terbit : " << data->th_terbit << endl;
        cout << "Harga      : " << data->harga << endl;
    }
    else
    {
        // TODO: NOTIF ERROR
        // TODO: PILIHAN = 1. KE MENU; 2. KE PENCARIAN
    }
}

// TODO: buat funcion print spesifikasi buku
//! if ptr then print else notif not exist
