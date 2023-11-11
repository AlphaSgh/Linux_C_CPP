#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

STACK *stack_create(int initsize)
{
    return llist_create(initsize);
}
int stack_push(STACK *head, const void *data)
{
    return llist_insert(head, data, LLIST_FORWARD);
}
static int always_match(const void *p1, const void *p2) 
{
    return 0;
}
int stack_pop(STACK *head, void *data)
{
    return llist_fetch(head, (void *)0, always_match, data);
}
void stack_destory(STACK *head)
{
    llist_destory(head);
}