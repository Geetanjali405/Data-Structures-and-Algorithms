#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
int createLL(struct node **h)
{
    int n;
    struct node *p;
    printf("Enter the number of elements in DLL: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        struct node *cur = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d :", i + 1);
        scanf("%d", &x);
        cur->data = x;
        if ((*h) == NULL)
        {
            (*h) = p = cur;
        }
        else
        {
            p->next = cur;
            cur->prev = p;
            p = cur;
        }
    }
    return n;
}
void displayLL(struct node *h)
{
    while (h != NULL)
    {
        printf("%d  ", h->data);
        h = h->next;
    }
}
void insert(struct node **h, int n)
{
    int pos, val;
    struct node *p = *h;
    printf("Enter position and value of element : ");
    scanf("%d%d", &pos, &val);
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur->data = val;
    if (pos < 1)
        printf("INVALID POSITION TRY AGAIN ");
    else if (pos == 1)
    {
        p->prev = cur;
        cur->next = p;
        *h = cur;
    }
    else if (pos > 1 && pos <= n)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        cur->prev = p->prev;
        cur->next = p;
        p->prev->next = cur;
        p->prev = cur;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        cur->prev = p;
        p->next = cur;
    }
}
void delpos(struct node **h, int n)
{
    int pos;
    struct node *p = *h;
    printf("Enter position to delete : ");
    scanf("%d", &pos);
    if (pos < 1 && pos > n)
        printf("INVALID\n");
    if (pos == n)
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
    }
    if (pos == 1)
    {
        *h = p->next;
        free(p);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}
void delval(struct node **h, int n)
{
    int val;
    printf("Enter value to delete : ");
    scanf("%d", &val);
    struct node *p = *h;
    for (int i = 0; i < n; i++)
    {
        if (p->data == val)
        {
            /* code */
            if (p == (*h))
            {
                *h = p->next;
                free(p);
            }
            else if (p->next == NULL)
            {
                p->prev->next = NULL;
                free(p);
                // p->prev->next == NULL;
            }
            else
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                free(p);
            }
        }

        else
            p = p->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n = createLL(&head);
    // displayLL(head);
    // insert(&head, n);
    delval(&head, n);
    // delpos(&head, n);
    displayLL(head);
    return 0;
}