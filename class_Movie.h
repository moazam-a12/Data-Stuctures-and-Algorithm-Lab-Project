#include <iostream>
using namespace std;

class movie
{
private:
    string name;
    int price;
    int duration;
    movie *next;
    static int count;
    static int totalPrice;

public:
    movie();
    movie(string name, int price, int duration);
    string getName();
    int getPrice();
    int getDuration();
    movie *insertAtHead(movie *&head, string name, int price, int duration);
    void insertAtTail(movie *&head, string name, int price, int duration);
    void insertAtTail(movie *&head, movie *data);
    bool movSearch(string movName, movie *&head);
    movie *movDeets(int proNum, movie *&head);
    void deleteAtIndex(movie *head, int index);
    friend ostream &operator<<(ostream &os, movie *&head);
    ~movie();
};

int movie::count = 0;
int movie::totalPrice = 0;

movie::movie()
{
    this->name = "NULL";
    this->price = 0;
    this->duration = 0;
    this->next = NULL;
}

movie::movie(string name, int price, int duration)
{
    this->name = name;
    this->price = price;
    this->duration = duration;
    this->next = NULL;
}

string movie::getName()
{
    return this->name;
}

int movie::getPrice()
{
    return this->price;
}

int movie::getDuration()
{
    return this->duration;
}

movie *movie::insertAtHead(movie *&head, string name, int price, int duration)
{
    movie *newPro = new movie(name, price, duration);
    if (head == NULL)
    {
        head = newPro;
    }
    else
    {
        movie *temp = head;
        newPro->next = temp;
        head = newPro;
    }
    return head;
}

void movie::insertAtTail(movie *&head, string name, int price, int duration)
{
    movie *newPro = new movie(name, price, duration);
    if (head == NULL)
    {
        head = newPro;
        return;
    }
    movie *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPro;
}

void movie::insertAtTail(movie *&head, movie *data)
{
    movie *newPro = new movie(data->getName(), data->getPrice(), data->getDuration());
    if (head == NULL)
    {
        head = newPro;
        return;
    }
    movie *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPro;
}

bool movie::movSearch(string movName, movie *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty!" << endl;
    }
    else
    {
        movie *temp = head;
        while (temp != NULL)
        {
            if (temp->name == movName)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

movie *movie::movDeets(int proNum, movie *&head)
{
    movie *current = head;
    for (int i = 0; i < proNum; i++)
    {
        current = current->next;
    }
    return current;
}
void movie::deleteAtIndex(movie *head, int index)
{

    if (head == NULL)
    {
        cout << "There's only one item on the list and its deleted." << endl;
    }
    else if (index == 0)
    {
        movie *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        movie *current = head;
        movie *previous = head;
        for (int i = 0; i < index; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
}

ostream &operator<<(ostream &os, movie *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty!" << endl;
    }
    else
    {
        movie *temp = head;
        temp->count = 0;
        temp->totalPrice = 0;
        while (temp != NULL)
        {
            os << "\n\n ++ Number "
               << (temp->count + 1) << ". ";
            os << "\n\n ++ \tMovie Name: "
               << temp->name;
            os << "\n ++ \tPrice: $"
               << temp->price;
            temp->totalPrice += (temp->price);
            os << "\n ++ \tDuration: "
               << temp->duration << "mins";
            temp = temp->next;
            temp->count++;
        }
        // cout << "\n\n ++ Your total is: Rs." << temp->totalPrice << endl;
        // os << "\n\n\n************End of the List*************" << endl;
    }
    return os;
}

movie::~movie()
{
    delete next;
}