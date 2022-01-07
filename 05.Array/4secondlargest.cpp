// return the index of second largest in an array
#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 7, 6};
    int res = -1, largest = 0;
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[largest])
        {
            res = largest;
            largest = i;
        }
        else if (a[i] != a[largest])
        {
            if (res == -1 || a[i] > a[res])
                res = i;
        }
    }
    cout << "MAX=" << largest << "  "
         << "SECMAX=" << res << " " << endl;
    return 0;
}