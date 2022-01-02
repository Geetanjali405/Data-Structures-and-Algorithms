// To print all the dividors of the given number
#include <iostream>
using namespace std;
void printdiv(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << "   ";
}
void printdiv1(int n)
{
    // efficient ,TC-O(n^1/2)
    /*// doesnt print in order.
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << "   ";
            if (i != n / i)
                cout << n / i << "   ";
        }
    }*/
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            cout << i << "   ";
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
            cout << n / i << "   ";
    }
}
int main()
{
    int n;
    cout << "Enter a number:      ";
    cin >> n;
    printdiv(n);
    cout << endl;
    printdiv1(n);
    return 0;
}