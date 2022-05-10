//enter at pos
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
} *head = NULL, *tail = NULL;
int size(node *head)
{
    int count = 0;
    for (; head != NULL; head = head->next)
    {
        count++;
    }
    //cout << count;
    return count;
}
int main()
{
    int n, x, ele, pos;
    cout << "Enter the number of nodes required.  ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element : ";
        cin >> x;
        node *cur = new node(x);
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
    node *cur;
    cout << "DISPLAY" << endl;
    for (cur = head; cur != NULL; cur = cur->next)
    {

        cout << cur->data << "  ";
    }
    /*  cout << endl;
    cout << "size : " << size(head) << endl;
    cout << "head->data : " << head->data;*/
    cout << endl;
    cout << "Enter the position for insertion: ";
    cin >> pos;
    cout << " Enter the element: ";
    cin >> ele;
    node *temp = new node(ele);
    node *ptr = head;
    if (pos < 1)
    {
        cout << "INVALID POSITION.";
    }
    if (pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (pos >= size(head) + 1)
    {
        tail->next = temp;
        temp->prev = NULL;
        tail = temp;
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            ptr = ptr->next;
        }

        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
    cout << "AFTER INSERTING : ";
    for (cur = head; cur != NULL; cur = cur->next)
    {

        cout << cur->data << "  ";
    }
    return 0;
}