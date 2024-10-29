#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr)
    {
    }
    ~LinkedList()
    {
        Node *current = head;
        Node *nextNode;
        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtIndex(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        int i = 0;
        while (i != index - 1)
        {
            current = current->next;
            i++;
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
    LinkedList list;

    list.insertAtHead(17);
    list.insertAtHead(18);
    list.insertAtHead(19);
    list.insertAtHead(20);

    list.Traverse();

    list.insertAtIndex(15, 2);
    list.Traverse();
    return 0;
}