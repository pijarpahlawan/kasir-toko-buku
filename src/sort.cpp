#include <iostream>
using namespace std;

#include "declare.h"

/**
 * @brief Menentukan string yang akan ditukar
 *
 * @param a first string
 * @param b second string
 * @return true
 * @return false
 */
bool isPrecede(string a, string b)
{
    int id = 0;
    while (id != (b.length() - 1) || id != (a.length() - 1))
    {
        if (b[id] < a[id])
            return true;
        else if (b[id] > a[id])
            return false;
        id++;
    }
    return id == (b.length() - 1) ? true : false;
}

/**
 * @brief Mengurutkan string sesuai alfabet
 *
 * @param obj string yang akan diurutkan
 * @param it banyak string yang akan diurutkan
 */
void sortingName(string *obj, int it)
{
    string temp;
    int j = 0;

    for (int i = 0; i < it; i++)
    {
        temp = *(obj + i);
        j = i - 1;
        while (j >= 0 && isPrecede(*(obj + j), temp))
        {
            *(obj + j + 1) = *(obj + j);
            j--;
        }
        *(obj + j + 1) = temp;
    }
}