#include <bits/stdc++.h>
#include <vector>
using namespace std;
// brute force

vector<int> findNearestSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        // Initialize to -1 if no larger element is found
        int nearestSmallerToLeft = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                nearestSmallerToLeft = arr[j];
                // Found a larger element, exit the inner loop
                break;
            }
        }
        // reverse(result.begin(), result.end());
        result.push_back(nearestSmallerToLeft);
    }

    return result;
}
// best aprroach using stack/

/*vector<int> findNearestSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            result.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < arr[i])
        {
            result.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}*/
int main()
{

    // vector<int> arr = {1, 2, 3, 4};
    vector<int> arr = {4, 7, 8, 2, 3, 1};

    vector<int> result = findNearestSmaller(arr);

    cout << "Nearest smaller elements: ";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
