#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
void Traverse(Node *ptr)
{
    cout<<"The Linked List: ";
    while (ptr != nullptr)
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
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

    second->prev = head;
    third->prev = second;
    forth->prev = third;

    Traverse(head);

    return 0;
}
