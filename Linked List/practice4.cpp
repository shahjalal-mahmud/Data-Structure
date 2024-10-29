// Circular Doubly Linked list

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr) {}
};
void Traverse(Node *head)
{
    Node *ptr = head;
    cout << "The Circular Doubly Linked list: ";
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
int main()
{
    Node *head = new Node(45);
    Node *second = new Node(78);
    Node *third = new Node(99);

    head->next = second;
    second->next = third;
    third->next = head;

    third->prev = second;
    second->prev = head;
    head->prev = third;

    Traverse(head);

    return 0;
}