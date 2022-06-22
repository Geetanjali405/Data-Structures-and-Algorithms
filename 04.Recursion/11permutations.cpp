#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &arr, int freq[], vector<vector<int>> &ans, vector<int> &op)
    {
        if (op.size() == arr.size())
        {
            ans.push_back(op);
            return;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (!freq[i])
            {
                op.push_back(arr[i]);
                freq[i] = 1;
                solve(arr, freq, ans, op);
                freq[i] = 0;
                op.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> op;
        int n = nums.size();
        int freq[n];
        for (int i = 0; i < n; i++)
        {
            freq[i] = 0;
        }
        solve(nums, freq, ans, op);
        return ans;
    }
};