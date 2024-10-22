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
        Node *nextNode;
        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void AddNode(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
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

    list.AddNode(11);
    list.AddNode(21);
    list.AddNode(19);

    list.Traverse();
    return 0;
}
