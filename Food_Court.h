#include <iostream>
#include <stdlib.h>
#include <stack>
#include <fstream>
#include "class_Food.h"
using namespace std;

class foodCourt
{
private:
    food *fastFood;
    food *italien;
    food *chinese;
    food *indian;
    food *japanese;
    stack<food *> takeOrder;
    food *order;

public:
    foodCourt();
    void enter();
    void menu();
    void getMenu();
    void getFoodFromFile(const string fileName, food *&head);
    void checkOrder();
};
foodCourt::foodCourt()
{
    fastFood = NULL;
    italien = NULL;
    chinese = NULL;
    indian = NULL;
    japanese = NULL;
    order = NULL;
}
void foodCourt::enter()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** Welcome to the Food Court **************************\n"
         << endl;
    cout << "\n\n ++ Explore the Options:\n"
         << "\n\n ++ 1. \tMENU"
         << "\n\n ++ 2. \tCHECK YOUR ORDER"
         << "\n\n ++ 3. \tGO BACK TO STORE" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        menu();
        break;
    case 2:
        checkOrder();
        break;
    case 3:
        return;

    default:
        menu();
        break;
    }
    return;
}
void foodCourt::menu()
{
    if (this->italien == NULL || this->chinese == NULL || this->indian == NULL || this->japanese == NULL || this->fastFood == NULL)
    {
        getMenu();
    }
    int choice;
    int foNum;
    food *fo = NULL;
    system("CLS");
    cout << "\n\n ************************** Menu **************************\n"
         << endl;
    cout << "\n\n ++ Choose from the following Food Menu\n"
         << "\n\n ++ 1. \tITALIEN"
         << "\n\n ++ 2. \tCHINESE"
         << "\n\n ++ 3. \tINDIAN"
         << "\n\n ++ 4. \tJAPANESE"
         << "\n\n ++ 5. \tFAST FOOD"
         << "\n\n ++ 6. \tBACK TO THE FOOD COURT" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    cout << "\n\n ************************** Menu **************************\n"
         << endl;
    switch (choice)
    {
    case 1:
        cout << "\n\n ------------++ ITALIEN FOOD ++------------" << endl;
        cout << italien << endl;
        cout << "\n\n ------------++ MENU END ++------------" << endl;
        cout << "\n\n ++ __Mama Mia, order away!" << endl;
        cout << "\n\n Enter Food Number to Order -> ";
        cin >> foNum;
        fo = italien->foDeets(foNum - 1);
        takeOrder.push(fo);
        break;

    case 2:
        cout << "\n\n ------------++ CHINESE FOOD ++------------" << endl;
        cout << chinese << endl;
        cout << "\n\n ------------++ MENU END ++------------" << endl;
        cout << "\n\n ++ __Qing, Order!" << endl;
        cout << "\n\n Enter Food Number to Order -> ";
        cin >> foNum;
        fo = chinese->foDeets(foNum - 1);
        takeOrder.push(fo);
        break;

    case 3:
        cout << "\n\n ------------++ INDIAN FOOD ++------------" << endl;
        cout << indian << endl;
        cout << "\n\n ------------++ MENU END ++------------" << endl;
        cout << "\n\n ++ __Please, Order Below!" << endl;
        cout << "\n\n Enter Food Number to Order -> ";
        cin >> foNum;
        fo = indian->foDeets(foNum - 1);
        takeOrder.push(fo);
        break;

    case 4:
        cout << "\n\n ------------++ JAPANESE FOOD ++------------" << endl;
        cout << japanese << endl;
        cout << "\n\n ------------++ MENU END ++------------" << endl;
        cout << "\n\n ++ __Arigatou Gozaimasu!" << endl;
        cout << "\n\n Enter Food Number to Order -> ";
        cin >> foNum;
        fo = japanese->foDeets(foNum - 1);
        takeOrder.push(fo);
        break;

    case 5:
        cout << "\n\n ------------++ FAST FOOD ++------------" << endl;
        cout << fastFood << endl;
        cout << "\n\n ------------++ MENU END ++------------" << endl;
        cout << "\n\n ++ __Please, Order Below!" << endl;
        cout << "\n\n Enter Food Number to Order -> ";
        cin >> foNum;
        fo = fastFood->foDeets(foNum - 1);
        takeOrder.push(fo);
        break;

    case 6:
        enter();
        break;

    default:
        return;
    }
    system("CLS");
    cout << "\n\n ************************** Menu **************************\n"
         << endl;
    cout << "\n\n ++ Anything else?\n"
         << "\n\n ++ 1. \tMORE FOOD"
         << "\n\n ++ 2. \tCONFIRM ORDER"
         << "\n\n ++ 3. \tBACK TO FOOD COURT" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        menu();
        break;
    case 2:
        checkOrder();
        break;
    case 3:
        enter();
        break;

    default:
        break;
    }
    return;
}
void foodCourt::getMenu()
{
    getFoodFromFile("italien_food.txt", this->italien);
    getFoodFromFile("chinese_food.txt", this->chinese);
    getFoodFromFile("indian_food.txt", this->indian);
    getFoodFromFile("japanese_food.txt", this->japanese);
    getFoodFromFile("fast_food.txt", this->fastFood);
}
void foodCourt::getFoodFromFile(const string fileName, food *&head)
{
    ifstream availFood;
    availFood.open(fileName, ios::in);

    if (!availFood.is_open())
    {
        cout << "\n\n ++ Error: Couldn't Open the File" << endl;
    }
    else
    {
        string line;
        while (getline(availFood, line))
        {
            if (line.find("item") != string::npos)
            {
                string name, tempStr;
                int price;

                getline(availFood, tempStr);
                name = tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1);

                getline(availFood, tempStr);
                price = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));

                head->insertAtTail(head, name, price);
            }
        }
        availFood.close();
    }
}
void foodCourt::checkOrder()
{
    system("CLS");
    cout << "\n\n ************************** Order **************************\n"
         << endl;
    if (takeOrder.empty())
    {
        cout << "\n\n ++ No order yet!" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Order food or go back to the Food Court?" << endl;
        cout << "\n\n ++ 1. \tMENU"
             << "\n\n ++ 2. \tFOOD COURT" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        int decision;
        cin >> decision;
        switch (decision)
        {
        case 1:
            menu();
            break;
        case 2:
            enter();
            break;
        default:
            break;
        }
    }
    else
    {
        while (!this->takeOrder.empty())
        {
            this->order->insertAtTail(this->order, this->takeOrder.top());
            this->takeOrder.pop();
        }
        cout << "\n\n ++ So far your order looks like: \n"
             << endl;
        cout << this->order << endl;
        cout << "\n\n ++ Total bill for the Food ordered: $" << this->order->getTotalPrice() << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Ready to dive in or order more food? " << endl;
        cout << "\n\n ++ 1. \tDIVE IN"
             << "\n\n ++ 2. \tMENU"
             << "\n\n ++ 3. \tTAKEOUT" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "\n\n ************************** Order **************************\n"
                 << endl;
            cout << "\n\n ~~~~~~~~~~~~ Bon Appetit! ~~~~~~~~~~~~" << endl;
            cout << "\n\n **************************\n"
                 << endl;
            cout << "\n\n ++ Enter \'1\' to go back to the Store -> ";
            cin >> choice;
            while (choice != 1)
            {
                cout << "\n\n ++ Enter \'1\' to go back to the Store -> ";
            }
            return;
        case 2:
            menu();
            break;
        case 3:
            system("CLS");
            cout << "\n\n ************************** Takeout **************************\n"
                 << endl;
            cout << "\n\n ~~~~~~~~~~~~ Bon Appetit! ~~~~~~~~~~~~" << endl;
            cout << "\n\n **************************\n"
                 << endl;
            cout << "\n\n ++ Enter \'1\' to go back to the Store -> ";
            cin >> choice;
            while (choice != 1)
            {
                cout << "\n\n ++ Enter \'1\' to go back to the Store -> ";
            }
            return;

        default:
            break;
        }
    }
    return;
}