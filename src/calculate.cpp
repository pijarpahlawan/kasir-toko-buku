#include "declare.h"

int calculate(int numof_title_new)
{
    int numof_title_now;
    ifstream read_amount("export\\amount.txt");
    read_amount.seekg(23);
    read_amount >> numof_title_now;
    read_amount.close();

    numof_title_now += numof_title_new;

    ofstream write_amount("export\\amount.txt");
    write_amount << "jumlah buku saat ini = " << numof_title_now;
    write_amount.close();

    return numof_title_now;
}