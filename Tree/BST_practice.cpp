#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
Node *insert(Node *node, int value)
{
    if (node == NULL)
    {
        return new Node(value);
    }
    else if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }
}
bool Search(Node *node, int value)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->data == value)
    {
        return true;
    }
    return (value < node->data) ? Search(node->left, value) : Search(node->right, value);
}
Node *Findmin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *Delete(Node *node, int value)
{
    if (node == NULL)
    {
        return node;
    }
    if (value < node->data)
    {
        node->left = Delete(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = Delete(node->right, value);
    }
    else
    {
        if (node->left == NULL)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        // Case 2: Node with two children
        Node *temp = Findmin(node->right);
        node->data = temp->data;
        node->right = Delete(node->right, temp->data);
    }
    return node;
}
void Inorder(Node *node)
{
    if (node != NULL)
    {
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);

    Inorder(root);

    cout << endl;
    Delete(root, 20);
    Inorder(root);
    return 0;
}