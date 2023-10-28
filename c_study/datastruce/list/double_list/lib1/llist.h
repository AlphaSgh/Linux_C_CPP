#ifndef __LLIST_H__
#define __LLIST_H__

#define LLIST_FORWARD    1
#define LLIST_BACKWARD   2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *, const void *);

typedef struct llist_node_st
{
    void *data;
    struct llist_node_st *prev;
    struct llist_node_st *next;
} llist_node_st;

typedef struct llist
{
    int size;
    struct llist_node_st head;
} LLIST;

LLIST *llist_create(int initsize);
int llist_insert(LLIST *llist, const void *data, int mode);
void *llist_find(LLIST *llist, const void *key, llist_cmp * cmp);
int llist_delete(LLIST *llist, const void *key, llist_cmp *cmp);
int llist_fetch(LLIST *llist, const void *key, llist_cmp *cmp, void *data);
void llist_travel(LLIST *llist, llist_op *print_op);
void llist_destory(LLIST *llist);

#endif