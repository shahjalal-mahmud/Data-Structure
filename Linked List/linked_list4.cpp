#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
Node *Traversal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
Node *createNode(int data)
{
    Node *newNode = new Node(data);
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
int main()
{
    Node *head = createNode(2);
    Node *second = createNode(11);
    Node *third = createNode(7);

    head->next = second;
    second->next = third;
    // third->next = nullptr;

    Traversal(head);

    return 0;
}