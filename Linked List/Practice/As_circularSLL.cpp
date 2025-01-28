#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
Node *Traverse(Node *head)
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
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = head;

    Traverse(head);
    return 0;
}
