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
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    Node *head = new Node(11);
    Node *second = new Node(22);
    Node *third = new Node(33);
    Node *forth = new Node(44);
    Node *five = new Node(55);
    Node *six = new Node(66);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = five;
    five->next = six;
    six->next = head;

    Traversal(head);
    return 0;
}