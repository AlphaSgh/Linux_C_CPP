#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

QUEUE *queue_create(int initsize)
{
    return llist_create(initsize);
}
int queue_add(QUEUE *head, const void *data)
{
    return llist_insert(head, data, LLIST_BACKWARD);
}
static int always_match(const void *p1, const void *p2) 
{
    return 0;
}
int queue_remove(QUEUE *head, void *data)
{
    return llist_fetch(head, (void *)0, always_match, data);
}
void queue_destory(QUEUE *head)
{
    llist_destory(head);
}