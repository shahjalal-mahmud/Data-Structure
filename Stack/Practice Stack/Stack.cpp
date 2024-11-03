#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << data << " pushed in the Stack." << endl;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow!!" << endl;
        }
        Node *temp = top;
        top = top->next;
        cout << temp->data << " poped from the Stack." << endl;
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack Empty." << endl;
            return;
        }
        cout << "The top data is: " << top->data << endl;
    }
    void Traverse(){
        Node *temp = top;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" "<<endl;
            temp = temp->next;
        }
    }
};
int main()
{
    Stack S1;

    S1.push(11);
    S1.push(12);
    S1.push(13);
    S1.push(14);
    S1.push(15);
    S1.Traverse();

    S1.pop();
    S1.Traverse();

    S1.peek();

    return 0;
}