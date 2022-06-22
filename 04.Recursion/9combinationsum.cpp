#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int i, vector<int> &arr, int t, vector<vector<int>> &res, vector<int> &op)
    {
        if (arr.size() == i)
        {
            if (t == 0)
            {
                res.push_back(op);
            }
            return;
        }
        if (arr[i] <= t)
        {
            op.push_back(arr[i]);
            solve(i, arr, t - arr[i], res, op);
            op.pop_back();
        }
        solve(i + 1, arr, t, res, op);
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        vector<vector<int>> res;
        vector<int> op;
        solve(0, arr, target, res, op);
        return res;
    }
};