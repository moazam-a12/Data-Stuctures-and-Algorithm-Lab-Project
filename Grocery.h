#include <iostream>
#include <stdlib.h>
#include <stack>
#include <fstream>
#include "class_Product.h"
using namespace std;

class grocery
{
    Product *stock;
    stack<Product *> Cart;
    Product *receipt;

public:
    grocery();
    void enter();
    void surfProducts();
    void getStockFromFile();
    void checkOut();
};
grocery::grocery()
{
    stock = NULL;
    receipt = NULL;
}
void grocery::enter()
{
    int choice;
    system("CLS");
    cout << "\n****Welcome to the Grocery Shop****\n"
         << endl;
    cout << "Explore the Options:\n"
         << "\n1.\tSurf for Products"
         << "\n2.\tCheck out"
         << "\n3.\tMain Menu" << endl;
    cout << "\nEnter your answer: ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        surfProducts();
        break;
    case 2:
        checkOut();
        break;
    case 3:
        return;

    default:
        surfProducts();
        break;
    }
    return;
}
void grocery::surfProducts()
{
    if (this->stock == NULL)
    {
        getStockFromFile(); // working as expected as of now
    }
    bool choice = true;
    int proNum;
    system("CLS");
    cout << "The Products available in the store are as: " << endl;
    cout << stock << endl;

    cout << "Anything that sparked your interest?" << endl;
    cout << "\nAdd it to your cart by giving the number of the product: " << endl;
    cin >> proNum;
    Product *pro = stock->proDeets((proNum - 1), stock);
    Cart.push(pro);
    system("CLS");
    cout << "Add another product to the cart or go back to the main menu?" << endl;
    cout << "\n1.\tAdd another Product"
         << "\n2.\tMain" << endl;
    int decision;
    cin >> decision;
    switch (decision)
    {
    case 1:
        surfProducts();
        break;
    case 2:
        enter();
        break;

    default:
        break;
    }
}
void grocery::getStockFromFile()
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
            if (line.find("Product") != string::npos) // Finds the line of product, its description afterwards
            {
                string name, tempStr;
                int price, quantity;

                getline(availProds, tempStr);
                name = tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1);

                getline(availProds, tempStr);
                price = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));

                getline(availProds, tempStr);
                quantity = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));
                stock->insertAtTail(stock, name, price, quantity);
            }
        }
        availProds.close();
    }
}
void grocery::checkOut()
{
    while (!this->Cart.empty())
    {
        this->receipt->insertAtTail(this->receipt, this->Cart.top());
        this->Cart.pop();
    }
    system("CLS");
    cout << "*************Check Out***************\n\n\n"
         << endl;
    cout << "Your receipt of the Products bought is as: \n"
         << endl;
    cout << this->receipt << endl;
    cout << "\n\nPress \'1\' to check out" << endl;
    int choice;
    cin >> choice;
    while (choice != 1)
    {
        cout << "Please Press \'1\': ";
        cin >> choice;
    }
    return;
}