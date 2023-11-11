#include <stdlib.h>
#include <stdio.h>
#include "sqstack.h"

sqlstack *st_create(void)
{
      sqlstack *st;
      st = malloc(sizeof(*st));
      if (st == NULL)
      {
            return NULL;
      }
      st->top = -1;
      return st;
}

int st_isempty(sqlstack *st)
{
      return (st->top == -1);
}

int st_push(sqlstack *st, datatype *data)
{
      if (st->top == (MAXSIZE - 1))
      {
            return -1;
      }
      st->top++;
      st->data[st->top] = *data;
      return 0;
}
int st_pop(sqlstack *st, datatype *data)
{
      if (st_isempty(st))
      {
            return -1;
      }
      *data = st->data[st->top--];

      return 0;
}
int st_top(sqlstack *st, datatype *data)
{
      if (st_isempty(st))
      {
            return -1;
      }
      *data = st->data[st->top];
      return 0;
}

void st_travel(sqlstack *st)
{
      if (st_isempty(st))
      {
            return;
      }

      for (size_t i = 0; i <= st->top; i++)
      {
            printf("%d ", st->data[i]);
      }
      printf("\n");
}
void st_destory(sqlstack *st)
{
      free(st);
}