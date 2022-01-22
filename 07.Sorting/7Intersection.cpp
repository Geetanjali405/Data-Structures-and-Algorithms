// INTERSECTION OF TWO SORTED ARRAYS
#include <iostream>
using namespace std;
void intersection(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout << a[i] << "   ";
            i++;
            j++;
        }
    }
}
int main()
{
    int a[] = {10, 20, 20, 40, 60};
    int m = 5; // size of array a
    int b[] = {2, 20, 20, 20};
    int n = 4;
    intersection(a, b, m, n);
    return 0;
}