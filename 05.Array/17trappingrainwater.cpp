// trapping rain water problem
#include <bits/stdc++.h>
using namespace std;
int getwater(int a[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lmax = a[0], rmax = a[0];
        for (int j = 0; j < i; j++)
            lmax = max(lmax, a[j]);
        for (int j = i + 1; j < n; j++)
            rmax = max(lmax, a[j]);
        // cout << lmax << "    " << rmax << endl;
        res += min(lmax, rmax) - a[i];
        // cout << res << endl;
    }
    return res;
}
int main()
{
    int a[] = {3, 0, 1, 2, 5};
    int n = sizeof(a) / sizeof(int);
    cout << endl
         << getwater(a, n) << endl;
    return 0;
}