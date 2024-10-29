#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int value) : data(value), next(nullptr) {} 
};
// Function for printing the linked list
void Traversal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
// Function for creating a new Node
Node *createLinkedList(int data)
{
    Node *newNode = new Node(data);
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
int main()
{
    // Creating new Node
    Node *head = createLinkedList(10);
    Node *second = createLinkedList(20);
    Node *third = createLinkedList(30);

    // Creating Linked list
    head->next = second;
    second->next = third;
    third->next = nullptr;

    // Printing the Linked List
    Traversal(head);

    // Memory clean ups to avoid memory leaks
    delete third;
    delete second;
    delete head;

    return 0;
}