#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    void push(int data)
    {
        arr[++top] = data;
    }
    void Traverse()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack st(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.Traverse();
    return 0;
}