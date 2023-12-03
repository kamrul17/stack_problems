#include <bits/stdc++.h>
using namespace std;

// NSL
vector<int> NSL(vector<int> &arr)
{
    int n = arr.size();
    vector<int> NSL;

    int psuedoIndex = -1;

    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            NSL.push_back(psuedoIndex);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            NSL.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                NSL.push_back(psuedoIndex);
            }
            else
            {
                NSL.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }

    return NSL;
}
// ---------------------------------------------------------
// NSR
vector<int> NSR(vector<int> &arr)
{
    int n = arr.size();
    vector<int> NSR;

    int psuedoIndex2 = n;

    stack<pair<int, int>> s2;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.size() == 0)
        {
            NSR.push_back(psuedoIndex2);
        }
        else if (s2.size() > 0 && s2.top().first < arr[i])
        {
            NSR.push_back(s2.top().second);
        }
        else if (s2.size() > 0 && s2.top().first >= arr[i])
        {
            while (s2.size() > 0 && s2.top().first >= arr[i])
            {
                s2.pop();
            }
            if (s2.size() == 0)
            {
                NSR.push_back(psuedoIndex2);
            }
            else
            {
                NSR.push_back(s2.top().second);
            }
        }
        s2.push({arr[i], i});
    }
    reverse(NSR.begin(), NSR.end());
    return NSR;
}
vector<int> widthNikalo(vector<int> &left, vector<int> &right, int n)
{
    vector<int> widths;

    for (int i = 0; i < n; i++)
    {
        int width = (right[i] - left[i]) - 1;
        widths.push_back(width);
    }
    return widths;
}
vector<int> AreaNikalo(vector<int> &widthans, vector<int> &arr, int n)
{
    vector<int> area;
    for (int i = 0; i < n; i++)
    {
        int Area = arr[i] * widthans[i];
        area.push_back(Area);
    }
    return area;
}
int maxArea(vector<int> &areaAns)
{
    int maxi = INT8_MIN;
    for (int i = 0; i < areaAns.size(); i++)
    {
        if (areaAns[i] > maxi)
        {
            maxi = areaAns[i];
        }
    }
    return maxi;
}
int MAH(vector<int> &v)
{
    vector<int> right = NSR(v);
    vector<int> left = NSL(v);
    int n = v.size();
    vector<int> widthans = widthNikalo(left, right, n);
    vector<int> areaAns = AreaNikalo(widthans, v, n);
    int maxAns = maxArea(areaAns);
    return maxAns;
}

// =============
int maxArea(int M[4][4], int n, int m)
{

    vector<int> v;
    for (int j = 0; j < m; j++)
    {
        v.push_back(M[0][j]);
    }
    int mx = MAH(v);

    //  remaining row k liye

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
            {
                v.push_back(0);
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + M[i][j];
                // cout << v[j] << " ";
            }
        }
        mx = max(mx, MAH(v));
    }
    return mx;
}
int main()
{
    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};
    int ans = maxArea(M, 4, 4);
    cout << ans;
}