// Time complexity- Theta(n) Auxilary Space-Theta(1)
#include <iostream>
using namespace std;
void reverse(int a[], int low, int high)
{
    while (low < high)
    {
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2; // rotate 2 times towards left
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    reverse(a, 0, n - 1);

    // printing the rotated array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}