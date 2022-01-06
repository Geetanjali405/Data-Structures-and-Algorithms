// count set bits in an integer(0-255)
// fr eg-Input-5,Output-2
// Lookup table method for counting 32 bit numbers.(some preprocessing is done beforehand)
// divide 32 bit in 4 chunck of 8 bits  i.e. 0 to 2^7-1=256
/* TC=THETA(1)*/
#include <bits/stdc++.h>
using namespace std;

int table[256];

// recursive function to count set bits
void initialize()
{

    // To initially generate the table algorithmically:
    table[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        table[i] = (i & 1) + table[i / 2];
    }
}

int countSetBits(int n)
{
    return table[n & 0xff] +
           table[(n >> 8) & 0xff] +
           table[(n >> 16) & 0xff] +
           table[n >> 24];
    // 0xff is the hexadecimal representation of 8 set bits.
}

/* Program to test function countSetBits */
int main()
{
    initialize();
    int n = 5;
    cout << countSetBits(n);
    return 0;
}