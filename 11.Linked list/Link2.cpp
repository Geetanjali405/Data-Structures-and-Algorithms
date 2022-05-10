#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x) //PARAMETRIC CONSTRUCTOR CALL
    {
        data = x;
        next = NULL;
    }
};
node *head = NULL;

int main()
{
    node *head = new node(7);
    node *temp = new node(67);
    node *temp1 = new node(78);

    head->next = temp1;
    head->next->next = temp;

    cout << head->data << " " << temp->data << " " << temp1->data;

    return 0;
} //short implementation