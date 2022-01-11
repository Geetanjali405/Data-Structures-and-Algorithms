// search in infinite sized array
// This algo is commonly known as unbounded binary search
// Time complexity= O(log(x))
#include <iostream>
using namespace std;
int binsearch(int arr[], int x, int low, int high)
{
    int res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}
int search(int arr[], int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
        i = i * 2;
    if (arr[i] == x)
        return i;
    return binsearch(arr, x, i / 2 + 1, i);
}
int main()
{
    int arr[] = {1, 10, 15, 20, 40, 60, 80, 100, 200, 500, 1000, 1100, 1234, 1250, 3400, 4500, 4700, 4900, 5000};
    int n = sizeof(arr) / sizeof(int);
    int x = 100;
    cout << search(arr, x);
    return 0;
}