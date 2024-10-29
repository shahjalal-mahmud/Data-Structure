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
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode; // If the list is empty, head and tail point to newNode
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int data) {
        Node *newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode; // If the list is empty, head and tail point to newNode
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty. No head to delete.\n";
            return;
        }
        Node *temp = head;
        if (head == tail) {
            head = tail = nullptr; // Only one node in the list
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteTail() {
        if (tail == nullptr) {
            cout << "List is empty. No tail to delete.\n";
            return;
        }
        Node *temp = tail;
        if (head == tail) {
            head = tail = nullptr; // Only one node in the list
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty. Node not found.\n";
            return;
        }
        if (head->data == target) {
            deleteHead();
            return;
        }
        Node *current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Node with value " << target << " not found.\n";
            return;
        }
        if (current == tail) {
            deleteTail();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void traverseForward() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void traverseBackward() const {
        Node *current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtHead(100);
    list.insertAtHead(90);
    list.insertAtTail(110);
    list.insertAtTail(120);
    list.traverseForward();  // Output: 90 100 110 120
    list.traverseBackward(); // Output: 120 110 100 90

    list.deleteHead();
    list.traverseForward();  // Output: 100 110 120

    list.deleteTail();
    list.traverseForward();  // Output: 100 110

    list.deleteNode(110);
    list.traverseForward();  // Output: 100

    list.deleteNode(999);    // Testing non-existent node deletion
    list.deleteHead();
    list.deleteTail();
    list.traverseForward();  // Output should show an empty list

    return 0;
}
