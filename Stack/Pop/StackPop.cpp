#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack {
private:
    Node *top;
public:
    Stack() : top(nullptr) {}
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
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.Traverse();

    st.pop();
    st.Traverse();
    return 0;
}