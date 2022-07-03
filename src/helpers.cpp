#include "declare.h"

string fprice(int price)
{
    string price_s = to_string(price);
    int count = 0;
    for (int i = price_s.size(); i > 0; i -= 3)
    {
        // tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0)
            price_s.insert(i, ".");
        count++;
    }
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return "Rp" + price_s;
}