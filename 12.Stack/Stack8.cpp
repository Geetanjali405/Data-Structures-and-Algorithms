// max area of histogram
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
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

        /* for(int i=0;i<n;i++)
            cout<<vr[i]<<"   ";
         cout<<endl;
         for(int i=0;i<n;i++)
           cout<<v[i]<<"   ";
           // vr[i]=vr[i]-v[i]-1;
         cout<<endl;

         for(int i=0;i<n;i++)
           cout<<width[i]<<"     ";

         cout<<endl;

         for(int i=0;i<n;i++)
           cout<<area[i]<<"     ";
         */
        return *max_element(area.begin(), area.end());
    }
};