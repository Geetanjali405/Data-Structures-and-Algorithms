// find the peak element in array(element is not smaller than the neighbour elements)
// Time complexity->O(logn)
#include <iostream>
using namespace std;
int peak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == (n - 1) || arr[mid + 1] <= arr[mid]))
            return mid;
        if (mid > 0 && arr[mid + 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {10, 20, 15, 5, 90, 67};
    int n = 6;
    cout << arr[peak(arr, n)];
    return 0;
}