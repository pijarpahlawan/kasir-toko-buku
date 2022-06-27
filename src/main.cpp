#include "declare.h"

int main()
{
    int menu = 0;

    while (true)
    {
        display();

        cout << "\n[1] Input data\n[2] Beli buku\n[3] Keluar" << endl;
        cout << "Silahkan pilih: ";
        cin >> menu;

        if (menu == 1)
        {
            input();
        }
        else if (menu == 2)
        {
            // beli
        }
        else if (menu == 3)
        {
            break;
        }
        else
        {
            cout << "Pilih yg benar masnya" << endl;
        }
    }

    return 0;
}
