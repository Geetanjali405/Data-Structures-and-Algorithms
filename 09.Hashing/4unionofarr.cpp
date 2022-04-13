// count of union of arrrays
#include <bits/stdc++.h>
using namespace std;
int unionarr(vector<int> a, vector<int> b)
{
    int res = 0;
    unordered_set<int> s;
    for (int i = 0; i < a.size(); i++)
        s.insert(a[i]);
    for (int j = 0; j < b.size(); j++)
        s.insert(b[j]);

    return s.size();
}
int main()
{
    vector<int> a = {15, 20, 15, 5};
    vector<int> b = {15, 15, 15, 20, 10};
    cout << unionarr(a, b);

    return 0;
}