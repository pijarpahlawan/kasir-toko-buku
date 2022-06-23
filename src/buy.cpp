#include "declare.h"

Buku *beli()
{
    // TODO: disempurakan lagi ya wkwkwk
    // TODO: jangan lupa deklarasikan function ini ke declare.h sebagai extern
    //! 1. bikin array of struct buku (dinamis)
    Buku *kumpulan_buku = new Buku[numof_book];
    Buku *buku = nullptr;
    //! 2. bikin objek data
    //! 3. parse array tadi ke objek data
    Data data(kumpulan_buku, numof_book);
    //! 4. cari buku
    data.read();
    buku = data.search("Judul buku");
    return buku;
}