#include <iostream>
using namespace std;
#include <stack>

class twoStacks
{
    int *arr;
    int size;
    int top1;
    int top2;

public:
    twoStacks(int n)
    {
        this->size = n;
        top1 = -1;
        top2 = n;
        arr = new int[n];
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = x;
            cout << "Pushed into Stack 1: " << x << endl;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = x;
            cout << "Pushed into Stack 2: " << x << endl;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }
};

int main()
{
    twoStacks st(5);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push1(5);
    st.push1(6);
    st.pop1();
    st.push1(6);
    return 0;
}