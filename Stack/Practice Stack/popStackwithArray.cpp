#include<iostream>
using namespace std;
class Stack{
private:
    int *arr;
    int capacity;
    int top;
public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    void push(int data){
        if (top == capacity -1)
        {
            cout<<"Stack Overflow."<<endl;
            return;
        }
        arr[++top] = data;
        
    }
    void pop(){
        top--;
    }
};
int main()
{
 return 0;
}