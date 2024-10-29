// Circular Singly Linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
void Traverse(Node *head)
{
    Node *ptr = head;
    cout << "The Circular Linked list: ";
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
int main()
{
    Node *head = new Node(12);
    Node *second = new Node(19);
    Node *third = new Node(15);

    head->next= second;
    second->next = third;
    third->next = head;

    Traverse(head);
    
    return 0;
}