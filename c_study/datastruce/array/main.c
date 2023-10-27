#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main(void)
{
    sqlist *list1, *list2;
    list1 = sqlist_create();
    list2 = sqlist_create();

    if (list1 == NULL || list2 == NULL)
    {
        fprintf(stderr, "sqlist_create() faile\n");
        exit(1);
    }
    datatype data[5] = {1, 2, 3, 4, 5};
    int err;

    for (size_t i = 0; i < sizeof(data) / sizeof(*data); i++)
    {
        if (err = ((sqlist_insert(list1, 0, &data[i])) || (sqlist_insert(list2, 0, &data[i])) != 0))
        {
            if (err == -1)
            {
                fprintf(stderr, "sqlist is full\n");
            }
            else if (err == -1)
            {
                fprintf(stderr, "the pos you want to insert is wrong\n");
            }
            else
            {
                fprintf(stderr, "error\n");
            }
            exit(1);
        }
    }
    sqlist_show(list1);
    sqlist_show(list2);
    // sqlist_delte(list1, 3);
    // sqlist_show(list1);
    // datatype find = 3;
    // int index = sqlist_find(list1, &find);
    // printf("index of find is %d\n", index);
    // sqlist_setempty(list1);
    // int empty = sqlist_isempty(list1);
    // empty == 0 ? printf("list is empty\n") : printf("list size is %d\n", list1->size);

    // sqlist_show(list1);
    // printf("%d\n", __LINE__);
    sqlist_union(list1, list2);
    // printf("%d\n", __LINE__);
    sqlist_show(list1);
    // printf("%d\n", __LINE__);
    sqlist_destory(list2);
    sqlist_destory(list1);
}