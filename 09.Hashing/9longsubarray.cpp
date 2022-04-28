// longest subarray with equal number of 0s and 1s
// i/p ={1,0 ,1,1,1,0,0} o/p=6
#include <bits/stdc++.h>
using namespace std;
int subsum(vector<int> a, int sum)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
            a[i] = -1;
    }
    unordered_map<int, int> s;
    int presum = 0, res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        presum += a[i];
        if (presum == sum)
            res = i + 1;
        if (!s.count(presum))
            s.insert({presum, i});
        if (s.count(presum - sum))
            res = max(res, i - s[presum - sum]);
    }
    return res;
}
int main()
{
    vector<int> a = {1, 0, 1, 1, 1, 0, 0};
    int sum = 0;
    cout << subsum(a, sum);
    return 0;
}