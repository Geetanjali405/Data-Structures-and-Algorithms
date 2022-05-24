// reverse single linked list
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
} *head = NULL, *tail = NULL;
void display(struct node *head)
{
    node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
void create(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        int k;
        cout << "Enter element" << i + 1 << " ";
        cin >> k;
        node *cur = new node(k);

        if (head == NULL) // accesing a global variable
        {
            head = tail = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
        }
    }
    cout << "DISPLAYING THE LINKED LIST."
         << "\t";
    display(head);
}
void reverse(node **h)
{
    node *cur = *h;
    node *prv = NULL;
    while (cur != NULL)
    {
        node *next = cur->next;
        if (cur->next == NULL)
            (*h) = cur;
        cur->next = prv;
        prv = cur;
        cur = next;
    }
}
int main()
{
    create(5);
    reverse(&head);
    cout << "DISPLAYING THE REVERSED LINKED LIST."
         << "\t";
    display(head);
    return 0;
}