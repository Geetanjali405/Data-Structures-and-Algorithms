// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void sortv(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();
    sortv(s);
    insert(s, temp);
    return;
}
void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    return;
}
void sort()
{
    // Your code here
    sortv(s);
}