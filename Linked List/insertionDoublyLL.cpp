#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class linkedList
{
private:
    Node *head;
    Node *tail;

public:
    linkedList() : head(nullptr), tail(nullptr) {}
    // Case 1: Insertion at the Head
    void insertAthead(int data)
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
    // Case 2: Insertion at the End
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    // Case 3: Insertion After a given data
    void insertAfterNode(int data, int nodeData)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->data != nodeData)
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
};
int main()
{
    linkedList list;

    list.insertAthead(19);

    list.insertAtEnd(29);
    list.insertAtEnd(39);
    list.insertAtEnd(49);

    list.Traverse();

    list.insertAfterNode(100, 39);
    list.Traverse();

    return 0;
}