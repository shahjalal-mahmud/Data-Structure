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

void Traverse(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void InsertAtHead(Node *&head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void InsertAtEnd(Node *head, int value) {
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = new Node(value);
    head->next->prev = head;
}

void InsertAfter(Node *head, int afterValue, int value) {
    while (head->data != afterValue) {
        head = head->next;
    }
    Node *newNode = new Node(value);
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
}

int main()
{
    Node *p = new Node(11);
    Node *q = new Node(12);
    Node *r = new Node(13);
    Node *s = new Node(14);

    p->next = q;
    q->next = r;
    r->next = s;

    s->prev = r;
    r->prev = q;
    q->prev = p;

    Traverse(p);

    InsertAtHead(p, 55);
    Traverse(p);

    InsertAtEnd(p, 99);
    Traverse(p);
    
    InsertAfter(p, 13, 101);
    Traverse(p);

    return 0;
}