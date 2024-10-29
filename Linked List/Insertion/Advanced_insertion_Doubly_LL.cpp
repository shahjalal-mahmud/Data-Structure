#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
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
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
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
        newNode->prev = current;
    }

    void insertAfterNode(int data, int target) {
        Node *current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }

        if (current != nullptr) {
            Node *newNode = new Node(data);
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next != nullptr) {
                current->next->prev = newNode; // Link the next node back to newNode
            }
            current->next = newNode; // Link current node to newNode
        } else {
            cout << "Target node " << target << " not found." << endl;
        }
    }

    void traverse() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverseTraverse() {
        Node *current = head;
        if (current == nullptr) return; // Check if the list is empty

        // Go to the last node
        while (current->next != nullptr) {
            current = current->next;
        }
        // Traverse backward
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtHead(101);
    list.insertAtTail(102);
    list.insertAtTail(103);
    list.insertAtTail(104);
    list.insertAtTail(105);
    list.traverse();

    list.insertAtHead(100);
    list.traverse();

    list.insertAtTail(106);
    list.traverse();

    list.insertAfterNode(199, 104);
    list.traverse();

    cout << "Reverse traverse: ";
    list.reverseTraverse();

    return 0;
}
