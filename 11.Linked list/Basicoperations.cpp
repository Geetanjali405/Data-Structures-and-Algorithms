//Applications on single link list.
#include <bits/stdc++.h>
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

        if (head == NULL) //accesing a global variable
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

void insert_beg(struct node **head)
{
    int newele;
    cout << "Enter the element to insert at beginning.  ";
    cin >> newele;
    node *cur = new node(newele);
    cur->next = *head;
    *head = cur;    //created a link
    display(*head); //it works but still gonna avoid
}
void insert_end(struct node **head)
{
    int endele;
    cout << "Enter the element to insert at end.  ";
    cin >> endele;
    node *cur = new node(endele);
    tail->next = cur;
    tail = cur;
    display(*head);
}
void insert_pos(struct node **head)
{
    int pos, val, i;
    cout << "Enter a position on which you want to insert at: ";
    cin >> pos;
    cout << "Enter the value to be inserted at position " << pos << " : ";
    cin >> val;
    node *cur = new node(val);
    if (*head == NULL)
    {
        *head = cur;
    }
    else if (pos == 0 || pos == 1) //it inserts at the beginning
    {
        cur->next = *head;
        *head = cur;
    }
    else
    {
        node *ptr = *head;
        while (i < pos - 2 && ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
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
    display(*head);
}
void del_end(node **head)
{
    node *ptr = *head;
    if (*head == NULL)
    {
        cout << "Link list is empty!";
    }
    else if (((*head)->next) == NULL)
    {
        delete *head;
        cout << "The only element present in linked list was deleted! \n Link list empty." << endl;
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete (ptr->next);
        ptr->next = NULL;
        tail = ptr;
    }
    display(*head);
}
int search(node *head)
{
    int ele;
    cout << "Enter the element to search";
    cin >> ele;
    if (head == NULL)
        return -1;
    if (head->data == ele)
        return 1;
    else
    {
        int res = search(head->next);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}
int cnoe(node *head)
{
    int count = 0;
    node *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void search(node *head, node *tail)
{
    int ele, count = 0;
    node *cur;
    cout << "Enter the element to search";
    cin >> ele;

    if (tail->data != ele)
    {
        for (cur = head; cur != NULL; cur = (cur->next))
        {
            if (cur->data == ele)
            {
                cout << "Element found at position " << count + 1;
            }
            count++;
        }
    }
    else if (tail->data == ele)
    {
        cout << "Element found at position " << cnoe(head);
    }
    else
    {
        cout << "Element not found";
    }
}
int main()
{
    int n, i;
    cout << "Enter no. of elements.";
    cin >> n;
    create(n);          //creating a link list
    insert_beg(&head);  //inserting at beginning
    insert_end(&head);  //inserting at the end
    insert_pos(&head);  //inserting by position
    del_beg(&head);     //delete from beginnning
    del_end(&head);     //delete from end
    search(head, tail); //search in single link list
    //search(head);
    //cout << "Position of element in Linked List: " << search(head);

    return 0;
}