// Double circular
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void createDC(struct node **h)
{
    struct node *cur;

    for (int i = 0; i < 5; i++)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        cur->next = cur->prev = NULL;
        int val;
        printf("Enter element %d : ", i + 1);
        scanf("%d", &val);
        cur->data = val;
        if ((*h) == NULL)
        {
            (*h) = cur->next = cur->prev = cur;
        }
        else
        {
            cur->prev = (*h)->prev;
            cur->next = (*h);
            (*h)->prev->next = cur;
            (*h)->prev = cur;
        }
    }
}
void displayDC(struct node *h)
{
    struct node *ptr = h;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != h);
}
void insertDC(struct node **h)
{
    int pos, val;
    printf("Enter position to insert and value.  ");
    scanf("%d%d", &pos, &val);
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur->data = val;
    if (pos < 0)
        printf("INVALID");
    else if (pos == 0)
    {
        cur->prev = (*h);
        cur->next = (*h);
        (*h)->prev->next = cur;
        (*h)->prev = cur;
        (*h) = cur;
    }
    else
    {
        struct node *ptr = (*h);
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->next == (*h))
        {
            cur->prev = (*h)->prev;
            cur->next = (*h);
            (*h)->prev = cur;
            ptr->next = cur;
        }
        else
        {
            cur->prev = ptr;
            cur->next = ptr->next;
            cur->prev->next = cur;
            cur->next->prev = cur;
        }
    }
}
void delDC(struct node **h)
{
    int val;
    struct node *ptr = (*h);
    printf("Enter value. ");
    scanf("%d", &val);
    if ((*h) == NULL)
        printf("Empty Link List.");
    else
    {
        while (ptr->next != (*h) && ptr->data != val)
        {
            ptr = ptr->next;
        }
        if (ptr->data != val && ptr->next == (*h))
        {
            printf("Data not found\n");
        }
        else if ((*h) == (*h)->next && (*h) == (*h)->prev)
        {
            (*h) == NULL;
            free(ptr);
        }
        else if (ptr == (*h))
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            (*h) = ptr->next;
            free(ptr);
        }
        else
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            free(ptr);
        }
    }
}
int main()
{
    struct node *head = NULL;
    createDC(&head);
    // insertDC(&head);
    delDC(&head);
    displayDC(head);
}