// binary search recursive code
#include <iostream>
using namespace std;
int bsea(int a[], int n, int x, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] == x)
        return mid;
    else if (a[mid] > x)
        return bsea(a, n, x, low, mid - 1);
    else
        return bsea(a, n, x, mid + 1, high);
}
int main()
{
    int n = 9;
    int a[] = {6, 8, 13, 21, 36, 47, 63, 81, 97};
    int x;
    cout << "Search element: ";
    cin >> x;
    int low = 0, high = n - 1;
    cout << bsea(a, n, x, low, high);
    bsea(a, n, x, low, high);
    return 0;
}