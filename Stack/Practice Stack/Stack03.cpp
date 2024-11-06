#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stact
{
private:
    Node *top;

public:
    Stact() : top(nullptr) {}
    void push(int data){
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    void pop(){
        top = top->next;
    }
    void Traverse(){
        Node *temp = top;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void peek(){
        cout<<top->data<<" ";
    }
};
int main()
{
    Stact s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.Traverse();

    s.pop();
    s.Traverse();

    s.peek();
    return 0;
}