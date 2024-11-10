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
    void insert_At_head(int data)
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
    void reverseTraverse(){
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    void deleteHead(){
        head = head->next;
        head->prev= nullptr;
    }
    void deleteEnd(){
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->next!=nullptr)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        tail = t1;
        t1->next = nullptr;
    }
    void deleteNode(int target){
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->data!= target)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = t2->next;
        t2->next->prev = t1;
    }
};
int main()
{
    Linkedlist list;
     list.insert_At_head(10);
    list.insert_At_head(20);
    list.insert_At_head(30);
    list.insert_At_head(40);
    list.insert_At_head(50);
    list.insert_At_head(60);
    list.insert_At_head(70);
    list.insert_At_head(80);
    list.insert_At_head(90);
    list.insert_At_head(100);
    list.Traverse();
    
    list.deleteHead();
    list.Traverse();

    list.deleteEnd();
    list.Traverse();

    list.deleteNode(50);
    list.Traverse();

    list.reverseTraverse();
    return 0;
}