// SIEVE OF ERATOSTHENES
// print all the smaller prime numbers than n
#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void printprimes(int n)
{
    // naive solution,TC->O(n* root(n))
    cout << "NAIVE METHOD" << endl;
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i))
            cout << i << "   ";
    }
}
void sieve(int n)
{
    cout << "SIEVE OF ERATOSTHENES" << endl;
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j = j + i)
                isprime[j] = false;
        }
    }
    for (int j = 2; j <= n; j++)
    {
        if (isprime[j])
            cout << j << "   ";
    }
}
int main()
{
    int n;
    cout << "Enter a number:      ";
    cin >> n;
    printprimes(n);
    cout << endl;
    sieve(n);
    return 0;
}