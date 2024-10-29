#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Linkedlist
{
private:
    Node *head;
public:
    Linkedlist() : head(nullptr) {}
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data){
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->next!=nullptr)
        {
            current= current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void insertAfterNode(int data, int target){
        Node *newNode = new Node(data);
        Node *current = head;
        while (current->data != target)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void Traverse(){
        Node *current = head;
        while (current!=nullptr)
        {
            cout<<current->data<<" ";
            current =current->next;
        }
        cout<<endl;
    }
};
int main()
{
    Linkedlist list;
    list.insertAtHead(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.Traverse();

    list.insertAfterNode(25, 10);
    list.Traverse();
    return 0;
}
