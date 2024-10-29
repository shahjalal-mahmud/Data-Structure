#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty. No head to delete.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty. No tail to delete.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
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
        while (current->next != nullptr && current->next->data != target) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Node with value " << target << " not found.\n";
            return;
        }
        Node *targetNode = current->next;
        current->next = targetNode->next;
        delete targetNode;
    }

    void traverse() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(100);
    list.insertAtHead(90);
    list.insertAtHead(80);
    list.insertAtHead(70);
    list.insertAtHead(60);
    list.insertAtHead(50);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.traverse(); // Output: 30 40 50 60 70 80 90 100

    list.deleteHead();
    list.traverse(); // Output: 40 50 60 70 80 90 100

    list.deleteTail();
    list.traverse(); // Output: 40 50 60 70 80 90

    list.deleteNode(60);
    list.traverse(); // Output: 40 50 70 80 90

    list.deleteNode(999); // Testing non-existent node deletion
    list.deleteHead();
    list.deleteTail();
    list.traverse();

    return 0;
}
