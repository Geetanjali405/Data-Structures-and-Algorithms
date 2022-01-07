// move all zeroes to end
// TC-o(n),AS-0(1)
#include <iostream>
using namespace std;
int main()
{
    int a[] = {8, 5, 0, 10, 0, 20};
    int n = sizeof(a) / sizeof(int);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            int temp = a[i];
            a[i] = a[count];
            a[count] = temp;
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}