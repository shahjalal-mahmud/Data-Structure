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
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (front == nullptr)
        {
            front = rare = newNode;
            return;
        }
        rare->next = newNode;
        rare = newNode;
    }
    void pop(){
        front = front->next;
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
    q.push(11);
    q.push(21);
    q.push(31);
    q.push(41);
    q.push(51);
    q.Traverse();

    q.pop();
    q.Traverse();
    return 0;
}