#include "declare.h"

string fprice(int price)
{

    int count = 0;
    for (int i = to_string(price).size(); i > 0; i -= 3)
    {
        // tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0)
            to_string(price).insert(i, ".");
        count++;
    }
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return "Rp" + to_string(price);
}