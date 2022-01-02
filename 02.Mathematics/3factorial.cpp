// Find the factorial of number.
#include <iostream>
using namespace std;
int iterative_fact(int n)
{
    // time complexity->theta(n),space complexity->theta(1)----This is better.
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}
int recursive_fact(int n)
{
    // time complexity->theta(n),space complexity->theta(n)
    if (n == 0)
        return 1;
    return n * recursive_fact(n - 1);
}
int main()
{
    int n;
    cout << "Enter a integer to find the factorial of: ";
    cin >> n;
    cout << endl
         << iterative_fact(n);
    cout << endl
         << recursive_fact(n);
    return 0;
}