// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> res;
    void solve(string ip, string op)
    {
        if (ip.size() == 0)
        {
            res.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;

        op1 += " ";
        op1 += ip[0];
        op2 += ip[0];
        ip.erase(ip.begin() + 0);
        solve(ip, op1);
        solve(ip, op2);
    }

    vector<string> permutation(string ip)
    {
        // Code Here
        string op = "";
        op.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        solve(ip, op);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}
// } Driver Code Ends