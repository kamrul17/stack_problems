#include <bits/stdc++.h>
#include <vector>
using namespace std;
// brute force
// circular array problem
vector<int> findNearestLarger(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            int nextIndex = (i + j) % n;
            if (arr[nextIndex] > arr[i] && result[i] == -1)
            {
                result[i] = arr[nextIndex];
            }
        }
    }

    return result;
}
// best aprroach using stack
/*vector<int> findNearestLarger(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i % n])
        {
            s.pop();
        }
        if (i < n)
        {
            if (s.empty() == false)
            {
                result.push_back(s.top());
            }
            else
            {
                result.push_back(-1);
            }
        }

        s.push(arr[i % n]);
    }
    reverse(result.begin(), result.end());
    return result;
}*/
int main()
{

    vector<int> arr = {1, 2, 1};
    // vector<int> arr = {1, 5, 3, 4, 2};

    vector<int> result = findNearestLarger(arr);

    cout << "Nearest larger elements: ";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
