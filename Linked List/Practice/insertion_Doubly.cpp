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
    void insert_At_End(int data)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void insert_After(int data, int target)
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
    void reverseTraverse(){
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main()
{
    Linkedlist list;
    list.insert_At_head(11);
    list.insert_At_End(12);
    list.insert_At_End(13);
    list.insert_At_End(14);
    list.Traverse();

    list.insert_After(20, 13);
    list.Traverse();

    list.reverseTraverse();
    return 0;
}