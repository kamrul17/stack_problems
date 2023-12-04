#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
private:
    stack<int> s; // Regular stack to store elements
    int miniElement = INT8_MIN;

public:
    // Function to push an element onto the stack
    void push(int a)
    {
        if (s.size() == 0)
        {
            s.push(a);
            miniElement = a;
        }
        else
        {
            if (a >= miniElement)
            {
                s.push(a);
            }
            else if (a < miniElement)
            {
                s.push(2 * a - miniElement);
                miniElement = a;
            }
        }
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        else
        {
            if (s.top() >= miniElement)
            {
                s.pop();
            }
            else if (s.top() < miniElement)
            {
                miniElement = 2 * miniElement - s.top();
                s.pop();
            }
        }
    }

    int top()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        else
        {
            if (s.top() >= miniElement)
            {
                s.top();
            }
            else if (s.top() < miniElement)
            {
                return miniElement;
            }
        }
    }
    bool isEmpty()
    {
        return s.empty();
    }
    // Function to get the minimum element in the stack
    int getMin()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        else
        {
            return miniElement;
        }
    }
};
int main()
{
    SpecialStack specialStack;

    specialStack.push(18);
    specialStack.push(19);
    // specialStack.push(20);
    specialStack.push(15);
    // specialStack.push(16);

    cout << "Min Element: " << specialStack.getMin() << endl;

    specialStack.pop();

    cout << "Min Element after pop: " << specialStack.getMin() << endl;
    return 0;
}
