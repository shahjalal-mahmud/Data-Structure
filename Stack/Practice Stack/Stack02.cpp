#include <iostream>
using namespace std;

class Node {
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

    // Push element onto the stack
    void push(int data) {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << data << " pushed into the Stack." << endl;
    }

    // Pop element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!" << endl;
            return; // Ensure we exit the function if stack is empty
        }
        Node *temp = top;
        top = top->next;
        cout << temp->data << " popped from the Stack." << endl;
        delete temp; // Free up memory
    }

    // Peek at the top element
    void peek() {
        if (top == nullptr) {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "The top data is: " << top->data << endl;
    }

    // Traverse through the stack
    void Traverse() {
        Node *temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
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
