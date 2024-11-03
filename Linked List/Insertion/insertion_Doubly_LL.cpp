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
class Linkedlist
{
private:
    Node *head;
    Node *tail;

public:
    Linkedlist() : head(nullptr), tail(nullptr) {}
    void insertAtHead(int data)
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
    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
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
    void reverseTraverse(){
        Node *current = tail;
        while (current!=nullptr)
        {
            cout<<current->data<<" ";
            current = current->prev;
        }
        cout<<endl;
    }
};
int main()
{
    Linkedlist list;

    list.insertAtHead(101);
    list.insertAtTail(102);
    list.insertAtTail(103);
    list.insertAtTail(104);
    list.insertAtTail(105);
    list.Traverse();

    list.insertAtHead(100);
    list.Traverse();

    list.insertAtTail(106);
    list.Traverse();

    list.insertAfterNode(199, 104);
    list.Traverse();

    list.reverseTraverse();
    return 0;
}