#include <bits/stdc++.h>
using namespace std;
void solve(int a[], int n)
{

    stack<int> st;
    st.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        st.push(min(a[i], st.top()));
    }
    while (!st.empty())
    {
        int ans = st.top();
        cout << ans << " ";
        st.pop();
    }
}
int main()
{
    int N = 5;
    int a[] = {1, 2, 0, 4, 5};
    solve(a, N);
}