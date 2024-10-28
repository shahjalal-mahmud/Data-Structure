#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void Traverse(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void inserAtEnd(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}
void insertAfterNode(Node *head, int data, int target)
{
    Node *newNode = new Node();
    newNode->data = data;
    Node *current = head;
    while (current->data != target)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
int main()
{
    struct Node *head = nullptr;

    insertAtHead(head, 11);
    inserAtEnd(head, 22);
    inserAtEnd(head, 33);
    inserAtEnd(head, 44);

    Traverse(head);

    insertAfterNode(head, 99, 33);
    Traverse(head);
    return 0;
}