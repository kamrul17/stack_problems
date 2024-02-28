#include <bits/stdc++.h>
using namespace std;
int findMaxLen(string s)
{
    stack<int> stk;
    stk.push(-1);

    int maxLen = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                maxLen = max(maxLen, i - stk.top());
            }
        }
    }

    return maxLen;
}

int main()
{
    string S = "(()(";
    int ans = findMaxLen(S);
    cout << ans;
}