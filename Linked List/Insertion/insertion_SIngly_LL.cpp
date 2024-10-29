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
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void inserAtTail(int data)
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
    void insertAfterNode(int data, int target)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->data != target)
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
    Linkedlist list;
    list.insertAtHead(101);
    list.inserAtTail(102);
    list.inserAtTail(103);
    list.inserAtTail(104);
    list.inserAtTail(105);
    list.Traverse();

    list.insertAtHead(100);
    list.Traverse();

    list.inserAtTail(106);
    list.Traverse();

    list.insertAfterNode(199, 104);
    list.Traverse();
    return 0;
}