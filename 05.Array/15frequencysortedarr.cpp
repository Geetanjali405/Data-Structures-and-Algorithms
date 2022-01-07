// print the frequency of the sorted array
#include <iostream>
using namespace std;
int main()
{
    int a[] = {10, 15, 15, 20, 20, 30};
    int n = 6;
    int i = 1, freq = 1;
    while (i < n)
    {
        while (i < n && a[i] == a[i - 1])
        {
            freq++;
            i++;
        }
        cout << a[i - 1] << ": Frequency :" << freq << endl;
        i++;
        freq = 1;
    }
    if (n == 1 || a[n - 1] != a[n - 2])
        cout << a[i - 1] << ": Frequency :" << 1 << endl;
    return 0;
}