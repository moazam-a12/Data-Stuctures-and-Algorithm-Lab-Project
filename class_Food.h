#include <iostream>
using namespace std;

class food
{
private:
    string name;
    int price;
    food *next;
    static int count;
    static int totalPrice;

public:
    food();
    food(string name, int price);
    string getName();
    int getPrice();
    int getTotalPrice();
    food *insertAtHead(food *&head, string name, int price);
    void insertAtTail(food *&head, string name, int price);
    void insertAtTail(food *&head, food *data);
    food *foDeets(int foNum);
    friend ostream &operator<<(ostream &os, food *&head);
    ~food();
};

int food::count = 0;
int food::totalPrice = 0;

food::food()
{
    this->name = "NULL";
    this->price = 0;
    this->next = NULL;
}
food::food(string name, int price)
{
    this->name = name;
    this->price = price;
    this->next = NULL;
}
string food::getName()
{
    return this->name;
}
int food::getPrice()
{
    return this->price;
}
int food::getTotalPrice()
{
    food *temp = this;
    totalPrice = 0;
    while (temp != NULL)
    {
        temp->totalPrice += temp->price;
        temp = temp->next;
    }
    return temp->totalPrice;
}
food *food::insertAtHead(food *&head, string name, int price)
{
    food *newPro = new food(name, price);
    if (head == NULL)
    {
        head = newPro;
    }
    else
    {
        food *temp = head;
        newPro->next = temp;
        head = newPro;
    }
    return head;
}
void food::insertAtTail(food *&head, string name, int price)
{
    food *newPro = new food(name, price);
    if (head == NULL)
    {
        head = newPro;
        return;
    }
    food *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPro;
}
void food::insertAtTail(food *&head, food *data)
{
    food *newPro = new food(data->getName(), data->getPrice());
    if (head == NULL)
    {
        head = newPro;
        return;
    }
    food *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPro;
}
food *food::foDeets(int foNum)
{
    food *current = this;
    for (int i = 0; i < foNum; i++)
    {
        current = current->next;
    }
    return current;
}
ostream &operator<<(ostream &os, food *&head)
{
    if (head == NULL)
    {
        cout << "\n\n ++ No Food Available!" << endl;
    }
    else
    {
        food *temp = head;
        temp->count = 0;
        temp->totalPrice = 0;
        while (temp != NULL)
        {
            os << "\n\n ++ Food Number "
               << (temp->count + 1) << ". ";
            os << "\n\n\t <-- Dish Name: "
               << temp->name << " --> " << endl;
            os << "\n\n \t\t( Price: $"
               << temp->price << " )" << endl;
            temp->totalPrice += temp->price;
            temp = temp->next;
            temp->count++;
        }
        // cout << "\n\n ++ Your bill of ordered food is: Rs." << temp->totalPrice << endl;
        // os << "\n\n\n************End of the List*************" << endl;
    }
    return os;
}
food::~food()
{
    delete next;
}