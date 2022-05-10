#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;
int main()
{
    struct node *cur = NULL;
    for (int i = 0; i < 4; i++)
    {
        cur = malloc(sizeof(struct node));

        printf("Enter element %d : ", i + 1);
        scanf("%d", &cur->data);
       // printf("%d", cur->data);//debug successful^_^
        cur->next = NULL;

        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            (tail->next) = cur;
            tail = cur;
        }
    }
    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}