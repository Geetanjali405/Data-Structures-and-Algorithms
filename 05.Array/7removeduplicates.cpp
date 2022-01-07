// remove duplicates in o(n) Time Complexity and in o(1) Auxilary Space
#include <iostream>
using namespace std;
int main()
{
    int a[] = {10, 20, 20, 30, 30, 30};
    int n = sizeof(a) / sizeof(int);
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[res - 1] != a[i])
        {
            a[res] = a[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}