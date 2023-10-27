#ifndef __SQLIST_H__
#define __SQLIST_H__

#define DATASIZE 1024
typedef int datatype;
typedef struct node_st
{
    datatype data[DATASIZE];
    int size;
} sqlist;

sqlist* sqlist_create();
void sqlist_create1(sqlist** list);
int sqlist_destory(sqlist* list);
int sqlist_insert(sqlist* list, int index, datatype* data);
int sqlist_delte(sqlist* list, int index);
int sqlist_find(sqlist* list, datatype* data);
int sqlist_isempty(sqlist* list);
int sqlist_setempty(sqlist* list);
int sqlist_getnum(sqlist* list);
void sqlist_show(sqlist* list);
int sqlist_union(sqlist* list1, sqlist* list2);

#endif