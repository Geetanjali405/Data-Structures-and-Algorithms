// singal circular again
#include <stdlib.h>
#include <stdio.h>
struct node
{
    struct node *next;
    int data;
};
void createCLL(struct node **h)
{
    // 5nodes
    for (int i = 0; i < 5; i++)
    {
        int val;
        printf("Enter element %d : ", i + 1);
        scanf("%d", &val);
        struct node *ptr;
        struct node *cur = (struct node *)malloc(sizeof(struct node));
        cur->data = val;
        if (*h == NULL)
        {
            *h = ptr = cur;
            cur->next = *h;
        }
        else
        {
            ptr->next = cur;
            cur->next = (*h);
            ptr = cur;
        }
    }
}
void displayCLL(struct node *h)
{
    struct node *ptr = h;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != h);
}
void insertCLL(struct node **h)
{
    int pos, val;
    printf("Enter position to insert and value.  ");
    scanf("%d%d", &pos, &val);
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    cur->data = val;
    if (pos < 0)
        printf("INVALID! ");
    else if (pos == 0)
    {
        struct node *ptr = *h;
        while (ptr->next != (*h))
        {
            ptr = ptr->next;
        }
        cur->next = (*h);
        ptr->next = cur;
        (*h) = cur;
    }
    else
    {
        pos = pos % 5;
        struct node *ptr = *h;
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->next;
            //  if (ptr->next = (*h))
            //     break;
        }
        cur->next = ptr->next;
        ptr->next = cur;
    }
}
void del(struct node **h)
{
    int val;
    struct node *prev, *ptr = (*h);
    printf("Enter value. ");
    scanf("%d", &val);
    if ((*h) == NULL)
        printf("Empty Link List.");
    else
    {
        while (ptr->next != (*h) && ptr->data != val)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->data != val && ptr->next == (*h))
        {
            printf("Data not found\n");
        }
        else if ((*h) == (*h)->next)
        {
            (*h) == NULL;
            free(ptr);
        }
        else if (ptr == (*h))
        {
            /*struct node *temp = *h;
            while (temp->next != (*h))
            {
                temp = temp->next;
            }
            (*h) = (*h)->next;
            temp->next = (*h)->next;
            free(ptr);*/
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
    struct node *head = NULL;
    createCLL(&head);
    // insertCLL(&head);
    del(&head);
    displayCLL(head);
    return 0;
}