#include <iostream>
#include <windows.h>
#include "Class_Book.h"
using namespace std;

class library
{
private:
    book *stock;

public:
    library();
    void enter();
    void insert();
    void remove();
    void view();
};
library::library()
{
    stock = NULL;
}
void library::enter()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** Welcome to the Library **************************\n"
         << endl;
    cout << "\n\n ++ Explore the Options:\n"
         << "\n\n ++ 1. \tINSERT A BOOK"
         << "\n\n ++ 2. \tREMOVE A BOOK"
         << "\n\n ++ 3. \tVIEW BOOKS"
         << "\n\n ++ 4. \tGO BACK TO STORE" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        remove();
        break;
    case 3:
        view();
        break;
    case 4:
        return;
    default:
        break;
    }
    cout << "\n\n ++ Ready to head back to the Main Menu? "
         << "\n\n ++ Press \'8\' to go back"
         << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    if (choice == 8)
    {
        enter();
        return;
    }
    else
    {
        return;
    }
    return;
}
void library::insert()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** Inserting a Book **************************\n"
         << endl;
    cout << "\n\n ++ Explore the Options:\n"
         << "\n\n ++ 1. \tINSERT AT START"
         << "\n\n ++ 2. \tINSERT AT INDEX"
         << "\n\n ++ 3. \tINSERT AFTER INDEX"
         << "\n\n ++ 4. \tINSERT BEFORE INDEX"
         << "\n\n ++ 5. \tINSERT AT MIDDLE WITH COUNT"
         << "\n\n ++ 6. \tINSERT AT MIDDLE WITHOUT COUNT"
         << "\n\n ++ 7. \tINSERT AT END"
         << "\n\n ++ 8. \tMAIN MENU" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    cout << "\n\n ************************** Inserting a Book **************************\n"
         << endl;
    string bookName;
    int bookChapter;
    int index;
    switch (choice)
    {
    case 1:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter the Data for the Book: " << endl;
        cout << "\n\n ++ Name of Book: ";
        cin >> bookName;
        cout << "\n\n ++ Number of Chapters: ";
        cin >> bookChapter;
        stock->insertAtStart(stock, bookName, bookChapter);
        break;
    case 2:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter the Index: ";
        cin >> index;
        stock->insertAtIndex(stock, index);
        break;
    case 3:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter the Index: ";
        cin >> index;
        stock->insertAfterIndex(stock, index);
        break;
    case 4:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter the Index: ";
        cin >> index;
        stock->insertBeforeIndex(stock, index);
        break;
    case 5:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        stock->insertAtMiddleWithCount(stock);
        break;
    case 6:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        stock->insertAtMiddleWithoutCount(stock);
        break;
    case 7:
        cout << stock;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter the Data for the Book: " << endl;
        cout << "\n\n ++ Name of Book: ";
        cin >> bookName;
        cout << "\n\n ++ Number of Chapters: ";
        cin >> bookChapter;
        stock->insertAtEnd(stock, bookName, bookChapter);
        break;
    case 8:
        enter();
        break;
    default:
        break;
    }
    cout << "\n\n **************************\n"
         << endl;
    return;
}
void library::remove()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** Removing a Book **************************\n"
         << endl;
    cout << "\n\n ++ Explore the Options:\n"
         << "\n\n ++ 1. \tREMOVE AT START"
         << "\n\n ++ 2. \tREMOVE AT INDEX"
         << "\n\n ++ 3. \tREMOVE AT MIDDLE"
         << "\n\n ++ 4. \tREMOVE AT END"
         << "\n\n ++ 5. \tMAIN MENU" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    cout << "\n\n ************************** Removing a Book **************************\n"
         << endl;
    string bookName;
    int bookChapter;
    int index;
    switch (choice)
    {
    case 1:
        cout << stock;
        if (stock == NULL)
        {
            break;
        }
        cout << "\n\n **************************\n"
             << endl;
        stock->deleteAtStart(stock);
        cout << "\n\n ++ Deleted At Start" << endl;
        break;
    case 2:
        cout << stock;
        if (stock == NULL)
        {
            break;
        }
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter the Index: ";
        cin >> index;
        stock->deleteAtIndex(stock, index);
        cout << "\n\n ++ Deleted At Index" << endl;
        break;
    case 3:
        cout << stock;
        if (stock == NULL)
        {
            break;
        }
        cout << "\n\n **************************\n"
             << endl;
        stock->deleteAtMiddle(stock);
        cout << "\n\n ++ Deleted At Middle" << endl;
        break;
    case 4:
        cout << stock;
        if (stock == NULL)
        {
            break;
        }
        cout << "\n\n **************************\n"
             << endl;
        stock->deleteAtEnd(stock);
        cout << "\n\n ++ Deleted At End" << endl;
        break;
    case 5:
        enter();
        break;
    default:
        break;
    }
    cout << "\n\n **************************\n"
         << endl;
    return;
}
void library::view()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** View Books **************************\n"
         << endl;
    cout << "\n\n ++ Explore the Options:\n"
         << "\n\n ++ 1. \tVIEW IN ORDER"
         << "\n\n ++ 2. \tVIEW IN REVERSE ORDER" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        cout << "\n\n ************************** View Books **************************\n"
             << endl;
        stock->printInOrder();
        break;
    case 2:
        cout << "\n\n ************************** View Books **************************\n"
             << endl;
        stock->printInReverseOrder();
        break;

    default:
        cout << "\n\n ************************** View Books **************************\n"
             << endl;
        stock->printInOrder();
        break;
    }
    cout << "\n\n **************************\n"
         << endl;
    return;
}