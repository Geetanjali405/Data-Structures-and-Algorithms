// finding two odd appearing numbers
// there will be atleast two numbers in input array
#include <bits/stdc++.h>
using namespace std;
void oddappear(int a[], int n)
{
    // Naive solution ,Time complexity->O(n^2)
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }
        if (count % 2 != 0)
            cout << a[i] << "   ";
    }
}
int main()
{
    int arr[10] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
    oddappear(arr, 10);
    return 0;
}