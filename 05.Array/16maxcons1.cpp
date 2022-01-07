// maximum consecutive 1s
#include <bits/stdc++.h>
using namespace std;
int max1(int a[], int n)
{
    int res = 0, best = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            res++;
        else
            res = 0;
        best = max(best, res);
    }
    return best;
}
int main()
{
    int a[] = {0, 1, 1, 1, 0, 1, 1};
    int n = sizeof(a) / sizeof(int);
    cout << endl
         << max1(a, n) << endl;
    return 0;
}