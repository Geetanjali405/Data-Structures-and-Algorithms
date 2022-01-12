// 3sum,with two pointer approach
// two pointer approach
// given a sorted array and a sum ,find if there is a pair with given sum
// T.C->O(n^2)+ {O(nlogn) if unsorted to sort}
#include <iostream>
using namespace std;
bool pair2(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
        if (arr[l] + arr[h] == x)
            return true;
        else if (arr[l] + arr[h] > x)
            h--;
        else
            l++;
    }
    return false;
}
bool sum3(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
        if (pair2(arr, i + 1, n - 1, sum - arr[i]))
            return true;

    return false;
}
int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int sum = 32;
    int n = 7;
    if (sum3(arr, n, sum))
        cout << "yes";
    else
        cout << "no";
    return 0;
}