#include <iostream>
using namespace std;
#include <stack>

class Stack
{
public:
    int *arr;
    int size;
    int top;
    // constructor

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    //  push
    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    //  pop
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }
    // top
    int peak()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
        return -1;
    }
    // empty
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(223);

    st.push(445);
    cout << st.peak() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is Not empty" << endl;
    }

    return 0;
}