// To find lcm of two numbers.
// using euclidiean algorithm
#include <bits/stdc++.h>
using namespace std;
int lcm1(int a, int b)
{
    // This was the naive approach.Time complexity O(a*b-max(a,b)).
    int res = max(a, b);
    while (true)
    {
        if (res % a == 0 && res % b == 0)
        {
            break;
        }
        res++;
    }
    return res;
}
int gcd(int a, int b)
{
    // Euclidean algorithm(optimised)
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm2(int a, int b)
{
    // T.C. -O(log(min(a,b)))
    return (a * b) / gcd(a, b);
}
int main()
{
    int a, b;
    cout << "Enter two numbers to find GCD or HCF of:    ";
    cin >> a >> b;
    cout << "LCM: " << lcm1(a, b) << endl;
    cout << "LCM: " << lcm2(a, b) << endl;
}