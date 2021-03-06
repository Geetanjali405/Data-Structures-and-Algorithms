// palindrome linked list
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *rest_head = reverseList(head->next);
        ListNode *rest_tail = head->next;
        rest_tail->next = head;
        head->next = NULL;
        return rest_head;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = reverseList(slow->next);
        ListNode *curr = head;
        while (rev != NULL)
        {
            if (rev->val != curr->val)
                return false;
            rev = rev->next;
            curr = curr->next;
        }
        return true;
    }
};