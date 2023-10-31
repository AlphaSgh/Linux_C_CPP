#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"

struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[1];
};

struct llist_head_st
{
    int size;
    struct llist_node_st head;
};

void *llist_create(int initsize)
{
    struct llist_head_st *new;
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
int llist_insert(void *l, const void *data, int mode)
{
    struct llist_head_st *llist = l; 
    struct llist_node_st *newnode;
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
static struct llist_node_st *find_(void *l, const void *key, llist_cmp *cmp)
{
    struct llist_head_st  *llist = l;
    struct llist_node_st *cur;
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
void *llist_find(void *l, const void *key, llist_cmp *cmp)
{
    struct llist_head_st *llist = l;
    struct llist_node_st *node;
    node = find_(llist, key, cmp);
    if (node == &llist->head)
    {
        return NULL;
    }
    return node->data;
}
int llist_delete(void *l, const void *key, llist_cmp *cmp)
{
    struct llist_head_st *llist = l;
    struct llist_node_st *node;
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
int llist_fetch(void *l, const void *key, llist_cmp *cmp, void *data)
{
    struct llist_head_st *llist = l;
    struct llist_node_st *node;
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
void llist_travel(void *l, llist_op *print_op)
{
    struct llist_head_st *llist = l;
    struct llist_node_st *cur;
    cur = llist->head.next;
    while (cur != &llist->head)
    {
        print_op(cur->data);
        cur = cur->next;
    }
    
}
void llist_destory(void *l)
{
    struct llist_head_st *llist = l;
    struct llist_node_st *cur, *next;
    cur = llist->head.next;
    while (cur != &llist->head)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(llist);
}
