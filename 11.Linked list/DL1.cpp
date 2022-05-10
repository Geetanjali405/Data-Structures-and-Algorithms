#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
    node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
} *head = NULL, *tail = NULL;
int main()
{
    node *head = new node(10);
    node *temp = new node(20);
    node *tail = new node(30);
    head->next = temp;
    temp->prev = head;
    temp->next = tail;
    tail->prev = temp;

    cout << head->data << "\t" << head->next->data << "\t" << head->next->next->data;
}