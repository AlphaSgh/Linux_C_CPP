#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define NAMESIZE 32
typedef struct student_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}student;

static void print_student(const void *s)
{
    const student *stu = s;
    printf("id: %2d name: %s math: %2d chinese: %2d\n", stu->id, stu->name, stu->math, stu->chinese);
}
int main(void)
{
    QUEUE *my_queue;
    student temp;
    my_queue = queue_create(sizeof(temp));
    if (my_queue == NULL)
    {
        exit(-1);
    }
    for (size_t i = 0; i < 5; i++)
    {
        temp.id = i;
        snprintf(temp.name, NAMESIZE, "student%zd", i);
        temp.math = rand() % 100;
        temp.chinese = rand() % 100;
        queue_add(my_queue, &temp);
    }
    student *stu1;
    int ret;
    while (1)
    {
        ret = queue_remove(my_queue, stu1);
        if (ret != 0)
        {
            exit(-1);
        }
        print_student(stu1);
    }
    
    queue_destory(my_queue);
    exit(0);
}