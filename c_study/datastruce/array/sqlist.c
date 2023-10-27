#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

sqlist* sqlist_create()
{
    sqlist *me;
    me = malloc(sizeof(*me));
    if (me == NULL)
    {
        return NULL;
    }
    me->last = -1;
    return me;
}
void sqlist_create1(sqlist** list)
{
    *list = malloc(sizeof(**list));
    if (*list == NULL)
    {
        return;
    }
    (*list)->last = -1;
    return;
}
int sqlist_destory(sqlist* list)
{
    
}
int sqlist_insert(sqlist* list, int index, datatype* data)
{
    size_t j;
    if (list->last == DATASIZE - 1)
    {
        return -1;
    }
    if (index < 0 || index > list->last + 1)
    {
        return -2;
    }
    for (j = list->last; index <= j; j--)
    {
        printf("%zd\n", j);
        list->data[j + 1] = list->data[j];
    }
    list->data[index] = *data;
    list->last++;

    return 0;
}
int sqlist_delte(sqlist* list, int index)
{
    
}
int sqlist_find(sqlist* list, datatype* data)
{
    
}
int sqlist_isempty(sqlist* list)
{
    
}
int sqlist_setempty(sqlist* list)
{
    
}
int sqlist_getnum(sqlist* list)
{
    
}
void sqlist_show(sqlist* list)
{
    if (list->last == -1)
    {
        return;
    }
    for (size_t i = 0; i <= list->last; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return;
}
int sqlist_union(sqlist* list1, sqlist* list2)
{
    
}