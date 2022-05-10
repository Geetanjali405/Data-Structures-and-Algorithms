#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x) //parametric constructor called
    {
        data = x;
        next = NULL;
    }
};
node *head = NULL;
node *tail = NULL;

int main()
{
    node *head = new node(10);
    node *temp = new node(20);
    node *temp1 = new node(30);
    head->next = temp;
    head->next->next = temp1;

    cout << head->data << " " << temp->data << " " << temp1->data;
    return 0;
}