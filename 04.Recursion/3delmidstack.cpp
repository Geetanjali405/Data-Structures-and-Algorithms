#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to delete middle element of a stack.
    void del(stack<int> &s, int k)
    {
        if (k == 1)
        {
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        del(s, k - 1);
        s.push(temp);
        return;
    }
    void deleteMid(stack<int> &s, int n)
    {
        // code here..
        int k = n / 2 + 1;
        del(s, k);
    }
};