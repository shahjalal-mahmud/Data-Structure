#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val): data(val), next(nullptr){}
};

void Traversal(Node *ptr){
    cout<<"Linked list: ";
    while (ptr != nullptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    
}
int main(){
    Node *head = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(5);

    head->next = second;
    second->next = third;
    third->next = nullptr;

    Traversal(head);
}