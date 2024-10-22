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
Node *Traversal(Node *head)
{
    Node *ptr = head;
    cout<<"The Linked list: ";
    do
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    Node *head = new Node(2);
    Node *second = new Node(4);
    Node *third = new Node(6);

    head->next = second;
    second->next = third;
    third->next = head;

    head->prev = third;
    second->prev = head;
    third->prev = second;

    Traversal(head);

    return 0;
}