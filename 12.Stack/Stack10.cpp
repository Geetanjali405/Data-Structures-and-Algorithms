// trapping rain water
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &a)
    {
        int n = a.size();
        int mxl[n];
        int mxr[n];
        mxl[0] = a[0];
        mxr[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
            mxl[i] = max(mxl[i - 1], a[i]);
        for (int i = n - 2; i >= 0; i--)
            mxr[i] = max(mxr[i + 1], a[i]);
        int water[n];
        for (int i = 0; i < n; i++)
            water[i] = min(mxl[i], mxr[i]) - a[i];
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += water[i];
        return sum;
    }
};