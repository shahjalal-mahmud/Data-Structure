#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
void insertAfterNode(int data, int target)
{
    Node *temp = head;
    while (temp->data != target)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
int main()
{
    Node *p = new Node(10);
    Node *q = new Node(20);
    Node *r = new Node(30);
    Node *s = new Node(40);

    p->next = q;
    q->next = r;
    r->next = s;

    s->prev = r;
    r->prev = q;
    q->prev = p;
    
    return 0;
}