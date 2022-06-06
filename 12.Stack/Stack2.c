// linkedlist implementation of stack in c
#include <stdlib.h>
#include <stdio.h>
struct node
{
    int val;
    struct node *next;
};
typedef struct
{
    struct node *top;
} STACK;
int push(STACK *, int);
int pop(STACK *, int *);
void init(STACK *);
void init(STACK *S)
{
    S->top = NULL;
}
int push(STACK *S, int v)
{
    struct node *cur = (struct node *)malloc(sizeof(int));
    if (cur == NULL)
    {
        printf("OVERFLOW");
        return 1;
    }
    cur->val = v;
    cur->next = S->top;
    S->top = cur;
    return 0;
}
int pop(STACK *S, int *data)
{
    if (S->top == NULL)
    {
        printf("UNDERFLOW");
        return 1;
    }
    struct node *ptr;
    ptr = S->top;
    S->top = S->top->next;
    *data = ptr->val;
    free(ptr);
    return 0;
}
int main()
{
    STACK S1;
    int t;
    init(&S1);
    int k = push(&S1, 10);
    int h = pop(&S1, &t);
    if (h == 0)
        printf("%d", t);
    return 0;
}