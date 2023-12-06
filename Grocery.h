#include <iostream>
#include <fstream>
#include "class_Product.h"
using namespace std;

class grocery
{
    Product *cart;
    Product *receipt;

public:
    void enter();
    void stock();
};
void grocery::enter()
{
    int choice;
    cout << "\n****Welcome to the Grocery Shop****\n"
         << endl;
    cout << "Explore the Options:\n"
         << "\n1.\tSurf for Products"
         << "\n2.\tLook for the Products on Sale"
         << "\n3.\tCheck out" << endl;
    cout << "\nEnter your answer: ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        stock();
        break;

    default:
        break;
    }
    return;
}
void grocery::stock()
{
    ifstream availProds;
    availProds.open("Grocery_Stock.txt", ios::in);

    if (!availProds.is_open())
    {
        cout << "Error: Couldn't Open the File" << endl;
    }
    else
    {
        string line;
        while (getline(availProds, line))
        {
            if (line.find("Product") != string::npos) //Finds the line of product, its description afterwards
            {
                string name, tempStr;
                int price, quantity;

                getline(availProds, tempStr);
                name = tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1);

                getline(availProds, tempStr);
                price = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));

                getline(availProds, tempStr);
                quantity = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));

                if (cart == NULL)
                {
                    cart = new Product(name, price, quantity);
                }
                else
                {
                    cart->insertAtTail(cart, name, price, quantity);
                }
            }
        }
        availProds.close();
    }
}