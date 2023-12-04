#include <iostream>
#include <stdlib.h>
#include "Grocery.h"
#include "Arcade.h"
#include "Food_Court.h"
#include "Library.h"
#include "Cinema.h"
using namespace std;

class store
{
private:
    grocery shop1;
    // arcade shop2;
    // foodCourt shop3;
    // library shop4;
    // cinema shop5;

public:
    store();
    void welcome();
    void menu();
};
store::store() {}
void store::welcome()
{
    bool check;
    cout << "\n********Welcome to the Store********\n"
         << endl;
    cout << "\n\nWould you like to get started by choosing"
         << " \nwhich shop to head in first?"
         << "\t(\'1\' for \'Yes\' and \'0\' for \'No\')" << endl;
    cin >> check;
    system("CLS");
    if (check)
    {
        this->menu();
    }
    else if (!check)
    {
        cout << "Would you like to exit the store instead?" << endl;
        cin >> check;
        if (!check)
        {
            this->menu();
        }
        else
        {
            return;
        }
    }
}
void store::menu()
{
    int choice;
    cout << "\nChoose from the following shops: " << endl;
    cout << "\n1. \tGrocery Shop"
         << "\n2. \tArcade"
         << "\n3. \tFood Court"
         << "\n4. \tLibrary"
         << "\n5. \tCinema" << endl;
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        shop1.enter();
        break;
        // case 2:
        //     shop2.enter();
        //     break;
        // case 3:
        //     shop3.enter();
        //     break;
        // case 4:
        //     shop4.enter();
        //     break;
        // case 5:
        //     shop5.enter();
        //     break;

    default:
        break;
    }
}