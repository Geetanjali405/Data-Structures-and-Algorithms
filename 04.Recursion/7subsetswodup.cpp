#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    void solve(vector<int> ip, vector<int> op)
    {
        if (ip.size() == 0)
        {
            res.push_back(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        solve(ip, op1);
        solve(ip, op2);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &ip)
    {
        vector<int> op;
        int n = ip.size();
        solve(ip, op);
        set<vector<int>> s;
        for (int i = 0; i < res.size(); i++)
        {
            sort(res[i].begin(), res[i].end());
            s.insert(res[i]);
        }
        vector<vector<int>> ans;
        set<vector<int>>::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            ans.push_back(*itr);
        }
        return ans;
    }
};