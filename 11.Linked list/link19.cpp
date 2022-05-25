// CLONE A LINKED LIST(with same next and random pointers)
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> hm;
        for (Node *curr = head; curr != NULL; curr = curr->next)
            hm[curr] = new Node(curr->val);

        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            Node *cloneCurr = hm[curr];
            cloneCurr->next = hm[curr->next];
            cloneCurr->random = hm[curr->random];
        }
        Node *head2 = hm[head];

        return head2;
        /*      Node *next,*temp;
         for(Node *curr=head;curr!=NULL;){
             next=curr->next;
             curr->next=new Node(curr->val);
             curr->next->next=next;
             curr=next;
         }
         for(Node *curr=head;curr!=NULL;curr=curr->next->next){
             curr->next->random=(curr->random!=NULL)?(curr->random->next):NULL;
         }

         Node* original = head, *copy = head->next;
         temp = copy;

         while (original && copy)
         {
             original->next = original->next ? original->next->next : original->next;
             copy->next = copy->next?copy->next->next:copy->next;
             original = original->next;
             copy = copy->next;
         }

         return temp;   */
    }
};