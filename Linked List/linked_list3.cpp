#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
void Traversal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
Node *createLinkedList(int arr[], int size)
{
    if (size == 0)
    {
        return nullptr;
    }
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    int size;
    cout<<"Enter the size of the linked list: ";
    cin>>size;

    int arr[size];
    cout<<"Enter data for linked list: ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    Node *head = createLinkedList(arr, size);
    Traversal(head);
    return 0;
}