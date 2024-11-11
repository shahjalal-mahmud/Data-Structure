#include <iostream>
using namespace std;
class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node *top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}
    ~Stack()
    {
        clear();
    }
    bool isEmpty() const
    {
        return top == nullptr;
    }
    int size() const
    {
        return count;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        count++;
        cout << data << " pushed on stack" << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty, no element to pop." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << temp->data << " poped" << endl;
        delete temp;
        count--;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty, no element to peek." << endl;
            return -1;
        }
        return top->data;
    }
    void Traverse() const
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void clear(){
        while (top!=nullptr)
        {
            Node *temp = top;
            top = top->next;
            cout << temp->data << " deleted" << endl;
            delete temp;
            count = 0;
        }
        
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.Traverse();

    st.pop();
    st.Traverse();

    cout << "Current top element: " << st.peek() << endl;
    cout << "Stack size: " << st.size() << endl;

    st.clear();
    cout << "Stack size after clearing: " << st.size() << endl;

    return 0;
}