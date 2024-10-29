#include <iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){}
};
Node *CreateNode(int data){
    return new Node(data);
}
void Traversal(Node *ptr){
    while (ptr!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
// Function for insertion at the begining
Node *insert_at_first(Node *head, int data){
    Node *ptr = new Node(data);
    ptr->next = head;
    return ptr;
}
int main()
{
    Node *head = CreateNode(12);
    Node *second = CreateNode(22);
    Node *third = CreateNode(44);

    head->next = second;
    second->next = third;

    // Traversal begore the insertion
    cout<<"Linked list before the insertion: ";
    Traversal(head);

    // Insertion at the first
    head = insert_at_first(head, 52);
    head = insert_at_first(head, 15);
    head = insert_at_first(head, 212);
    head = insert_at_first(head, 842);

    // Traversal after the insertion
    cout<<"Linked list After the insertion: ";
    Traversal(head);

    return 0;
}