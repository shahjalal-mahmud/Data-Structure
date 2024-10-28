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
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
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
    void Traverse(){
        Node *current = head;
        while (current!=nullptr)
        {
            cout<<current->data<<" ";
            current =current->next;
        }
        cout<<endl;
    }
};
int main()
{
    Linkedlist list;
    list.insertAtHead(100);
    list.insertAtEnd(200);
    list.insertAtEnd(300);
    list.insertAtEnd(400);
    list.insertAtEnd(500);
    list.insertAtEnd(600);

    list.Traverse();

    list.insertAfterNode(450, 400);
    list.Traverse();

    list.insertAtHead(50);
    list.insertAtEnd(900);
    list.Traverse();
    return 0;
}