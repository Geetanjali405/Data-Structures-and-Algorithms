// index of first occurence
#include <iostream>
using namespace std;
int foc(int a[], int n, int x)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x > a[mid])
            low = mid + 1;
        else if (x < a[mid])
            high = mid - 1;
        else
        {
            if (mid == 0 || a[mid] != a[mid - 1])
                return mid;
            else
                high = mid - 1;
        }
    }
    return result;
}
// index of last occurence
int loc(int a[], int n, int x)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == a[mid])
        {
            result = mid;
            low = mid + 1;
        }
        else if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}
// index of no. of occurences
int noc(int a[], int n, int x)
{
    int first = foc(a, n, x);
    if (first == -1)
        return 0;
    else
        return (loc(a, n, x) - first + 1);
}
int main()
{
    int a[] = {1, 10, 10, 10, 10, 10, 20, 20, 40};
    int n = 9;
    int x;
    cout << "Enter a element to search.  ";
    cin >> x;
    cout << " FIRST OCCURENCE " << foc(a, n, x) + 1 << endl;
    cout << " LAST OCCURENCE " << loc(a, n, x) + 1 << endl;
    cout << "NO. OF OCCURENCES " << noc(a, n, x) << endl;
    return 0;
}