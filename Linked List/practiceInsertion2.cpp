#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class linkedList
{
private:
    Node *head;

public:
    linkedList() : head(nullptr) {}
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
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    // Case 3 -> Insertion After a given data
    void insertAfterNode(int data, int nodeData)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->data != nodeData)
        {
            current = current->next;
        }
        newNode->next = current->next;
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

    list.insertAtHead(11);
    list.insertAtEnd(12);
    list.insertAtEnd(13);
    list.insertAtEnd(14);

    list.Traverse();

    list.insertAfterNode(20, 13);
    list.Traverse();

    return 0;
}