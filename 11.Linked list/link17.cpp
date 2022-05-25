// INTERSECTION OF TWO SINGLE LINK LIST
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb)
    {
        int c1 = 0, c2 = 0;
        ListNode *ptr = NULL, *q = NULL, *cur = ha;
        while (cur->next != NULL)
        {
            cur = cur->next;
            c1++;
        }
        cur = hb;
        while (cur->next != NULL)
        {
            cur = cur->next;
            c2++;
        }
        int d = 0;
        if (c1 > c2)
        {
            d = c1 - c2;
            ptr = ha;
            q = hb;
        }

        else
        {
            d = c2 - c1;
            ptr = hb;
            q = ha;
        }

        if (d == 0)
        {
            if (ha == hb)
                return ha;
        }
        while (d--)
        {
            ptr = ptr->next;
        }
        if (ptr == q)
        {
            return ptr;
        }
        while ((ptr->next) != (q->next))
        {
            ptr = ptr->next;
            q = q->next;
        }
        return ptr->next;
    }
};