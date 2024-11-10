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
    void insert_At_Head(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void deleteHead(){
        head = head->next;
    }
    void deleteEnd(){
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->next!=nullptr)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
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
    }
  
};
int main()
{
    Linkedlist list;
    list.insert_At_Head(10);
    list.insert_At_Head(20);
    list.insert_At_Head(30);
    list.insert_At_Head(40);
    list.insert_At_Head(50);
    list.insert_At_Head(60);
    list.insert_At_Head(70);
    list.insert_At_Head(80);
    list.insert_At_Head(90);
    list.insert_At_Head(100);
    list.Traverse();

    list.deleteHead();
    list.Traverse();

    list.deleteEnd();
    list.Traverse();

    list.deleteNode(50);
    list.Traverse();
    return 0;
}