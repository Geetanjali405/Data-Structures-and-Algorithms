/*
Bitwise operators (they work on binary representation of operators)--
1) AND(&)-produces 1 only if both input bit is 1
2) OR(:)-produces 1 when either of input is 1
3) XOR(^)*-produces 1 when both input bits are different.
4) LEFT SHIFT OPERATOR(<<)-add 'n' no. of zeroes at the end of binary reperesentation for n no. of shifts.
    If we assume that rhe leading y bits are 0 ,then result of (x<<y) is equivalent for x*2^y.
5) RIGHT SHIFT OPERATOR(>>)-remove n no. of bits from end for n no. of shifts.
    x>>y is equivalent to floor of x/2^y.
6) BITWISE NOT(~)-it is unary not operator inverts all the bits in binary representation of a number .
signed int no. negative no. is stired in 2s complement it allows us to have one representation of zeroes
and a larger range of values ,in 1s complement we will have 2 representation of zero (-ve and +ve)

*/
#include <iostream>
using namespace std;
int main()
{
    int x = 3, y = 6;
    unsigned int p = 1, q = 5; // unsigned -> all the numbers represented by this data type (unsigned) is 0 or positives
                               // for 32 bit rep,(~ (of 0) will do all 1's->32 '1' ->2^32 -1->4294967295(maximum value we can represent) ) ;
    signed int z = 1, w = 5;   // signed int , range -2^31(represented as 1 followed by all zeroes) to  2^31 -1  ; genrally represented in 2s complement of x
                               // in n bits representation 2's complement of x is 2^n -x and output is -x
                               // Leading bit is the "sign " bit(if leading bit is 1->its a negative number)
    cout << (x & y) << endl;
    cout << (x | y) << endl;
    cout << (x ^ y) << endl;
    cout << (x << 1) << endl; // 3(011)->(110)added 1 "0" at the end.
    cout << (x >> 1) << endl; // 3(001)->removed 1 bit from the end.
    cout << (~p) << endl;
    cout << (~q) << endl;
    cout << (~z) << endl; //(2^32 -1-1) = (2^32 -x) => equating we get output = -1-1=-2
    cout << (~w) << endl; //(2^32 -1-5) = (2^32 -x) => equating we get output = -1-5=-6
    return 0;
}