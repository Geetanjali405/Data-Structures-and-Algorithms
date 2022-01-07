// median of two sorted arrays
//  { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        // Your code goes here
        vector<double> v;
        int n = array1.size();
        int m = array2.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back(array1[i]);
        }
        for (int i = n, j = 0; i <= m + n, j < m; i++, j++)
        {
            v.push_back(array2[j]);
        }
        int num = v.size();
        sort(v.begin(), v.end());
        if (num % 2 != 0)
            return (v[num / 2]);
        if (num % 2 == 0)
            return (((v[num / 2 - 1] + v[num / 2]) / 2));
        return 0.0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}

// } Driver Code Ends