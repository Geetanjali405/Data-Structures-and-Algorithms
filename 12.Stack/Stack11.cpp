// minimum element in stack in o(1) time
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    long long int min;
    stack<long long int> s;
    MinStack()
    {
    }

    void push(int valu)
    {
        long long val = valu;
        if (s.size() == 0)
        {
            s.push(val);
            min = val;
        }
        else
        {
            if (val >= min)
                s.push(val);
            else if (val < min)
            {
                long long int x = 2 * val - min;
                s.push(x);
                min = val;
            }
        }
    }

    void pop()
    {
        if (s.size() == 0)
            return;
        else
        {
            if (s.top() >= min)
                s.pop();
            else if (s.top() < min)
            {
                min = 2 * min - s.top();
                s.pop();
            }
        }
    }

    int top()
    {
        if (s.size() == 0)
            return -1;
        else
        {
            if (s.top() >= min)
                return s.top();
            else if (s.top() < min)
            {
                return min;
            }
        }
        return 0;
    }

    int getMin()
    {
        if (s.size() == 0)
            return -1;
        return min;
    }
};
