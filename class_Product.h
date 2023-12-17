#include <iostream>
using namespace std;

class Product
{
private:
    string name;
    int price;
    int quantity;
    Product *next;
    static int count;
    static int totalPrice;

public:
    Product();
    Product(string name, int price, int quantity);
    string getName();
    int getPrice();
    int getQuantity();
    Product *insertAtHead(Product *&head, string name, int price, int quantity);
    void insertAtTail(Product *&head, string name, int price, int quantity);
    void insertAtTail(Product *&head, Product* data);
    bool proSearch(string proName, Product *&head);
    Product *proDeets(int proNum, Product *&head);
    void deleteAtIndex(Product *head, int index);
    friend ostream &operator<<(ostream &os, Product *&head);
    ~Product();
};

int Product::count = 0;
int Product::totalPrice = 0;

Product::Product()
{
    this->name = "NULL";
    this->price = 0;
    this->quantity = 0;
    this->next = NULL;
}

Product::Product(string name, int price, int quantity)
{
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    this->next = NULL;
}

string Product::getName()
{
    return this->name;
}

int Product::getPrice()
{
    return this->price;
}

int Product::getQuantity()
{
    return this->quantity;
}

Product *Product::insertAtHead(Product *&head, string name, int price, int quantity)
{
    Product *newPro = new Product(name, price, quantity);
    if (head == NULL)
    {
        head = newPro;
    }
    else
    {
        Product *temp = head;
        newPro->next = temp;
        head = newPro;
    }
    return head;
}

void Product::insertAtTail(Product *&head, string name, int price, int quantity)
{
    Product *newPro = new Product(name, price, quantity);
    if (head == NULL)
    {
        head = newPro;
        return;
    }
    Product *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPro;
}

void Product::insertAtTail(Product *&head, Product* data)
{
    Product *newPro = new Product(data->getName(),data->getPrice(),data->getQuantity());
    if (head == NULL)
    {
        head = newPro;
        return;
    }
    Product *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPro;
}

bool Product::proSearch(string proName, Product *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty!" << endl;
    }
    else
    {
        Product *temp = head;
        while (temp != NULL)
        {
            if (temp->name == proName)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

Product *Product::proDeets(int proNum, Product *&head)
{
    Product *current = head;
    for (int i = 0; i < proNum; i++)
    {
        current = current->next;
    }
    return current;
}
void Product::deleteAtIndex(Product *head, int index)
{

    if (head == NULL)
    {
        cout << "There's only one item on the list and its deleted." << endl;
    }
    else if (index == 0)
    {
        Product *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Product *current = head;
        Product *previous = head;
        for (int i = 0; i < index; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
}

ostream &operator<<(ostream &os, Product *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty!" << endl;
    }
    else
    {
        Product *temp = head;
        temp->count = 0;
        temp->totalPrice = 0;
        while (temp != NULL)
        {
            os << "\n"
               << (temp->count + 1) << ". ";
            os << "\tItem Name: "
               << temp->name << endl;
            os << "\tPrice: $"
               << temp->price << endl;
            temp->totalPrice += (temp->price * temp->quantity);
            os << "\tQuantity: "
               << temp->quantity << endl;
            temp = temp->next;
            temp->count++;
        }
        cout << "\n\n ++ Your total is: $" << temp->totalPrice << endl;
        // os << "\n\n\n************End of the List*************" << endl;
    }
}

Product::~Product()
{
    delete next;
}