// reverse a single linked list in groups of k
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
node *reverse(node **h, int k)
{
    node *cur = *h;
    node *prv = NULL;
    node *next = NULL;
    int count = 0;
    while (cur != NULL && count < k)
    {
        next = cur->next;
        cur->next = prv;
        prv = cur;
        cur = next;
        count++;
    }
    if (next != NULL)
    {
        node *rest_head = reverse(&next, k);
        (*h)->next = rest_head;
    }
    return prv;
}
int main()
{
    create(8);
    int k;
    cout << "Enter the value of k :";
    cin >> k;
    head = reverse(&head, k);
    cout << "DISPLAYING THE REVERSED LINKED LIST."
         << "\t";
    display(head);
    return 0;
}