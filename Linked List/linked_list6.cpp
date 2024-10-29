#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
void Traversal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
Node *CreateNode(int data){
    return new Node(data);
}
int main()
{
    Node *head = CreateNode(11);
    Node *second = CreateNode(21);
    Node *third = CreateNode(31);

    head->next = second;
    second->next = third;

    Traversal(head);

    return 0;
}