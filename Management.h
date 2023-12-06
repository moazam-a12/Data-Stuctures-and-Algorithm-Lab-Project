#include <iostream>
#include "Store.h"

using namespace std;

void welcomeStore()
{
    system("CLS");
    bool check;
    cout << "\n********Welcome to the Store********\n"
         << endl;
    store Moze;
    cout << "\n\nWould you like to get started by choosing"
         << " \nwhich shop to head in first?"
         << "\t(\'1\' for \'Yes\' and \'0\' for \'No\')" << endl;
    cout << "\nEnter your answer: ";
    cin >> check;
    system("CLS");
    if (check)
    {
        Moze.shops();
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