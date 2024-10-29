#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
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
    Node *head = new Node(11);
    Node *second = new Node(22);
    Node *third = new Node(33);

    head->next = second;
    second->next = third;
    third->next = head;

    Traversal(head);
    return 0;
}