// to find the given number is palindrome or not.
#include <iostream>
using namespace std;
bool ispal(int x)
{
    int rev = 0;
    int temp = x;
    while (temp > 0)
    {
        int ld = temp % 10;
        rev = rev * 10 + ld;
        temp /= 10;
    }
    return (rev == x);
}
int main()
{
    int n;
    cout << "Enter a integer: ";
    cin >> n;
    cout << endl
         << ispal(n);
}