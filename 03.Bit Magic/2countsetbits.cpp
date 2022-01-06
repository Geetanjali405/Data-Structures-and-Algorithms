// count set bits in an integer
// fr eg-Input-5(Binary reperesentation-101,2 set bits),Output-2
#include <iostream>
using namespace std;
int countset(int n)
{
    // naive solution.TC->Theta(TOTAL BITS IN N)
    int count = 0;
    while (n != 0)
    {
        if ((n & 1) == 1) // if(n%2!=0)
            count++;      // if stmt can also be replaced by count+= (n&1)
        n = n >> 1;       // n=n/2;
    }
    return count;
}
int countset1(int n)
{
    // Brian Kerningam's Algorithm
    // TC= Theta(set bit counts)
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1); // turning off the last set bit
                         // fr eg n=40, 1st iteration 40 &39=32
                         // 2nd iteration 32 &31=0;
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter a number.  ";
    cin >> n;
    cout << "NAIVE SOLUTION" << endl;
    cout << "No. of set bits = " << countset(n) << endl;
    cout << "OPTIMISED METHOD" << endl;
    cout << "No. of set bits = " << countset1(n) << endl;
    return 0;
}