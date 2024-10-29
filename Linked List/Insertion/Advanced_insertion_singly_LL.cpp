#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class Linkedlist {
private:
    Node *head;

public:
    Linkedlist() : head(nullptr) {}

    ~Linkedlist() {
        Node *current = head;
        Node *nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data) {
        if (head == nullptr) {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode; 
    }

    void insertAfterNode(int data, int target) {
        Node *newNode = new Node(data);
        Node *current = head;

        // Find the target node
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        
        // If target was found, insert the new node
        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            // Handle the case where the target node is not found
            cout << "Target node " << target << " not found." << endl;
            delete newNode; // prevent memory leak
        }
    }

    void Traverse() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Linkedlist list;
    list.insertAtHead(101);
    list.insertAtTail(102);
    list.insertAtTail(103);
    list.insertAtTail(104);
    list.insertAtTail(105);
    list.Traverse();

    list.insertAtHead(100);
    list.Traverse();

    list.insertAtTail(106);
    list.Traverse();

    list.insertAfterNode(199, 104);
    list.Traverse();

    return 0;
}
