//printing a link list using recurssion
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
void rprint(node *head)
{
    if (head == NULL)
        return;
    cout << head->data << "  ";
    rprint(head->next);
}
int main()
{
    node *head = new node(89);
    node *temp = new node(90);
    node *temp1 = new node(900);
    head->next = temp1;
    head->next->next = temp;
    rprint(head);
    // return 0;
}