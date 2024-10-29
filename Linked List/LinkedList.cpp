#include <iostream>
using namespace std;

class linkedList
{
public:
    int data;
    linkedList *next;

    linkedList(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void linkedListTraversal(linkedList *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    linkedList *head = new linkedList(2);
    linkedList *second = new linkedList(4);
    linkedList *third = new linkedList(6);
    linkedList *forth = new linkedList(8);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = nullptr;

    linkedListTraversal(head);
}