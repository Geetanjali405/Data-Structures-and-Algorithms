// { Driver Code Starts
// Initial Template for C++
// LARGEST ELEMENT IN AN ARRAY-Help a theif problem in GFG PRACTICE .
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxCoins(int A[], int B[], int T, int N)
    {
        int coins = 0;
        for (int j = 0; j < T; j++)
        {
            int max = B[0], index = 0;
            for (int i = 0; i < N; i++)
            {
                if (B[i] > max)
                {
                    max = B[i];
                    index = i;
                }
            }
            if (A[index] != 0)
            {
                coins += max;
                A[index]--;
            }
            if (A[index] == 0)
            {
                B[index] = 0;
            }
        }
        return coins;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int T = 3, N = 3;
        //  cin >> T >> N;

        //  int A[N], B[N];
        int A[3] = {1, 2, 3};
        int B[3] = {3, 2, 1};

        Solution ob;
        cout << ob.maxCoins(A, B, T, N) << endl;
    }
    return 0;
} // } Driver Code Ends
