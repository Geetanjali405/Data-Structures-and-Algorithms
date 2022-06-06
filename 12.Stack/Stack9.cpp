// max area of a rectangle in a histogram
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int MAH(vector<int> &a)
    {
        vector<int> v;
        stack<pair<int, int>> s;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if (s.size() > 0 && s.top().first < a[i])
            {
                v.push_back(s.top().second);
            }
            else if (s.size() > 0 && s.top().first >= a[i])
            {
                while (s.size() > 0 && s.top().first >= a[i])
                    s.pop();
                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top().second);
            }
            s.push({a[i], i});
        }

        vector<int> vr;
        stack<pair<int, int>> sr;
        for (int i = n - 1; i >= 0; i--)
        {
            if (sr.size() == 0)
            {
                vr.push_back(n);
            }
            else if (sr.size() > 0 && sr.top().first < a[i])
            {
                vr.push_back(sr.top().second);
            }
            else if (sr.size() > 0 && sr.top().first >= a[i])
            {
                while (sr.size() > 0 && sr.top().first >= a[i])
                    sr.pop();
                if (sr.empty())
                    vr.push_back(n);
                else
                {
                    vr.push_back(sr.top().second);
                }
            }
            sr.push({a[i], i});
        }
        reverse(vr.begin(), vr.end());

        vector<int> width(n);
        for (int i = 0; i < n; i++)
            width[i] = vr[i] - v[i] - 1;

        vector<int> area(n);
        for (int i = 0; i < n; i++)
            area[i] = a[i] * width[i];

        return *max_element(area.begin(), area.end());
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        int n = matrix.size();    // no. of rows
        int m = matrix[0].size(); // no. of columns

        vector<int> v;

        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == '1')
                v.push_back(1);
            else
                v.push_back(0);
        }
        int mx = MAH(v);
        cout << mx;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    v[j] = 0;
                else
                    v[j] += 1;
            }
            // cout<<endl<<v[0]<<"   "<<v[1];
            mx = max(mx, MAH(v));
        }
        return mx;
    }
};