// array implementation of stack in c
#include <stdlib.h>
#include <stdio.h>
#define MAX 6
typedef struct
{
    int data[MAX];
    int top;
} STACK;
int push(STACK *S, int val)
{
    if (S->top == MAX - 1)
    {
        printf("Overflow");
        return -1;
    }
    S->top++;
    S->data[S->top] = val;

    return 0;
}
int pop(STACK *S, int *val)
{
    if (S->top == -1)
    {
        printf("UNDERFLOW");
        return 1;
    }
    *val = S->data[S->top];
    S->top--;
    return 0;
}
int main()
{
    STACK S1;
    int V;
    S1.top = -1;
    int k = push(&S1, 10);
    k = pop(&S1, &V);
    if (k == 0)
    {
        printf("%d", V);
    }
    return 0;
}