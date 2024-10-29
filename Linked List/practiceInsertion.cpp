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
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node *current = head;
        Node *nextptr;
        while (nextptr->next != nullptr)
        {
            nextptr = current->next;
            delete current;
            current = nextptr;
        }
    }
    void inserAtHead(int data)
    {
        Node *current = head;
        Node *newptr = new Node(data);
        newptr->next = head;
        head = newptr;
    }
    void insertAtEnd(int data)
    {
        Node *current = head;
        Node *newptr = new Node(data);
        if (head == nullptr)
        {
            head = newptr;
            return;
        }

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newptr;
    }
    void insertAtIndex(int data, int index)
    {
        if (index == 0)
        {
            inserAtHead(data);
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
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
};
int main()
{
    return 0;
}