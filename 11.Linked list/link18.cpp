// SWAP PAIRWISE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapPairs(ListNode *h)
    {
        if (h == NULL || h->next == NULL)
            return h;
        ListNode *cur = h->next->next;
        ListNode *prv = h;
        h = h->next;
        h->next = prv;

        while (cur != NULL && cur->next != NULL)
        {
            prv->next = cur->next;
            prv = cur;
            ListNode *next = cur->next->next;
            cur->next->next = cur;
            cur = next;
        }
        prv->next = cur;
        return h;
    }
};