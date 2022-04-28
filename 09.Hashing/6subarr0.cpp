// if there is a subarray of 0 sum
// i/p-{1,4,13,-3,-10,5},o/p=yes
#include <bits/stdc++.h>
using namespace std;
bool sumz(vector<int> a)
{
    unordered_set<int> s;
    int presum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        presum += a[i];
        if (s.count(presum))
            return true;
        if (presum == 0)
            return true;
        s.insert(presum);
    }
    return false;
}
int main()
{
    vector<int> a = {1, 4, 13, -3, -10, 5};
    cout << sumz(a);
    return 0;
}