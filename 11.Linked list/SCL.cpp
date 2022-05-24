// create a single circular linked list
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
} *head = NULL, *tail = NULL;
int main()
{
    int n, x;
    struct node *p;
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
            head->next = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
            tail->next = head;
        }
    }
    node *curr = head;
    cout << "DISPLAY" << endl;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}