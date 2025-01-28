#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(Node* node, int value) {
        if (node == NULL) return false;
        if (node->data == value) return true;
        return (value < node->data) ? search(node->left, value) : search(node->right, value);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL) return node;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node to delete found
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Inorder traversal before deletion
    cout << "Inorder traversal before deletion: ";
    tree.inorderTraversal();

    // Delete a node
    tree.deleteNode(50);

    // Inorder traversal after deletion
    cout << "Inorder traversal after deletion: ";
    tree.inorderTraversal();

    return 0;
}
