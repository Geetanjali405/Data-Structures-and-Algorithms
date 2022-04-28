// if there is a subarray of given sum
// i/p-{5,8,6,13,3,-1},o/p=yes
#include <bits/stdc++.h>
using namespace std;
bool subsum(vector<int> a, int sum)
{
    unordered_set<int> s;
    int presum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        presum += a[i];
        if (presum == sum)
            return true;
        if (s.count(presum - sum))
            return true;
        s.insert(presum);
    }
    return false;
}
int main()
{
    vector<int> a = {5, 8, 6, 13, 3, -1};
    int sum = 22;
    cout << subsum(a, sum);
    return 0;
}