#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
private:
    stack<int> s;  // Regular stack to store elements
    stack<int> ss; // Stack to store the minimum element at the top

public:
    // Function to push an element onto the stack
    void push(int a)
    {
        s.push(a);
        if (ss.size() == 0 || ss.top() >= a)
        {
            ss.push(a);
            return;
        }
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        int ans = s.top();
        s.pop();
        if (ss.top() == ans)
        {
            ss.pop();
        }
        return ans;
    }

    // Function to get the minimum element in the stack
    int getMin()
    {
        if (ss.size() == 0)
        {
            return -1;
        }
        else
        {
            return ss.top();
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
