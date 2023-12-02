#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            result.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > arr[i])
        {
            result.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    for (int i = 0; i < result.size(); i++)
    {
        result[i] = i - result[i];
    }
    return result;
}
int main()
{

    // vector<int> arr = {20, 12, 1, 28, 16, 20};
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = solve(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}