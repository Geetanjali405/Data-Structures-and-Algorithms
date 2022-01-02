// to check if n is prime or not
#include <bits/stdc++.h>
using namespace std;
bool isprime1(int n)
{
    // Naive method
    if (n == 1)
        return false;
    else
    {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}
bool isprime2(int n)
{
    // Efficient way
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cout << "Enter a number:  ";
    cin >> n;
    if (isprime1(n))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    if (isprime2(n))
        cout << "YES";
    else
        cout << "NO";
}