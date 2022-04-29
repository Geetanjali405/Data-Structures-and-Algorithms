// To find the length of longest consecutive subsequence
// a={1,9,3,4,2,20} o/p=4
// naive- we can sort the array and then move on- T.C -O(nlogn){to sort the array } and O(n) time to find the longest subsequence [overall tc-O(nlogn)]
// T.C of optimized =O(n)

#include <bits/stdc++.h>
using namespace std;
int cons_sub(vector<int> a)
{
    int res = 0;
    unordered_set<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        int curr = 1;
        while (s.count(a[i] + curr))
            curr++;
        res = max(res, curr);
    }
    return res;
}
int main()
{
    vector<int> a = {1, 9, 3, 4, 2, 20};
    int sum = 0;
    cout << cons_sub(a);
    return 0;
}