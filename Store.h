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
    cout << "Choose from the following shops: " << endl;
    cout << "\n1.\tGrocery Shop"
         << "\n2.\tArcade"
         << "\n3.\tFood Court"
         << "\n4.\tLibrary"
         << "\n5.\tCinema" << endl;
    cout << "\nEnter your answer: ";
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
store::~store() {}