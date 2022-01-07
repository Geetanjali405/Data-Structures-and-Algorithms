// To find maximum value of arr[j]-arr[i] such that j>i

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxDiffIndex(int A[], int N)
    {
        if (N == 0)
        {
            int diff = 0;
            return diff;
        }
        int mini = A[0];
        int diff = A[1] - A[0];
        for (int i = 1; i < N; i++)
        {
            diff = max(diff, A[i] - mini);
            mini = min(mini, A[i]);
        }
        return diff;
    }
};

// { Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxDiffIndex(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends