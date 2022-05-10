//insert at the beginning
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
} *head = NULL;
void insert_beg(node *beg)
{
    if (head == NULL)
    {
        head = beg;
    }
    else
    {
        beg->next = head;
        head = beg;
    }
}
void display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    head = new node(10);
    node *temp = new node(20);
    node *temp1 = new node(30);
    head->next = temp;
    head->next->next = temp1;
    cout << "INITIAL LINKED LIST. ";
    display(head);
    node *beg = new node(100);
    insert_beg(beg);
    cout << "AFTER INSERTING AT BEGINNING.";
    display(head);
    return 0;
}