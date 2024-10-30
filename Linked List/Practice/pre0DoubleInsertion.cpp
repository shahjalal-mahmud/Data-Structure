#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int val): data(val),next(NULL),prev(NULL){}
};
void travers(Node *n){
    while( n!=NULL){
        cout<<"LINKED LIST= "<<n->data<<endl;
        n=n->next;
    }
    
}
void reverseTraverse(Node *n){
    while (n->next!=nullptr)
    {
        n = n->next;
    }
    while (n!=nullptr)
    {
        cout<<n->data<<" ";
        n = n->prev;
    }
    cout<<endl;
}
int main()
{
    Node*head=new Node(3);
    Node*second=new Node(4);
    Node*third=new Node(5);

    head->next=second;
    second->next=third;
    third->next=NULL;

//create Node
    Node*addNode=new Node(8);
    addNode->next=NULL;

    //At tail
    Node*ptr=head;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    ptr->next=addNode;
    addNode->prev=ptr;
    

    travers(head);
    reverseTraverse(head);

 return 0;
}