// find the majority occuring element index in the array
// Moore's voting algorithm
#include <iostream>
using namespace std;
int findmajority(int a[], int n)
{
    int count = 1, res = 0;
    for (int i = 1; i < n; i++) // find a canditate
    {
        if (a[res] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) // check the candidate if is actually a majority
        if (a[res] == a[i])
            count++;
    if (count <= n / 2)
        res = -1;

    return res;
}
int main()
{
    int arr[] = {8, 3, 4, 8, 8};
    int n = 5;
    cout << findmajority(arr, n);
    return 0;
}