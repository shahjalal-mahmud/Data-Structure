#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Linkedlist
{
private:
    Node *head;

public:
    Linkedlist() : head(nullptr) {}
    // Case 1-> Insertion at the Head
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    // Case 2 -> Insertion at the End
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    // Case 3 -> Insertion at any middle of the index
    void insertAtIndex(int data, int index)
    {
        if (index == 0)
        {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *current = head;
        int i = 0;
        while (i < index - 1 && current != nullptr)
        {
            current = current->next;
            i++;
        }
        if (current == nullptr)
        {
            cout << "Index is out of bounds." << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void Traversal()
    {
        Node *current = head;
        cout<<"The Linked list: ";
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
    Linkedlist list;

    list.insertAtHead(29);

    list.insertAtEnd(54);
    list.insertAtEnd(69);
    list.insertAtEnd(28);

    list.Traversal();

    list.insertAtIndex(100, 1);
    list.Traversal();

    return 0;
}