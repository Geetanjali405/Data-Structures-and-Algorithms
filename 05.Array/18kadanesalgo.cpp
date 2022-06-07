// maxsubarraysum or KADANES ALGORITHM
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int a[], int n)
    {

        // Your code here
        int c = 0;
        long long int res = a[0], best = 0, x;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
                c++;
        }
        if (c == n)
            return *max_element(a, a + n);
        int temp[n];
        temp[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            x = a[i];
            best = res;
            res = max(x, (x + res));
            temp[i] = res;
            //  cout<<res<<"\t"<<endl;
            // best+=res;
            // cout<<best<<endl;
        }
        return *max_element(temp, temp + n);
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends