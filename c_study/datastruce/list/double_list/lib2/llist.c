#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"

LLIST *llist_create(int initsize)
{
    LLIST *new;
    new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return NULL;
    }
    new->size = initsize;
    new->head.prev = &new->head;
    new->head.next = &new->head;

    return new;
}
int llist_insert(LLIST *llist, const void *data, int mode)
{
    llist_node_st *newnode;
    newnode = malloc(sizeof(*newnode) + llist->size);
    if (newnode == NULL)
    {
        return -1;
    }
    memcpy(newnode->data, data, llist->size);
    if (mode == LLIST_FORWARD)
    {
        newnode->prev = &llist->head;
        newnode->next = llist->head.next;
        newnode->prev->next = newnode;
        newnode->next->prev = newnode;
    }
    else if (mode == LLIST_BACKWARD)
    {
        newnode->prev = llist->head.prev;
        newnode->next = &llist->head;
        newnode->prev->next = newnode;
        newnode->next->prev = newnode;
    }
    else
    {
        return -3;
    }
    return 0;
}
static llist_node_st *find_(LLIST *llist, const void *key, llist_cmp *cmp)
{
    llist_node_st *cur;
    cur = llist->head.next;
    while (cur != &llist->head)
    {
        if (cmp(key, cur->data) == 0)
        {
            break;
        }
        cur = cur->next;
    }
    return cur;
}
void *llist_find(LLIST *llist, const void *key, llist_cmp *cmp)
{
    llist_node_st *node;
    node = find_(llist, key, cmp);
    if (node == &llist->head)
    {
        return NULL;
    }
    return node->data;
}
int llist_delete(LLIST *llist, const void *key, llist_cmp *cmp)
{
    llist_node_st *node;
    node = find_(llist, key, cmp);
    if (node == &llist->head)
    {
        return -1;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
    
}
int llist_fetch(LLIST *llist, const void *key, llist_cmp *cmp, void *data)
{
    llist_node_st *node;
    node = find_(llist, key, cmp);
    if (node == &llist->head)
    {
        return -1;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (data != NULL)
    {
        memcpy(data, node->data, llist->size);
    }
    free(node);
    return 0;
}
void llist_travel(LLIST *llist, llist_op *print_op)
{
    llist_node_st *cur;
    cur = llist->head.next;
    while (cur != &llist->head)
    {
        print_op(cur->data);
        cur = cur->next;
    }
    
}
void llist_destory(LLIST *llist)
{
    llist_node_st *cur, *next;
    cur = llist->head.next;
    while (cur != &llist->head)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(llist);
}
