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
    void deleteAtHead()
    {
        head = head->next;
    }
    void deleteAtEnd()
    {
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->next != nullptr)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = nullptr;
    }
    void deleteAfterNode(int target)
    {
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->data != target)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = t2->next;
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

    list.insertAtHead(60);
    list.insertAtHead(50);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);

    list.Traverse();

    list.deleteAtHead();
    list.Traverse();

    list.deleteAtEnd();
    list.Traverse();

    list.deleteAfterNode(40);
    list.Traverse();
    return 0;
}