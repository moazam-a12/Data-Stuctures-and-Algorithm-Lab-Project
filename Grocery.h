#include <iostream>
#include "class_Product.h"
using namespace std;

class grocery
{
    Product *head;
    Product *sales;

public:
    void enter();
};

void grocery::enter()
{
    int choice;
    cout << "\n****Welcome to the Grocery Shop****\n"
         << endl;
    cout << "Explore the Options:\n"
         << "\n\t1.Surf for Products"
         << "\n\t2.Look for the Products on Sale"
         << "\n\t2.Check out" << endl;
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        cout << "Here are the products" << endl;
        break;

    default:
        break;
    }
    return;
}
