// count inversions in the array--> a pair (arr[i],arr[j]) forms an inversion when i<j
// and arr[i]>arr[j]

#include <bits/stdc++.h>
using namespace std;
int countandmerge(int a[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = a[i + l];
    for (int i = 0; i < n2; i++)
        right[i] = a[m + 1 + i];
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
            res += n1 - i;
        }
    }
    while (i < n1)
        a[k++] = left[i++];
    while (j < n2)
        a[k++] = right[j++];
    return res;
}
int countinv(int a[], int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        res += countinv(a, l, m);
        res += countinv(a, m + 1, r);
        res += countandmerge(a, l, m, r);
    }
    return res;
}
int main()
{
    int a[] = {10, 20, 30, 40};
    int n = 4;
    cout << countinv(a, 0, n - 1) << endl;
    int arr[] = {40, 30, 20, 10};
    int num = 4;
    cout << countinv(arr, 0, num - 1) << endl;

    /* int a[] = {2, 4, 1, 3, 5};
    int n = 5;
    cout << countinv(a, 0, n - 1) << endl;*/
    return 0;
}