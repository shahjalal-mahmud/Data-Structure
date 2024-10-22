#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
void Traversal(Node *ptr)   //Does not have a returtn type
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    Node *head = new Node(2);
    Node *second = new Node(4);
    Node *third = new Node(6);

    head->next = second;
    second->next = third;
    third->next = nullptr;

    head->prev = nullptr;
    second->prev = head;
    third->prev = second;

    Traversal(head);

    return 0;
}