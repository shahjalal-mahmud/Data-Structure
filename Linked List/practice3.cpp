// Doubly Linked list
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
void Traverse(Node *ptr)
{
    cout << "The Doubly Linked list: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(64);
    Node *second = new Node(78);
    Node *third = new Node(98);

    head->next = second;
    second->next = third;

    third->prev = second;
    second->prev = head;

    Traverse(head);
    
    return 0;
}