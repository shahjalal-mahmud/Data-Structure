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
        while (current != nullptr)
        {
            nextptr = current->next;
            delete current;
            current = nextptr;
        }
    }
    Node *CreateNode(int data){
        return new Node(data);
    }
    void insertAtHead(int data)
    {
        Node *newptr = CreateNode(data);
        newptr->next = head;
        head = newptr;
    }
    void insertAtIndex(int data, int index)
    {
        if (index == 0)
        {
            insertAtHead(data);
            return;
        }
        Node *newptr = CreateNode(data);
        Node *current = head;
        int i = 0;
        while (i < index - 1 && current != nullptr)
        {
            current = current->next;
            i++;
        }
        if (current == nullptr)
        {
            cout << "index out of bounds." << endl;
            delete newptr;
            return;
        }
        newptr->next = current->next;
        current->next = newptr;
    }
    void Traversal()
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
    list.insertAtHead(11);
    list.insertAtHead(21);
    list.insertAtHead(31);
    list.insertAtHead(41);

    list.Traversal();
    return 0;
}