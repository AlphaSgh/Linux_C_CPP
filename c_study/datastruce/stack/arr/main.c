#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

int main(int argc, char const *argv[])
{
      sqlstack *st;
      datatype data[] = {1, 4, 5, 0, 1};
      st = st_create();
      if (st == NULL)
      {
            exit(1);
      }
      for (size_t i = 0; i < sizeof(data) / sizeof(*data); i++)
      {
            st_push(st, &data[i]);
      }
      st_travel(st);
      datatype tmp;
      int res;
      res = st_top(st, &tmp);
      printf("tmp = %d\n", tmp);
      res = st_pop(st, &tmp);
      printf("tmp = %d\n", tmp);
      st_travel(st);

      st_destory(st);

      return 0;
}
