#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node *prev; 
    Node(int value) : data(value), next(nullptr), prev(nullptr) {} // Initialize prev as nullptr
};
class LinkedList {
private:
    Node *head;
public:
    LinkedList() : head(nullptr) {}

    // Case 1: Insertion at the Head
    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode; 
        }
        head = newNode;
    }

    // Case 2: Insertion at the End
    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current; 
    }

    // Case 3: Insertion at any given index
    void insertAtIndex(int data, int index) {
        if (index == 0) {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *current = head;
        int i = 0;

        while (i < index - 1 && current != nullptr) {
            current = current->next;
            i++;
        }

        if (current == nullptr) {
            cout << "Index is out of bounds." << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void Traverse() {
        Node *current = head;
        cout << "The Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(29);
    list.insertAtEnd(54);
    list.insertAtEnd(69);
    list.insertAtEnd(28);

    list.Traverse();

    list.insertAtIndex(100, 1);
    list.Traverse();

    return 0;
}
