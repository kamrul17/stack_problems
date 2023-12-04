#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<int> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[' or s[i] == '{' or s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char ch = st.top();
            st.pop();
            if ((ch == '{' and s[i] == '}') or (ch == '(' and s[i] == ')' or (ch == '[' and s[i] == ']')))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s = "()";
    // string s = "()[{}()]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}