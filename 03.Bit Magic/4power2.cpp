// to find if the number is a power of 2 or not .- for eg.input-4,output-yes
#include <iostream>
using namespace std;

bool isPow2(int n)
{
    // naive method
    if (n == 0)
        return true;
    while (n != 1)
    {
        if (n % 2 != 0)
            return false;
        n = n / 2;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number.  ";
    cin >> n;
    isPow2(n) ? cout << "true" : cout << "false";
}
/*
if(n==0)
return false;
//power of 2 has only 1 set bit so using brian kerningam's algo n&(n-1)will return 0
return (n&(n-1)==0);
*/
/*
//one line solution
return (n!=0)&&(n&(n-1)==0) //OPTIMISED
*/