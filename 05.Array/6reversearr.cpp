// Reverse an array
#include <iostream>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int low = 0;
        int high = n - 1;

        while (low < high)
        {
            int temp = 0;
            temp = a[low];
            a[low] = a[high];
            a[high] = temp;
            low++;
            high--;
            if (low == high)
                break;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}