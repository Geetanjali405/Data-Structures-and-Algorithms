// Merge function to sort an array

// Time complexity->O(n),Auxilary space->theta(n)

#include <iostream>
using namespace std;
void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[n1 + j];
    int i = 0, j = 0, k = 0;
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
int main()
{
    int a[] = {10, 20, 40, 20, 30};
    int n = 5; // size of array a
    int low = 0, mid = 2, high = 4;
    merge(a, low, mid, high);
    // sorted array
    for (int i = 0; i < 5; i++)
        cout << a[i] << "   ";
    return 0;
}