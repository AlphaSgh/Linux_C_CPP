#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "llist.h"
typedef LLIST QUEUE;

QUEUE *queue_create(int initsize);
int queue_add(QUEUE *head, const void *data);
int queue_remove(QUEUE *head, void *data);
void queue_destory(QUEUE *head);
#endif