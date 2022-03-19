// 3. intersection of arrrays
#include <bits/stdc++.h>
using namespace std;
int intersection(vector<int> a, vector<int> b, int m, int n)
{
    int res = 0;
    unordered_set<int> s;
    for (int i : a)
        s.insert(a[i]);
    for (int j : b)
    {
        if (s.count(b[j]))
        {
            res++;
            s.erase(b[j]);
        }
    }
    return res;
}
int main()
{
    vector<int> a = {10, 15, 20, 15, 30, 30, 5};
    vector<int> b = {30, 5, 30, 80};
    int m = a.size();
    int n = b.size();
    cout << intersection(a, b, m, n);

    return 0;
}