#include <bits/stdc++.h>
using namespace std;
int maxprofit(int a[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        // cout << a[i] << " " << a[i - 1] << endl;
        if (a[i] > a[i - 1])
            max += a[i] - a[i - 1];
    }
    return max;
}
int main()
{
    int arr[] = {1, 5, 3, 8, 12};
    // o/p->13 sizeof(arr) / sizeof(int)
    cout << endl
         << maxprofit(arr, sizeof(arr) / sizeof(int)) << endl;
    return 0;
}