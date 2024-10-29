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
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
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
    list.insertAtEnd(22);
    list.insertAtEnd(33);
    list.insertAtEnd(44);

    list.Traverse();

    list.insertAfterNode(99, 22);
    list.Traverse();
    return 0;
}