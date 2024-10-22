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
    // Destructor for cleaning up memory
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
    void insertAtFirst(int data){
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void Traverse()
    {
        if (head == nullptr)
        {
            cout << "The Linked List is Empty." << endl;
            return;
        }
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

    list.insertAtFirst(15);
    list.insertAtFirst(16);
    list.insertAtFirst(17);
    list.insertAtFirst(18);
    list.insertAtFirst(19);
    list.insertAtFirst(20);

    list.Traverse();
    return 0;
}