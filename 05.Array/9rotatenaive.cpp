// rotate an array
//  { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// NAIVE method
//  } Driver Code Ends
class Solution
{

public:
    void leftRotate(int arr[], int k, int n)
    {
        // Your code goes here
        for (int j = 0; j < k; j++)
        {
            int temp = arr[0];
            for (int i = 1; i < n; i++)
                arr[i - 1] = arr[i];
            arr[n - 1] = temp;
        }
    }
};
// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.leftRotate(a, k, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends