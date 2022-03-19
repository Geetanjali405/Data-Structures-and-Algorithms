// 2.frequencies of array elements
#include <bits/stdc++.h>
using namespace std;
void frequency(vector<int> arr, int n)
{
    unordered_map<int, int> h;
    for (int x : arr)
        h[x]++;
    for (auto itr = h.begin(); itr != h.end(); itr++)
        cout << itr->first << " " << itr->second << endl;
}
int main()
{
    vector<int> arr = {10, 20, 10, 20, 30};
    int n = 5;
    frequency(arr, n);
    return 0;
}