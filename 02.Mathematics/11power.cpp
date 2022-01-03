// Find the power of  a given number when power and base are given
#include <iostream>
using namespace std;
int powern(int x, int y)
{
    // naive solution
    int res = 1;
    for (int i = 0; i < y; i++)
        res = res * x;
    return res;
}
int powern1(int x, int n)
{
    // efficient solution,TC-theta(log n),AS-theta(log n)
    if (n == 0)
        return 1;
    int temp = powern1(x, n / 2);
    temp = temp * temp;
    if (n % 2 == 0)
        return temp;
    else
        return temp * x;
}
int main()
{
    int x, y;
    cout << "Enter a power and base:      ";
    cin >> x >> y;
    cout << powern(x, y);
    cout << endl;
    cout << powern(x, y);
    return 0;
}