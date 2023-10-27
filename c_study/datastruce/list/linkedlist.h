#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef int datatype;

typedef struct node_st
{
    datatype data;
    struct node_st *next;
}linkedlist;

linkedlist* list_create();

int list_insert_at(linkedlist *head, int index, datatype *data);
int list_order_insert(linkedlist *head, datatype *data);

int list_delete_at(linkedlist *head, int index);
int list_delete(linkedlist *head, datatype *data);

int list_isempty(linkedlist *head);

void list_show(linkedlist *head);
void list_destory(linkedlist **head);
#endif