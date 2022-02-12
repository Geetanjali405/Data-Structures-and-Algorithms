#include <bits/stdc++.h>
using namespace std;
void lpartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[h]);
}
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = 7;
    lpartition(arr, 0, n - 1);
    cout << "Displaying the partitioned array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}