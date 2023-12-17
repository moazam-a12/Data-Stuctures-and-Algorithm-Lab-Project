#include <iostream>
#include <stdlib.h>
#include <queue>
#include <fstream>
#include "class_Movie.h"
using namespace std;

class cinema
{
private:
    movie *stock;
    queue<movie *> Q;
    movie *list;

public:
    cinema();
    void enter();
    void availMovie();
    void getStockFromFile();
    void viewQueue();
    void clearQueue();
};
cinema::cinema()
{
    stock = NULL;
    list = NULL;
}
void cinema::enter()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** Welcome to the Cinema **************************\n"
         << endl;
    cout << "\n\n ++ Explore the Options:\n"
         << "\n\n ++ 1. \tAVALAIBLE MOVIES"
         << "\n\n ++ 2. \tVIEW QUEUE"
         << "\n\n ++ 3. \tCLEAR QUEUE"
         << "\n\n ++ 4. \tGO BACK TO STORE" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        availMovie();
        break;
    case 2:
        viewQueue();
        break;
    case 3:
        clearQueue();
        break;
    case 4:
        return;

    default:
        availMovie();
        break;
    }
    return;
}
void cinema::availMovie()
{
    if (this->stock == NULL)
    {
        getStockFromFile();
    }
    bool choice = true;
    int movNum;
    system("CLS");
    cout << "\n\n ************************** Welcome to the cinema Shop **************************\n"
         << endl;
    cout << "\n\n ++ The movies available in the store are as: " << endl;
    cout << stock << endl;
    cout << "\n\n **************************\n"
         << endl;

    cout << "\n\n ++ Anything that sparked your interest?" << endl;
    cout << "\n\n ++ Add it to your Queue by giving the number of the movie below!" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> movNum;
    movie *mov = stock->movDeets((movNum - 1), stock);
    Q.push(mov);
    system("CLS");
    cout << "\n\n ************************** Welcome to the cinema Shop **************************\n"
         << endl;
    cout << "\n\n ++ Add another movie to the Queue or go back to the main menu?" << endl;
    cout << "\n\n ++ 1. \tADD ANOTHER MOVIE"
         << "\n\n ++ 2. \tMAIN MENU" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    int decision;
    cin >> decision;
    switch (decision)
    {
    case 1:
        availMovie();
        break;
    case 2:
        enter();
        break;

    default:
        break;
    }
}
void cinema::getStockFromFile()
{
    ifstream availMovies;
    availMovies.open("Movies_Available.txt", ios::in);

    if (!availMovies.is_open())
    {
        cout << "Error: Couldn't Open the File" << endl;
    }
    else
    {
        string line;
        while (getline(availMovies, line))
        {
            if (line.find("Movie") != string::npos) // Finds the line of movie, its description afterwards
            {
                string name, tempStr;
                int price, duration;

                getline(availMovies, tempStr);
                name = tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1);

                getline(availMovies, tempStr);
                price = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));

                getline(availMovies, tempStr);
                duration = stoi(tempStr.substr(tempStr.find("(") + 1, tempStr.find(")") - tempStr.find("(") - 1));
                stock->insertAtTail(stock, name, price, duration);
            }
        }
        availMovies.close();
    }
}
void cinema::viewQueue()
{
    system("CLS");
    cout << "\n\n ************************** Welcome to the cinema Shop **************************\n"
         << endl;
    if (Q.empty())
    {
        cout << "\n\n ++ Queue is Empty!" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Add another movie to the Queue or go back to the main menu?" << endl;
        cout << "\n\n ++ 1. \tADD ANOTHER MOVIE"
             << "\n\n ++ 2. \tMAIN MENU" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        int decision;
        cin >> decision;
        switch (decision)
        {
        case 1:
            availMovie();
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
        while (!this->Q.empty())
        {
            this->list->insertAtTail(this->list, this->Q.front());
            this->Q.pop();
        }
        system("CLS");
        cout << "\n\n ************************** Welcome to the cinema Shop **************************\n"
             << endl;
        cout << "\n\n ++ QUEUE" << endl;
        cout << "\n\n ++ Your list of the movies in the queue is as:"
             << endl;
        cout << this->list << endl;
        cout << "\n\n ++ Press \'1\' to head back to main menu:" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        int choice;
        cin >> choice;
        while (choice != 1)
        {
            cout << "Please Press \'1\' to head back to main menu: ";
            cin >> choice;
        }
        if (choice == 1)
        {
            enter();
        }
    }
    return;
}
void cinema::clearQueue()
{
    while (!this->Q.empty())
    {
        this->Q.pop();
    }
    system("CLS");
    cout << "\n\n ************************** Welcome to the cinema Shop **************************\n"
         << endl;
    if (this->Q.empty())
    {
        cout << "\n\n ++ Queue is Cleared!" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Add a movie to the Queue or go back to the main menu?" << endl;
        cout << "\n\n ++ 1. \tADD ANOTHER MOVIE"
             << "\n\n ++ 2. \tMAIN MENU" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        int decision;
        cin >> decision;
        switch (decision)
        {
        case 1:
            availMovie();
            break;
        case 2:
            enter();
            break;
        default:
            enter();
            break;
        }
    }
}