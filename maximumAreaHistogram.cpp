#include <bits/stdc++.h>
#include <vector>
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
int main()
{

    vector<int> arr = {6, 2, 5, 4, 5, 1, 6};

    vector<int> right = NSR(arr);
    vector<int> left = NSL(arr);
    // cout << "Nearest smaller elements: ";

    // for (int i = 0; i < right.size(); i++)
    // {
    //     cout << right[i] << " ";
    // }
    cout << "----------------------------" << endl;
    cout << "----------------------------" << endl;
    cout << "----------------------------" << endl;
    // for (int i = 0; i < left.size(); i++)
    // {
    //     cout << left[i] << " ";
    // }
    cout << "----------------------------" << endl;
    cout << "----------------------------" << endl;
    int n = arr.size();
    vector<int> widthans = widthNikalo(left, right, n);
    // for (int i = 0; i < widthans.size(); i++)
    // {
    //     cout << widthans[i] << " ";
    // }
    vector<int> areaAns = AreaNikalo(widthans, arr, n);
    // vector<int> area;
    // for (int i = 0; i < n; i++)
    // {
    //     int Area = arr[i] * widthans[i];
    //     area.push_back(Area);
    // }
    int maxAns = maxArea(areaAns);
    cout << "maximum area histogram :-->" << maxAns;
    // auto maxi = max_element(areaAns.begin(), areaAns.end());
    // cout << "maximum area histogram :-->" << *maxi;

    return 0;
}
