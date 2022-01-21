// merge sort algorithm
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            k++;
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = left[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r)
{
    if (r > l) // Atleast 2 elements
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int n;
    cout << "Enter the no. of elements in the array.  ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int low = 0, high = n - 1;
    mergesort(a, low, high);
    // sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << "   ";
    return 0;
}