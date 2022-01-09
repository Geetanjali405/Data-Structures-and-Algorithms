// Binary search iterative in sorted array
// prerequisite -already sorted array
#include <iostream>
using namespace std;
int bsea(int a[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int n = 9;
    int a[] = {6, 8, 13, 21, 36, 47, 63, 81, 97};
    int x;
    cout << "Search element: ";
    cin >> x;
    cout << bsea(a, n, x);

    return 0;
}