// return the floor of square root of number .
#include <iostream>
using namespace std;
int squarer(int x)
{
    int low = 0, high = x, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int msq = mid * mid;
        if (msq == x)
            return mid;
        else if (msq > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main()
{
    int x = 8;
    cout << squarer(x);
    return 0;
}