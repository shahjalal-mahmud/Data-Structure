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

    // Case 1: Insertion at the Head
    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Case 2: Insertion at the End
    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node *current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // Case 3: Insertion at any middle of the index
    void insertAtIndex(int data, int index) {
        if (index == 0) {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *current = head;
        int i = 0;

        while (i < index - 1 && current->next != head) {
            current = current->next;
            i++;
        }

        if (current->next == head && i < index - 1) {
            cout << "Index is out of bounds." << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void Traverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node *current = head;
        cout << "The Circular Linked List: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
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
