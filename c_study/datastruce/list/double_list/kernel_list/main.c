#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define NAMESIZE 32
typedef struct student_st
{
      int id;
      char name[NAMESIZE];
      struct list_head node;
      int math;
      int chinese;
} student;
void print_s(student *d)
{
      printf("%d %s %d %d\n", d->id, d->name, d->math, d->chinese);
}
int main(void)
{
      student *datap;
      struct list_head *cur;
      LIST_HEAD(head);

      for (size_t i = 0; i < 7; i++)
      {
            datap = malloc(sizeof(*datap));
            if (datap == NULL)
            {
                  exit(1);
            }

            datap->id = i;
            snprintf(datap->name, NAMESIZE, "stu%zd", i);
            datap->math = rand() % 100;
            datap->chinese = rand() % 100;

            list_add(&(datap->node), &head);
      }
      __list_for_each(cur, &head)
      {
            datap = list_entry(cur, student, node);
            print_s(datap);
      }
      __list_for_each(cur, &head)
      {
            datap = list_entry(cur, student, node);
            if (datap->id == 15)
            {
                  break;
            }
      }
      if (cur == &head)
      {
            printf("con't find the student\n");
      }
      else
      {
            print_s(datap);
      }

      exit(0);
}