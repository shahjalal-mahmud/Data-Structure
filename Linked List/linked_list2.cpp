#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val): data(val), next(nullptr){}
};
void Traversal(Node *ptr){
    while (ptr !=nullptr)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    
}
Node* createLinkedList(int arr[], int size){
    if(size ==0){
        return nullptr;
    }
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 0; i < size; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}
int main()
{
    int values[] = {1, 3, 5, 7, 9};
    int size = sizeof(values)/sizeof(values[0]);

    Node *head = createLinkedList(values, size);
    Traversal(head);
    return 0;
}