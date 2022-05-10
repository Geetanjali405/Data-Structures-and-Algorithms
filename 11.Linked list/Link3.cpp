// read and display the content of linked list
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
};
node *head = NULL;
void display(struct node *h)
{
    node *cur = h;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}
/*void display(struct node **h)
{
    while (*h != NULL)
    {
        cout << (*h)->data << " ";
        (*h) = (*h)->next;
    }
}*/
int main()
{
    node *head = new node(67);
    node *temp = new node(678);
    node *temp1 = new node(90);
    head->next = temp;
    head->next->next = temp1;
    // cout << head->data;
    // display(&head);
    //  cout << head->data << "          ";
    //   cout << head->data << temp->data << temp1->data;
    // cout << head->data << head->next->data << head->next->next->data;
    display(head);
}