// polynomial using link list-lecture10-&A8%nA5%
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int exp;
    int coef;
    struct node *next;
};
void create(struct node **h)
{
    int nt;
    struct node *cur, *ptr;
    printf("Enter number of terms. ");
    scanf("%d", &nt);
    for (int i = 0; i < nt; i++)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of term %d : ", i + 1);
        scanf("%d%d", &cur->coef, &cur->exp);
        cur->next == NULL;
        if (*h == NULL)
        {
            *h = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    } // end of for loop
} // end of function create
void join(struct node **h1, struct node *h2)
{
    if (*h1 == NULL)
        *h1 = h2;
    else
    {
        struct node *ptr;
        for (ptr = *h1; ptr->next != NULL; ptr = ptr->next)
            ;
        ptr->next = h2;
    }
}
void simplify(struct node **h)
{
    struct node *ptr, *ptr1, *prev;
    ptr = *h;
    while (ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr1->exp == ptr->exp)
            {
                ptr->coef += ptr1->coef;
            }
            prev->next = ptr1->next;
            free(ptr1);
            ptr1 = prev;
            prev = ptr1;
            ptr1 = ptr->next;
        }
        ptr = ptr->next;
    }
}
int main()
{
    struct node *h1, *h2;
    h1 = h2 = NULL;
    create(&h1);
    create(&h2);
    join(&h1, h2);
    simplify(&h1);
    return 0;
}
