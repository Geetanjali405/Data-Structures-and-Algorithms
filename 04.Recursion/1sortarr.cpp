// sort an array using recursion
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortv(vector<int> &num)
    {
        if (num.size() == 1)
            return;

        int temp = num[num.size() - 1];
        num.pop_back();
        sortv(num);
        insert(num, temp);
        return;
    }
    void insert(vector<int> &v, int temp)
    {
        if (v.size() == 0 || v[v.size() - 1] <= temp)
        {
            v.push_back(temp);
            return;
        }
        int val = v[v.size() - 1];
        v.pop_back();
        insert(v, temp);
        v.push_back(val);
        return;
    }
    vector<int> sortArray(vector<int> &nums)
    {
        sortv(nums);
        return nums;
    }
};