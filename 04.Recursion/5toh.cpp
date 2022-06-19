// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // You need to complete this function
    long long count = 0;
    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int s, int d, int h)
    {
        // Your code here
        count++;
        if (n == 1)
        {
            cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
            return count;
        }
        toh(n - 1, s, h, d);
        cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
        toh(n - 1, h, d, s);
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T; // testcases
    while (T--)
    {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

// Position this line where user code will be pasted.  // } Driver Code Ends