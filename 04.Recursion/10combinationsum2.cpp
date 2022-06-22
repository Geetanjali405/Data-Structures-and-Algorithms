#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int idx, vector<int> &arr, int t, vector<vector<int>> &res, vector<int> &op)
    {
        if (t == 0)
        {
            res.push_back(op);
            return;
        }

        for (int i = idx; i < arr.size(); i++)
        {
            if (i > idx && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > t)
                return;
            op.push_back(arr[i]);
            solve(i + 1, arr, t - arr[i], res, op);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {
        vector<vector<int>> res;
        vector<int> op;
        sort(arr.begin(), arr.end());
        solve(0, arr, target, res, op);
        return res;
    }
};