#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool ispal(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void f(int ind, string s, vector<vector<string>> &res, vector<string> &op)
    {
        if (ind == s.size())
        {
            res.push_back(op);
            return;
        }

        for (int i = ind; i < s.size(); ++i)
        {
            if (ispal(s, ind, i))
            {
                op.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, s, res, op);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> op;
        f(0, s, res, op);
        return res;
    }
};