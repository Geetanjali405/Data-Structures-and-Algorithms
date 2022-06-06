// next largest element aka nearest greter to right modified(2 array)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        stack<int> s;
        unordered_map<int, int> m;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
            {
                m[nums2[i]] = -1;
            }
            else if (s.size() > 0 && s.top() > nums2[i])
            {
                m[nums2[i]] = s.top();
            }
            else if (s.size() > 0 && s.top() <= nums2[i])
            {
                while (s.size() > 0 && s.top() <= nums2[i])
                    s.pop();
                if (s.empty())
                    m[nums2[i]] = -1;
                else
                    m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        for (int num : nums1)
        {
            if (m.count(num))
                v.push_back(m[num]);
        }
        return v;
    }
};