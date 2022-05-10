//to reverse double link list.
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
    node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
} *head = NULL, *tail = NULL;
int main()
{
    int n, val;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> val;
        node *cur = new node(val);
        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
        }
    }
    cout << "DISPLAY. ";
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }

    //reverse the link list
    node *q;
    node *temp = NULL;
    for (q = head; q != NULL; q = q->prev)
    {

        temp = q->prev;
        q->prev = q->next;
        q->next = temp;
        if (q->prev == NULL)
            head = q;
    }
    cout << endl
         << "DISPLAYING REVERSED LINKED LIST " << endl;
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << "  ";
        p = p->next;
    }

    return 0;
}