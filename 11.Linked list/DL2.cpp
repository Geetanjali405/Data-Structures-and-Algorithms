#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
    node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
} *head = NULL, *tail = NULL;
void create()
{
    int n;
    cout << "Enter number of nodes. ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the value of element " << i + 1 << " ";
        cin >> x;
        node *cur = new node(x);
        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            cur->prev = tail;
            tail->next = cur;
            tail = cur;
        }
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
    cout << endl
         << "No. of elements in linked list. " << count << endl;
    return count;
}
void display()
{
    cout << "Displaying link list" << endl;
    struct node *ptr = head;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->data << " ";
    }
    cout << endl;
}
void insert_beg()
{
    int x;
    cout << "\nEnter the value to insert at beginning. ";
    cin >> x;
    node *cur = new node(x);
    if (head == NULL)
    {
        head = tail = cur;
    }
    else
    {
        cur->next = head;
        head->prev = cur;
        head = cur;
    }
    display();
}
void insert_end()
{
    int x;
    cout << "\nEnter the value to insert at end. ";
    cin >> x;
    node *cur = new node(x);
    if (head == NULL)
    {
        head = tail = cur;
    }
    else
    {
        cur->prev = tail;
        tail->next = cur;
        tail = cur;
    }
    display();
}
void insert_pos()
{
    int pos, val, i;
    cout << "Enter position at which you want to insert.";
    cin >> pos;
    if (pos == 1)
    {
        insert_beg();
    }
    else
    {
        cout << "Enter the value to insert at position " << pos << " : ";
        cin >> val;
        node *temp = new node(val);
        node *ptr = head;

        while (i < (pos - 1) && ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        temp->prev = ptr->prev;
        temp->next = ptr;
        ptr->prev->next = temp;
        ptr->prev = temp;

        display();
    }
}
int search()
{
    int val, res;
    cout << "Enter the value to search. ";
    cin >> val;
    node *ptr = head;
    int pos = 1;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == val)
        {
            cout << "Element fount at " << pos;
            return 0;
        }
        else
        {
            pos++;
            res = 1;
        }
    }
    // else
    cout << "Element not found.";
    return -1;
}
void del_beg()
{
    node *ptr = head;
    head = head->next;
    delete ptr;
    cout << "\nAFTER DELETING THE BEGINNING\n";
    display();
    // cout << endl;
    //  cout << tail->data << endl;

    //  cout << tail->prev->data << endl;
}
void del_end()
{
    node *ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete ptr;
    cout << "\nAFTER DELETING THE END\n";
    display();
}
void del_pos()
{
    int pos, i;
    cout << "Enter the position of the value you want to delete. ";
    cin >> pos;
    node *ptr;
    for (i = 0, ptr = head; i < pos - 1 && ptr != NULL; i++, ptr = ptr->next)
        ;
    //cout << ptr->data;
    if (ptr->next == NULL)
    {
        del_end();
    }
    else
    {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        delete ptr;
        cout << "\nAFTER DELETION. \n";
        display();
    }
}

int main()
{

    create();  //creating double link list
    display(); //display link list
               // insert_beg(); //insert at beginning
               //  insert_end(); //insert at end
               //   insert_pos(); //insert a position
               //  int y = cnoe(head);
    //cout << y;
    //search();
    //del_beg();
    //del_pos();
    //del_end();
    return 0;
}
