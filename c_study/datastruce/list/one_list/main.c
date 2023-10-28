#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main(void)
{
    linkedlist *head;
    head = list_create();
    datatype a[7] = {11, 22, 3, 3, 4, 43, 15};
    for (size_t i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        list_insert_at(head, 0, &a[i]);
        // list_order_insert(head, &a[i]);
    }
    list_show(head);
    list_delete_at(head, 4);
    list_show(head);
    datatype d = 3;
    list_delete(head, &d);
    list_show(head);
    list_destory(&head);
    exit(0);
}