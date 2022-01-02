// To find gcd or hcf of two numbers.
// using euclidiean algorithm
#include <bits/stdc++.h>
using namespace std;
int gcd1(int a, int b)
{
    // This was the naive approach.Time complexity o(min(a,b)).
    int res = min(a, b);
    while (res > 0)
    {
        if (a % res == 0 && b % res == 0)
        {
            break;
        }
        res--;
    }
    return res;
}
int gcd2(int a, int b)
{
    // Euclidean algorithm(but not optimised)
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
int gcd3(int a, int b)
{
    // Euclidean algorithm but optimised
    if (b == 0)
        return a;
    else
        return gcd3(b, a % b);
}
int main()
{
    int a, b;
    cout << "Enter two numbers to find GCD or HCF of:    ";
    cin >> a >> b;
    cout << "GCD: " << gcd1(a, b) << endl;
    cout << "GCD: " << gcd2(a, b) << endl;
    cout << "GCD: " << gcd3(a, b) << endl;
}