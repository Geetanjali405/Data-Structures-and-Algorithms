// Find the number of trailing zeroes in factorial of a number
#include <iostream>
using namespace std;
int count(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i = i * 5)
        res = res + (n / i);
    return res;
}
int main()
{
    int n;
    cout << "Enter a number(We'll find the number of zeroes in its factorial):     ";
    cin >> n;
    cout << endl
         << count(n);
    return 0;
}
//