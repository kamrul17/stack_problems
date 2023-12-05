#include <iostream>
using namespace std;
#include <stack>
void display(stack<int> s2)
{
    while (!s2.empty())
    {
        int ans = s2.top();
        s2.pop();
        cout << ans << " ";
    }
    cout << endl;
}
int reverseStack(stack<int> &s)
{
    stack<int> s2;
    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }

    display(s2);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    reverseStack(s);

    while (!s.empty())
    {
        int ans = s.top();
        s.pop();
        cout << ans << " ";
    }

    return 0;
}