// next largest element aka nearest greter to right modified(circular)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> v;
        stack<int> s;
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if (s.size() > 0 && s.top() > nums[i % n])
            {
                v.push_back(s.top());
            }
            else if (s.size() > 0 && s.top() <= nums[i % n])
            {
                while (s.size() > 0 && s.top() <= nums[i % n])
                    s.pop();
                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums[i % n]);
        }

        reverse(v.begin(), v.end());
        vector<int> ans;
        for (int j = 0; j < n; j++)
        {
            ans.push_back(v[j]);
        }
        return ans;
    }
};