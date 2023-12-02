#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> immediateSmaller(vector<int> &a)
{
    int n = a.size();
    vector<int> res;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            // a[i] = a[i + 1];
            res.push_back(a[i + 1]);
        }
        else
        {
            // a[i] = -1;
            res.push_back(-1);
        }
    }
    // a[n - 1] = -1;
    res.push_back(-1);
    return res;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    // vector<int> arr = {4, 7, 8, 2, 3, 1};

    vector<int> result = immediateSmaller(arr);

    cout << "Nearest smaller elements: ";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
