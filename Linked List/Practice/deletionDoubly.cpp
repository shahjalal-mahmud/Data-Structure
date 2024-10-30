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
    void deleteHead()
    {
        head = head->next;
        head->prev = nullptr;
    }
    void deleteTail()
    {
        tail->prev->next = nullptr;
        tail = tail->prev;
    }
    void deleteNode(int target)
    {
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->data != target)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = t2->next;
        t2->next->prev = t1;
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
            current =current->prev;
        }
        cout<<endl;
    }
};
int main()
{
    Linkedlist list;

    list.insertAtHead(90);
    list.insertAtHead(80);
    list.insertAtHead(70);
    list.insertAtHead(60);
    list.insertAtHead(50);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtHead(5);
    list.Traverse();

    list.deleteHead();
    list.Traverse();

    list.deleteTail();
    list.Traverse();

    list.deleteNode(50);
    list.Traverse();

    list.reverseTraverse();
    return 0;
}