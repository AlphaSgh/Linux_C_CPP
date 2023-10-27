#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main(void)
{
    sqlist* list;
    list = sqlist_create();
    if (list == NULL)
    {
        fprintf(stderr, "sqlist_create() faile\n");
        exit(1);
    }
    datatype data[5] = {1, 2, 3, 4, 5};
    int err;
    printf("%d %zd\n", __LINE__, sizeof(data) / sizeof(*data));
    int j = 15;
    err = sqlist_insert(list, 0, &j);
    err = sqlist_insert(list, 0, &j);
    err = sqlist_insert(list, 0, &j);
    err = sqlist_insert(list, 0, &j);

    // for (size_t i = 0; i < sizeof(data) / sizeof(*data); i++)
    // {
    //     int j = 15;
    //     if ((err = sqlist_insert(list, i, &j)) != 0)
    //     {
    //         printf("%d %zd\n", __LINE__, sizeof(data) / sizeof(*data));
    //         if (err == -1)
    //         {
    //             fprintf(stderr, "sqlist is full\n");
    //         }
    //         else if (err == -1)
    //         {
    //             fprintf(stderr, "the pos you want to insert is wrong\n");
    //         }
    //         else
    //         {
    //             fprintf(stderr, "error\n");
    //         }
    //         exit(1);
    //     }
    // }
    sqlist_show(list);
    sqlist_destory(list);
}