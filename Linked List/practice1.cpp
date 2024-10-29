// Single Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
void Traverse(Node *ptr)
{
    cout << "The Linked list: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(85);
    Node *second = new Node(45);
    Node *third = new Node(78);

    head->next = second;
    second->next = third;

    Traverse(head);
    return 0;
}