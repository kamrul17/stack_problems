// #include <bits/stdc++.h>
// using namespace std;
// int sumSubarrayMins(vector<int> &arr, int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int minVal = arr[i];
//         for (int j = i; j < n; j++)
//         {
//             minVal = min(minVal, arr[j]);
//             sum += minVal;
//         }
//     }
//     return sum;
// }
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4};
//     int n = arr.size();
//     int ans = sumSubarrayMins(arr, n);
//     cout << ans;
// }
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// brute force

/*vector<int> findNearestLarger(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;

    for (int i = 0; i < n; ++i)
    {
        // Initialize to -1 if no larger element is found
        int nearestLargerToLeft = -1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                nearestLargerToLeft = arr[j];
                // Found a larger element, exit the inner loop
                break;
            }
        }

        result.push_back(nearestLargerToLeft);
    }

    return result;
}*/
// best aprroach using stack
vector<int> findNearestLarger(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            result.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            result.push_back(i + 1);
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
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
    // reverse(result.begin(), result.end());
    return result;
}
int main()
{

    vector<int> arr = {3, 1, 2, 4};

    vector<int> result = findNearestLarger(arr);

    cout << "Nearest larger elements: ";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
