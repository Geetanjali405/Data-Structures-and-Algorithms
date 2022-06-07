// maximum circular sub array sum
// use of kadenes algo again
#include <bits/stdc++.h>
using namespace std;
int arrsum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    // cout << sum << endl;
    return sum;
}
int maxsum(int a[], int n)
{
    int temp[n], res = a[0], best = 0, count = 0, x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            count++;
    }
    if (count == n)
        return *max_element(a, a + n);
    temp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        best = res;
        res = max(x, (x + res));
        temp[i] = res;
    }
    // cout << "max" << *max_element(temp, temp + n) << endl;
    return *max_element(temp, temp + n);
}
int minsub(int a[], int n)
{
    int temp[n], count = 0, res = a[0], best = 0, x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            count++;
    }
    if (count == n)
        return arrsum(a, n);
    temp[0] = a[0];
    for (int i = 0; i < n; i++)
    {
        x = a[i];
        best = res;
        res = min(x, (x + res));
        temp[i] = res;
    }
    // cout << "min" << *min_element(temp, temp + n) << endl;
    return *min_element(temp, temp + n);
}
int main()
{
    int a[] = {8, -4, 3, -5, 4};
    // output=12
    int n = 5;
    // logic----max(max subarray sum,(arrsum-min subarray diff))
    int res = max(maxsum(a, n), (arrsum(a, n) - minsub(a, n)));
    cout << res << endl;
    return 0;
}
