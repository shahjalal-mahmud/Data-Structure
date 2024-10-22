#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
Node *CreateNode(int data)
{
    return new Node(data);
}
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
    Node *head = CreateNode(11);
    Node *second = CreateNode(21);
    Node *third = CreateNode(17);

    head->next = second;
    second->next = third;

    Traverse(head);
    return 0;
}