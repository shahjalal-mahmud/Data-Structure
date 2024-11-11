#include <iostream>
using namespace std;
class Queue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node *front;
    Node *rare;

public:
    Queue() : front(nullptr), rare(nullptr) {}
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (rare == nullptr)
        {
            front = rare = newNode;
            return;
        }
        rare->next = newNode;
        rare = newNode;
    }
    void dequeue(){
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    void Traverse(){
        Node *temp = front;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.Traverse();

    q.dequeue();
    q.Traverse();
    return 0;
}