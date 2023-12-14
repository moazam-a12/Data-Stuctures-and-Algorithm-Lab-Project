#include <iostream>
using namespace std;

class book
{
private:
    string bookName;
    int bookChapter;
    book *next;
    book *prev;
    static int count;

public:
    book();
    book(string bookName, int bookChapter);
    string getBookName();
    int getbookChapter();
    void insertAtStart(book *&head, string bookName, int bookChapter);
    void insertBeforeIndex(book *&head, int index);
    void insertAtIndex(book *&head, int index);
    void insertAfterIndex(book *&head, int index);
    void insertAtMiddleWithCount(book *&head);
    void insertAtMiddleWithoutCount(book *&head);
    void insertAtEnd(book *head, string bookName, int bookChapter);
    void deleteAtStart(book *&head);
    void deleteAtIndex(book *&head, int index);
    void deleteAtMiddle(book *&head);
    void deleteAtEnd(book *&head);
    void printInOrder();
    void printInReverseOrder();
    friend ostream &operator<<(ostream &os, book *&head);
    ~book();
};

int book::count = 0;

book::book()
{
    next = NULL;
    prev = NULL;
}
book::book(string bookName, int bookChapter)
{
    this->bookName = bookName;
    this->bookChapter = bookChapter;
    next = NULL;
    prev = NULL;
}
string book::getBookName()
{
    return bookName;
}
int book::getbookChapter()
{
    return bookChapter;
}
void book::insertAtStart(book *&head, string bookName, int bookChapter)
{
    book *newbook = new book(bookName, bookChapter);
    if (head == NULL)
    {
        head = newbook;
    }
    else
    {
        book *temp = head;
        newbook->next = temp;
        head->prev = newbook;
        head = newbook;
        // delete temp;
    }
}
void book::insertBeforeIndex(book *&head, int index)
{
    if (head == NULL)
    {
        cout << "\n\n ++ There's no index to precede!" << endl;
    }
    else
    {
        insertAtIndex(head, (index - 1));
    }
}
void book::insertAtIndex(book *&head, int index)
{
    string bookName;
    int bookNumber;
    cout << "\n\n ++ Enter the Data for the Book: " << endl;
    cout << "\n\n ++ Name of Book: ";
    cin >> bookName;
    cout << "\n\n ++ Number of Chapters: ";
    cin >> bookNumber;
    book *newbook = new book(bookName, bookChapter);
    if (head == NULL)
    {
        head = newbook;
    }
    else if ((index - 1) == 0)
    {
        insertAtStart(head, bookName, bookChapter);
    }
    else
    {
        book *temp = head;
        for (int i = 0; i < (index - 1); i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            insertAtEnd(head, bookName, bookChapter);
        }
        else
        {
            newbook->prev = temp->prev;
            newbook->next = temp;
            temp->prev->next = newbook;
            temp->prev = newbook;
        }
    }
}
void book::insertAfterIndex(book *&head, int index)
{
    if (head == NULL)
    {
        insertAtIndex(head, index);
    }
    else
    {
        insertAtIndex(head, (index + 1));
    }
}
void book::insertAtMiddleWithCount(book *&head)
{
    book *temp = head;
    temp->count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        temp->count++;
    }
    int index = (temp->count) / 2;
    if ((temp->count % 2) == 0)
    {
        index = index + 1;
        insertAtIndex(head, index);
    }
    else
    {
        index = index + 2;
        insertAtIndex(head, index);
    }
}
void book::insertAtMiddleWithoutCount(book *&head)
{
    string bookName;
    int bookNumber;
    cout << "\n\n ++ Enter the Data for the Book: " << endl;
    cout << "\n\n ++ Name of Book: ";
    cin >> bookName;
    cout << "\n\n ++ Number of Chapters: ";
    cin >> bookNumber;
    book *newbook = new book(bookName, bookChapter);
    book *fast = head;
    book *slow = head;
    while (fast->next != NULL)
    {
        if (fast->next->next == NULL)
        {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    newbook->prev = slow->prev;
    newbook->next = slow;
    slow->prev->next = newbook;
    slow->prev = newbook;
}
void book::insertAtEnd(book *head, string bookName, int bookChapter)
{
    book *newbook = new book(bookName, bookChapter);
    if (head == NULL)
    {
        head = newbook;
    }
    else
    {
        book *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newbook;
        newbook->prev = temp;
        // delete temp;
    }
}
void book::deleteAtStart(book *&head)
{
    if (head == NULL)
    {
        cout << "\n\n ++ List is empty!" << endl;
    }
    else
    {
        book *temp = head;
        head = temp->next;
        head->prev = NULL;
        // delete temp;
    }
}
void book::deleteAtIndex(book *&head, int index)
{
    if (head == NULL)
    {
        cout << "\n\n ++ Cannot find index, List is empty!" << endl;
    }
    else if ((index - 1) == 0)
    {
        deleteAtStart(head);
    }
    else
    {
        book *temp = head;
        for (int i = 0; i < (index - 1); i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            deleteAtEnd(head);
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}
void book::deleteAtMiddle(book *&head)
{
    if (head == NULL)
    {
        cout << "\n\n ++ List is empty!" << endl;
    }
    book *fast = head;
    book *slow = head;
    while (fast->next != NULL)
    {
        if (fast->next->next == NULL)
        {
            break;
        }
        else
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    slow->prev->next = slow->next;
    slow->next->prev = slow->prev;
}
void book::deleteAtEnd(book *&head)
{
    if (head == NULL)
    {
        cout << "\n\n ++ List is empty!" << endl;
    }
    else
    {
        book *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
    }
}
void book::printInOrder()
{
    if (this == NULL)
    {
        cout << "\n\n ++ List is empty!" << endl;
    }
    else
    {
        book *temp = this;
        temp->count = 0;
        cout << "\n\n ++ The library has the following content: " << endl;
        while (temp != NULL)
        {
            cout << "\n\n ++ Rack "
                 << (temp->count + 1) << ". "
                 << "\tBook: " << temp->bookName
                 << "\tChapter: " << temp->bookChapter << endl;
            temp = temp->next;
            temp->count++;
        }

        // cout << "\n\n\n***************This is the end of the book!****************\n\n"
        //      << endl;
    }
}
void book::printInReverseOrder()
{
    if (this == NULL)
    {
        cout << "\n\n ++ List is empty!" << endl;
    }
    else
    {
        book *temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "\n\n ++ The library has the following content: " << endl;
        do
        {
            cout << "\n\n ++ Rack "
                 << (temp->count) << ". "
                 << "\tBook: " << temp->bookName
                 << "\tChapter: " << temp->bookChapter << endl;
            temp = temp->prev;
            temp->count--;
        } while (temp != NULL);

        // cout << "\n\n\n***************This is the end of the book!****************\n\n"
        //      << endl;
    }
}
ostream &operator<<(ostream &os, book *&head)
{
    if (head == NULL)
    {
        cout << "\n\n ++ List is empty!" << endl;
    }
    else
    {
        book *temp = head;
        temp->count = 0;
        cout << "\n\n ++ The library has the following content: " << endl;
        while (temp != NULL)
        {
            cout << "\n\n ++ Rack "
                 << (temp->count + 1) << ". "
                 << "\tBook: " << temp->bookName
                 << "\tChapter: " << temp->bookChapter << endl;
            temp = temp->next;
            temp->count++;
        }

        // cout << "\n\n\n***************This is the end of the book!****************\n\n"
        //      << endl;
    }
    return os;
}

book::~book()
{
    delete next;
    delete prev;
}
