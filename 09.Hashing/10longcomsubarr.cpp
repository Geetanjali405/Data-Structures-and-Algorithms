// longest common subarray with same sum in binary array
// i/p=arr1={0,1,0,0,0,0} arr2={1,0,1,0,0,1} o/p=4
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
    vector<int> arr1 = {0, 1, 0, 0, 0, 0};
    vector<int> arr2 = {1, 0, 1, 0, 0, 1};
    int n = arr1.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = arr1[i] - arr2[i];
    int sum = 0;
    cout << subsum(a, sum);
    return 0;
}