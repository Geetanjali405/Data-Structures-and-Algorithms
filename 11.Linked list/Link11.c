// single circular link list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void displayCLL(struct node *head)
{
    struct node *ptr;
    if (head != NULL)
    {
        ptr = head;
        while (ptr->next != head)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d  ", ptr->data);
    }
}
void insertCLL(struct node **h)
{
    int pos, val;
    struct node *p = *h;
    printf("Enter position and value of element : ");
    scanf("%d%d", &pos, &val);
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur->data = val;
    if (p == NULL)
    {
        (*h) = cur;
        cur->next = (*h);
    }
    else if (pos == 0)
    {
        while (p->next != (*h))
        {
            p = p->next;
        }
        p->next = cur;
        cur->next = (*h);
        *h = cur;
    }
    else
    {
        // pos %= 5;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        cur->next = p->next;
        p->next = cur;
    }
}
void delval(struct node **h)
{
    int val;
    struct node *ptr, *prev;
    printf("Enter value to be deleted : ");
    scanf("%d", &val);
    if ((*h) == NULL)
    {
        printf("Empty Link List.\n");
    }
    else
    {
        ptr = *h;
        while (ptr->data != val && ptr->next != (*h))
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == (*h) && ptr->data != val)
        {
            printf("Data not found!\n");
        }
        else if ((*h) == (*h)->next)
        {
            (*h) == NULL;
            free(ptr);
        }
        else if (ptr == (*h))
        {
            struct node *temp = (*h);
            while (temp->next != (*h))
            {
                temp = temp->next;
            }
            (*h) = ptr->next;
            temp->next = (*h);
            free(ptr);
        }
        else
        {
            prev->next = ptr->next;
            free(ptr);
        }
    }
}
int main()
{
    struct node *head = NULL, *ptr;
    //  createCLL(&head);
    for (int i = 0; i < 5; i++)
    {
        int x;
        struct node *cur = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d :", i + 1);
        scanf("%d", &x);
        cur->data = x;
        cur->next = NULL;
        if (head == NULL)
        {
            head = ptr = cur;
            cur->next = head;
        }
        else
        {
            cur->next = head;
            ptr->next = cur;
            ptr = cur;
        }
    }

    // insertCLL(&head);
    delval(&head);
    displayCLL(head);

    return 0;
}