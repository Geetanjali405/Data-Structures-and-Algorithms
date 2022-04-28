// Find if there is a given pair sum in unsorted array
// i/p-{3,2,8,15,-8},pair sum =17(given)  o/p=yes
#include <bits/stdc++.h>
using namespace std;
bool pairsum(vector<int> a, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        if (s.count(sum - a[i]))
            return true;
        s.insert(a[i]);
    }
    return false;
}
int main()
{
    vector<int> a = {3, 2, 8, 15, -8};
    int sum = 17;
    cout << pairsum(a, sum);
    return 0;
}