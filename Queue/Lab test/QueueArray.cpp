#include <iostream>
using namespace std;
class Queue
{
private:
    int *arr;
    int capacity;
    int rare;
    int front;

public:
    Queue(int size)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rare = -1;
    }
    void push(int data)
    {
        arr[++rare] = data;
    }
    void pop()
    {
        front++;
    }
    void Traverse()
    {
        for (int i = front; i <= rare; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(10);
    q.push(11);
    q.push(21);
    q.push(31);
    q.push(41);
    q.push(51);
    q.Traverse();

    q.pop();
    q.Traverse();
    return 0;
}