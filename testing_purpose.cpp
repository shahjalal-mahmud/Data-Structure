#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val): data(val), next(nullptr) {}
};
void traversal(Node *head) 
 {
    Node* ptr = head;
    if (head != nullptr) {
        do {
            cout << ptr->data;
            ptr = ptr->next;
            if (ptr != head) {
                cout << " -> ";  // Print the arrow if not bac
            }
        } while (ptr != head);  // Stop when we reach the head again
        cout << " -> (back to " << head->data << ")" << endl;  // Indicate circular nature
    }
}

int main() {
    // Create the head node
    Node* head = new Node(2);
    Node* second = new Node(5);
    Node* third = new Node(7);
    
    // Link the nodes to form a circular linked list
    head->next = second;
    second->next = third;
    third->next = head;  // Make it circular
    
    // Print the list in the desired format
    traversal(head);

    return 0;
}