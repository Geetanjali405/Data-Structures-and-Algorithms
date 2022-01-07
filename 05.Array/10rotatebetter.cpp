// time complexity-theta(n+d)~theta(n),auxilary space-theta(d)
#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    int d = 2; // rotate 2 times towards left
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = a[i];
    for (int i = d; i < n; i++)
        a[i - d] = a[i];
    for (int i = 0; i < d; i++)
        a[n - d + i] = temp[i];

    // printing the rotated array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}