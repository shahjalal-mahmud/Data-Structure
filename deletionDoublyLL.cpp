#include<iostream>
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
    // Case-1 => Delete the first node
    void deleteHead(){
        head = head->next;
        head->prev = nullptr;
    }
    // Case-2 Delete the last node
    void deleteTail(){
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->next != nullptr)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = nullptr;
        t2->prev = t1;
        tail = t1;
    }
    // Case-3 Delete after a given node
    void deleteAfterNode(int target){
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

    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtHead(5);
    list.insertAtHead(3);
    list.Traverse();

    list.deleteHead();
    list.Traverse();

    list.deleteTail();
    list.Traverse();

    list.deleteAfterNode(10);
    list.Traverse();
    
 return 0;
}