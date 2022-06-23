#pragma once
#include <iostream>
using namespace std;

// Jumlah buku dalam database
int numof_book = 0;

// Informasi detail buku
struct Buku
{
    string judul, isbn, penulis, penerbit, th_terbit;
    int harga;
};
