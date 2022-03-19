// 1. count distinct elements in an array
#include <bits/stdc++.h>
using namespace std;
int countdistinct(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    return s.size();
}
int main()
{
    int arr[] = {10, 20, 10, 20, 30};
    int n = 5;
    int x = countdistinct(arr, n);
    cout << x << endl;
    return 0;
}