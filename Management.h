#include <iostream>
#include "Store.h"

using namespace std;

void welcomeStore()
{
    system("CLS");
    bool check;
    cout << "\n ************************** Welcome to the Store **************************\n"
         << endl;

    store Moze;

    cout << "\n\n ++ Would you like to get started by choosing"
         << "\n    which shop to head in first?" << endl;
    cout << "\n\n ++ Enter \'1\' for \'Yes\' and \'0\' for \'No\'" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> check;
    system("CLS");
    if (check)
    {
        Moze.shops();
        system("CLS");
        cout << "\n\n\n ************************** Thank you for coming, See you next time? ;) **************************\n\n\n"
             << endl;
        return;
    }
    else if (!check)
    {
        cout << "Would you like to exit the store instead?" << endl;
        cin >> check;
        if (!check)
        {
            Moze.shops();
        }
        else
        {
            system("CLS");
            cout << "******* Thank you for coming, See you next time? ;) *******" << endl;
            return;
        }
    }
}