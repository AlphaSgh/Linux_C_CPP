#ifndef __STACK_H__
#define __STACK_H__

#include "llist.h"
typedef LLIST STACK;

STACK *stack_create(int initsize);
int stack_push(STACK *head, const void *data);
int stack_pop(STACK *head, void *data);
void stack_destory(STACK *head);
#endif