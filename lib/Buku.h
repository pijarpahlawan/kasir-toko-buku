#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Informasi detail buku
struct Buku
{
    string judul, isbn, penulis, penerbit, th_terbit;
    int harga, jumlah;
};
