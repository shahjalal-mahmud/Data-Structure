#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root; // Root of the tree

    // Helper function for inserting a value
    void insertHelper(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insertHelper(node->left, value);
        } else {
            insertHelper(node->right, value);
        }
    }

    // Helper function for in-order traversal
    void inorderTraversalHelper(Node* node) {
        if (node != nullptr) {
            inorderTraversalHelper(node->left);  // Traverse left subtree
            cout << node->data << " ";          // Print the current node
            inorderTraversalHelper(node->right); // Traverse right subtree
        }
    }

    // Helper function for search a value
    bool searchHelper(Node* node, int value){
        if(!node) return false;
        if(node->data == value) return true;
        return (value <node->data) ? searchHelper(node->left, value) : searchHelper(node->right, value);
    }
public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Public method to insert a value
    void insert(int value) {
        insertHelper(root, value);
    }

    // Public method to perform in-order traversal
    void inorderTraversal() {
        inorderTraversalHelper(root);
        cout << endl; // Add a newline for clean output
    }

    // Public method to search a value
    bool search(int value){
        searchHelper(root, value);
    }
};

int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Perform in-order traversal
    cout << "In-order Traversal: ";
    tree.inorderTraversal();

    return 0;
}
