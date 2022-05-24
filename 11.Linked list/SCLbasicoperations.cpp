// insert in a single circular position (beginning ,end ,at amy position)
#include <iostream>
using namespace std;
int n;
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

void createSCL(int n)
{
    int x;
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
}
void display(node *h)
{
    if (h == NULL)
    {
        cout << "Link list is empty!";
        return;
    }
    node *curr = h;
    cout << endl
         << "DISPLAY" << endl;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != h);
}
void insert_beg(struct node **head)
{
    int newele;
    cout << "Enter the element to insert at beginning.  ";
    cin >> newele;
    node *cur = new node(newele);
    cur->next = *head;
    *head = cur; // created a link
    tail->next = (*head);
    display(*head); // it works but still gonna avoid
}
void insert_end(struct node **head)
{
    int endele;
    cout << "Enter the element to insert at end.  ";
    cin >> endele;
    node *cur = new node(endele);
    tail->next = cur;
    tail = cur;
    tail->next = (*head);
    display(*head);
}
void insert_pos(struct node **head)
{
    int pos, val, i = 0;
    cout << "Enter a position on which you want to insert at: ";
    cin >> pos;
    cout << "Enter the value to be inserted at position " << pos << " : ";
    cin >> val;
    node *cur = new node(val);
    if (*head == NULL)
    {
        tail = *head = cur;
        cur->next = (*head);
    }
    else if (pos == 0 || pos == 1) // it inserts at the beginning
    {
        cur->next = *head;
        *head = cur;
        tail->next = (*head);
    }
    else if (pos == 2)
    {
        cur->next = (*head)->next;
        (*head)->next = cur;
    }
    else
    {
        node *ptr = *head;
        do
        {
            ptr = ptr->next;
            i++;
        } while (i < pos - 2 && ptr != *head);
        cur->next = ptr->next;
        ptr->next = cur;
    }
    display(*head);
}
void del_beg(node **head)
{
    node *prv = *head;
    *head = (*head)->next;
    delete prv;
    tail->next = (*head);
    display(*head);
}
void del_end(node **head)
{
    node *ptr = *head;
    if (*head == NULL)
    {
        cout << "Link list is empty!";
    }
    else if (((*head)->next) == (*head))
    {
        delete *head;
        cout << "The only element present in linked list was deleted! \n Link list empty." << endl;
        return;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            ptr = ptr->next;
        }
        node *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
        display(*head);
    }
}
int main()
{

    cout << "Enter the number of nodes required.  ";
    cin >> n;
    createSCL(n);
    display(head);
    // insert_beg(&head); // inserting at beginning
    // insert_end(&head); // inserting at the end
    // insert_pos(&head); // inserting by position
    // del_beg(&head); // delete from beginnning
    del_end(&head); // delete from end

    return 0;
}