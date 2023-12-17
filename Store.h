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
    arcade shop2;
    foodCourt shop3;
    library shop4;
    cinema shop5;

public:
    store();
    void shops();
    ~store();
};
store::store() {}
void store::shops()
{
    int choice;
    do
    {
        system("CLS");
        cout << "\n\n ************************** Welcome to the Store **************************\n"
             << endl;
        cout << "\n\n ++ Choose from the following shops: " << endl;
        cout << "\n\n ++ 1. \tGROCERY SHOP"
             << "\n\n ++ 2. \tARCADE"
             << "\n\n ++ 3. \tFOOD COURT"
             << "\n\n ++ 4. \tLIBRARY"
             << "\n\n ++ 5. \tCINEMA"
             << "\n\n ++ 6. \tEXIT" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        cin >> choice;
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
        case 4:
            shop4.enter();
            break;
        case 5:
            shop5.enter();
            break;
        case 6:
            return;

        default:
            break;
        }
    } while (choice);
}
store::~store() {}