// count 1s in sorted array
#include <iostream>
using namespace std;
int count1(int a[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == 0)
            low = mid + 1;
        else
        {
            if (mid == 0 || a[mid - 1] == 0)
                return (n - mid);
            else
                high = mid - 1;
        }
    }
    return 0;
}
int main()
{
    int a[] = {0, 0, 1, 1, 1, 1, 1};
    int n = 7;
    cout << count1(a, n);
    return 0;
}