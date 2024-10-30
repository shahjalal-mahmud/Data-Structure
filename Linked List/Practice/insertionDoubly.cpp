#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr) {}
};
class Linkedlist
{
private:
    Node *head;
    Node *tail;

public:
    Linkedlist() : head(nullptr), tail(nullptr) {}
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        tail = newNode;
    }
    void insertAfterNode(int data, int target)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->data != target)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
    void Traverse()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void reverseTraverse()
    {
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main()
{
    Linkedlist list;

    list.insertAtHead(15);
    list.insertAtTail(20);
    list.insertAtTail(25);
    list.insertAtTail(30);
    list.insertAtTail(35);
    list.Traverse();

    list.insertAfterNode(29, 25);
    list.Traverse();

    list.insertAtHead(5);
    list.Traverse();

    list.insertAtTail(40);
    list.Traverse();

    list.reverseTraverse();
    return 0;
}