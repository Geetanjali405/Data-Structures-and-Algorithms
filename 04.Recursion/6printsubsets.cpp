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

    vector<vector<int>> subsets(vector<int> &ip)
    {

        vector<int> op;
        solve(ip, op);
        return res;
    }
};