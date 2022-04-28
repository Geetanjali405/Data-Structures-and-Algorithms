// longest subarray with a given sum
// i/p={5,8,-4,-4,9,-2,2} sum=0, o/p=3
#include <bits/stdc++.h>
using namespace std;
int subsum(vector<int> a, int sum)
{
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
    vector<int> a = {5, 8, -4, -4, 9, -2, 2};
    int sum = 0;
    cout << subsum(a, sum);
    return 0;
}