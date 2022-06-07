// max evenodd subarray
#include <bits/stdc++.h>
using namespace std;
int maxeo(int a[], int n)
{
    int res = 1, cur = 1;
    for (int i = 1; i < n; i++)
    {
        if ((a[i] % 2 == 0 && a[i - 1] % 2 != 0) || (a[i] % 2 != 0 && a[i - 1] % 2 == 0))
            cur++;
        else
            cur = 1;
        res = max(res, cur);
    }

    return res;
}
int main()
{
    int a[] = {5, 10, 20, 6, 3, 8, 7};
    int n = 7;
    // res=4
    cout << endl
         << maxeo(a, n) << endl;
    return 0;
}