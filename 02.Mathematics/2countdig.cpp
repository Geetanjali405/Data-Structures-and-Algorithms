// given a number count the number of digits in a an integer.assume x>0
#include <iostream>
using namespace std;
int countdig(int x)
{
    int res = 0;
    while (x > 0)
    {
        x = x / 10;
        res++;
    }
    return res;
}
int main()
{
    int n;
    cout << "Enter a integer: ";
    cin >> n;
    int x = countdig(n);
    cout << endl
         << x;
    return 0;
}