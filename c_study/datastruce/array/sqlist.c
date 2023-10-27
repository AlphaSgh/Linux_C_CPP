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
    me->size = 0;
    return me;
}
void sqlist_create1(sqlist** list)
{
    *list = malloc(sizeof(**list));
    if (*list == NULL)
    {
        return;
    }
    (*list)->size = 0;
    return;
}
int sqlist_destory(sqlist* list)
{
    if (list == NULL)
    {
        return -1;
    }
    free(list);
    return 0;
}
int sqlist_insert(sqlist* list, int index, datatype* data)
{
    if (list->size == DATASIZE) // list is full
    {
        return -1;
    }
    if (index < 0 || index > list->size)
    {
        return -2;
    }
    for (size_t j = list->size; j > index; j--)
    {
        list->data[j] = list->data[j - 1];
    }
    list->data[index] = *data;
    (list->size)++;

    return 0;
}
int sqlist_delte(sqlist* list, int index)
{
    if (index < 0 || index > list->size) // index out of bound
    {
        return -1;
    }
    for (size_t j = index; j < list->size - 1; j++)
    {
        list->data[j] = list->data[j + 1];
    }
    list->size--;
    return 0;
}
int sqlist_find(sqlist* list, datatype* data)
{
    if (list == NULL)
    {
        return -1;
    }
    
    for (size_t i = 0; i < list->size; i++)
    {
        if (list->data[i] == *data)
        {
            return i;
        }
    }
    return -1;
}
int sqlist_isempty(sqlist* list)
{
    if (list == NULL)
    {
        return -1;
    }
    
    return list->size;
}
int sqlist_setempty(sqlist* list)
{
    if (list == NULL)
    {
        return -1;
    }
    list->size = 0;
    return 0;
}
int sqlist_getnum(sqlist* list)
{
    if (list == NULL)
    {
        return -1;
    }
    return list->size;
}
void sqlist_show(sqlist* list)
{
    if (list->size == 0) // list is empty
    {
        return;
    }
    for (size_t i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return;
}
int sqlist_union(sqlist* list1, sqlist* list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return -1;
    }
    // printf("list1 size = %d\nlist2 size = %d\n", list1->size, list2->size);
    for (size_t i = list1->size, j = 0; j < list2->size; i++, j++)
    {
        list1->data[i] = list2->data[j];
        list1->size++;
    }
    return list1->size;    
}