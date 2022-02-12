#include <bits/stdc++.h>
using namespace std;

int lpartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[h]);
    return i;
}
void qsort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lpartition(arr, l, h);
        qsort(arr, l, p - 1);
        qsort(arr, p + 1, h);
    }
}
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = 7;
    // int arr[] = {8, 4, 7, 9, 3, 10, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, 0, n - 1);
    cout << "Displaying the sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}