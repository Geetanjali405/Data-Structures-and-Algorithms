#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
void qsort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        qsort(arr, l, p);
        qsort(arr, p + 1, h);
    }
}
int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = 8;
    qsort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}